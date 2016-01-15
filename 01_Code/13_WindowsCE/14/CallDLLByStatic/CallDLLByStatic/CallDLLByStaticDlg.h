// CallDLLByStaticDlg.h : 头文件
//

#pragma once

// CCallDLLByStaticDlg 对话框
class CCallDLLByStaticDlg : public CDialog
{
// 构造
public:
	CCallDLLByStaticDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALLDLLBYSTATIC_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCall();
};
