#include "stdafx.h"
#include "resource.h"
class CZjw : public CCmdTarget
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CZjw, CCmdTarget )
	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CZjw::OnNew( )
{
	AfxMessageBox( "zjw�ദ���½������" );
}
class CMyDoc : public CDocument
{
	DECLARE_MESSAGE_MAP( )
};
BEGIN_MESSAGE_MAP( CMyDoc, CDocument )
END_MESSAGE_MAP( )

class CMyView : public CEditView
{
	DECLARE_MESSAGE_MAP( )
	DECLARE_DYNCREATE( CMyView )
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
IMPLEMENT_DYNCREATE( CMyView, CEditView )
BEGIN_MESSAGE_MAP( CMyView, CEditView )
ON_WM_CREATE( )
END_MESSAGE_MAP( )
int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	return CEditView::OnCreate(lpCreateStruct);
	//����ͼ�������ĵ���������󶨹�ϵ
}
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnCmdMsg( 
		UINT nID, int nCode, 
		void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
BOOL CMyFrameWnd::OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo )
{
	CZjw zjw;
	if(zjw.OnCmdMsg( nID, nCode, pExtra, pHandlerInfo ))
		return TRUE;
	return CFrameWnd::OnCmdMsg(
				nID, nCode, pExtra, pHandlerInfo );
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	return CFrameWnd::OnCreate(lpCreateStruct);
	//������ͼ����
}
class CMyWinApp : public CWinApp
{
	DECLARE_MESSAGE_MAP( )
public:
	virtual BOOL InitInstance( );
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CMyWinApp, CWinApp )
	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CMyWinApp::OnNew( )
{
	AfxMessageBox( "Ӧ�ó����ദ���½������" );
}
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	CCreateContext cct;
	cct.m_pCurrentDoc = new CMyDoc;
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	pFrame->LoadFrame( IDR_MENU1, WS_OVERLAPPEDWINDOW,
		NULL, &cct );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}

