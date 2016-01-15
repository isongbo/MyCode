// EDBUseDlg.h : 头文件
//

#pragma once

// CEDBUseDlg 对话框
class CEDBUseDlg : public CDialog
{
// 构造
public:
	CEDBUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EDBUSE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnrefresh();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtnedit();
	afx_msg void OnBnClickedBtndelete();
};
