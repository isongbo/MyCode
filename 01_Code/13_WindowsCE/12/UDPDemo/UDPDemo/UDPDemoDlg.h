// UDPDemoDlg.h : 头文件
//
#include "UDP_CE.h"
#pragma once

//UDP 接收数据消息
#define WM_RECV_UDP_DATA WM_USER + 101

// CUDPDemoDlg 对话框
class CUDPDemoDlg : public CDialog
{
// 构造
public:
	CUDPDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_UDPDEMO_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	// UDP接收数据处理函数
	afx_msg LONG OnRecvUdpData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	//UDP接收数据事件
	static void CALLBACK OnUdpCERecv(void * pOwner,char* buf,DWORD dwBufLen,sockaddr * addr);
	//UDP通讯错误事件
	static void CALLBACK OnUdpCEError(void * pOwner,int nErrorCode);
public:
	CString m_RemoteHost;
	int m_RemotePort;
	int m_LocalPort;
private:
	//定义UDP通讯类变量
	CUDP_CE m_CEUdp;

public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSend();
};
