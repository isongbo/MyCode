/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� EricCamera.cpp
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
#include "StdAfx.h"
#include "EricCamera.h"
#include "PropertyBag.h"
#define CHK( x ) do{ if( FAILED( hResult = ( x ))) { goto Cleanup; }} while( FALSE );
#define ERR( x ) do{ hResult = x; goto Cleanup; } while( FALSE );

//���캯��
CEricCamera::CEricCamera(void)
{
	//��ʼ�� COM ����
	CoInitialize(NULL); 
}

//��������
CEricCamera::~CEricCamera(void)
{
	//�ͷ�DSHOW�ӿ�
	FreeDShow();
	//�ͷ�COM ����
	CoUninitialize();
}

/*
*�������ܣ� �ͷ�DSHOW�ӿ�
*��ڲ����� (��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
void CEricCamera::FreeDShow()
{
	//�ͷ�IMediaControl�ӿ�
	if (m_pMediaControl  != NULL)
	{
		m_pMediaControl->Stop();
		m_pMediaControl.Release();
		m_pMediaControl = NULL;
	}
	//�ͷ�IPropertyBag�ӿ�
	if (m_pPropertyBag != NULL)
	{
		m_pPropertyBag.Release();
		m_pPropertyBag = NULL;
	}

	//�ͷ�IVideoWindow�ӿ�
	if (m_pVideoWindow != NULL)
	{
		//������Ƶ����
		m_pVideoWindow->put_Visible(OAFALSE);
		//������Ƶ���Ŵ��ھ��Ϊ��
		m_pVideoWindow->put_Owner(NULL);
		m_pVideoWindow.Release();
		m_pVideoWindow = NULL;
	}
	//�ͷ�IMediaSeeking�ӿ�
	if (m_pMediaSeeking != NULL)
	{
		m_pMediaSeeking.Release();
		m_pMediaSeeking = NULL;
	}
	//�ͷ�IMediaEvent�ӿ�
	if (m_pMediaEvent != NULL)
	{
		m_pMediaEvent.Release();
		m_pMediaEvent = NULL;
	}
	//�ͷ�IVideoCaptureFilter�ӿ�
	if (m_pVideoCaptureFilter != NULL )
	{
		m_pVideoCaptureFilter.Release();
		m_pVideoCaptureFilter = NULL;

	}
	//�ͷ�IImageSinkFilter�ӿ�
	if (m_pImageSinkFilter != NULL )
	{
		m_pImageSinkFilter.Release();
		m_pImageSinkFilter = NULL;
	}
	//�ͷ�IGraphBuilder�ӿ�
	if (m_pGraphBuilder != NULL)
	{
		m_pGraphBuilder.Release();
		m_pGraphBuilder = NULL;
	}
	//�ͷ�ICaptureGraphBuilder2�ӿ�
	if (m_pCaptureGraphBuilder != NULL)
	{
		m_pCaptureGraphBuilder->SetFiltergraph(NULL);
		m_pCaptureGraphBuilder.Release();
		m_pCaptureGraphBuilder = NULL;
	}
}

/*
*�������ܣ� ���ҵ�1������ͷ�豸
*��ڲ����� pwzName : �洢����ͷ�豸���ƣ�Ӧ��ǰ������ڴ�
*���ڲ�����pwzName :�洢����ͷ�豸����
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricCamera::GetFirstCameraDriver( WCHAR *pwzName )
{
	HRESULT hr = S_OK;
	HANDLE	handle = NULL;
	DEVMGR_DEVICE_INFORMATION di;
	GUID guidCamera = { 0xCB998A05, 0x122C, 0x4166, 0x84, 0x6A, 0x93, 0x3E, 0x4D, 0x7E, 0x3C, 0x86 };

	if( pwzName == NULL )
	{
		return FALSE;
	}
	di.dwSize = sizeof(di);
	//�鵽��1������ͷ�豸
	handle = FindFirstDevice( DeviceSearchByGuid, &guidCamera, &di );
	if(( handle == NULL ) || ( di.hDevice == NULL ))
	{
		FindClose( handle );
		return FALSE;
	}
	//�����豸��
	StringCchCopy( pwzName, MAX_PATH, di.szLegacyName );
	//�رղ����豸
	FindClose( handle );
	return TRUE;
}


/*
*�������ܣ� ��ʼ��DSHOW�ӿڣ���Ԥ����Ƶ
*��ڲ����� hVideoWnd : ��ʾ��Ƶ�Ĵ��ھ��
			strFileName :¼���ļ���
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricCamera::PreviewCamera(HWND hVideoWnd /*��Ƶ��ʾ����*/
		,LPCTSTR strFileName /*¼���ļ���*/)
{
	HRESULT hResult = S_FALSE;
	LONGLONG dwStart = 0, dwEnd = 0;
	WORD     wStartCookie = 1, wEndCookie = 2;
	CRect rectVideo;  //��Ƶ���ڳߴ�
	CComVariant   varCamName;  //��������ͷ�豸����
	WCHAR	      wzDeviceName[ MAX_PATH + 1 ]; //����ͷ�豸����
	CPropertyBag  PropBag;  //����ͷ����ҳ

	//--����¼���õ��ı��롢д�ļ���FILTER
	CComPtr<IBaseFilter>            pVideoEncoder;
	CComPtr<IBaseFilter>            pASFMultiplexer;
	CComPtr<IFileSinkFilter>        pFileSinkFilter;
	CComPtr<IDMOWrapperFilter>      pWrapperFilter;

	//Ĭ�����ͷ�DSHOW�ӿ�
	FreeDShow();

	//1,����ICaptureGraphBuilder2�ӿڣ����ڹ���ý�岶׽����
	CHK(m_pCaptureGraphBuilder.CoCreateInstance(CLSID_CaptureGraphBuilder));

	//2,����IGraphBuilder�ӿ�
	CHK(m_pGraphBuilder.CoCreateInstance(CLSID_FilterGraph));

	//3,
	CHK(m_pCaptureGraphBuilder->SetFiltergraph(m_pGraphBuilder ));

	//4���õ�IMediaControl�ӿڣ����ڿ���������
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaControl)); 


	//5���õ�IMediaSeeking�ӿڣ��������ò���λ��
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaSeeking)); 

	//6,�õ�m_pMediaEvent�ӿڣ����ڻ�ȡý���¼�
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaEvent)); 

	//7��������Ƶ��׽Filter
	CHK(m_pVideoCaptureFilter.CoCreateInstance(CLSID_VideoCapture));

	//8,�õ���Ƶ��׽����ҳ�ӿ�
	CHK(m_pVideoCaptureFilter->QueryInterface(&m_pPropertyBag ));

	//9,ѡ����Ƶ��׽�豸
	//�õ���1����Ƶ��׽�豸����
	if (!GetFirstCameraDriver( wzDeviceName ))
	{
		goto Cleanup;
	}
	varCamName = wzDeviceName;
	if(( varCamName.vt == VT_BSTR ) == NULL ) {
		return FALSE;
	}
	//������Ƶ��׽Ϊ��1����׽�豸
	PropBag.Write( L"VCapName", &varCamName );   
	CHK(m_pPropertyBag->Load( &PropBag, NULL ));

	//10,����Ƶ��׽FILTER��ӵ�FILTERͼ�С�
	CHK(m_pGraphBuilder->AddFilter( m_pVideoCaptureFilter, L"Video capture source" ));

	//11,����IDMOWrapperFilter�ӿ�
	CHK(pVideoEncoder.CoCreateInstance( CLSID_DMOWrapperFilter ));
	CHK(pVideoEncoder.QueryInterface( &pWrapperFilter ));
	//12,����WMV9 DMO
	CHK(pWrapperFilter->Init( CLSID_CWMV9EncMediaObject, DMOCATEGORY_VIDEO_ENCODER ));

	// 13,��������FILTER���뵽������ͼ��
	CHK(m_pGraphBuilder->AddFilter( pVideoEncoder, L"WMV9 DMO Encoder" ));

	//14,����ASF��·(����)���������뵽������ͼ��
	CHK(m_pCaptureGraphBuilder->SetOutputFileName( &MEDIASUBTYPE_Asf,strFileName, &pASFMultiplexer, &pFileSinkFilter ));


	//15,��ȾԤ����ƵPIN
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_PREVIEW,
		&MEDIATYPE_Video, m_pVideoCaptureFilter,
		NULL, NULL ));

	//16,������ƵԤ������
	CHK(m_pGraphBuilder.QueryInterface(&m_pVideoWindow));

	////������Ƶ���ŵ�WINDOWS����
	m_pVideoWindow->put_Owner((OAHWND)hVideoWnd);
	m_pVideoWindow->put_WindowStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	//������Ƶ�ߴ�
	GetClientRect(hVideoWnd,&rectVideo);
	m_pVideoWindow->SetWindowPosition(0,0,rectVideo.Width(),rectVideo.Height());
	m_pVideoWindow->put_Visible(OATRUE);
	
	//17,��Ⱦ��׽PIN�� ����¼��
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, m_pVideoCaptureFilter, pVideoEncoder, pASFMultiplexer ));

	//18,����Still Pin������ץͼ
	CHK(m_pImageSinkFilter.CoCreateInstance(CLSID_IMGSinkFilter));
	CHK(m_pGraphBuilder->AddFilter(m_pImageSinkFilter, L"Still image filter" ));
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_STILL, &MEDIATYPE_Video, m_pVideoCaptureFilter, NULL, m_pImageSinkFilter ));

	//19,���ò�׽����ͣ
	CHK(m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, m_pVideoCaptureFilter, 0, 0 ,0,0 ));

	//20��Ԥ����Ƶ
	CHK(m_pMediaControl->Run());
	Sleep(1000);

