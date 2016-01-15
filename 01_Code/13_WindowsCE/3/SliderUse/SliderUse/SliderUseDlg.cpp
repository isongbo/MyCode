// SliderUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SliderUse.h"
#include "SliderUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSliderUseDlg 对话框

CSliderUseDlg::CSliderUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSliderUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSliderUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSliderUseDlg 消息处理程序

BOOL CSliderUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//设置红色值滑动条
	CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
	ASSERT(pSliderRed!=NULL);
	//设置滑动条取值范围
	pSliderRed->SetRange(0,255);
	pSliderRed->SetPos(128);

	//设置绿色值滑动条
	CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
	ASSERT(pSliderGreen!=NULL);
	//设置滑动条取值范围
	pSliderGreen->SetRange(0,255);
	pSliderGreen->SetPos(128);

	//设置蓝色值滑动条
	CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);
	ASSERT(pSliderBlue!=NULL);
	//设置滑动条取值范围
	pSliderBlue->SetRange(0,255);
	pSliderBlue->SetPos(128);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSliderUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SLIDERUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SLIDERUSE_DIALOG));
	}
}
#endif


void CSliderUseDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int iRed,iGreen,iBlue;
	//得到红色、绿色和蓝色滑动条滚动事件
	if ((pScrollBar->GetDlgCtrlID() == IDC_SLIDER_RED) 
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_GREEN)
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_BLUE))
	{
		CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
		CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
		CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);

		iRed = pSliderRed->GetPos();
		iGreen = pSliderGreen->GetPos();
		iBlue = pSliderBlue->GetPos();

	}

	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//得到RGB颜色值
    clRGB = RGB(iRed,iGreen,iBlue);
	CClientDC * pClientDC;
	//得到绘图环境
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//显示颜色
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
