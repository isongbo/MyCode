// ResDllTestDlg.h : ͷ�ļ�
//

#pragma once

// CResDllTestDlg �Ի���
class CResDllTestDlg : public CDialog
{
// ����
public:
	CResDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RESDLLTEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	//DLL���
	HINSTANCE m_hDll;

public:
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnFree();
	afx_msg void OnBnClickedBtnBmp();
	afx_msg void OnBnClickedBtnIcon();
};
