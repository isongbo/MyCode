// VODClientView.cpp : implementation of the CVODClientView class
//

#include "stdafx.h"
#include "VODClient.h"

#include "VODClientDoc.h"
#include "VODClientView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODClientView

IMPLEMENT_DYNCREATE(CVODClientView, CFormView)

BEGIN_MESSAGE_MAP(CVODClientView, CFormView)
	//{{AFX_MSG_MAP(CVODClientView)
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODClientView construction/destruction

CVODClientView::CVODClientView()
	: CFormView(CVODClientView::IDD)
{
	//{{AFX_DATA_INIT(CVODClientView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CVODClientView::~CVODClientView()
{
}

void CVODClientView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVODClientView)
	DDX_Control(pDX, IDC_MEDIA_PLAYER, m_wndPlayer);
	//}}AFX_DATA_MAP
}

BOOL CVODClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CVODClientView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	

}

/////////////////////////////////////////////////////////////////////////////
// CVODClientView printing

BOOL CVODClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVODClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVODClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVODClientView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CVODClientView diagnostics

#ifdef _DEBUG
void CVODClientView::AssertValid() const
{
	CFormView::AssertValid();
}

void CVODClientView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CVODClientDoc* CVODClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVODClientDoc)));
	return (CVODClientDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODClientView message handlers

void CVODClientView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rcClient;
	GetClientRect(&rcClient);
	if (m_wndPlayer.GetSafeHwnd())
	{
		m_wndPlayer.MoveWindow(0,0,rcClient.Width(),rcClient.Height()); 
	}
}

BEGIN_EVENTSINK_MAP(CVODClientView, CFormView)
    //{{AFX_EVENTSINK_MAP(CVODClientView)
	ON_EVENT(CVODClientView, IDC_MEDIA_PLAYER, 6506 /* DoubleClick */, OnDoubleClickMediaPlayer, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CVODClientView::OnDoubleClickMediaPlayer(short nButton, short nShiftState, long fX, long fY) 
{
	// TODO: Add your control notification handler code here
	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();
	pFrame->ShowControlBar(&pFrame->m_LeftCtrBar,
		!pFrame->m_LeftCtrBar.IsVisible(),FALSE);
}



void CVODClientView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CString strFullPath="C:\\ÏàÇ×2.wmv";
	m_wndPlayer.SetUrl(strFullPath);
}
