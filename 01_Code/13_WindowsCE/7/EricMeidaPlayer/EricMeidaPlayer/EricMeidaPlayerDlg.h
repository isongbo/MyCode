// EricMeidaPlayerDlg.h : 头文件
//

#pragma once

#include "EricMediaControl.h"

// CEricMeidaPlayerDlg 对话框
class CEricMeidaPlayerDlg : public CDialog
{
// 构造
public:
	CEricMeidaPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ERICMEIDAPLAYER_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	CEricMediaControl m_VideoControl; //媒体播放对象
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnPlay();
	afx_msg void OnBnClickedBtnPause();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnFull();
	afx_msg void OnStnClickedWndVideo();
	//媒体播放事件消息处理函数
	afx_msg LRESULT OnNotifyMedia(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
