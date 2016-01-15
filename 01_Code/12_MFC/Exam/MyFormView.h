#if !defined(AFX_MYFORMVIEW_H__81EC2528_021C_4CF0_B7C6_5D30D6D35890__INCLUDED_)
#define AFX_MYFORMVIEW_H__81EC2528_021C_4CF0_B7C6_5D30D6D35890__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "MyListView.h"
class CMyFormView : public CFormView
{
protected:
	CMyFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyFormView)

// Form Data
public:
	//{{AFX_DATA(CMyFormView)
	enum { IDD = IDD_FORMVIEW };
	CString	m_strName;
	CString	m_strAge;
	CString	m_strAddress;
	//}}AFX_DATA

// Attributes
public:
   CMyListView* m_pList;
	 CEditView* m_pEdit;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFormView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMyFormView)
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFORMVIEW_H__81EC2528_021C_4CF0_B7C6_5D30D6D35890__INCLUDED_)
