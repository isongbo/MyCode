// Sdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <afxext.h>//CEditView
#include "resource.h"

// 4 �ĵ���(֧�ֶ�̬����)
class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

// 3 ��ͼ��(֧�ֶ�̬����)
class CMyView:public CEditView
{
   DECLARE_DYNCREATE(CMyView)
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)

// 2 ��ܴ�����(֧�ֶ�̬����)
class CMyFrameWnd:public CFrameWnd
{
   DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd,CFrameWnd)

// 1 Ӧ�ó�����
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
}; 

CMyWinApp theApp;//ȫ�ֵ�Ӧ�ó������
BOOL CMyWinApp::InitInstance()
{
   //1 �������ĵ�ģ��
   CSingleDocTemplate* pTemplate=new CSingleDocTemplate(
	   IDR_MENU1,
	   RUNTIME_CLASS(CMyDoc),
	   RUNTIME_CLASS(CMyFrameWnd),
	   RUNTIME_CLASS(CMyView)); 
   //2 ���ĵ�ģ����ӵ�Ӧ�ó���
   AddDocTemplate(pTemplate);

   //3 �½��ĵ�(�������ĵ�����ܡ���ͼ��������)
   OnFileNew();
  
   //4 ��ʾ�͸��´���
   m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
   m_pMainWnd->UpdateWindow();
   return TRUE;
}


