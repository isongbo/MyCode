// DrawDemoView.h : interface of the CDrawDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDEMOVIEW_H__DA16F99F_C592_4014_BE01_6314AC3B0F52__INCLUDED_)
#define AFX_DRAWDEMOVIEW_H__DA16F99F_C592_4014_BE01_6314AC3B0F52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawDemoView : public CView
{
protected: // create from serialization only
	CDrawDemoView();
	DECLARE_DYNCREATE(CDrawDemoView)

// Attributes
public:
	CDrawDemoDoc* GetDocument();

// Operations
public:
    int m_nType;//ͼ������
	CPoint m_ptBegin;//ͼ�ε����
	CPoint m_ptEnd;//ͼ�ε��յ�
	BOOL m_bFlag;//�Ƿ�ʼ��ͼ

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawDemoView)
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
	virtual ~CDrawDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawDemoView)
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawEllipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DrawShape(CDC* pDC,CPoint p1,CPoint p2);
};

#ifndef _DEBUG  // debug version in DrawDemoView.cpp
inline CDrawDemoDoc* CDrawDemoView::GetDocument()
   { return (CDrawDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDEMOVIEW_H__DA16F99F_C592_4014_BE01_6314AC3B0F52__INCLUDED_)
