#include "stdafx.h"
#include "resource.h"
class CMyDoc : public CDocument
{
	DECLARE_MESSAGE_MAP( )
public:
	CString str;
public:
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CMyDoc, CDocument )
	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CMyDoc::OnNew( )
{
	this->str = "hello data";
	this->UpdateAllViews( NULL );
}
class CMyView : public CEditView
{
	DECLARE_MESSAGE_MAP( )
	DECLARE_DYNCREATE( CMyView )
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnUpdate( 
		CView* pSender, LPARAM lHint, CObject* pHint );
};
IMPLEMENT_DYNCREATE( CMyView, CEditView )
BEGIN_MESSAGE_MAP( CMyView, CEditView )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
void CMyView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint )
{
//	CMyDoc *pDoc = (CMyDoc*)this->GetDocument();
	CMyDoc *pDoc = (CMyDoc*)this->m_pDocument;
	this->SetWindowText(pDoc->str);
}
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
	virtual BOOL OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext);
	CSplitterWnd split;
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
BOOL CMyFrameWnd::OnCreateClient(
			LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	split.CreateStatic( this, 1, 2 );
	split.CreateView( 0, 0, pContext->m_pNewViewClass,
						CSize(100,100), pContext );
	split.CreateView( 0, 1, RUNTIME_CLASS(CMyView),
						CSize(100,100), pContext );
	return TRUE;
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	return CFrameWnd::OnCreate(lpCreateStruct);
	//������ͼ����
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

