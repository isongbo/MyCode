// ASynDllTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ASynDllTest.h"
#include "ASynDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CASynDllTestDlg 对话框

CASynDllTestDlg::CASynDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CASynDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CASynDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CASynDllTestDlg, CDialog)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_CALL, &CASynDllTestDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CASynDllTestDlg 消息处理程序

BOOL CASynDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//加载ASynDll
	m_hModule = LoadLibrary(_T("ASynDll.dll"));
    if (m_hModule == NULL)
	{
		AfxMessageBox(_T("加载DLL失败"));
		return FALSE;
	}
	//得到ASynDll中QueryData函数地址
	m_pQueryData = (TQueryData)GetProcAddress(m_hModule,_T("QueryData"));
	if ( m_pQueryData == NULL )
	{
		AfxMessageBox(_T("获取QueryData函数失败"));
		FreeLibrary(m_hModule);
		return FALSE;
	}
	
	//得到ASynDll中SetCallbackProcAddr函数地址
	m_pSetCallbackProcAddr = 
		(TSetCallbackProcAddr)GetProcAddress(m_hModule,_T("SetCallbackProcAddr"));
	if ( m_pSetCallbackProcAddr == NULL )
	{
		AfxMessageBox(_T("获取SetCallbackProcAddr函数失败"));
		FreeLibrary(m_hModule);
		return FALSE ;
	}

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//回调函数，当DLL中QueryData方法执行完毕时执行
void QueryReadNotify(long lDBData)
{
	TCHAR sDBData[11];
	TCHAR sMessage[64];
	_ltow(lDBData, sDBData, 10);
	wcscpy(sMessage, _T("DBData from DLL is: "));
	wcscat(sMessage, sDBData);
	::MessageBox(0, sMessage, 
		_T("Sample App"), MB_OK + MB_ICONINFORMATION);
};

void CASynDllTestDlg::OnDestroy()
{
	//释放AsynDll库
	FreeLibrary(m_hModule);
	CDialog::OnDestroy();	
}

//调用DLL
void CASynDllTestDlg::OnBnClickedBtnCall()
{
	long lProcAdr;

   //设置回调函数地址
   lProcAdr = (long)(&QueryReadNotify);
   m_pSetCallbackProcAddr(lProcAdr);
   
   //执行异步查询操作
   m_pQueryData();
}
