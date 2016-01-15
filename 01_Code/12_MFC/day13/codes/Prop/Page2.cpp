// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 property page

IMPLEMENT_DYNCREATE(CPage2, CPropertyPage)

CPage2::CPage2() : CPropertyPage(CPage2::IDD)
{
	//{{AFX_DATA_INIT(CPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_LineColor=RGB(0,0,0);
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CPage2)
	ON_BN_CLICKED(IDC_SET_COLOR, OnSetColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

void CPage2::OnSetColor() 
{
   //1 弹出颜色对话框
	 CColorDialog dlg;
	 if(dlg.DoModal()==IDCANCEL)return;
	 m_LineColor=dlg.GetColor();
	 //2 将应用按钮设置为可用
	 SetModified(TRUE);
}
#include "PropView.h"
BOOL CPage2::OnApply() 
{
  
	//获取视图
	CPropView* pView=(CPropView*)
  ((CFrameWnd*)AfxGetMainWnd())->GetActiveView();
  //将颜色值传递给视图
	pView->m_Color=m_LineColor;
	//视图重绘
	pView->Invalidate(TRUE);

	return CPropertyPage::OnApply();
}

BOOL CPage2::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet* pParent=
		(CPropertySheet*)GetParent(); 
	
  pParent->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}
