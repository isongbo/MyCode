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
	//1 ���� 2 �� 
	if (!Create(nPort))
	 {
		 return FALSE;
	 }
	// 3 ����
	return Listen();
}
//���������ļ��Ľṹ��
typedef struct _tagHeader
{
	long nLen;//�ļ�����
	char szFile[256];//�ļ�����
}HEADER,*LPHEADER;

void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	// 4 ���տͻ�������
  CSocket client;
	Accept(client);
	// 5 �����ļ�...
  // 5.1 �����ļ�����֮ǰ�����Ƚ����ļ���Ϣ
	HEADER header={0};
  if (!RecvData(client,(BYTE*)&header,
		sizeof(header)))
  {
		AfxMessageBox("�����ļ���Ϣʧ�ܣ�");
		return;
  }
  // 5.2 �����ļ�����
	BYTE* pData=(BYTE*)malloc(header.nLen);
	if (!RecvData(client,pData,header.nLen))
	{
		AfxMessageBox("�����ļ�����ʧ�ܣ�");
		return;
	}
	// 5.3 ���浽������
  CFile file;
	CString strPath="C:/";
	strPath+=header.szFile;
	file.Open(strPath,
		CFile::modeCreate|CFile::modeWrite);
  file.Write(pData,header.nLen);
	file.Close();
	free(pData);

	// 6 �ر��׽���
	client.Close();

	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvData(CSocket& client,
											BYTE* pData, long nLen)
{
	BYTE* pTmpData=pData;
  long nLeft=nLen;//ʣ��Ļ�û�еĽ��յ����ݵĳ���
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