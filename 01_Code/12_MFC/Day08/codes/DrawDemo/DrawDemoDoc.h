// DrawDemoDoc.h : interface of the CDrawDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDEMODOC_H__07F708D4_C7BC_485A_8543_6947626C58ED__INCLUDED_)
#define AFX_DRAWDEMODOC_H__07F708D4_C7BC_485A_8543_6947626C58ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawDemoDoc : public CDocument
{
protected: // create from serialization only
	CDrawDemoDoc();
	DECLARE_DYNCREATE(CDrawDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDEMODOC_H__07F708D4_C7BC_485A_8543_6947626C58ED__INCLUDED_)
