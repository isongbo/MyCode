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
//���������ļ��Ľṹ��
typedef struct _tagHeader
{
	long nLen;//�ļ�����
	char szFile[256];//�ļ�����
}HEADER,*LPHEADER;

BOOL CClientSocket::SendFile(CString strPath)
{
	// �����ļ�
	// 1 ���ļ�����ȡ�ļ���Ϣ������
  CFile file;
	file.Open(strPath,CFile::modeRead);
  
	HEADER header={0};
	header.nLen=file.GetLength();
  strcpy(header.szFile,file.GetFileName());
  
	BYTE* pData=(BYTE*)malloc(header.nLen);
	file.Read(pData,header.nLen);
	file.Close();
	//2 �����ļ���Ϣ
  if (!SendData((BYTE*)&header,sizeof(header)))
  {
		AfxMessageBox("�����ļ���Ϣʧ�ܣ�");
		return FALSE;
  }
	//3 �����ļ�����
	if (!SendData(pData,header.nLen))
	{
	  AfxMessageBox("�����ļ�����ʧ�ܣ�");
		return FALSE;
	}

	//4 �ͷ��ڴ棬�ر��׽���
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