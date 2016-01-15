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
	CScrollBar	m_vbar;			//竖直滚动条
	CScrollBar	m_hbar;			//水平滚动条

	CDC m_dcMem;				//内存设备环境，用于绘制位图
	
	HBITMAP m_hBmpNew;			// 保存新的Bitmap对象句柄
   
	CRect m_rectStaticClient;	//存储bmp显示控件的大小

	BOOL m_erase;				//代表是否擦除

	int m_offsetX,m_offsetY;	//代表显示位图的偏移量
	int m_sourceX, m_sourceY;	//代表显示位图时，源位图的开始点
private:
	//将位图加载到控件上显示
	void LoadBmpToCtrl();
public:
	//初始化滚动位图显示控件
	void InitBmpCtrl();
	//根据位图名加载位图
	BOOL LoadBmp(LPCTSTR lpszFileName);
	//根据位图资源ID加载位图
	BOOL LoadBmp(UINT nIDResource);


	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


