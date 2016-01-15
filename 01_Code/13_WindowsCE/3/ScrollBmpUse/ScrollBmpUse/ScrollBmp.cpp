// ScrollBmp.cpp : 实现文件
//

#include "stdafx.h"
#include "ScrollBmp.h"


// CScrollBmp

IMPLEMENT_DYNAMIC(CScrollBmp, CWnd)

//构造函数
CScrollBmp::CScrollBmp()
{
	m_hBmpNew = NULL;
}

//析构函数
CScrollBmp::~CScrollBmp()
{
	//释放位图GDI对象
	if (m_hBmpNew)
	{
		DeleteObject(m_hBmpNew);
		m_hBmpNew = NULL;
	}
}


BEGIN_MESSAGE_MAP(CScrollBmp, CWnd)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CScrollBmp 消息处理程序

//将位图加载到控件上显示
void CScrollBmp::LoadBmpToCtrl()
{
	BITMAP bmInfo;        // bmp位图信息结构
	CPoint pt; 
	SCROLLINFO horz,vert;
	
	m_sourceX=m_sourceY=0;
	
	//得到滚动位图显示控件大小
	GetClientRect( &m_rectStaticClient );
	m_rectStaticClient.NormalizeRect();
	
	pt.x = m_rectStaticClient.left;
	pt.y = m_rectStaticClient.top;

	//得到位图信息，存储到bmInfo
	GetObject(m_hBmpNew , sizeof(BITMAP), &bmInfo );
	SelectObject(m_dcMem, m_hBmpNew );

	m_offsetX= pt.x;
	m_offsetY=pt.y;

	horz.cbSize = sizeof(SCROLLINFO);
	horz.fMask = SIF_ALL;
	horz.nMin = 0;
	horz.nMax = bmInfo.bmWidth-m_rectStaticClient.Width();
	horz.nPage =0;
	horz.nPos = 0;
	horz.nTrackPos=0;
	
	//设置底部和右边滚动条
	if(bmInfo.bmWidth<=m_rectStaticClient.Width())
	{
		if((m_rectStaticClient.Width()-bmInfo.bmWidth)==0)
			m_offsetX= pt.x;
		else
			m_offsetX= pt.x+((m_rectStaticClient.Width()-bmInfo.bmWidth)/2);
		m_vbar.MoveWindow(m_offsetX+bmInfo.bmWidth,m_offsetY,18,m_rectStaticClient.Height());
		m_hbar.ShowWindow(false);
	}
	else
		m_hbar.ShowWindow(true);
	m_hbar.SetScrollInfo(&horz);

	vert.cbSize = sizeof(SCROLLINFO);
	vert.fMask = SIF_ALL;
	vert.nMin = 0;
	vert.nMax = bmInfo.bmHeight-(m_rectStaticClient.Height());
	vert.nPage = 0;
	vert.nPos = 0;
	vert.nTrackPos= 0;
	if(bmInfo.bmHeight<=m_rectStaticClient.Height())
	{
		if((m_rectStaticClient.Height()-bmInfo.bmHeight)==0)
			m_offsetY= pt.y;
		else
			m_offsetY= pt.y+((m_rectStaticClient.Height()-bmInfo.bmHeight)/2);
		m_hbar.MoveWindow(m_offsetX,m_offsetY+bmInfo.bmHeight,m_rectStaticClient.Width(),18);
		m_vbar.ShowWindow(false);
	}
	else
		m_vbar.ShowWindow(true);
	m_vbar.SetScrollInfo(&vert);
	
	//更新显示
	InvalidateRect(&m_rectStaticClient);
}  


//初始化滚动位图显示控件
void CScrollBmp::InitBmpCtrl()
{
	CClientDC dc(this);
	//创建位图显示内存环境变量
	m_dcMem.CreateCompatibleDC( &dc );
   
	CRect tmpRect;
	GetClientRect(tmpRect);
	//创建位图显示控件底部滚动条
	m_hbar.Create(SBS_HORZ | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.left,tmpRect.bottom-10,tmpRect.right, tmpRect.bottom), this, 100);
    //创建位图显示控件右边滚动条
	m_vbar.Create(SBS_VERT  | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.right-10,tmpRect.top,tmpRect.right, tmpRect.bottom-10), this, 101);
	
	m_hbar.ShowWindow(false);  
	m_vbar.ShowWindow(false);
}

