/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� EricCamera.h
* �ļ���ʶ�� 
* ժҪ�����ڷ�װDSHOW ����ͷԤ����¼��ץ�Ĺ���
*
* ��ǰ�汾�� 1.0
* ���ߣ� ���� Eric Wong
* ������ڣ� 2008��2��4��
*
* ȡ���汾��
* ԭ���ߣ� 
* ������ڣ� 
----------------------------------------*/
#pragma once

#include <streams.h>
#include <dmodshow.h>
#include <dmoreg.h>
#include <wmcodecids.h>

class CEricCamera
{
public:
	CEricCamera(void);
	~CEricCamera(void);

private:
	//-----DSHOW�ӿ�-----------
	//��Ƶ��׽ͼ�ι������ӿ�
	CComPtr<ICaptureGraphBuilder2>	m_pCaptureGraphBuilder;
	//ͼ�ι������ӿ�
	CComPtr<IGraphBuilder>			m_pGraphBuilder;
	//��Ƶ��׽������
	CComPtr<IBaseFilter>			m_pVideoCaptureFilter;
	//��Ƶ�豸����ҳ
	CComPtr<IPersistPropertyBag>    m_pPropertyBag ;
	//��̬��׽PIN������
	CComPtr<IBaseFilter>	        m_pImageSinkFilter;
	//ý�岥�ſ�����
	CComPtr<IMediaControl>			m_pMediaControl  ;
	//��Ƶ���ڽӿ�
	CComPtr<IVideoWindow>			m_pVideoWindow ;
	//��Ƶ���Ž��ȿ��ƽӿ�
	CComPtr<IMediaSeeking>			m_pMediaSeeking;
	//ý���¼��ӿ�
	CComPtr<IMediaEvent>			m_pMediaEvent;

public:
	//�ͷ�DSHOW�ӿ�
	void FreeDShow();
public:
	//���ҵ�1������ͷ�豸��
	BOOL GetFirstCameraDriver( WCHAR *pwzName );
public:
	//Ԥ����Ƶ
	BOOL PreviewCamera(HWND hVideoWnd /*��Ƶ��ʾ����*/
		,LPCTSTR strFileName /*¼���ļ���*/);

public:
	//��ʼ¼��
	BOOL StartRecord();

	//ֹͣ¼��
	BOOL StopRecord();
public:
	//ץ��
	BOOL SnapPicture(LPCTSTR strFileName /*ͼ���ļ�������ʽΪJPG*/);
};
