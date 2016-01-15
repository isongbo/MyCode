// CameraDemoDlg.h : 头文件
//

#pragma once

#include "EricCamera.h"

// CCameraDemoDlg 对话框
class CCameraDemoDlg : public CDialog
{
// 构造
public:
	CCameraDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CAMERADEMO_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	CEricCamera m_Camera; //摄像头控制类
public:
	afx_msg void OnBnClickedBtnPreview();
	afx_msg void OnBnClickedBtnSnap();
	afx_msg void OnBnClickedBtnRecord();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
