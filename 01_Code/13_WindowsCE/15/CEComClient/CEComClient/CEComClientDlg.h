// CEComClientDlg.h : ͷ�ļ�
//

#pragma once

// CCEComClientDlg �Ի���
class CCEComClientDlg : public CDialog
{
// ����
public:
	CCEComClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CECOMCLIENT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnBnClickedBtnCall();
};
