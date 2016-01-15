// Draw2DGraphDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw2DGraph.h"
#include "Draw2DGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDraw2DGraphDlg 对话框

CDraw2DGraphDlg::CDraw2DGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDraw2DGraphDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDraw2DGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDraw2DGraphDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDraw2DGraphDlg 消息处理程序

BOOL CDraw2DGraphDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CRect rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 240;
	rect.bottom = 160;
	//创建曲线控件实例
	m_2DGraph.Create(_T(""),_T(""),WS_VISIBLE | WS_CHILD, rect, this,0,NULL) ; 
	m_pointCount = 0;
	//启动添加点计时器
	SetTimer(1,1000,NULL);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CDraw2DGraphDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_DRAW2DGRAPH_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_DRAW2DGRAPH_DIALOG));
	}
}
#endif


//定时器消息处理函数
void CDraw2DGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nRandomY;

	//产生一个1到10的随机数
	nRandomY = rand() % 10;

	//如果曲线点数大于10个点，则删除第1个点。
	if (m_pointCount > 10 )
	{
		m_2DGraph.DeleteFirstPoint();
		m_pointCount--;
	}

	//给曲线添加点
	m_2DGraph.AppendPoint(nRandomY);	
	
	TRACE(L" y = %d \n",nRandomY);
	m_pointCount++;
	
	CDialog::OnTimer(nIDEvent);

}
