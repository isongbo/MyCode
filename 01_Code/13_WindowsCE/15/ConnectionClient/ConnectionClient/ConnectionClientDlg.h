// ConnectionClientDlg.h : 头文件
//

#pragma once

// CConnectionClientDlg 对话框
class CConnectionClientDlg : public CDialog
{
// 构造
public:
	CConnectionClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CONNECTIONCLIENT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	long m_number1;
	long m_number2;

	afx_msg void OnBnClickedBtnExec();
};
