// MFCTabDlg.h : header file
//

#if !defined(AFX_MFCTABDLG_H__43DCE6A4_4B72_4FC5_96BF_5FBBC0991AA9__INCLUDED_)
#define AFX_MFCTABDLG_H__43DCE6A4_4B72_4FC5_96BF_5FBBC0991AA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCTabDlg dialog
#include "Dlg1.h"
#include "Dlg2.h"
class CMFCTabDlg : public CDialog
{
// Construction
public:
	void InitTabCtrl();
	CMFCTabDlg(CWnd* pParent = NULL);	// standard constructor
  CDlg1 m_dlg1;
	CDlg2 m_dlg2;
// Dialog Data
	//{{AFX_DATA(CMFCTabDlg)
	enum { IDD = IDD_MFCTAB_DIALOG };
	CTabCtrl	m_wndTab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTabDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCTabDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTABDLG_H__43DCE6A4_4B72_4FC5_96BF_5FBBC0991AA9__INCLUDED_)
