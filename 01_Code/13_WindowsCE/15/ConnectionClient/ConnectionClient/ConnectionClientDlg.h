// ConnectionClientDlg.h : ͷ�ļ�
//

#pragma once

// CConnectionClientDlg �Ի���
class CConnectionClientDlg : public CDialog
{
// ����
public:
	CConnectionClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CONNECTIONCLIENT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	long m_number1;
	long m_number2;

	afx_msg void OnBnClickedBtnExec();
};
