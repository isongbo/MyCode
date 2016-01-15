/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： ImageST.cpp
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
#include "stdafx.h"
#include "initguid.h"
#include "ImageST.h"

IMPLEMENT_DYNAMIC(CImageST, CStatic)

//构造函数
CImageST::CImageST()
{
	 m_pImagingFactory =NULL; //Image工厂接口对象
	 m_pImage = NULL;	//Image接口对象

	 HRESULT hr;
	//初始化COM环境
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//得到Image工厂接口对象
     hr = CoCreateInstance(CLSID_ImagingFactory, 
                          NULL, 
                          CLSCTX_INPROC_SERVER, 
                          IID_IImagingFactory, 
                          (void**) &m_pImagingFactory);


}

//析构函数
CImageST::~CImageST()
{
	//释放IImage接口对象
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}
        
	//释放IImagingFactory接口对象
    if (m_pImagingFactory)
	{
        m_pImagingFactory->Release();
		m_pImagingFactory = NULL;
	}

	//释放程序占用的COM资源
    CoUninitialize();

}

BEGIN_MESSAGE_MAP(CImageST, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

//WM_PAINT,绘制图片
void CImageST::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//定义绘制尺寸
	RECT rect;
	GetClientRect(&rect);

	if (m_pImage)
	{
		//绘制图片
		m_pImage->Draw(dc.m_hDC, &rect, NULL);
	}

}

//从文件中，加载图象
BOOL CImageST::LoadImageFromFile(LPCTSTR strFileName  /*图象文件名*/)
{
	//
	HRESULT hr ; //返回结果

	//释放IImage接口对象
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}

	//加载图象文件到IImage接口对象中
	hr = m_pImagingFactory->CreateImageFromFile(strFileName,&m_pImage);

	if (hr == S_OK)
	{
		//更新显示
		Invalidate();
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

//从内存中，加载图象
BOOL CImageST::LoadImageFromBuffer(const DWORD dwBufLen, /*缓冲区长度*/ 
		const BYTE * pBuffer /*缓冲区*/)
{
	HRESULT hr ; //返回结果

	BYTE * buf = NULL;

	//释放IImage接口对象
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}

	//分配内存
	buf = (BYTE*)CoTaskMemAlloc(dwBufLen);
	//拷贝内存
	CopyMemory(buf,pBuffer,dwBufLen);
	//加载图象缓冲区到IImage接口对象中
	hr = m_pImagingFactory->CreateImageFromBuffer(buf,dwBufLen,BufferDisposalFlagCoTaskMemFree,&m_pImage);

	if (hr == S_OK)
	{
		//更新显示
		Invalidate();
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}