Cleanup:
	//�ͷŽӿ�
	if (pVideoEncoder != NULL)
	{
		pVideoEncoder.Release();
		pVideoEncoder = NULL;
	}

	if (pASFMultiplexer != NULL)
	{
		pASFMultiplexer.Release();
		pASFMultiplexer = NULL;
	}

	if (pFileSinkFilter != NULL)
	{
		pFileSinkFilter.Release();
		pFileSinkFilter = NULL;
	}

	if (pWrapperFilter != NULL)
	{
		pWrapperFilter.Release();
		pWrapperFilter = NULL;
	}

	if( FAILED( hResult ))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}

/*
*�������ܣ���ʼ¼��
*��ڲ����� (��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricCamera::StartRecord()
{
	LONGLONG dwStart = 0, dwEnd = 0;
	WORD     wStartCookie = 1, wEndCookie = 2;

	HRESULT hResult = 0;

    if( m_pCaptureGraphBuilder == NULL )
    {
       return FALSE;
    }

	//��ʼ¼��
	dwStart=0;
	dwEnd=MAXLONGLONG;
	hResult = m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, NULL, &dwStart, &dwEnd, wStartCookie, wEndCookie );

	TRACE(L"��ʼ¼��\n");
	if( FAILED( hResult ))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*
*�������ܣ�ֹͣ¼��
*��ڲ����� (��)
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricCamera::StopRecord()
{
	HRESULT   hResult = S_OK;
	LONGLONG  dwStart = 0, dwEnd = 0;
	WORD      wStartCookie = 1, wEndCookie = 2;

	LONG lEventCode = 0;
	LONG lParam1 = 0;
	LONG lParam2 = 0;

    if( m_pCaptureGraphBuilder == NULL )
    {
       return FALSE;
    }

	//ֹͣ��Ƶ��׽���������뵽�ļ���
	dwStart = 0;
	hResult = m_pMediaSeeking->GetCurrentPosition( &dwEnd );
	hResult = m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, NULL, &dwStart, &dwEnd, wStartCookie, wEndCookie );

	//���¼���ļ����ɽ���
	while (true)
	{
		m_pMediaEvent->GetEvent( &lEventCode, &lParam1, &lParam2, INFINITE );
		m_pMediaEvent->FreeEventParams( lEventCode, lParam1, lParam2 );

		if( lEventCode == EC_STREAM_CONTROL_STOPPED ) {
			TRACE(L"¼��ֹͣ\n");
			break;
		}
	}
	//
	if( FAILED( hResult ))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*
*�������ܣ�ץ��
*��ڲ����� strFileName��ץ�ı�����ļ�����ͼ���ʽΪJPG.
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ�;FALSE:ʧ��
*/
BOOL CEricCamera::SnapPicture(LPCTSTR strFileName /*ͼ���ļ�������ʽΪJPG*/)
{
	HRESULT hResult = S_FALSE;
	CComPtr<IFileSinkFilter> pFileSink;
	CComPtr<IUnknown>		 pUnkCaptureFilter;
	CComPtr<IPin>			 pStillPin;
	CComPtr<IAMVideoControl> pVideoControl;
    if( m_pCaptureGraphBuilder == NULL )
    {
       goto Cleanup;
    }
	//�õ�IFileSinkFilter�ӿ�
	CHK( m_pImageSinkFilter.QueryInterface( &pFileSink ));
	//����ץ�ı����ͼ���ļ���
	CHK( pFileSink->SetFileName( strFileName, NULL ));
	//�õ�StillPin
	CHK( m_pVideoCaptureFilter.QueryInterface( &pUnkCaptureFilter ));
	CHK( m_pCaptureGraphBuilder->FindPin( pUnkCaptureFilter, PINDIR_OUTPUT, &PIN_CATEGORY_STILL, &MEDIATYPE_Video, FALSE, 0, &pStillPin ));
	//����ץ�Ķ���
	CHK( m_pVideoCaptureFilter.QueryInterface( &pVideoControl ));
	CHK( pVideoControl->SetMode( pStillPin, VideoControlFlag_Trigger ));

Cleanup:
	//�ͷ�DSHOW�ӿ�
	if (pFileSink != NULL)
	{
		pFileSink.Release();
		pFileSink = NULL;
	}
	if (!pUnkCaptureFilter != NULL)
	{
		pUnkCaptureFilter.Release();
		pUnkCaptureFilter = NULL;
	}
	if (pStillPin != NULL)
	{
		pStillPin.Release();
		pStillPin = NULL;
	}
	if (pVideoControl != NULL)
	{
		pVideoControl.Release();
		pVideoControl = NULL;
	}

	if( FAILED( hResult ))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
