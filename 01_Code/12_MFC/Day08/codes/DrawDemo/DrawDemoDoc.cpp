// DrawDemoDoc.cpp : implementation of the CDrawDemoDoc class
//

#include "stdafx.h"
#include "DrawDemo.h"

#include "DrawDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoDoc

IMPLEMENT_DYNCREATE(CDrawDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoDoc construction/destruction

CDrawDemoDoc::CDrawDemoDoc()
{
	// TODO: add one-time construction code here

}

CDrawDemoDoc::~CDrawDemoDoc()
{
}

BOOL CDrawDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawDemoDoc serialization

void CDrawDemoDoc::Serialize(CArchive& ar)
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
// CDrawDemoDoc diagnostics

#ifdef _DEBUG
void CDrawDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoDoc commands
