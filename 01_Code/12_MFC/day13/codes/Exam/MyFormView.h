#if !defined(AFX_MYFORMVIEW_H__2AB811B4_50B3_485F_A5D4_F45EA84F4220__INCLUDED_)
#define AFX_MYFORMVIEW_H__2AB811B4_50B3_485F_A5D4_F45EA84F4220__INCLUDED_

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
  
  CMyListView* m_pViewList;
	CEditView* m_pViewEdit; 

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

#endif // !defined(AFX_MYFORMVIEW_H__2AB811B4_50B3_485F_A5D4_F45EA84F4220__INCLUDED_)
