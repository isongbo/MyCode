// NetClient.cpp: implementation of the CNetClient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vodserver.h"
#include "NetClient.h"
#include "UserManager.h"
#include "TypeManager.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNetClient::CNetClient()
{

}

CNetClient::~CNetClient()
{

}
BOOL CNetClient::Initialize( )
{
    DWORD dwThreadID = 0;
    HANDLE hThread = CreateThread(NULL,0,ClientThread,
        this,0,&dwThreadID);
    CloseHandle(hThread);
    return TRUE;
}
DWORD CNetClient::ClientThread(LPVOID pParam){
    CNetClient * pThis = (CNetClient *)pParam;
    BOOL bRet = TRUE;
    while (bRet)
    {
        VODHEADER header = { 0 };
        bRet = pThis->RecvData( &header,sizeof(header));
        switch (header.dwCmd)
        {
        case VODNETCMD_LOGIN:
            bRet = pThis->OnLogin();
            break;
        case VODNETCMD_MEDIADATA:
            bRet = pThis->OnMediaData();
            break;
		case VODNETCMD_TYPES:
			bRet=pThis->OnAllVideoTypes();
			break;
		case VODNETCMD_GETVIDES:
			bRet=pThis->OnVideosByTypeID();
        default:
            break;
        }
    }
    closesocket(pThis->m_hClientSocket);
    return 0;
}

BOOL CNetClient::OnLogin()
{
    VODLOGIN login = {0};
    if (FALSE == RecvData(&login,sizeof(login)))
    {
        return FALSE;
    }
	//数据库查询
    CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CUserManager userMgr(&pWnd->m_adoConnection);
    CUser user;
	user.strUserName=login.szUserName;
	user.strPwd=login.szPassword;
	VODLOGINRET loginret = {0};
	if(userMgr.ValidateUser(user))
	{
	   loginret.dwSuccess = 1;
	}
	else
	{
		loginret.dwSuccess = 0;
		
	}
    BOOL nRet = SendData(VODNETCMD_LOGIN_RET,
        &loginret,sizeof(loginret));
    return nRet;
}
BOOL CNetClient::OnAllVideoTypes()
{
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CTypeManager typeMgr(&pWnd->m_adoConnection);
	CList<CType,CType> lstType;
	typeMgr.GetAllType(&lstType);
	
	CType type;
	CString strData;
    
    for (int i=0;i<lstType.GetCount();i++)
    {
	    type=lstType.GetAt(lstType.FindIndex(i));
		strData+=type.strTypeName;
		strData+=",";
		CString strID;
		strID.Format("%d,",type.nTypeID);
		strData+=strID;
    }

	//首先发送数据长度，然后发送数据
	int nLen=strData.GetLength();
	LPSTR pData=(LPSTR)malloc(nLen+1);
	memset(pData,0,nLen+1);
	strcpy(pData,strData);
	SendData(VODNETCMD_TYPES_RET,pData,strData.GetLength());
	free(pData);
	return TRUE;
}
BOOL CNetClient::OnVideosByTypeID()
{
	GETVIDEOS getVideo;
	if (!RecvData(&getVideo,sizeof(getVideo)))
	{
		return FALSE;
	}
	//数据库查询指定类型ID的所有视频
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CVideoManager videoMgr(&pWnd->m_adoConnection);
	CList<CVideo,CVideo> lstVideo;
	videoMgr.GetVideosByTypeID(getVideo.typdID,&lstVideo);
	
	CVideo v;
	CString strData;
    
    for (int i=0;i<lstVideo.GetCount();i++)
    {
		v=lstVideo.GetAt(lstVideo.FindIndex(i));
		strData+=v.strVideoName;
		strData+=",";
		CString strID;
		strID.Format("%d,",v.nVideoID);
		strData+=strID;
    }
	//首先发送数据长度，然后发送数据
	int nLen=strData.GetLength();
	LPSTR pData=(LPSTR)malloc(nLen+1);
	memset(pData,0,nLen+1);
	strcpy(pData,strData);
	SendData(VODNETCMD_TYPES_RET,pData,strData.GetLength());
	free(pData);
	return TRUE;
}
BOOL CNetClient::OnMediaData()
{
    MEDIADATA data = {0};
    if(!RecvData(&data,sizeof(data)))
		return FALSE;
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CVideoManager videoMgr(&pWnd->m_adoConnection);
	CString strVideoPath=videoMgr.GetVideoPathByID(data.videoID);
    CFile file;
    MEDIADATARET dataret = {0};
    if(!file.Open(strVideoPath,CFile::modeRead))
	{
        return FALSE;
    }
    //从文件路径中获取文件名称
	int pos=strVideoPath.ReverseFind('\\');
	strcpy(dataret.szFileName,strVideoPath.Mid(pos+1));
    dataret.dwFileLen = file.GetLength();
    if(!SendData(VODNETCMD_MEDIADATA_RET,&dataret,sizeof(dataret)))
    {
        file.Close();
        return FALSE;
    }
	BOOL bExit=FALSE;
    if (RecvData(&bExit,sizeof(bExit)))
    {
		if (bExit)
		{
			file.Close();
			return TRUE;
		}
    }
	else
	{
		return FALSE;
	}
    CHAR szBuff[2000] = {0};
    LONG nLeft = dataret.dwFileLen;
    while(nLeft>0){
        int nSend = 2000;
        if (nLeft<nSend)
        {
            nSend = nLeft;
        }
        file.Read(szBuff,nSend);
        SendRaw(szBuff,nSend);
        nLeft = nLeft - nSend;
    }
    file.Close();
    return TRUE;
}
BOOL CNetClient::RecvData(LPVOID  pData,UINT nLen)
{
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = recv(m_hClientSocket,pTemp,nLeft,0);
        if((nRev==SOCKET_ERROR)||(nRev ==0)) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}

BOOL CNetClient::SendData(DWORD dwCmdID,LPVOID pData,UINT nLen )
{
    VODHEADER header = {0};
    header.dwCmd = dwCmdID;
    header.dwLen = nLen;
    if (SendRaw(&header,sizeof(header))!=TRUE)
    {
        return FALSE;
    }
    if (SendRaw(pData,nLen) != TRUE)
    {
        return FALSE;
    }
    return TRUE;
}
BOOL CNetClient::SendRaw(LPVOID  pData,UINT nLen)
{
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = send(m_hClientSocket,pTemp,nLeft,0);
        if(nRev ==0) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}
