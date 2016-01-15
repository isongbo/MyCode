#pragma once


// CLedCtrl
class CMemDC : public CDC {
private:
	CBitmap m_bitmap; //����λͼ
	CBitmap* m_oldBitmap; //�洢��λͼ
	CDC* m_pDC; //�洢��ͼ����
	CRect m_rect; //�洢�ؼ���������
	BOOL m_bMemDC; //�жϻ�ͼ�����Ƿ�׼����
public:
	//���캯��
	CMemDC(CDC* pDC, CRect rect = CRect(0,0,0,0)) : CDC(), m_oldBitmap(NULL), m_pDC(pDC)
	{
		//�жϻ�ͼ�Ƿ�Ϊ��
		ASSERT(m_pDC != NULL); 
		//�жϻ�ͼ�����Ƿ�׼����
		m_bMemDC = !pDC->IsPrinting();
		if (m_bMemDC)
		{
			//�����������ƻ���
			CreateCompatibleDC(pDC);
			if ( rect == CRect(0,0,0,0) )
				pDC->GetClipBox(&m_rect);
			else
				m_rect = rect;

			//��������λͼ
			m_bitmap.CreateCompatibleBitmap(pDC, m_rect.Width(), m_rect.Height());
			m_oldBitmap = SelectObject(&m_bitmap);
		} else 
		{
			m_hDC = pDC->m_hDC;
			m_hAttribDC = pDC->m_hAttribDC;
		}
	}
	
	//��������
	~CMemDC()
	{
		if (m_bMemDC) {
			//������λͼ������Ļ��
			m_pDC->BitBlt(m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height(),
				this, m_rect.left, m_rect.top, SRCCOPY);
			//����λͼ����ѡ�񵽻�ͼ����
			SelectObject(m_oldBitmap);
		} else {
			m_hDC = m_hAttribDC = NULL;
		}
	}
	
	//ָ�����������
	CMemDC* operator->() {return this;}
	
	//ָ�����������
	operator CMemDC*() {return this;}
};


class CLedCtrl : public CStatic
{
	DECLARE_DYNAMIC(CLedCtrl)

public:
	CLedCtrl();
	virtual ~CLedCtrl();

protected:
	DECLARE_MESSAGE_MAP()
protected:
	//�洢�Ƿ���Ƶ��뵭��Ч�����ر���
	bool m_bDrawFadedNotches;
	//��ʾ�Ƿ��Ѿ����û����ϵ
	bool m_bGotMetrics;

	//�洢�ؼ��ͻ�����
	RECT m_recClient;

	//���õ���
	int m_nNotchWidth;
	//���õ㳤��
	int m_nNotchLength;

	//�洢��ʾ������
	CString m_strNumber;
    
	//�ؼ�����ɫ
	COLORREF m_crColorBackground;
	//�ؼ�ǰ��ɫ��Ҳ����������ɫ
	COLORREF m_crColorForeground;
    
	//������ˢ
	CBrush m_brBackground;
 protected:
	//����һ������
	void Draw(CMemDC* pDC, DWORD dwChar, int nCol);
public:
	//�����Ƿ���ʾ���뵭��Ч��
	void SetDrawFaded(bool bState);
	//���ñ���ɫ
	void SetColorBackGround(COLORREF crColor);
	//����ǰ��ɫ
	void SetColorForeGround(COLORREF crColor);
public:
	//��ʾ����
	void Display(int nNumber);

	afx_msg void OnPaint();
};


