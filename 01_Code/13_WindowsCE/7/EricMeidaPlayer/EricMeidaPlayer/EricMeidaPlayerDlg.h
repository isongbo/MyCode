// EricMeidaPlayerDlg.h : ͷ�ļ�
//

#pragma once

#include "EricMediaControl.h"

// CEricMeidaPlayerDlg �Ի���
class CEricMeidaPlayerDlg : public CDialog
{
// ����
public:
	CEricMeidaPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ERICMEIDAPLAYER_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	CEricMediaControl m_VideoControl; //ý�岥�Ŷ���
public:
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnPlay();
	afx_msg void OnBnClickedBtnPause();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnFull();
	afx_msg void OnStnClickedWndVideo();
	//ý�岥���¼���Ϣ������
	afx_msg LRESULT OnNotifyMedia(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
