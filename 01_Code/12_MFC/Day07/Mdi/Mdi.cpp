// Mdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
//5 �ĵ���
class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
public:
	CString m_strData;
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

//4 ��ͼ��
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
// 3 ���ĵ����ӿ����(֧�ֶ�̬����)
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
    // 1 ��ȡ��ǰ����ӿ�ܴ���
	CChildFrame* pChild=
	   (CChildFrame*)GetActiveFrame();
	// 2 ��ȡ��ӿ�ܶ�Ӧ���ĵ�
	CMyDoc* pDoc=
		(CMyDoc*)pChild->GetActiveDocument(); 
	// 3 ��ȡ�ĵ���Ӧ���ĵ�ģ��
    CDocTemplate* pTemplate=pDoc->GetDocTemplate();
	// 4 ʹ���ĵ�ģ�崴���µ��ӿ��
	CChildFrame* pNewChild=
		(CChildFrame*)pTemplate->CreateNewFrame(pDoc,NULL);
    pNewChild->InitialUpdateFrame(pDoc,TRUE);
}

// 2 ���ĵ����������
class CMainFrame:public CMDIFrameWnd
{

};

// 1 Ӧ�ó�����
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

	//1 �����ĵ�ģ�����
	CMultiDocTemplate* pTemplate=new CMultiDocTemplate(
		IDR_CHILDFRAME,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CMyView));
	//2 ���ĵ�ģ����ӵ�Ӧ�ó���
	AddDocTemplate(pTemplate);
	//3 �½��ĵ�
	OnFileNew();

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}


