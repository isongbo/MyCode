// 2DGraph.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw2DGraph.h"
#include "2DGraph.h"


// C2DGraph

IMPLEMENT_DYNAMIC(C2DGraph, CWnd)

//���캯��
C2DGraph::C2DGraph()
{
	//��ʼ���ؼ�����
	m_crBackColor = RGB(0,0,0);
	m_crGridColor = RGB(0,255,255);
	m_crLineColor = RGB(255,0,255);
	m_crTextColor = RGB(255,0,255);
	
	m_strXCaption = _T("X��");
	m_strYCaption = _T("Y��");
	m_dXMaxValue = 10;
	m_dXMinValue = 0;
	m_dYMaxValue = 10;
	m_dYMinValue = 0; 

	m_pOldBitmapGrid = NULL;
	m_pOldBitmapLine = NULL;

}

//��������
C2DGraph::~C2DGraph()
{	
	//��ԭGDI����
	if (m_dcGrid.GetSafeHdc() != NULL)
	{
		m_dcGrid.SelectObject(m_pOldBitmapGrid);
	}

	if (m_dcLine.GetSafeHdc() != NULL)
	{
		m_dcLine.SelectObject(m_pOldBitmapLine);
	}
}


BEGIN_MESSAGE_MAP(C2DGraph, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// C2DGraph ��Ϣ�������

BOOL C2DGraph::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL result ;
	//ע�ᴰ����
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//����������
	result = CWnd::CreateEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 
		className, NULL, dwStyle, 
		rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), (HMENU)nID) ;

	
	return TRUE;
}


//���û���ӵĵ�ֵת������Ļ����
CPoint C2DGraph::GpToSp(CPoint& point)
{
	CPoint rPoint;
   	CRect rectClient;
	CRect rectLine;
	
	GetClientRect(rectClient) ;
	rectLine.left = rectClient.left + 20;
	rectLine.right = rectClient.right - 10;
	rectLine.top = rectClient.top + 10;
	rectLine.bottom = rectClient.bottom - 20;
	rPoint.x = rectLine.left + (point.x / (m_dXMaxValue - m_dXMinValue))*rectLine.Width();
	rPoint.y = rectLine.top + (1 - point.y / (m_dYMaxValue - m_dYMinValue))*rectLine.Height(); 
	return rPoint;
}

