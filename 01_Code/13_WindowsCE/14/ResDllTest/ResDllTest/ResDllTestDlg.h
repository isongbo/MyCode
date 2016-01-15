// ResDllTestDlg.h : 头文件
//

#pragma once

// CResDllTestDlg 对话框
class CResDllTestDlg : public CDialog
{
// 构造
public:
	CResDllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RESDLLTEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	//DLL句柄
	HINSTANCE m_hDll;

public:
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnFree();
	afx_msg void OnBnClickedBtnBmp();
	afx_msg void OnBnClickedBtnIcon();
};
