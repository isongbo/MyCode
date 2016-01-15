// CallDLLByDynamicDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallDLLByDynamic.h"
#include "CallDLLByDynamicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCallDLLByDynamicDlg 对话框

CCallDLLByDynamicDlg::CCallDLLByDynamicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallDLLByDynamicDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallDLLByDynamicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallDLLByDynamicDlg, CDialog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CCallDLLByDynamicDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CCallDLLByDynamicDlg 消息处理程序

BOOL CCallDLLByDynamicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//动态调用DLL示例
void CCallDLLByDynamicDlg::OnBnClickedBtnCall()
{
	//1、加载DLL
	HINSTANCE	hModule = LoadLibrary(_T("MyCEDLL.dll"));
    if (hModule == NULL)
	{
		AfxMessageBox(_T("加载DLL失败"));
		return;
	}
   //得到MyCEDLL中TestDll函数地址
	pTestDll pFun = (pTestDll)GetProcAddress(hModule,_T("TestDll"));
	if ( pFun == NULL )
	{
		AfxMessageBox(_T("获取TestDll函数失败"));
	}
	else
	{
		//执行MyCEDLL中TestDll函数
		pFun();
	}

    //3、释放DLL;
	FreeLibrary(hModule);
}
