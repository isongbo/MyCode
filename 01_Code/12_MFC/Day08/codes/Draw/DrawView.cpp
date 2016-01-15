// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_COMMAND(ID_DC_CLIENT, OnDcClient)
	ON_WM_PAINT()
	ON_COMMAND(ID_DC_META, OnDcMeta)
	ON_COMMAND(ID_GDI_PEN, OnGdiPen)
	ON_COMMAND(ID_GDI_BRUSH, OnGdiBrush)
	ON_COMMAND(ID_GDI_FONT, OnGdiFont)
	ON_COMMAND(ID_GDI_BMP, OnGdiBmp)
	ON_COMMAND(ID_GDI_RGN, OnGdiRgn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
    m_hMeta=NULL;
}

CDrawView::~CDrawView()
{
	if(m_hMeta)
	{
	   DeleteMetaFile(m_hMeta);
	}
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnDcClient() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOut(0,0,"Hello CClientDC");
}

void CDrawView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    dc.TextOut(0,100,"Hello CPaintDC");
	if(m_hMeta)
	{
	   dc.PlayMetaFile(m_hMeta);
	}
}

void CDrawView::OnDcMeta() 
{
	// 1 创建
	CMetaFileDC dcMeta;
	dcMeta.Create();
	// 2 添加绘制代码
	dcMeta.TextOut(100,200,"Hello CMetaFileDC");
	dcMeta.MoveTo(100,200);
	dcMeta.LineTo(200,200);
	// 3 关闭
    m_hMeta=dcMeta.Close(); 
	// 4  使用
	CClientDC dc(this);
	dc.PlayMetaFile(m_hMeta);
	
}

void CDrawView::OnGdiPen() 
{
	// 画笔的使用
	CPen pen(PS_SOLID,5,RGB(255,0,0));
	CClientDC dc(this);
	CPen* pOldPen=dc.SelectObject(&pen);
	dc.Rectangle(200,200,300,300);
	dc.SelectObject(pOldPen);
    pen.DeleteObject();

	
}

void CDrawView::OnGdiBrush() 
{
	// TODO: Add your command handler code here
	//CBrush brush(HS_CROSS ,RGB(0,0,255));
	CBitmap bmp;
    bmp.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bmp);
	CClientDC dc(this);
	CBrush* pOldBrush=dc.SelectObject(&brush);
    dc.Rectangle(100,100,400,400);
	dc.SelectObject(pOldBrush);
	brush.DeleteObject();
}

void CDrawView::OnGdiFont() 
{
	// TODO: Add your command handler code here
	CFont font;
	font.CreatePointFont(500,"黑体");
	CClientDC dc(this);
	CFont* pOldFont=dc.SelectObject(&font);
	dc.TextOut(100,200,"Hello CFont!");
	dc.SelectObject(pOldFont);
	font.DeleteObject();
}

void CDrawView::OnGdiBmp() 
{
	//1 加载位图
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	//2 创建与当前视图窗口的dc兼容dc
	CClientDC dc(this);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);
	//3 将位图选入到兼容dc
    dcBmp.SelectObject(&bmp);
	//4  将位图从兼容dc拷贝到当前dc
	dc.BitBlt(0,0,48,48,&dcBmp,0,0,SRCCOPY);
	//5 删除兼容dc
    dcBmp.DeleteDC();
	//6 删除位图对象
	bmp.DeleteObject();
}

void CDrawView::OnGdiRgn() 
{
	// CRgn类的使用
    // 1 创建
	CRgn rgn1,rgn2,rgn3;
	rgn1.CreateRectRgn(100,100,300,300);
	rgn2.CreateRectRgn(200,200,400,400);
	rgn3.CreateRectRgn(300,300,500,500);
	// 2 运算
	rgn1.CombineRgn(&rgn1,&rgn2,RGN_XOR );
	//rgn1.CombineRgn(&rgn1,&rgn3,RGN_OR);
	// 3 填充
	CClientDC dc(this);
	CBrush brush(RGB(0,0,255));
	dc.FillRgn(&rgn1,&brush);
	// 4 填充边界
	CBrush brush2(RGB(255,0,0));
	dc.FrameRgn(&rgn1,&brush2,20,5);
	// 5 设置主框架窗口的区域为rgn1
    AfxGetMainWnd()->SetWindowRgn(rgn1,TRUE);


 

	
}
