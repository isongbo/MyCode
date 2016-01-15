#pragma once


// CDlgPull 对话框

class CDlgPull : public CDialog
{
	DECLARE_DYNAMIC(CDlgPull)

public:
	CDlgPull(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPull();

// 对话框数据
	enum { IDD = IDD_DLGPULL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_internetURL;
	CString m_internetUsername;
	CString m_internetPassword;
	CString m_tracking;
	CString m_errorTableName;
	CString m_connectStr;
	CString m_localConnectStr;
	CString m_localTableName;
	CString m_queryStr;
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
};
