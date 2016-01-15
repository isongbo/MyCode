// IPC_MSGCLIENTDlg.h : 头文件
//

#pragma once

#include "IPCClient.h"

// CIPC_MSGCLIENTDlg 对话框
class CIPC_MSGCLIENTDlg : public CDialog
{
// 构造
public:
	CIPC_MSGCLIENTDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IPC_MSGCLIENT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
private:
	CIPCClient m_IPCClient;  //IPC进程，客户端通讯对象
private:
  	//回调函数，客户端建立连接事件函数
	static void CALLBACK OnClientConnected(CWnd *parentWnd,HWND hWnd);
	//回调函数，客户端断开连接事件函数
	static void CALLBACK OnClientDisConnected(CWnd *parentWnd,HWND hWnd);
	//回调函数，客户端接收数据事件函数
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
