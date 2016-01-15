/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� ImageST.cpp
* �ļ���ʶ�� 
* ժҪ�� �̳�CStatic�ؼ���������ʾͼ��
*		 CImageST�ṩ�˴��ļ��м���ͼ��ʹ��ڴ��м���ͼ�����ַ���
*
* ��ǰ�汾�� 1.0
* ���ߣ� ���� Eric Wong
* ������ڣ� 2008��1��8��
*
* ȡ���汾��
* ԭ���ߣ� 
* ������ڣ� 
----------------------------------------*/
#include "stdafx.h"
#include "initguid.h"
#include "ImageST.h"

IMPLEMENT_DYNAMIC(CImageST, CStatic)

//���캯��
CImageST::CImageST()
{
	 m_pImagingFactory =NULL; //Image�����ӿڶ���
	 m_pImage = NULL;	//Image�ӿڶ���

	 HRESULT hr;
	//��ʼ��COM����
    if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
    {
       	TRACE(L"COINIT_MULTITHREADED ERROR");
		return;
    }

	//�õ�Image�����ӿڶ���
     hr = CoCreateInstance(CLSID_ImagingFactory, 
                          NULL, 
                          CLSCTX_INPROC_SERVER, 
                          IID_IImagingFactory, 
                          (void**) &m_pImagingFactory);


}

//��������
CImageST::~CImageST()
{
	//�ͷ�IImage�ӿڶ���
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}
        
	//�ͷ�IImagingFactory�ӿڶ���
    if (m_pImagingFactory)
	{
        m_pImagingFactory->Release();
		m_pImagingFactory = NULL;
	}

	//�ͷų���ռ�õ�COM��Դ
    CoUninitialize();

}

BEGIN_MESSAGE_MAP(CImageST, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

//WM_PAINT,����ͼƬ
void CImageST::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//������Ƴߴ�
	RECT rect;
	GetClientRect(&rect);

	if (m_pImage)
	{
		//����ͼƬ
		m_pImage->Draw(dc.m_hDC, &rect, NULL);
	}

}

//���ļ��У�����ͼ��
BOOL CImageST::LoadImageFromFile(LPCTSTR strFileName  /*ͼ���ļ���*/)
{
	//
	HRESULT hr ; //���ؽ��

	//�ͷ�IImage�ӿڶ���
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}

	//����ͼ���ļ���IImage�ӿڶ�����
	hr = m_pImagingFactory->CreateImageFromFile(strFileName,&m_pImage);

	if (hr == S_OK)
	{
		//������ʾ
		Invalidate();
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

//���ڴ��У�����ͼ��
BOOL CImageST::LoadImageFromBuffer(const DWORD dwBufLen, /*����������*/ 
		const BYTE * pBuffer /*������*/)
{
	HRESULT hr ; //���ؽ��

	BYTE * buf = NULL;

	//�ͷ�IImage�ӿڶ���
    if (m_pImage)
	{
        m_pImage->Release();
		m_pImage = NULL;
	}

	//�����ڴ�
	buf = (BYTE*)CoTaskMemAlloc(dwBufLen);
	//�����ڴ�
	CopyMemory(buf,pBuffer,dwBufLen);
	//����ͼ�󻺳�����IImage�ӿڶ�����
	hr = m_pImagingFactory->CreateImageFromBuffer(buf,dwBufLen,BufferDisposalFlagCoTaskMemFree,&m_pImage);

	if (hr == S_OK)
	{
		//������ʾ
		Invalidate();
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}


