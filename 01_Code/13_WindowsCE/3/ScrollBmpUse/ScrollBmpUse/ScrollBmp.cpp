// ScrollBmp.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScrollBmp.h"


// CScrollBmp

IMPLEMENT_DYNAMIC(CScrollBmp, CWnd)

//���캯��
CScrollBmp::CScrollBmp()
{
	m_hBmpNew = NULL;
}

//��������
CScrollBmp::~CScrollBmp()
{
	//�ͷ�λͼGDI����
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



// CScrollBmp ��Ϣ�������

//��λͼ���ص��ؼ�����ʾ
void CScrollBmp::LoadBmpToCtrl()
{
	BITMAP bmInfo;        // bmpλͼ��Ϣ�ṹ
	CPoint pt; 
	SCROLLINFO horz,vert;
	
	m_sourceX=m_sourceY=0;
	
	//�õ�����λͼ��ʾ�ؼ���С
	GetClientRect( &m_rectStaticClient );
	m_rectStaticClient.NormalizeRect();
	
	pt.x = m_rectStaticClient.left;
	pt.y = m_rectStaticClient.top;

	//�õ�λͼ��Ϣ���洢��bmInfo
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
	
	//���õײ����ұ߹�����
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
	
	//������ʾ
	InvalidateRect(&m_rectStaticClient);
}  


//��ʼ������λͼ��ʾ�ؼ�
void CScrollBmp::InitBmpCtrl()
{
	CClientDC dc(this);
	//����λͼ��ʾ�ڴ滷������
	m_dcMem.CreateCompatibleDC( &dc );
   
	CRect tmpRect;
	GetClientRect(tmpRect);
	//����λͼ��ʾ�ؼ��ײ�������
	m_hbar.Create(SBS_HORZ | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.left,tmpRect.bottom-10,tmpRect.right, tmpRect.bottom), this, 100);
    //����λͼ��ʾ�ؼ��ұ߹�����
	m_vbar.Create(SBS_VERT  | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.right-10,tmpRect.top,tmpRect.right, tmpRect.bottom-10), this, 101);
	
	m_hbar.ShowWindow(false);  
	m_vbar.ShowWindow(false);
}

//����λͼ������λͼ
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
		AfxMessageBox(_T("����λͼʧ��"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//����λͼ��ԴID����λͼ
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
		AfxMessageBox(_T("����λͼʧ��"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//ˮƽ�����¼�
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
	//С��0,������Ϊ0
	if (m_sourceX < 0)
	{
		m_sourceX = 0;
	}
	//�������ù�����λ��
	m_hbar.SetScrollPos(m_sourceX);
	m_erase=true;
	InvalidateRect(&m_rectStaticClient);

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

//��ֱ�����¼�
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

	//С��0,����0
	if (m_sourceY < 0)
	{
		m_sourceY = 0;
	}
	//�������ù�����λ��
	m_vbar.SetScrollPos(m_sourceY);
    m_erase=true;
    InvalidateRect(&m_rectStaticClient);
	
	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}

//WM_PAINT�����¼�
void CScrollBmp::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//���û��弼��,������Ļ��˸
	CDC memDC;
	CBitmap memBmp;
	//�Ƚ��������ɺ�ɫ
	CRect rectClient;
	GetClientRect(&rectClient);

	//����λͼ��ʾ�ڴ滷������
	memDC.CreateCompatibleDC( &dc );
	memBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());

	memDC.SelectObject(&memBmp);

	memDC.FillSolidRect(rectClient,RGB(0,0,0));

	//��ʾָ��λ�õ�ͼƬ
	memDC.BitBlt(m_offsetX,m_offsetY,m_rectStaticClient.Width()-10,m_rectStaticClient.Height()-10, 
                   &m_dcMem, m_sourceX, m_sourceY,SRCCOPY);

	//
	dc.BitBlt(0,0,rectClient.Width(),rectClient.Height(),&memDC,0,0,SRCCOPY);


	//�ͷ�memDC
	memDC.DeleteDC();
	//�ͷ�memBmp
	memBmp.DeleteObject();
	m_erase=false;	
}

//���������¼�
BOOL CScrollBmp::OnEraseBkgnd(CDC* pDC)
{
	if(m_erase)
		return false;
	else	
	return CWnd::OnEraseBkgnd(pDC);	

}
