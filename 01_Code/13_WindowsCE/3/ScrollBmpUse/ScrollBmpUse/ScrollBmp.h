#pragma once


// CScrollBmp

class CScrollBmp : public CWnd
{
	DECLARE_DYNAMIC(CScrollBmp)

public:
	CScrollBmp();
	virtual ~CScrollBmp();

protected:
	DECLARE_MESSAGE_MAP()
private:
	CScrollBar	m_vbar;			//��ֱ������
	CScrollBar	m_hbar;			//ˮƽ������

	CDC m_dcMem;				//�ڴ��豸���������ڻ���λͼ
	
	HBITMAP m_hBmpNew;			// �����µ�Bitmap������
   
	CRect m_rectStaticClient;	//�洢bmp��ʾ�ؼ��Ĵ�С

	BOOL m_erase;				//�����Ƿ����

	int m_offsetX,m_offsetY;	//������ʾλͼ��ƫ����
	int m_sourceX, m_sourceY;	//������ʾλͼʱ��Դλͼ�Ŀ�ʼ��
private:
	//��λͼ���ص��ؼ�����ʾ
	void LoadBmpToCtrl();
public:
	//��ʼ������λͼ��ʾ�ؼ�
	void InitBmpCtrl();
	//����λͼ������λͼ
	BOOL LoadBmp(LPCTSTR lpszFileName);
	//����λͼ��ԴID����λͼ
	BOOL LoadBmp(UINT nIDResource);


	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


