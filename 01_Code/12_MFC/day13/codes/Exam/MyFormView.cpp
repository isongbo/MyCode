// MyFormView.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "MyFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFormView

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

CMyFormView::CMyFormView()
	: CFormView(CMyFormView::IDD)
{
	//{{AFX_DATA_INIT(CMyFormView)
	m_strName = _T("");
	m_strAge = _T("");
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
	m_pViewEdit=NULL;
	m_pViewList=NULL;
}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyFormView)
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_strAge);
	DDX_Text(pDX, IDC_ADDRESS, m_strAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
	//{{AFX_MSG_MAP(CMyFormView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFormView diagnostics

#ifdef _DEBUG
void CMyFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFormView message handlers

void CMyFormView::OnAdd() 
{
	//添加前为空判断
	
	int static nItem=0;
	// 1 获取用户在编辑框中的输入
	UpdateData(TRUE);
	// 2 在列表视图中添加选项
  CListCtrl& theCtrl=m_pViewList->GetListCtrl();
  theCtrl.InsertItem(nItem,m_strName);
	theCtrl.SetItemText(nItem,1,m_strAge);
	theCtrl.SetItemText(nItem,2,m_strAddress);
	nItem++;
	// 3 在编辑视图中添加提示信息
	CString strInfo="添加新学员：";
	strInfo+=m_strName;
	m_pViewEdit->SetWindowText(strInfo);
  //添加后清空

}
