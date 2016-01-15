// CameraDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "EricCamera.h"

// CCameraDemoDlg �Ի���
class CCameraDemoDlg : public CDialog
{
// ����
public:
	CCameraDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CAMERADEMO_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	CEricCamera m_Camera; //����ͷ������
public:
	afx_msg void OnBnClickedBtnPreview();
	afx_msg void OnBnClickedBtnSnap();
	afx_msg void OnBnClickedBtnRecord();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
