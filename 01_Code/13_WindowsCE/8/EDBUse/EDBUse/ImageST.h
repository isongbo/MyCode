/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� ImageST.h
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
#pragma once

#include <Imaging.h>

class CImageST : public CStatic
{
	DECLARE_DYNAMIC(CImageST)
public:
	//���캯��
	CImageST();
	//��������
	virtual ~CImageST();
protected:
	//WM_PAINT �����������ڻ���ͼ��
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	//���ļ��У�����ͼ��
	BOOL LoadImageFromFile(LPCTSTR strFileName  /*ͼ���ļ���*/);
	//���ڴ��У�����ͼ��
	BOOL LoadImageFromBuffer(const DWORD dwBufLen, /*����������*/ 
		const BYTE * pBuffer /*������*/);
private:
	//Image�����ӿڶ���
	IImagingFactory * m_pImagingFactory ;
	//Image�ӿڶ���
	IImage * m_pImage ;	
};


