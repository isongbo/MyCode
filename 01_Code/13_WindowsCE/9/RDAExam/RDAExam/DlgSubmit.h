#pragma once


// CDlgSubmit 对话框

class CDlgSubmit : public CDialog
{
	DECLARE_DYNAMIC(CDlgSubmit)

public:
	CDlgSubmit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSubmit();

// 对话框数据
	enum { IDD = IDD_DLGSUBMIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_internetURL;
	CString m_internetUsername;
	CString m_internetPassword;
	CString m_connectStr;
	CString m_queryStr;
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
};
