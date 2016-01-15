// VODClientDoc.cpp : implementation of the CVODClientDoc class
//

#include "stdafx.h"
#include "VODClient.h"

#include "VODClientDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODClientDoc

IMPLEMENT_DYNCREATE(CVODClientDoc, CDocument)

BEGIN_MESSAGE_MAP(CVODClientDoc, CDocument)
	//{{AFX_MSG_MAP(CVODClientDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODClientDoc construction/destruction

CVODClientDoc::CVODClientDoc()
{
	// TODO: add one-time construction code here

}

CVODClientDoc::~CVODClientDoc()
{
}

BOOL CVODClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVODClientDoc serialization

void CVODClientDoc::Serialize(CArchive& ar)
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
// CVODClientDoc diagnostics

#ifdef _DEBUG
void CVODClientDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVODClientDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODClientDoc commands
