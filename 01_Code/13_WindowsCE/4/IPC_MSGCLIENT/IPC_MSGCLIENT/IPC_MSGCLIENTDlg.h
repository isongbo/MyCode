// IPC_MSGCLIENTDlg.h : ͷ�ļ�
//

#pragma once

#include "IPCClient.h"

// CIPC_MSGCLIENTDlg �Ի���
class CIPC_MSGCLIENTDlg : public CDialog
{
// ����
public:
	CIPC_MSGCLIENTDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IPC_MSGCLIENT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
private:
	CIPCClient m_IPCClient;  //IPC���̣��ͻ���ͨѶ����
private:
  	//�ص��������ͻ��˽��������¼�����
	static void CALLBACK OnClientConnected(CWnd *parentWnd,HWND hWnd);
	//�ص��������ͻ��˶Ͽ������¼�����
	static void CALLBACK OnClientDisConnected(CWnd *parentWnd,HWND hWnd);
	//�ص��������ͻ��˽��������¼�����
	static void CALLBACK OnClientDataArrive(CWnd *parentWnd,LPVOID pData,DWORD bufLen);

public:
	afx_msg void OnBnClickedBtnconnect();
	afx_msg void OnBnClickedBtndisconnect();
	afx_msg void OnBnClickedBtnsenddata();
	CString m_SessionName;
	CString m_SendData;
	CString m_RecvData;
	CString m_Status;
};
