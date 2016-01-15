// ClientSocket.cpp: implementation of the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VODClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientSocket::CClientSocket()
{
  m_hClientSock=NULL;
}

CClientSocket::~CClientSocket()
{
   if (m_hClientSock)
   {
	   closesocket(m_hClientSock);
   }
}
//创建socket，连接服务器
BOOL CClientSocket::Initialize()
{
	m_hClientSock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (m_hClientSock==INVALID_SOCKET )
	{
		return FALSE;
	}
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
	//已注册端口号：1024~49151
    addr.sin_port = htons(6789);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if(0!=connect(m_hClientSock,(sockaddr *)&addr,sizeof(addr)))
	{
       return FALSE;
	}
    return TRUE;
}
//登录
BOOL CClientSocket::Login(LPCSTR pszName,LPCSTR pszPwd){
    VODLOGIN login = {0};
    strcpy(login.szUserName,pszName);
    strcpy(login.szPassword,pszPwd);

    SendData(VODNETCMD_LOGIN,&login,sizeof(login));
	
    VODHEADER header = {0};
    RecvData(&header,sizeof(header));
    VODLOGINRET loginret = {0};
    RecvData(&loginret,sizeof(loginret));
    return loginret.dwSuccess;
}
//下载文件
BOOL CClientSocket::GetMediaData(DWORD videoID,LPCSTR pszFilePath,CString & strFullPath)
{
    MEDIADATA data = {0};
    data.videoID=videoID;
    if(!SendData(VODNETCMD_MEDIADATA,&data,sizeof(data)))
        return FALSE;
    
    VODHEADER header = {0};
    if(!RecvData(&header,sizeof(header)))
	   return FALSE;
    
    MEDIADATARET dataret = {0};
    if(!RecvData(&dataret,sizeof(dataret)))
		return FALSE;
    if (dataret.dwFileLen==0)
    {
        return TRUE;
    }
    strFullPath = pszFilePath;
	strFullPath+=dataret.szFileName;
    //判断文件是否存在
    BOOL bExit=PathFileExists(strFullPath);
   	if (!SendRaw(&bExit,sizeof(bExit)))return FALSE;
    if (bExit)return TRUE;//文件存在，将不再接收文件内容
    CFile file;
    if(!file.Open(strFullPath,CFile::modeCreate|CFile::modeWrite))
		return FALSE;
        
    CHAR szBuff[2000] = {0};
    LONG nLeft = dataret.dwFileLen;
    while(nLeft>0){
        int nRecv = 2000;
        if (nLeft<nRecv)
        {
            nRecv = nLeft;
        }
        RecvData(szBuff,nRecv);
        file.Write(szBuff,nRecv);
        nLeft = nLeft - nRecv;
    }
    file.Close();

    return TRUE;
}
//获取所有类型
BOOL CClientSocket::GetAllVideoTypes(CString & types)
{
	VODHEADER header={0};
	header.dwVer=1;
	header.dwCmd=VODNETCMD_TYPES;
	header.dwLen=0;
	if (SendRaw(&header,sizeof(header))!=TRUE)
    {
        return FALSE;
    }
	//返回所有类型
   
	RecvData(&header,sizeof(header));
	LPSTR pData=types.GetBuffer(header.dwLen);
	RecvData(pData,header.dwLen);
	//不调用该函数，不会有字符串的结束
	types.ReleaseBuffer(header.dwLen);
	return TRUE;
}
BOOL CClientSocket::GetVideosByTypeID(DWORD typeID,CString & videos)
{
    GETVIDEOS getVideo;
	getVideo.typdID=typeID;
	if(!SendData(VODNETCMD_GETVIDES,&getVideo,sizeof(getVideo)))
	{
		return FALSE;
	}
	//返回该类型下所有的影片
    VODHEADER header={0};
    RecvData(&header,sizeof(header));
    LPSTR pData=videos.GetBuffer(header.dwLen);
    RecvData(pData,header.dwLen);
   //不调用该函数，不会有字符串的结束
	videos.ReleaseBuffer(header.dwLen);
	return TRUE;
}
BOOL CClientSocket::RecvData(LPVOID  pData,UINT nLen){
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = recv(m_hClientSock,pTemp,nLeft,0);
        if((nRev==SOCKET_ERROR)||(nRev ==0)) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}

BOOL CClientSocket::SendData(DWORD dwCmdID,LPVOID pData,UINT nLen )
{
    VODHEADER header = {0};
    header.dwCmd = dwCmdID;
    header.dwLen = nLen;
	//发送数据包的包头
    if (SendRaw(&header,sizeof(header))!=TRUE)
    {
        return FALSE;
    }
	//发送登录数据包
    if (SendRaw(pData,nLen) != TRUE)
    {
        return FALSE;
    }
    return TRUE;
}
BOOL CClientSocket::SendRaw(LPVOID  pData,UINT nLen){
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = send(m_hClientSock,pTemp,nLeft,0);
        if(nRev ==0) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}