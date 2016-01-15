// RemindTips.cpp : implementation file
//

#include "stdafx.h"
#include "main_gui.h"
#include "RemindTips.h"
//#include "../selfclass/JpegFile.h"


//static CJpegFile m_JpegFile;

// RemindTips dialog

//IMPLEMENT_DYNAMIC(RemindTips, CDialog)

RemindTips::RemindTips(CWnd* pParent /*=NULL*/)
	: CDialog(RemindTips::IDD, pParent)
{

}

RemindTips::~RemindTips()
{
}

void RemindTips::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RemindTips, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RemindTips::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL RemindTips::OnInitDialog()
{
	CDialog::OnInitDialog();
	mfont.CreatePointFont(200,_T("黑体"));
	mbrush.CreateSolidBrush(RGB(128,165,210));  //162,205,90
	SetTimer(1,1000,NULL);

	CRect mRC;
	this->GetClientRect(mRC);

    if (isShutDown==1)
    {
		SetDlgItemText(IDOK,_T("确定"));
		SetDlgItemText(IDCANCEL,_T("取消"));
    }
	else if (isShutDown==2)  //取票失败，不显示重试按钮
	{		
		((CButton*)GetDlgItem(IDOK))->ShowWindow(SW_HIDE);
		SetDlgItemText(IDCANCEL,_T("确定"));
		CRect mButtonRC,NewRC;
		((CButton*)GetDlgItem(IDCANCEL))->GetClientRect(mButtonRC);
		int nButtonWidth = mButtonRC.right-mButtonRC.left;
		int nButtonHeith = mButtonRC.bottom-mButtonRC.top;
		NewRC.left = (mRC.right-mRC.left-nButtonWidth)/2;
        NewRC.right = (mRC.right-mRC.left+nButtonWidth)/2;
		NewRC.top = mRC.bottom-120;
		NewRC.bottom = NewRC.top+nButtonHeith;
        ((CButton*)GetDlgItem(IDCANCEL))->MoveWindow(NewRC,true);
	}
	else if (isShutDown==3)
	{
		((CButton*)GetDlgItem(IDOK))->ShowWindow(SW_HIDE);
		((CButton*)GetDlgItem(IDCANCEL))->ShowWindow(SW_HIDE);
	}
// 
// 	SetDlgItemText(IDC_STATIC_TIP_MSG,strToShow);
// 
// 	TimeTip.Format(_T("%d"),iTimeOut);
// 	SetDlgItemText(IDC_STATIC_TIME,TimeTip);

	return TRUE;
}
void RemindTips::OnPaint() 
{
	CPaintDC dc(this); 
	CDC* pDC = GetDC();

// 	pDC->SetBkMode(TRANSPARENT);
// 	pDC->SetBkColor(RGB(128,165,210));
// 	pDC->SelectObject(&mfont);
// 
// 	CRect rRC=CRect(20,30,500,200);
// 
// 	pDC->DrawText(strToShow,strToShow.GetLength(),rRC,DT_CENTER|DT_WORDBREAK);
// 
// 
// 	CString TimeTip;
// 	CRect tRC = CRect(510,240,540,270);
// 	TimeTip.Format(_T("%d"),iTimeOut);
// 	pDC->DrawText(TimeTip,TimeTip.GetLength(),tRC,DT_LEFT|DT_TOP);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SelectObject(&mfont);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	CBitmap bkg;
	bkg.LoadBitmap(IDB_BITMAP1);
	BITMAP bkginfo;
	bkg.GetBitmap(&bkginfo);
	memdc.SelectObject(&bkg);
	RECT rect;
	GetWindowRect(&rect);
	dc.StretchBlt(0,0,rect.right-rect.left,rect.bottom-rect.top,&memdc,0,0,bkginfo.bmWidth,bkginfo.bmHeight,SRCCOPY);

	CRect rRC=CRect(20,30,300,200);
	pDC->DrawText(strToShow,strToShow.GetLength(),rRC,DT_CENTER|DT_WORDBREAK);
	CRect rRC2=CRect(20,30,550,200);
	CString str;
	str.Format(_T("%d"),iTimeOut);
 	TimeTip.Format(str);
	pDC->DrawText(TimeTip,TimeTip.GetLength(),rRC2,DT_CENTER|DT_WORDBREAK);
/*	SetDlgItemText(IDC_STATIC_TIP_MSG,strToShow);*/
// 
// 	TimeTip.Format(_T("%d"),iTimeOut);
// 	SetDlgItemText(IDC_STATIC_TIME,TimeTip);


}

HBRUSH RemindTips::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	pDC->SetBkColor(RGB(128,165,210));
	pDC->SetTextColor(RGB(0,0,0));
	pDC->SelectObject(&mfont);
	return mbrush;
}

void RemindTips::OnBnClickedOk()
{
	KillTimer(1);
	iTimeOut = 0;
	OnOK();
}

void RemindTips::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		CDC* pDC = GetDC();
		
		CRect rRC2=CRect(20,30,550,200);
		CString str;
		str.Format(_T("%d"),iTimeOut);
		TimeTip.Format(str);
		pDC->DrawText(TimeTip,TimeTip.GetLength(),rRC2,DT_CENTER|DT_WORDBREAK);
		InvalidateRect(rRC2,false);
		iTimeOut--;



		//		CRect tRc;
		// 		((CButton*)GetDlgItem(IDC_STATIC_TIME))->GetClientRect(tRc);
		// 		TimeTip.Format(_T("%d"),iTimeOut);
		// 		SetDlgItemText(IDC_STATIC_TIME,TimeTip);
		//		InvalidateRect(tRc);
		if (iTimeOut < 1)
			EndDialog(0);
	}
	else if (nIDEvent == 2)
	{
		KillTimer(2);
		iTimeOut = 0;
		EndDialog(0);
	}

	CDialog::OnTimer(nIDEvent);
}

void RemindTips::OnBnClickedCancel()
{
	KillTimer(1);
	iTimeOut = 0;
	OnCancel();
}

void RemindTips::FreshTips()
{
	Invalidate();
}