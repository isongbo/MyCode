// LedCtrlUseDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "LedCtrl.h"

// CLedCtrlUseDlg �Ի���
class CLedCtrlUseDlg : public CDialog
{
// ����
public:
	CLedCtrlUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LEDCTRLUSE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	CLedCtrl m_led;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
