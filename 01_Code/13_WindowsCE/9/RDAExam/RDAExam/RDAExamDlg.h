// RDAExamDlg.h : 头文件
//

#pragma once

#include <ca_merge30.h>


// CRDAExamDlg 对话框
class CRDAExamDlg : public CDialog
{
// 构造
public:
	CRDAExamDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RDAEXAM_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	//显示远程数据访问时的错误
	void    ShowErrors(ISSCEErrors* pISSCEErrors);

public:
	afx_msg void OnBnClickedBtnSubmit();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnPull();
	afx_msg void OnBnClickedBtnPush();
};
