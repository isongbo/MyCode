// SpinUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SpinUse.h"
#include "SpinUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSpinUseDlg 对话框

CSpinUseDlg::CSpinUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinUseDlg::IDD, pParent)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpinUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_RED, m_red);
	DDV_MinMaxByte(pDX, m_red, 0, 255);
	DDX_Text(pDX, IDC_EDT_GREEN, m_green);
	DDV_MinMaxByte(pDX, m_green, 0, 255);
	DDX_Text(pDX, IDC_EDT_BLUE, m_blue);
	DDV_MinMaxByte(pDX, m_blue, 0, 255);
}

BEGIN_MESSAGE_MAP(CSpinUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDT_RED, &CSpinUseDlg::OnEnChangeEdtRed)
	ON_EN_CHANGE(IDC_EDT_GREEN, &CSpinUseDlg::OnEnChangeEdtGreen)
	ON_EN_CHANGE(IDC_EDT_BLUE, &CSpinUseDlg::OnEnChangeEdtBlue)
END_MESSAGE_MAP()


// CSpinUseDlg 消息处理程序

BOOL CSpinUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

//设置红色值微调按钮
	CSpinButtonCtrl *pSpinRed = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_RED);
	ASSERT(pSpinRed!=NULL);
	//设置伙伴窗口
	pSpinRed->SetBuddy(GetDlgItem(IDC_EDT_RED));
	pSpinRed->SetRange(0,255);
	pSpinRed->SetPos(128);

	//设置绿色值微调按钮
	CSpinButtonCtrl *pSpinGreen = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_GREEN);
	ASSERT(pSpinGreen!=NULL);
	//设置伙伴窗口
	pSpinGreen->SetBuddy(GetDlgItem(IDC_EDT_GREEN));
	pSpinGreen->SetRange(0,255);
	pSpinGreen->SetPos(128);

	//设置蓝色值微调按钮
	CSpinButtonCtrl *pSpinBlue = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_BLUE);
	ASSERT(pSpinBlue!=NULL);
	//设置伙伴窗口
	pSpinBlue->SetBuddy(GetDlgItem(IDC_EDT_BLUE));
	pSpinBlue->SetRange(0,255);
	pSpinBlue->SetPos(128);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSpinUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SPINUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SPINUSE_DIALOG));
	}
}
#endif

//当颜色值改变时，重显颜色值
void CSpinUseDlg::RGBColorChange() 
{
	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//得到RGB颜色值
    clRGB = RGB(m_red,m_green,m_blue);
	CClientDC * pClientDC;
	//得到绘图环境
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//显示颜色
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;
}


//红色值变化事件
void CSpinUseDlg::OnEnChangeEdtRed()
{
	RGBColorChange();
}

//绿色值变化事件
void CSpinUseDlg::OnEnChangeEdtGreen()
{
	RGBColorChange();
}

//蓝色值变化事件
void CSpinUseDlg::OnEnChangeEdtBlue()
{
	RGBColorChange();
}
