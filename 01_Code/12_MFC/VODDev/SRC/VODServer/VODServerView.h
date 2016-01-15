// VODServerView.h : interface of the CVODServerView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_VODSERVERVIEW_H__7558ED54_6089_4FB8_B47E_4695C38D9752__INCLUDED_)
#define AFX_VODSERVERVIEW_H__7558ED54_6089_4FB8_B47E_4695C38D9752__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "VODServerDoc.h"
class CVODServerView : public CFormView
{
protected: // create from serialization only
	CVODServerView();
	DECLARE_DYNCREATE(CVODServerView)

public:
	//{{AFX_DATA(CVODServerView)
	enum { IDD = IDD_VODSERVER_FORM };
	CDataGrid	m_wndGrid;
	//}}AFX_DATA

// Attributes
public:
	CVODServerDoc* GetDocument();

// Operations
public:
   
	CAdoRecordSet  m_adoRecordSet;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODServerView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
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
	void BindDataGrid(CAdoRecordSet *pSet);
	virtual ~CVODServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVODServerView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelChangeDatagrid(short FAR* Cancel);
	afx_msg void OnRowColChangeDatagrid(VARIANT FAR* LastRow, short LastCol);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VODServerView.cpp
inline CVODServerDoc* CVODServerView::GetDocument()
   { return (CVODServerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODSERVERVIEW_H__7558ED54_6089_4FB8_B47E_4695C38D9752__INCLUDED_)
