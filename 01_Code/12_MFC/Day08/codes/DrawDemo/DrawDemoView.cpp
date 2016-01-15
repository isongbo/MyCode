// DrawDemoView.cpp : implementation of the CDrawDemoView class
//

#include "stdafx.h"
#include "DrawDemo.h"

#include "DrawDemoDoc.h"
#include "DrawDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView

IMPLEMENT_DYNCREATE(CDrawDemoView, CView)

BEGIN_MESSAGE_MAP(CDrawDemoView, CView)
	//{{AFX_MSG_MAP(CDrawDemoView)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_COMMAND(ID_DRAW_ELLIPSE, OnDrawEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView construction/destruction

CDrawDemoView::CDrawDemoView()
{
	// TODO: add construction code here
    m_nType=0;
	m_ptBegin=m_ptEnd=0;
	m_bFlag=FALSE;//没有开始绘图
}

CDrawDemoView::~CDrawDemoView()
{
}

BOOL CDrawDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView drawing

void CDrawDemoView::OnDraw(CDC* pDC)
{
	CDrawDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView printing

BOOL CDrawDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView diagnostics

#ifdef _DEBUG
void CDrawDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDemoDoc* CDrawDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDemoDoc)));
	return (CDrawDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoView message handlers

void CDrawDemoView::OnDrawLine() 
{
	// TODO: Add your command handler code here
	m_nType=1;//直线
}

void CDrawDemoView::OnDrawRect() 
{
	// TODO: Add your command handler code here
	m_nType=2;//矩形
}

void CDrawDemoView::OnDrawEllipse() 
{
	// TODO: Add your command handler code here
	m_nType=3;//椭圆
}

void CDrawDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 1 设置鼠标起点
	m_ptBegin=m_ptEnd=point;
	// 2 开始绘图
	m_bFlag=TRUE;
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bFlag)
	{
		//动态的绘制图形
		CClientDC dc(this);
		// 1 擦除旧的图形
        DrawShape(&dc,m_ptBegin,m_ptEnd);
		// 2 画新的图形
        DrawShape(&dc,m_ptBegin,point);
		// 3 保存图形的终点
         m_ptEnd=point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CDrawDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //结束绘图
	m_bFlag=FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawDemoView::DrawShape(CDC *pDC, CPoint p1, CPoint p2)
{
    //设置绘图模式
	int nOldMode=pDC->SetROP2(R2_NOT);
	//选择库存的空画刷
    CBrush* pOldBrush=
		(CBrush*)pDC->SelectStockObject(NULL_BRUSH);
    switch(m_nType)
	{
	case 1://直线
       pDC->MoveTo(p1);
	   pDC->LineTo(p2);
	   break;
	 case 2://矩形
		pDC->Rectangle(p1.x,p1.y,p2.x,p2.y);
		break;
	 case 3://椭圆
		pDC->Ellipse(p1.x,p1.y,p2.x,p2.y);
		break;

	}
	//恢复到默认的绘图模式
	pDC->SetROP2(nOldMode);
	//恢复默认的画刷
	pDC->SelectObject(pOldBrush);  

}
