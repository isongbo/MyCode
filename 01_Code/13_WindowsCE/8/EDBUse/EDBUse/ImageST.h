/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： ImageST.h
* 文件标识： 
* 摘要： 继承CStatic控件，用于显示图象；
*		 CImageST提供了从文件中加载图象和从内存中加载图象两种方法
*
* 当前版本： 1.0
* 作者： 汪兵 Eric Wong
* 完成日期： 2008年1月8日
*
* 取代版本：
* 原作者： 
* 完成日期： 
----------------------------------------*/
#pragma once

#include <Imaging.h>

class CImageST : public CStatic
{
	DECLARE_DYNAMIC(CImageST)
public:
	//构造函数
	CImageST();
	//析构函数
	virtual ~CImageST();
protected:
	//WM_PAINT 处理方法，用于绘制图象
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	//从文件中，加载图象
	BOOL LoadImageFromFile(LPCTSTR strFileName  /*图象文件名*/);
	//从内存中，加载图象
	BOOL LoadImageFromBuffer(const DWORD dwBufLen, /*缓冲区长度*/ 
		const BYTE * pBuffer /*缓冲区*/);
private:
	//Image工厂接口对象
	IImagingFactory * m_pImagingFactory ;
	//Image接口对象
	IImage * m_pImage ;	
};


