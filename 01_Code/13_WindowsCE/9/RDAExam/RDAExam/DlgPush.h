#pragma once


// CDlgPush �Ի���

class CDlgPush : public CDialog
{
	DECLARE_DYNAMIC(CDlgPush)

public:
	CDlgPush(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPush();

// �Ի�������
	enum { IDD = IDD_DLGPUSH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
