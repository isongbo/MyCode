#include "stdafx.h"
class CMyView : public CView
{
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* pDC);
};
IMPLEMENT_DYNCREATE(CMyView, CView)
void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut( 100, 100, "自己的视图窗口" );
}
class CMyFrameWnd : public CFrameWnd
{
public:
	CSplitterWnd split1;//日子形框架
	CSplitterWnd split2;//倒日形框架
public:
	virtual BOOL OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext);
};
BOOL CMyFrameWnd::OnCreateClient(
			LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	split1.CreateStatic( this, 2, 1 );
	split2.CreateStatic( &split1, 1, 2, 
		WS_CHILD|WS_VISIBLE, split1.IdFromRowCol(0,0) );
	split2.CreateView( 0, 0, RUNTIME_CLASS(CMyView),
				CSize(100,100), pContext );
	split2.CreateView( 0, 1, RUNTIME_CLASS(CEditView),
				CSize(100,100), pContext );
	split1.CreateView( 1, 0, RUNTIME_CLASS(CHtmlView),
				CSize(100,100), pContext );
	CHtmlView *pView = (CHtmlView*)split1.GetPane( 1, 0 );
	pView->Navigate( "c:/" );
	return TRUE;
}
class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance( );
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create( NULL, "MFCSplit" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}

