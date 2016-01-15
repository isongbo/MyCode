// CreateProgressDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CreateProgress.h"
#include "CreateProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCreateProgressDlg 对话框

CCreateProgressDlg::CCreateProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateProgressDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCreateProgressDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNEXEC, &CCreateProgressDlg::OnBnClickedBtnexec)
END_MESSAGE_MAP()


// CCreateProgressDlg 消息处理程序

BOOL CCreateProgressDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CCreateProgressDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CREATEPROGRESS_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CREATEPROGRESS_DIALOG));
	}
}
#endif


/*
*函数描述：调用可执行文件
*入口参数：FileName:字符串，用于指定可执行文件名
*出口参数：(无)
*返回值：true : 代表调用成功；false：代表调用失败
*/
bool CCreateProgressDlg::WinExec(LPCTSTR FileName)
{
    PROCESS_INFORMATION processInfo; //进程相关信息
    if (!CreateProcess(FileName, NULL, NULL, NULL, NULL
      , CREATE_NEW_CONSOLE
      , NULL, NULL, NULL, &processInfo))
    {
		return false;
	}
    CloseHandle(processInfo.hThread);
	CloseHandle(processInfo.hProcess);
	return true ;
}

//调用外部应用程序
void CCreateProgressDlg::OnBnClickedBtnexec()
{
    WinExec(_T("iexplore"));	
}
