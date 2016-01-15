// LedCtrlUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedCtrlUse.h"
#include "LedCtrlUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLedCtrlUseDlg 对话框

CLedCtrlUseDlg::CLedCtrlUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLedCtrlUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLedCtrlUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LED, m_led);
}

BEGIN_MESSAGE_MAP(CLedCtrlUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLedCtrlUseDlg 消息处理程序

BOOL CLedCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//设置背景色
	m_led.SetColorBackGround(RGB(255,0,0));
	//设置前景色
	m_led.SetColorForeGround(RGB(0,255,255));
    //设置定时器
	SetTimer(100,1000,NULL);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CLedCtrlUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_LEDCTRLUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_LEDCTRLUSE_DIALOG));
	}
}
#endif

//定时器消息事件
void CLedCtrlUseDlg::OnTimer(UINT nIDEvent) 
{
	//设置LED显示数字
    m_led.Display(Random());  	
	CDialog::OnTimer(nIDEvent);
}
