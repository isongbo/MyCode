// PropView.cpp : implementation of the CPropView class
//

#include "stdafx.h"
#include "Prop.h"

#include "PropDoc.h"
#include "PropView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropView

IMPLEMENT_DYNCREATE(CPropView, CView)

BEGIN_MESSAGE_MAP(CPropView, CView)
	//{{AFX_MSG_MAP(CPropView)
	ON_COMMAND(ID_PROP, OnProp)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropView construction/destruction

CPropView::CPropView()
{
	// TODO: add construction code here
  m_nWidth=1;
	m_Color=RGB(0,0,0);

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPropView drawing

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
  CPen pen(PS_SOLID,m_nWidth,m_Color);
	CPen *pOldPen=pDC->SelectObject(&pen);
	pDC->Rectangle(100,100,300,300);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CPropView printing

BOOL CPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPropView diagnostics

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropView message handlers
#include "SetupSheet.h"
void CPropView::OnProp() 
{
	// 创建和显示标签式属性页
	CSetupSheet sheet("配置页面");
	// 设置为向导模式
	sheet.SetWizardMode();
	if(sheet.DoModal()==ID_WIZFINISH)
	{
     //将每步设置的参数传递给视图
     m_nWidth=sheet.m_page1.m_nLineWidth;
		 m_Color=sheet.m_page2.m_LineColor;
		 //视图重绘
		 Invalidate(TRUE);
	}
}
