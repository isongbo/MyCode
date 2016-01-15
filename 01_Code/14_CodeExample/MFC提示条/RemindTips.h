#pragma once


//#include "StdAfx.h"
//#include "resource.h"
// RemindTips dialog

class RemindTips : public CDialog
{
	//DECLARE_DYNAMIC(RemindTips)

public:
	RemindTips(CWnd* pParent = NULL);   // standard constructor
	virtual ~RemindTips();
    
	CString strToShow,TimeTip;
	int iTimeOut;
	int isShutDown;  //根据不同情况显示按钮，1为关机，2为取票失败，3，预留
    int nDownLoadedBytes;
	CBrush mbrush;
	CFont mfont;
	CButton m_btn1;
// Dialog Data
	enum {IDD = IDD_DIALOG_MSGREMIND};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

	
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);

	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedCancel();
	void FreshTips();
};
