#include "stdafx.h"
class CMyFrameWnd : public CFrameWnd
{
};
class CMyWinApp : public CWinApp
{
public:
	CMyWinApp( );
	virtual BOOL InitInstance( );
};
CMyWinApp::CMyWinApp( )
{
}
CMyWinApp theApp;//全局对象(爆破点)
BOOL CMyWinApp::InitInstance( )
{//此函数的this为&theApp
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create( NULL, "MFCBase" );
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}