#if !defined(AFX_DLGVIDEO_H__7EAEAADF_9798_4A9F_80E2_4F9A40606E88__INCLUDED_)
#define AFX_DLGVIDEO_H__7EAEAADF_9798_4A9F_80E2_4F9A40606E88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgVideo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgVideo dialog
#include "TypeManager.h"
#include "VideoManager.h"
#include "VODServerView.h"
class CDlgVideo : public CDialog
{
// Construction
public:
	void BindDataGrid();
	void ClearCtrlData();
	void InitVideoTypeCtrl();
	CDlgVideo(CWnd* pParent = NULL);   // standard constructor
    CAdoRecordSet m_Recordset;
// Dialog Data
	//{{AFX_DATA(CDlgVideo)
	enum { IDD = IDD_DLG_VIDEO };
	CButton	m_wndOK;
	CComboBox	m_cboType;
	CString	m_strVideoDesp;
	CString	m_strVideoName;
	CString	m_strVideoPath;
	CString	m_strVideoType;
	CString	m_strVideoID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgVideo)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgVideo)
	afx_msg void OnOpenfile();
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnNew();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVIDEO_H__7EAEAADF_9798_4A9F_80E2_4F9A40606E88__INCLUDED_)
