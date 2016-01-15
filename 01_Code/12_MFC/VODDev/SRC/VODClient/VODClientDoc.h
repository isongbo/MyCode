// VODClientDoc.h : interface of the CVODClientDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VODCLIENTDOC_H__9BFD0D1C_50D8_459A_AA80_18AAD931B1C9__INCLUDED_)
#define AFX_VODCLIENTDOC_H__9BFD0D1C_50D8_459A_AA80_18AAD931B1C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVODClientDoc : public CDocument
{
protected: // create from serialization only
	CVODClientDoc();
	DECLARE_DYNCREATE(CVODClientDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODClientDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVODClientDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVODClientDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODCLIENTDOC_H__9BFD0D1C_50D8_459A_AA80_18AAD931B1C9__INCLUDED_)
