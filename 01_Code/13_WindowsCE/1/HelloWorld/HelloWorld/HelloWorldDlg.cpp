// HelloWorldDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "HelloWorldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHelloWorldDlg 对话框

CHelloWorldDlg::CHelloWorldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelloWorldDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHelloWorldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHelloWorldDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CHelloWorldDlg 消息处理程序

BOOL CHelloWorldDlg::OnInitDialog()
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
void CHelloWorldDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_HELLOWORLD_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_HELLOWORLD_DIALOG));
	}
}
#endif

