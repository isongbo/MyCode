#pragma once


// CDlgPush 对话框

class CDlgPush : public CDialog
{
	DECLARE_DYNAMIC(CDlgPush)

public:
	CDlgPush(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPush();

// 对话框数据
	enum { IDD = IDD_DLGPUSH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_internetURL;
	CString m_internetUsername;
	CString m_internetPassword;
	CString m_connectStr;
	CString m_localConnectStr;
	CString m_localTableName;
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
};
