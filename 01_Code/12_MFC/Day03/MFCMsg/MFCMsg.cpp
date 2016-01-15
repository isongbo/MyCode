#include "stdafx.h"
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
/*private:
	static const AFX_MSGMAP_ENTRY _messageEntries[]; 
protected: 
	static AFX_DATA const AFX_MSGMAP messageMap; 
	virtual const AFX_MSGMAP* GetMessageMap() const; */
public: 
	LRESULT OnZjw( WPARAM wParam, LPARAM lParam );
	LRESULT OnPaint( WPARAM wParam, LPARAM lParam );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_MESSAGE( WM_PAINT, OnPaint )
	ON_MESSAGE( WM_CREATE, OnZjw )
END_MESSAGE_MAP( )
LRESULT CMyFrameWnd::OnPaint( WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint( this->m_hWnd, &ps );
	::TextOut( hdc, 100, 100, "hello", 5 );
	::EndPaint( m_hWnd, &ps );
	return 0;
}
/*
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const 
{ 
	return &CMyFrameWnd::messageMap; 
} 
AFX_COMDAT AFX_DATADEF const AFX_MSGMAP
CMyFrameWnd::messageMap = 
{ 
	&CFrameWnd::messageMap, 
	&CMyFrameWnd::_messageEntries[0] 
}; 
AFX_COMDAT const AFX_MSGMAP_ENTRY 
CMyFrameWnd::_messageEntries[] = 
{ 
	{ WM_CREATE, 0, 0, 0, AfxSig_lwl, 
		(AFX_PMSG)(AFX_PMSGW)
		(LRESULT (AFX_MSG_CALL CWnd::*)
		(WPARAM, LPARAM))&OnZjw },
	{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } 
}; */



LRESULT CMyFrameWnd::OnZjw( WPARAM wParam, LPARAM lParam )
{//此函数的this为pFrame
	AfxMessageBox( "CMyFrameWnd::OnZjw" );
	return 0;
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
	pFrame->Create( NULL, "MFCMsg" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}