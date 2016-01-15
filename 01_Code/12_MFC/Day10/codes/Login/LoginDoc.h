// LoginDoc.h : interface of the CLoginDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGINDOC_H__93A30A6F_FC7A_4581_AA30_8F73EE8C34C1__INCLUDED_)
#define AFX_LOGINDOC_H__93A30A6F_FC7A_4581_AA30_8F73EE8C34C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLoginDoc : public CDocument
{
protected: // create from serialization only
	CLoginDoc();
	DECLARE_DYNCREATE(CLoginDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLoginDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLoginDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDOC_H__93A30A6F_FC7A_4581_AA30_8F73EE8C34C1__INCLUDED_)
