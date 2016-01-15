// Dlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
// 2 对话框类
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){};
	virtual void OnOK();
	virtual void OnCancel();
	virtual void PostNcDestroy( );
};
void CMyDlg::OnOK()
{
    DestroyWindow();
}
void CMyDlg::OnCancel()
{
    DestroyWindow();
}
void CMyDlg::PostNcDestroy()
{
	delete this;
}


// 1 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;//全局的应用程序变量
BOOL CMyWinApp::InitInstance()
{
     /*
	//模式对话框
	CMyDlg dlg;
	m_pMainWnd=&dlg;
    dlg.DoModal();
	*/
	//非模式对话框
	CMyDlg* pDlg=new CMyDlg;
	pDlg->Create(IDD_DIALOG1);
	m_pMainWnd=pDlg;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
    
	return TRUE;
}



