#pragma once


// CDlgSubmit �Ի���

class CDlgSubmit : public CDialog
{
	DECLARE_DYNAMIC(CDlgSubmit)

public:
	CDlgSubmit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSubmit();

// �Ի�������
	enum { IDD = IDD_DLGSUBMIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
