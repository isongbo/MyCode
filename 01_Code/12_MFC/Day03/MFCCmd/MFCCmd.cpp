#include "stdafx.h"
#define WM_MYMESSAGE WM_USER+1001
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	int m_x;
	int m_y;
	CMyFrameWnd( );
public:
	afx_msg int OnCreate( LPCREATESTRUCT pcs );
	afx_msg void OnPaint( );
	afx_msg void OnMouseMove( UINT nKey, CPoint pt );
	afx_msg LRESULT OnMyMessage( WPARAM wParam, 
						LPARAM lParam );
	afx_msg void OnTest( );
	afx_msg void OnEnChange( );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_EN_CHANGE( 1002, OnEnChange )
	ON_COMMAND( 1001, OnTest )
	ON_WM_MOUSEMOVE( )
	ON_WM_CREATE( )
	ON_WM_PAINT( )
	ON_MESSAGE( WM_MYMESSAGE, OnMyMessage )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnEnChange( )
{
	AfxMessageBox( "文本内容被修改" );
}
void CMyFrameWnd::OnTest( )
{
	AfxMessageBox( "OK按钮被点击" );
}
LRESULT CMyFrameWnd::OnMyMessage(
						WPARAM wParam, LPARAM lParam )
{
	CString str;
	str.Format( "wParam=%d,lParam=%d", wParam, lParam );
	AfxMessageBox( str );
	return 0;
}
void CMyFrameWnd::OnMouseMove( UINT nKey, CPoint pt )
{
	m_x = pt.x;
	m_y = pt.y;
	::InvalidateRect( this->m_hWnd, NULL, TRUE );
}
CMyFrameWnd::CMyFrameWnd( )
{
	m_x = 100;
	m_y = 100;
}
void CMyFrameWnd::OnPaint( )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint( this->m_hWnd, &ps );
	::TextOut( hdc, m_x, m_y, "hello", 5 );
	::EndPaint( m_hWnd, &ps );
}
int CMyFrameWnd::OnCreate( LPCREATESTRUCT pcs )
{
	AfxMessageBox( "CMyFrameWnd::OnCreate" );
	::PostMessage( m_hWnd, WM_MYMESSAGE, 1, 2 );
	::CreateWindowEx( 0, "BUTTON", "OK", 
			WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			100, 100, 100, 40, this->m_hWnd, (HMENU)1001,
			AfxGetInstanceHandle(), NULL );
	::CreateWindowEx( 0, "EDIT", "",
			WS_CHILD|WS_VISIBLE|WS_BORDER,
			400, 100, 200, 200, m_hWnd, (HMENU)1002,
			AfxGetInstanceHandle(), NULL );
	return CFrameWnd::OnCreate(pcs);
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
	pFrame->Create( NULL, "MFCCmd" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}

