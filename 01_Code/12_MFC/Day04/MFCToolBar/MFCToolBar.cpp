#include "stdafx.h"
#include "resource.h"
UINT g_hIndicator[] = {
		0,
		IDS_TIME,
		IDS_POS
};
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	CToolBar toolbar;
	CStatusBar statusbar;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew( );
	afx_msg void OnSet( );
	afx_msg void OnInitMenuPopup(
				CMenu*pPopup, UINT nPos, BOOL i );
	afx_msg void OnTool( );
	afx_msg void OnTimer( UINT nID );
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_WM_MOUSEMOVE( )
	ON_WM_TIMER( )
	ON_COMMAND( ID_TOOL, OnTool )
	ON_WM_INITMENUPOPUP( )
	ON_COMMAND( ID_SET, OnSet )
	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	CString str;
	str.Format( "x=%d,y=%d", point.x, point.y );
	statusbar.SetPaneText( 2, str );
}
void CMyFrameWnd::OnTimer( UINT nID )
{
	SYSTEMTIME st;
	::GetLocalTime( &st );
	CString str;
	str.Format( "%d-%d-%d-%d:%d:%d", st.wYear, st.wMonth,
			st.wDay, st.wHour, st.wMinute, st.wSecond );
	statusbar.SetPaneText( 1, str );
}
void CMyFrameWnd::OnTool( )
{
	if( toolbar.IsWindowVisible() )
	{
		ShowControlBar( &toolbar, FALSE, FALSE );
	}else{
		ShowControlBar( &toolbar, TRUE, FALSE );
	}
}
void CMyFrameWnd::OnInitMenuPopup( 
					CMenu*pPopup, UINT nPos, BOOL i )
{
	if( toolbar.IsWindowVisible() )
	{
		pPopup->CheckMenuItem( ID_TOOL, MF_CHECKED );
	}else{
		pPopup->CheckMenuItem( ID_TOOL, MF_UNCHECKED );
	}
}
void CMyFrameWnd::OnSet( )
{
	AfxMessageBox( "��ɫ��ť�����" );
}
void CMyFrameWnd::OnNew( )
{
	AfxMessageBox( "�½������" );
} 
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	toolbar.CreateEx( this, TBSTYLE_TRANSPARENT,
				WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP|
				CBRS_GRIPPER|CBRS_SIZE_DYNAMIC|
				CBRS_TOOLTIPS|CBRS_FLYBY );
	toolbar.LoadToolBar( IDR_TOOLBAR1 );
	toolbar.EnableDocking( CBRS_ALIGN_ANY );
	this->EnableDocking( CBRS_ALIGN_ANY );
	this->DockControlBar( &toolbar, 
				AFX_IDW_DOCKBAR_TOP );
	toolbar.SetWindowText( "������" );

	statusbar.CreateEx( this );
	statusbar.SetIndicators( g_hIndicator, 
				sizeof(g_hIndicator)/sizeof(UINT) );
	statusbar.SetPaneInfo(1, IDS_TIME, SBPS_POPOUT, 200);
	statusbar.SetPaneInfo(2, IDS_POS, SBPS_NORMAL, 200);
	::SetTimer( this->m_hWnd, 1, 1000, NULL );
	return CFrameWnd::OnCreate(lpCreateStruct);
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
	pFrame->Create( NULL, "MFCToolBar", 
		WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault,
		NULL, MAKEINTRESOURCE(IDR_MENU1) );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}