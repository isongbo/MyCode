// DlgDDX.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

// 写一个基于模式对话框的应用程序
// Dlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
// 2 对话框类
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){};
    virtual BOOL OnInitDialog( );
	virtual void DoDataExchange( CDataExchange* pDX );
    virtual void OnOK();
public:
	CButton m_wndOK;//控件类型的成员变量
	CString m_strEdit;//值类型的变量
};
void CMyDlg::OnOK()
{
	//显示用户在文本框中的输入
    UpdateData(TRUE);
	MessageBox(m_strEdit);

	CDialog::OnOK();
}
void CMyDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
	//控件类型的绑定，
	DDX_Control(pDX,IDOK,m_wndOK);
	DDX_Text(pDX,IDC_EDIT1,m_strEdit);
}
BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//完成控件的初始化
    CWnd* pWnd=GetDlgItem(IDCANCEL);
	pWnd->EnableWindow(FALSE);
	//修改OK按钮的文本、位置和大小 
    m_wndOK.SetWindowText("确定");
	m_wndOK.MoveWindow(0,0,100,100);

	m_strEdit="Hello World";
    UpdateData(FALSE);
    return TRUE;
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
	//模式对话框
	CMyDlg dlg;
	m_pMainWnd=&dlg;
    dlg.DoModal();
	return TRUE;
}







