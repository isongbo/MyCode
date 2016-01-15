// VODClientView.h : interface of the CVODClientView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_VODCLIENTVIEW_H__DFEC4ADA_6F41_4E25_8523_BD349A52C016__INCLUDED_)
#define AFX_VODCLIENTVIEW_H__DFEC4ADA_6F41_4E25_8523_BD349A52C016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VODClientDoc.h"
class CVODClientView : public CFormView
{
protected: // create from serialization only
	CVODClientView();
	DECLARE_DYNCREATE(CVODClientView)

public:
	//{{AFX_DATA(CVODClientView)
	enum { IDD = IDD_VODCLIENT_FORM };
	CWMPPlayer4	m_wndPlayer;
	//}}AFX_DATA

// Attributes
public:
	CVODClientDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODClientView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVODClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVODClientView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDoubleClickMediaPlayer(short nButton, short nShiftState, long fX, long fY);
	afx_msg void OnFileOpen();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VODClientView.cpp
inline CVODClientDoc* CVODClientView::GetDocument()
   { return (CVODClientDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODCLIENTVIEW_H__DFEC4ADA_6F41_4E25_8523_BD349A52C016__INCLUDED_)
