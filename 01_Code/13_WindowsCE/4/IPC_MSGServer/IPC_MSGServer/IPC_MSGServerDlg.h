// IPC_MSGServerDlg.h : ͷ�ļ�
//

#pragma once

#include "IPCServer.h"

// CIPC_MSGServerDlg �Ի���
class CIPC_MSGServerDlg : public CDialog
{
// ����
public:
	CIPC_MSGServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IPC_MSGSERVER_DIALOG };


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
public:
	CString m_SessionName;
	CString m_SendData;
	CString m_RecvData;
	CString m_Status;
private:
	CIPCServer m_IPCServer;  //IPC SERVER����

public:
	//�洢�ͻ��˴��ھ��
	HWND m_ClientWnd;

private:
    //�ص������������������¼�
	static void CALLBACK OnServerConnected(CWnd* parentWnd,HWND hWnd);
    //�ص��������������Ͽ������¼�
	static void CALLBACK OnServerDisConnected(CWnd* parentWnd,HWND hWnd);
    //�ص����������������������¼�
	static void CALLBACK OnServerDataArrive(CWnd* parentWnd,LPVOID pData,DWORD bufLen,HWND hWnd);

public:
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnsenddata();
};
