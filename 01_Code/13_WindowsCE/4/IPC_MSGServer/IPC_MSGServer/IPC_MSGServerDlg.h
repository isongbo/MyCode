// IPC_MSGServerDlg.h : 头文件
//

#pragma once

#include "IPCServer.h"

// CIPC_MSGServerDlg 对话框
class CIPC_MSGServerDlg : public CDialog
{
// 构造
public:
	CIPC_MSGServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IPC_MSGSERVER_DIALOG };


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
public:
	CString m_SessionName;
	CString m_SendData;
	CString m_RecvData;
	CString m_Status;
private:
	CIPCServer m_IPCServer;  //IPC SERVER对象

public:
	//存储客户端窗口句柄
	HWND m_ClientWnd;

private:
    //回调函数，服务器连接事件
	static void CALLBACK OnServerConnected(CWnd* parentWnd,HWND hWnd);
    //回调函数，服务器断开连接事件
	static void CALLBACK OnServerDisConnected(CWnd* parentWnd,HWND hWnd);
    //回调函数，服务器接收数据事件
	static void CALLBACK OnServerDataArrive(CWnd* parentWnd,LPVOID pData,DWORD bufLen,HWND hWnd);

public:
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnsenddata();
};
