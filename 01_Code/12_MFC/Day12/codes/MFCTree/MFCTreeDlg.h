// MFCTreeDlg.h : header file
//

#if !defined(AFX_MFCTREEDLG_H__48791347_07C7_4D7B_AF0C_B6D512B9FD30__INCLUDED_)
#define AFX_MFCTREEDLG_H__48791347_07C7_4D7B_AF0C_B6D512B9FD30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCTreeDlg dialog

class CMFCTreeDlg : public CDialog
{
// Construction
public:
	void InitTreeCtrl();
	CMFCTreeDlg(CWnd* pParent = NULL);	// standard constructor
    CImageList m_ilNormal;
// Dialog Data
	//{{AFX_DATA(CMFCTreeDlg)
	enum { IDD = IDD_MFCTREE_DIALOG };
	CTreeCtrl	m_wndTree;
	CString	m_strName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddChild();
	afx_msg void OnAddRoot();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTREEDLG_H__48791347_07C7_4D7B_AF0C_B6D512B9FD30__INCLUDED_)
