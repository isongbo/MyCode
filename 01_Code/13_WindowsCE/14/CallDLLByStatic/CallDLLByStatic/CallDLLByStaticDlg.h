// CallDLLByStaticDlg.h : ͷ�ļ�
//

#pragma once

// CCallDLLByStaticDlg �Ի���
class CCallDLLByStaticDlg : public CDialog
{
// ����
public:
	CCallDLLByStaticDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALLDLLBYSTATIC_DIALOG };


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
