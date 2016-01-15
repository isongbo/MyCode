#pragma once

#include <Afxtempl.h>
// C2DGraph

class C2DGraph : public CWnd
{
	DECLARE_DYNAMIC(C2DGraph)

public:
	C2DGraph();
	virtual ~C2DGraph();
public:
	//�ؼ��������鷽������
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) ;

protected:
	//
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
private:
	//���û���ӵĵ�ֵת������Ļ����
	CPoint GpToSp(CPoint& point);
private:
	//������Ļ��
	void DrawPoints();
public:
	//����ˢ�¿ؼ���ʾ
	void InvalidateCtrl();
public:
	//������ĩβ���һ����
	void AppendPoint(DWORD dwPointY);
	//ɾ�����ߵ�һ��
	void DeleteFirstPoint();
private:
	//�洢���еĵ�Y����
	CList<DWORD,DWORD> m_lstPointsY;   

	//�����߿��豸����
	CDC m_dcGrid;

	//���߿��豸��������λͼ
	CBitmap m_bitmapGrid ; 
	CBitmap *m_pOldBitmapGrid;

	//�������ߵ��豸����
	CDC m_dcLine;  

	//�����豸��������λͼ
	CBitmap m_bitmapLine; 
	CBitmap *m_pOldBitmapLine;

public:
	COLORREF m_crBackColor; //�ؼ�����ɫ
	COLORREF m_crGridColor; //���߿���ɫ
	COLORREF m_crLineColor; //������ɫ
	COLORREF m_crTextColor; //����ı���ɫ

	double m_dXMaxValue ; //X�����ֵ
	double m_dXMinValue ; //X����Сֵ
	double m_dYMaxValue ; //Y�����ֵ
	double m_dYMinValue ; //Y����Сֵ

    LPCTSTR m_strXCaption ; //X�����
	LPCTSTR m_strYCaption ; //Y�����


};