//����ˢ�¿ؼ���ʾ
void C2DGraph::InvalidateCtrl()
{
    CPen *oldPen;
	CPen solidPen(PS_SOLID,0,m_crGridColor);
    CFont xFont,yFont,*oldFont;
	CBrush brushBack;
	brushBack.CreateSolidBrush(m_crBackColor) ;
	
	CRect rectClient;
	GetClientRect(rectClient);
	
	CClientDC dc(this);
	
	//��������豸�����Լ�������Ӧ������
	if (m_dcGrid.GetSafeHdc() == NULL)
	{
		m_dcGrid.CreateCompatibleDC(&dc);
		m_bitmapGrid.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_pOldBitmapGrid = m_dcGrid.SelectObject(&m_bitmapGrid);
	}
	
	//���ñ�����ɫ
	m_dcGrid.SetBkColor(m_crBackColor);
	m_dcGrid.FillRect(rectClient,&brushBack);
	
	//���߿�
	oldPen = m_dcGrid.SelectObject(&solidPen);
	m_dcGrid.MoveTo(rectClient.left + 20,rectClient.top + 10);
	m_dcGrid.LineTo(rectClient.right - 10,rectClient.top + 10);
	m_dcGrid.LineTo (rectClient.right - 10,rectClient.bottom - 20) ;
	m_dcGrid.LineTo (rectClient.left + 20 , rectClient.bottom - 20) ;
	m_dcGrid.LineTo (rectClient.left + 20 , rectClient.top  + 10) ;
	//��ԭGDI����
	m_dcGrid.SelectObject(oldPen);
	
	//����Y������
	yFont.CreateFont (14, 0, 900, 0, 300,
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, _T("����")) ;
	
	//����X������
	xFont.CreateFont (14, 0, 0, 0, 300,
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, _T("����")) ;
	
	//��Y�������
	m_dcGrid.SetTextColor(m_crTextColor);
	oldFont = m_dcGrid.SelectObject(&yFont);
	m_dcGrid.ExtTextOut (rectClient.left + 2, 
		(rectClient.top + rectClient.bottom ) / 2 + 5, ETO_CLIPPED,NULL,m_strYCaption,wcslen(m_strYCaption),NULL) ;
	
	//��Y�������ֵ
	CString strTmp;
	strTmp.Format(_T("%.2f"),m_dYMaxValue);
	m_dcGrid.ExtTextOut (rectClient.left+5  , 
		rectClient.top + 40 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��Y������Сֵ
	strTmp.Format(_T("%.2f"),m_dYMinValue);
	m_dcGrid.ExtTextOut (rectClient.left+5 , 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��ԭGDI����
	m_dcGrid.SelectObject(oldPen);

	//��X�������
	oldFont = m_dcGrid.SelectObject(&xFont);
	m_dcGrid.ExtTextOut ((rectClient.left+ rectClient.right)/2 - 5, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL,m_strXCaption,wcslen(m_strXCaption) ,NULL) ;
	
	//��X�������ֵ
	strTmp.Format(_T("%.2f"),m_dXMaxValue);
	m_dcGrid.ExtTextOut (rectClient.right - 40, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��X������Сֵ
	strTmp.Format(_T("%.2f"),m_dXMinValue);
	m_dcGrid.ExtTextOut (rectClient.left + 20, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��ԭGDI����
	m_dcGrid.SelectObject(oldPen);
	
	//���������豸�����Լ�������Ӧ������
	if (m_dcLine.GetSafeHdc() == NULL)
	{
		m_dcLine.CreateCompatibleDC(&dc) ;
		m_bitmapLine.CreateCompatibleBitmap(&dc, rectClient.Width(), rectClient.Height()) ;
		m_pOldBitmapLine = m_dcLine.SelectObject(&m_bitmapLine) ;
	}
	
	m_dcLine.SetBkColor (m_crBackColor) ;
	m_dcLine.FillRect(rectClient, &brushBack) ;

	//ɾ��������GDI����
	solidPen.DeleteObject();
	xFont.DeleteObject();
	yFont.DeleteObject();
	brushBack.DeleteObject();
}

//������Ļ��
void C2DGraph::DrawPoints()
{
	CPen *oldPen;
	CRect rectCleanUp;
	CPoint points[2];
	CPoint point_old;
	CPen penLine;
	//��������
	penLine.CreatePen(PS_SOLID, 0, m_crLineColor) ;

	//�õ���ͼ����
	CRect rectClient;
	GetClientRect(rectClient);

	m_dcLine.FillSolidRect(rectClient,m_crBackColor);

	int i = 0;
	oldPen = m_dcLine.SelectObject(&penLine) ;

	if (m_dcLine.GetSafeHdc() == NULL)
	{
		return;
	}

	
	//��������
	if (m_lstPointsY.GetCount() == 0 )
	{
		
	}
	//����ǵ�1����
	else if (m_lstPointsY.GetCount() == 1) 
	{
		POSITION pos = m_lstPointsY.GetHeadPosition();
		points[0].y = m_lstPointsY.GetAt(pos);
		points[0].x = 0; //��ʾ��1����
        points[0] = GpToSp(points[0]); //ת������Ļ����
		m_dcLine.SetPixel(points[0],m_crLineColor);
	}
	//������ڻ����2����
	else
	{
		POSITION pos = m_lstPointsY.GetHeadPosition();
		
		points[0].y = m_lstPointsY.GetNext(pos);
		points[0].x = 0; //��ʾ��1����
		point_old = points[0];
		i = 0;
		while (TRUE)
		{
			if (pos == NULL)
			{
				break;
			}

			points[1] = point_old;
			points[0].y = m_lstPointsY.GetNext(pos);
			points[0].x = i+1;
			point_old = points[0];
			points[0] = GpToSp(points[0]);
			points[1] = GpToSp(points[1]);
			//��������
			m_dcLine.MoveTo (points[1].x, points[1].y) ;	
			m_dcLine.LineTo (points[0].x,points[0].y) ;
			i++;
		}
	}
	
	m_dcLine.SelectObject(oldPen) ;
	//ɾ������GDI����
	penLine.DeleteObject();
}

//����WM_PAINT��Ϣ����
void C2DGraph::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	CRect rectClient;
	GetClientRect(rectClient) ;
	
	CDC memDC ;
	CBitmap memBitmap ;
	CBitmap* oldBitmap ; 
	
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rectClient.Width(), rectClient.Height()) ;
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;
	
	//���±�����ʾ
	InvalidateCtrl() ;
	//����
	DrawPoints();
	//��m_dcGrid��m_dcLine���Ƶ��ؼ���
	if (memDC.GetSafeHdc() != NULL)
	{

		memDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			         &m_dcGrid, 0, 0, SRCCOPY) ;
		memDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			         &m_dcLine, 0, 0, SRCPAINT) ;
		
		dc.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			&memDC, 0, 0, SRCCOPY) ;
	}
	
	memDC.SelectObject(oldBitmap) ;		
	
	//ɾ���ڴ�λͼGDI����
	memBitmap.DeleteObject();
	//ɾ���ڴ��ͼ����
	memDC.DeleteDC();

}

//������ĩβ���һ����
void C2DGraph::AppendPoint(DWORD dwPointY)
{
	//�ڶ��������1����
    m_lstPointsY.AddTail(dwPointY);	
	//������ʾ
	Invalidate();
}

//ɾ�����ߵ�һ��
void C2DGraph::DeleteFirstPoint()
{
	//ɾ��1���ڵ�
	if (m_lstPointsY.GetCount() > 0)
	{
		m_lstPointsY.RemoveHead();
	}
	//������ʾ
	Invalidate();		
}

