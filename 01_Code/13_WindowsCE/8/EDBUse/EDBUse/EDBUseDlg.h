// EDBUseDlg.h : ͷ�ļ�
//

#pragma once

// CEDBUseDlg �Ի���
class CEDBUseDlg : public CDialog
{
// ����
public:
	CEDBUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EDBUSE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnrefresh();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtnedit();
	afx_msg void OnBnClickedBtndelete();
};
