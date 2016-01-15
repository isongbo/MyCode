// VODServerDoc.cpp : implementation of the CVODServerDoc class
//

#include "stdafx.h"
#include "VODServer.h"

#include "VODServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODServerDoc

IMPLEMENT_DYNCREATE(CVODServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CVODServerDoc, CDocument)
	//{{AFX_MSG_MAP(CVODServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODServerDoc construction/destruction

CVODServerDoc::CVODServerDoc()
{
	// TODO: add one-time construction code here

}

CVODServerDoc::~CVODServerDoc()
{
}

BOOL CVODServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVODServerDoc serialization

void CVODServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVODServerDoc diagnostics

#ifdef _DEBUG
void CVODServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVODServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODServerDoc commands
