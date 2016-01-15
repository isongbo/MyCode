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
	m_bFlag=FALSE;//û�п�ʼ��ͼ
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
	m_nType=1;//ֱ��
}

void CDrawDemoView::OnDrawRect() 
{
	// TODO: Add your command handler code here
	m_nType=2;//����
}

void CDrawDemoView::OnDrawEllipse() 
{
	// TODO: Add your command handler code here
	m_nType=3;//��Բ
}

void CDrawDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 1 ����������
	m_ptBegin=m_ptEnd=point;
	// 2 ��ʼ��ͼ
	m_bFlag=TRUE;
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bFlag)
	{
		//��̬�Ļ���ͼ��
		CClientDC dc(this);
		// 1 �����ɵ�ͼ��
        DrawShape(&dc,m_ptBegin,m_ptEnd);
		// 2 ���µ�ͼ��
        DrawShape(&dc,m_ptBegin,point);
		// 3 ����ͼ�ε��յ�
         m_ptEnd=point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CDrawDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //������ͼ
	m_bFlag=FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawDemoView::DrawShape(CDC *pDC, CPoint p1, CPoint p2)
{
    //���û�ͼģʽ
	int nOldMode=pDC->SetROP2(R2_NOT);
	//ѡ����Ŀջ�ˢ
    CBrush* pOldBrush=
		(CBrush*)pDC->SelectStockObject(NULL_BRUSH);
    switch(m_nType)
	{
	case 1://ֱ��
       pDC->MoveTo(p1);
	   pDC->LineTo(p2);
	   break;
	 case 2://����
		pDC->Rectangle(p1.x,p1.y,p2.x,p2.y);
		break;
	 case 3://��Բ
		pDC->Ellipse(p1.x,p1.y,p2.x,p2.y);
		break;

	}
	//�ָ���Ĭ�ϵĻ�ͼģʽ
	pDC->SetROP2(nOldMode);
	//�ָ�Ĭ�ϵĻ�ˢ
	pDC->SelectObject(pOldBrush);  

}
