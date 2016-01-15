// PropView.h : interface of the CPropView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPVIEW_H__FCC4F612_81F7_4EDE_9A1A_385AA279DE31__INCLUDED_)
#define AFX_PROPVIEW_H__FCC4F612_81F7_4EDE_9A1A_385AA279DE31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PropDoc.h"
class CPropView : public CView
{
protected: // create from serialization only
	CPropView();
	DECLARE_DYNCREATE(CPropView)

// Attributes
public:
	CPropDoc* GetDocument();
  int m_nWidth;//Ïß¿í
	COLORREF m_Color;//ÑÕÉ«
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropView)
	afx_msg void OnProp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PropView.cpp
inline CPropDoc* CPropView::GetDocument()
   { return (CPropDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPVIEW_H__FCC4F612_81F7_4EDE_9A1A_385AA279DE31__INCLUDED_)
