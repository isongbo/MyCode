// ScrollBmpUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ScrollBmpUse.h"
#include "ScrollBmpUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CScrollBmpUseDlg 对话框

CScrollBmpUseDlg::CScrollBmpUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollBmpUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBmpUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBMP, m_scrollBmp);
}

BEGIN_MESSAGE_MAP(CScrollBmpUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CScrollBmpUseDlg 消息处理程序

BOOL CScrollBmpUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//初始化滚动位图控件
	m_scrollBmp.InitBmpCtrl();
	//根据文件名，加载图形
	m_scrollBmp.LoadBmp(_T("\\My Documents\\abc.bmp"));


	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CScrollBmpUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SCROLLBMPUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SCROLLBMPUSE_DIALOG));
	}
}
#endif

