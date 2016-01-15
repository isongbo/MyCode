// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions
BOOL CClientSocket::InitClient(char* IP,UINT nPort)
{
	if (!Create())
	{
		return FALSE;
	}
	return Connect(IP,nPort);
}
//定义描述文件的结构体
typedef struct _tagHeader
{
	long nLen;//文件长度
	char szFile[256];//文件名称
}HEADER,*LPHEADER;

BOOL CClientSocket::SendFile(CString strPath)
{
	// 发送文件
	// 1 打开文件，获取文件信息和数据
  CFile file;
	file.Open(strPath,CFile::modeRead);
  
	HEADER header={0};
	header.nLen=file.GetLength();
  strcpy(header.szFile,file.GetFileName());
  
	BYTE* pData=(BYTE*)malloc(header.nLen);
	file.Read(pData,header.nLen);
	file.Close();
	//2 发送文件信息
  if (!SendData((BYTE*)&header,sizeof(header)))
  {
		AfxMessageBox("发送文件信息失败！");
		return FALSE;
  }
	//3 发送文件数据
	if (!SendData(pData,header.nLen))
	{
	  AfxMessageBox("发送文件数据失败！");
		return FALSE;
	}

	//4 释放内存，关闭套接字
	free(pData);
	Close();
	return TRUE;
}
BOOL CClientSocket::SendData(BYTE* pData,long nLen)
{
	 BYTE* pTmpData=pData;
	 long nLeft=nLen;
	 while (nLeft>0)
	 {
		 int nSend=Send(pData,nLen);
		 if (nSend==SOCKET_ERROR)
		 {
			 return FALSE;
		 }
		 nLeft-=nSend;
     pTmpData+=nSend;
	 }
   return TRUE;
}