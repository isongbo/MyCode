// RDAExamDlg.h : ͷ�ļ�
//

#pragma once

#include <ca_merge30.h>


// CRDAExamDlg �Ի���
class CRDAExamDlg : public CDialog
{
// ����
public:
	CRDAExamDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RDAEXAM_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	//��ʾԶ�����ݷ���ʱ�Ĵ���
	void    ShowErrors(ISSCEErrors* pISSCEErrors);

public:
	afx_msg void OnBnClickedBtnSubmit();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnPull();
	afx_msg void OnBnClickedBtnPush();
};
