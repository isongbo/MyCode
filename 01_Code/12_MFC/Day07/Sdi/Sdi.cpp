// Sdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <afxext.h>//CEditView
#include "resource.h"

// 4 文档类(支持动态创建)
class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

// 3 视图类(支持动态创建)
class CMyView:public CEditView
{
   DECLARE_DYNCREATE(CMyView)
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)

// 2 框架窗口类(支持动态创建)
class CMyFrameWnd:public CFrameWnd
{
   DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd,CFrameWnd)

// 1 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
}; 

CMyWinApp theApp;//全局的应用程序对象
BOOL CMyWinApp::InitInstance()
{
   //1 创建单文档模板
   CSingleDocTemplate* pTemplate=new CSingleDocTemplate(
	   IDR_MENU1,
	   RUNTIME_CLASS(CMyDoc),
	   RUNTIME_CLASS(CMyFrameWnd),
	   RUNTIME_CLASS(CMyView)); 
   //2 将文档模板添加到应用程序
   AddDocTemplate(pTemplate);

   //3 新建文档(创建了文档、框架、视图各个对象)
   OnFileNew();
  
   //4 显示和更新窗口
   m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
   m_pMainWnd->UpdateWindow();
   return TRUE;
}


