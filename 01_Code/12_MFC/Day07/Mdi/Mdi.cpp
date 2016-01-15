// Mdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
//5 文档类
class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
public:
	CString m_strData;
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

//4 视图类
class CMyView:public CEditView
{
	DECLARE_DYNCREATE(CMyView)
    DECLARE_MESSAGE_MAP()
public:
	virtual void OnUpdate( 
		CView* pSender, 
		LPARAM lHint, 
		CObject* pHint ); 

protected:
	afx_msg void OnEnChange();
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)
BEGIN_MESSAGE_MAP(CMyView,CEditView)
  ON_CONTROL_REFLECT(EN_CHANGE,OnEnChange)
END_MESSAGE_MAP()
void CMyView::OnEnChange()
{
	CMyDoc* pDoc=(CMyDoc*)GetDocument();
	GetWindowText(pDoc->m_strData);
	pDoc->UpdateAllViews(this);

}
void CMyView::OnUpdate( CView* pSender, 
			LPARAM lHint, CObject* pHint )
{
    CMyDoc* pDoc=(CMyDoc*)GetDocument();
	SetWindowText(pDoc->m_strData);
}
// 3 多文档的子框架类(支持动态创建)
class CChildFrame:public CMDIChildWnd
{
   DECLARE_DYNCREATE(CChildFrame)
   DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnNewWindow();
};
IMPLEMENT_DYNCREATE(CChildFrame,CMDIChildWnd)
BEGIN_MESSAGE_MAP(CChildFrame,CMDIChildWnd)
  ON_COMMAND(ID_NEW_WINDOW,OnNewWindow)
END_MESSAGE_MAP()
void CChildFrame::OnNewWindow()
{
    // 1 获取当前活动的子框架窗口
	CChildFrame* pChild=
	   (CChildFrame*)GetActiveFrame();
	// 2 获取活动子框架对应的文档
	CMyDoc* pDoc=
		(CMyDoc*)pChild->GetActiveDocument(); 
	// 3 获取文档对应的文档模板
    CDocTemplate* pTemplate=pDoc->GetDocTemplate();
	// 4 使用文档模板创建新的子框架
	CChildFrame* pNewChild=
		(CChildFrame*)pTemplate->CreateNewFrame(pDoc,NULL);
    pNewChild->InitialUpdateFrame(pDoc,TRUE);
}

// 2 多文档的主框架类
class CMainFrame:public CMDIFrameWnd
{

};

// 1 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
protected:
	afx_msg void OnNew();

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
  ON_COMMAND(ID_NEW,OnNew)
END_MESSAGE_MAP()
void CMyWinApp::OnNew()
{
	OnFileNew();
}
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMainFrame* pFrame=new CMainFrame;
	pFrame->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd=pFrame;

	//1 创建文档模板对象
	CMultiDocTemplate* pTemplate=new CMultiDocTemplate(
		IDR_CHILDFRAME,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CMyView));
	//2 将文档模板添加到应用程序
	AddDocTemplate(pTemplate);
	//3 新建文档
	OnFileNew();

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}