//根据位图名加载位图
BOOL CScrollBmp::LoadBmp(LPCTSTR lpszFileName)
{
	if(m_hBmpNew != NULL )
	{
		DeleteObject(m_hBmpNew);
		m_hBmpNew = NULL;
	}
	
	m_hBmpNew = SHLoadDIBitmap(lpszFileName);
	if( m_hBmpNew == NULL )
	{
		AfxMessageBox(_T("加载位图失败"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//根据位图资源ID加载位图
BOOL CScrollBmp::LoadBmp(UINT nIDResource)
{
	if(m_hBmpNew != NULL )
	{
		DeleteObject(m_hBmpNew);
		m_hBmpNew = NULL;
	}
	
	m_hBmpNew = LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(nIDResource));
	if( m_hBmpNew == NULL )
	{
		AfxMessageBox(_T("加载位图失败"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//水平滚动事件
void CScrollBmp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
	case SB_TOP:
		m_sourceX = 0;
		break;
	case SB_BOTTOM:
		m_sourceX = INT_MAX;
		break;
	case SB_THUMBTRACK:
		m_sourceX= nPos;
		break;
	case SB_LINEUP:
		m_sourceX = m_hbar.GetScrollPos()-10;
		break;
	case SB_LINEDOWN:
		m_sourceX = m_hbar.GetScrollPos()+10;
		break;	
	case SB_PAGEUP:
		m_sourceX = m_hbar.GetScrollPos()-20;
		break;
	case SB_PAGEDOWN:
		m_sourceX = m_hbar.GetScrollPos()+20;
		break;
	}	
	//小于0,则设置为0
	if (m_sourceX < 0)
	{
		m_sourceX = 0;
	}
	//重新设置滚动条位置
	m_hbar.SetScrollPos(m_sourceX);
	m_erase=true;
	InvalidateRect(&m_rectStaticClient);

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

//竖直滚动事件
void CScrollBmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
	case SB_TOP:
		m_sourceY = 0;
		break;
	case SB_BOTTOM:
		m_sourceY = INT_MAX;
		break;
	case SB_THUMBTRACK:
		m_sourceY = nPos;
		break;
	case SB_LINEUP:
		m_sourceY = m_vbar.GetScrollPos()-10;
		break;
	case SB_LINEDOWN:
		m_sourceY = m_vbar.GetScrollPos()+10;
		break;	
	case SB_PAGEUP:
		m_sourceY = m_vbar.GetScrollPos()-20;
		break;
	case SB_PAGEDOWN:
		m_sourceY = m_vbar.GetScrollPos()+20;
		break;
	}

	//小于0,则置0
	if (m_sourceY < 0)
	{
		m_sourceY = 0;
	}
	//重新设置滚动条位置
	m_vbar.SetScrollPos(m_sourceY);
    m_erase=true;
    InvalidateRect(&m_rectStaticClient);
	
	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}

//WM_PAINT绘制事件
void CScrollBmp::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//采用缓冲技术,避免屏幕闪烁
	CDC memDC;
	CBitmap memBmp;
	//先将背景画成黑色
	CRect rectClient;
	GetClientRect(&rectClient);

	//创建位图显示内存环境变量
	memDC.CreateCompatibleDC( &dc );
	memBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());

	memDC.SelectObject(&memBmp);

	memDC.FillSolidRect(rectClient,RGB(0,0,0));

	//显示指定位置的图片
	memDC.BitBlt(m_offsetX,m_offsetY,m_rectStaticClient.Width()-10,m_rectStaticClient.Height()-10, 
                   &m_dcMem, m_sourceX, m_sourceY,SRCCOPY);

	//
	dc.BitBlt(0,0,rectClient.Width(),rectClient.Height(),&memDC,0,0,SRCCOPY);


	//释放memDC
	memDC.DeleteDC();
	//释放memBmp
	memBmp.DeleteObject();
	m_erase=false;	
}

//擦除背景事件
BOOL CScrollBmp::OnEraseBkgnd(CDC* pDC)
{
	if(m_erase)
		return false;
	else	
	return CWnd::OnEraseBkgnd(pDC);	

}
