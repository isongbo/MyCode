// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions
BOOL CServerSocket::InitServer(UINT nPort)
{
	//1 创建 2 绑定 
	if (!Create(nPort))
	 {
		 return FALSE;
	 }
	// 3 监听
	return Listen();
}
//定义描述文件的结构体
typedef struct _tagHeader
{
	long nLen;//文件长度
	char szFile[256];//文件名称
}HEADER,*LPHEADER;

void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	// 4 接收客户端连接
  CSocket client;
	Accept(client);
	// 5 接收文件...
  // 5.1 接收文件数据之前，首先接收文件信息
	HEADER header={0};
  if (!RecvData(client,(BYTE*)&header,
		sizeof(header)))
  {
		AfxMessageBox("接收文件信息失败！");
		return;
  }
  // 5.2 接收文件数据
	BYTE* pData=(BYTE*)malloc(header.nLen);
	if (!RecvData(client,pData,header.nLen))
	{
		AfxMessageBox("接收文件数据失败！");
		return;
	}
	// 5.3 保存到服务器
  CFile file;
	CString strPath="C:/";
	strPath+=header.szFile;
	file.Open(strPath,
		CFile::modeCreate|CFile::modeWrite);
  file.Write(pData,header.nLen);
	file.Close();
	free(pData);

	// 6 关闭套接字
	client.Close();

	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvData(CSocket& client,
											BYTE* pData, long nLen)
{
	BYTE* pTmpData=pData;
  long nLeft=nLen;//剩余的还没有的接收的数据的长度
	while (nLeft>0)
	{
		int nRecv=client.Receive(pTmpData,nLeft);
		if (nRecv==SOCKET_ERROR)
		{
			return FALSE;
		}
		nLeft-=nRecv;
    pTmpData+=nRecv;
	}
	return TRUE;
}