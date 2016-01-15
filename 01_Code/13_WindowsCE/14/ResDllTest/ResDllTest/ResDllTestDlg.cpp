// ResDllTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ResDllTest.h"
#include "ResDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//添加资源定义标识
#define IDB_RESBMP                      101
#define IDI_RESICON                     102

// CResDllTestDlg 对话框

CResDllTestDlg::CResDllTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CResDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CResDllTestDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_LOAD, &CResDllTestDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_FREE, &CResDllTestDlg::OnBnClickedBtnFree)
	ON_BN_CLICKED(IDC_BTN_BMP, &CResDllTestDlg::OnBnClickedBtnBmp)
	ON_BN_CLICKED(IDC_BTN_ICON, &CResDllTestDlg::OnBnClickedBtnIcon)
END_MESSAGE_MAP()


// CResDllTestDlg 消息处理程序

BOOL CResDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//加载资源DLL
void CResDllTestDlg::OnBnClickedBtnLoad()
{
	//加载DLL
	m_hDll = LoadLibrary(_T("ResDll.dll"));
	if (m_hDll == NULL)
	{
		AfxMessageBox(_T("加载Dll失败"));
	}	
}

//释放资源DLL
void CResDllTestDlg::OnBnClickedBtnFree()
{
	//释放DLL
	if (m_hDll != NULL)	
	{
		FreeLibrary(m_hDll);
	}	
}

//显示资源里的位图
void CResDllTestDlg::OnBnClickedBtnBmp()
{
	HBITMAP hOldBmp;
	//从DLL里加载指定的资源
	HBITMAP bmp = LoadBitmap(m_hDll,MAKEINTRESOURCE(IDB_RESBMP));	
	if (bmp == NULL)
	{
		AfxMessageBox(_T("调用位图资源失败"));
		return;
	}

	//获得绘图环境资源
	CDC memdc;
	CDC *pDC = new CClientDC(this);
	memdc.CreateCompatibleDC(pDC);
	hOldBmp = (HBITMAP)memdc.SelectObject(bmp);
	pDC->BitBlt(0,0,200,200,&memdc,0,0,SRCCOPY);
	memdc.SelectObject(hOldBmp);
	//释放资源
	DeleteObject(bmp);
	//释放DC
	delete pDC;
	pDC = NULL;
}

//显示资源里的图标
void CResDllTestDlg::OnBnClickedBtnIcon()
{
	//从DLL里加载指定的资源
	HICON icn = LoadIcon(m_hDll,MAKEINTRESOURCE(IDI_RESICON));
	if (icn == NULL)
	{
		AfxMessageBox(_T("调用图标资源失败"));
		return;
	}
	CDC *pDC = new CClientDC(this);
	//绘制图标
	pDC->DrawIcon(CPoint(100,100),icn);
	DeleteObject(icn);
	//释放CDC对象
	delete pDC;		
	pDC = NULL;
}
