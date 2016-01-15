/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： EricCamera.cpp
* 文件标识： 
* 摘要：用于封装DSHOW 摄像头预览、录像、抓拍功能
*
* 当前版本： 1.0
* 作者： 汪兵 Eric Wong
* 完成日期： 2008年2月4日
*
* 取代版本：
* 原作者： 
* 完成日期： 
----------------------------------------*/
#include "StdAfx.h"
#include "EricCamera.h"
#include "PropertyBag.h"
#define CHK( x ) do{ if( FAILED( hResult = ( x ))) { goto Cleanup; }} while( FALSE );
#define ERR( x ) do{ hResult = x; goto Cleanup; } while( FALSE );

//构造函数
CEricCamera::CEricCamera(void)
{
	//初始化 COM 环境
	CoInitialize(NULL); 
}

//析构函数
CEricCamera::~CEricCamera(void)
{
	//释放DSHOW接口
	FreeDShow();
	//释放COM 环境
	CoUninitialize();
}

/*
*函数介绍： 释放DSHOW接口
*入口参数： (无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
void CEricCamera::FreeDShow()
{
	//释放IMediaControl接口
	if (m_pMediaControl  != NULL)
	{
		m_pMediaControl->Stop();
		m_pMediaControl.Release();
		m_pMediaControl = NULL;
	}
	//释放IPropertyBag接口
	if (m_pPropertyBag != NULL)
	{
		m_pPropertyBag.Release();
		m_pPropertyBag = NULL;
	}

	//释放IVideoWindow接口
	if (m_pVideoWindow != NULL)
	{
		//隐藏视频窗口
		m_pVideoWindow->put_Visible(OAFALSE);
		//设置视频播放窗口句柄为空
		m_pVideoWindow->put_Owner(NULL);
		m_pVideoWindow.Release();
		m_pVideoWindow = NULL;
	}
	//释放IMediaSeeking接口
	if (m_pMediaSeeking != NULL)
	{
		m_pMediaSeeking.Release();
		m_pMediaSeeking = NULL;
	}
	//释放IMediaEvent接口
	if (m_pMediaEvent != NULL)
	{
		m_pMediaEvent.Release();
		m_pMediaEvent = NULL;
	}
	//释放IVideoCaptureFilter接口
	if (m_pVideoCaptureFilter != NULL )
	{
		m_pVideoCaptureFilter.Release();
		m_pVideoCaptureFilter = NULL;

	}
	//释放IImageSinkFilter接口
	if (m_pImageSinkFilter != NULL )
	{
		m_pImageSinkFilter.Release();
		m_pImageSinkFilter = NULL;
	}
	//释放IGraphBuilder接口
	if (m_pGraphBuilder != NULL)
	{
		m_pGraphBuilder.Release();
		m_pGraphBuilder = NULL;
	}
	//释放ICaptureGraphBuilder2接口
	if (m_pCaptureGraphBuilder != NULL)
	{
		m_pCaptureGraphBuilder->SetFiltergraph(NULL);
		m_pCaptureGraphBuilder.Release();
		m_pCaptureGraphBuilder = NULL;
	}
}

/*
*函数介绍： 查找第1个摄像头设备
*入口参数： pwzName : 存储摄像头设备名称，应提前分配好内存
*出口参数：pwzName :存储摄像头设备名称
*返回值：TRUE:成功;FALSE:失败
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
	//查到第1个摄像头设备
	handle = FindFirstDevice( DeviceSearchByGuid, &guidCamera, &di );
	if(( handle == NULL ) || ( di.hDevice == NULL ))
	{
		FindClose( handle );
		return FALSE;
	}
	//复制设备名
	StringCchCopy( pwzName, MAX_PATH, di.szLegacyName );
	//关闭查找设备
	FindClose( handle );
	return TRUE;
}


/*
*函数介绍： 初始化DSHOW接口，并预览视频
*入口参数： hVideoWnd : 显示视频的窗口句柄
			strFileName :录像文件名
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricCamera::PreviewCamera(HWND hVideoWnd /*视频显示窗口*/
		,LPCTSTR strFileName /*录像文件名*/)
{
	HRESULT hResult = S_FALSE;
	LONGLONG dwStart = 0, dwEnd = 0;
	WORD     wStartCookie = 1, wEndCookie = 2;
	CRect rectVideo;  //视频窗口尺寸
	CComVariant   varCamName;  //定义摄像头设备名称
	WCHAR	      wzDeviceName[ MAX_PATH + 1 ]; //摄像头设备名称
	CPropertyBag  PropBag;  //摄像头属性页

	//--定义录像用到的编码、写文件等FILTER
	CComPtr<IBaseFilter>            pVideoEncoder;
	CComPtr<IBaseFilter>            pASFMultiplexer;
	CComPtr<IFileSinkFilter>        pFileSinkFilter;
	CComPtr<IDMOWrapperFilter>      pWrapperFilter;

	//默认先释放DSHOW接口
	FreeDShow();

	//1,创建ICaptureGraphBuilder2接口，用于管理媒体捕捉对象
	CHK(m_pCaptureGraphBuilder.CoCreateInstance(CLSID_CaptureGraphBuilder));

	//2,创建IGraphBuilder接口
	CHK(m_pGraphBuilder.CoCreateInstance(CLSID_FilterGraph));

	//3,
	CHK(m_pCaptureGraphBuilder->SetFiltergraph(m_pGraphBuilder ));

	//4，得到IMediaControl接口，用于控制流播放
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaControl)); 


	//5，得到IMediaSeeking接口，用于设置播放位置
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaSeeking)); 

	//6,得到m_pMediaEvent接口，用于获取媒体事件
	CHK(m_pGraphBuilder.QueryInterface(&m_pMediaEvent)); 

	//7，创建视频捕捉Filter
	CHK(m_pVideoCaptureFilter.CoCreateInstance(CLSID_VideoCapture));

	//8,得到视频捕捉属性页接口
	CHK(m_pVideoCaptureFilter->QueryInterface(&m_pPropertyBag ));

	//9,选择视频捕捉设备
	//得到第1个视频捕捉设备名。
	if (!GetFirstCameraDriver( wzDeviceName ))
	{
		goto Cleanup;
	}
	varCamName = wzDeviceName;
	if(( varCamName.vt == VT_BSTR ) == NULL ) {
		return FALSE;
	}
	//设置视频捕捉为第1个捕捉设备
	PropBag.Write( L"VCapName", &varCamName );   
	CHK(m_pPropertyBag->Load( &PropBag, NULL ));

	//10,将视频捕捉FILTER添加到FILTER图中。
	CHK(m_pGraphBuilder->AddFilter( m_pVideoCaptureFilter, L"Video capture source" ));

	//11,创建IDMOWrapperFilter接口
	CHK(pVideoEncoder.CoCreateInstance( CLSID_DMOWrapperFilter ));
	CHK(pVideoEncoder.QueryInterface( &pWrapperFilter ));
	//12,加载WMV9 DMO
	CHK(pWrapperFilter->Init( CLSID_CWMV9EncMediaObject, DMOCATEGORY_VIDEO_ENCODER ));

	// 13,将编码器FILTER加入到过滤器图中
	CHK(m_pGraphBuilder->AddFilter( pVideoEncoder, L"WMV9 DMO Encoder" ));

	//14,创建ASF多路(复用)器，并加入到过滤器图中
	CHK(m_pCaptureGraphBuilder->SetOutputFileName( &MEDIASUBTYPE_Asf,strFileName, &pASFMultiplexer, &pFileSinkFilter ));


	//15,渲染预览视频PIN
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_PREVIEW,
		&MEDIATYPE_Video, m_pVideoCaptureFilter,
		NULL, NULL ));

	//16,设置视频预览窗口
	CHK(m_pGraphBuilder.QueryInterface(&m_pVideoWindow));

	////设置视频播放的WINDOWS窗口
	m_pVideoWindow->put_Owner((OAHWND)hVideoWnd);
	m_pVideoWindow->put_WindowStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	//设置视频尺寸
	GetClientRect(hVideoWnd,&rectVideo);
	m_pVideoWindow->SetWindowPosition(0,0,rectVideo.Width(),rectVideo.Height());
	m_pVideoWindow->put_Visible(OATRUE);
	
	//17,渲染捕捉PIN， 用于录像
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, m_pVideoCaptureFilter, pVideoEncoder, pASFMultiplexer ));

	//18,创建Still Pin，用于抓图
	CHK(m_pImageSinkFilter.CoCreateInstance(CLSID_IMGSinkFilter));
	CHK(m_pGraphBuilder->AddFilter(m_pImageSinkFilter, L"Still image filter" ));
	CHK(m_pCaptureGraphBuilder->RenderStream( &PIN_CATEGORY_STILL, &MEDIATYPE_Video, m_pVideoCaptureFilter, NULL, m_pImageSinkFilter ));

	//19,设置捕捉流暂停
	CHK(m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, m_pVideoCaptureFilter, 0, 0 ,0,0 ));

	//20，预览视频
	CHK(m_pMediaControl->Run());
	Sleep(1000);

Cleanup:
	//释放接口
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
*函数介绍：开始录像
*入口参数： (无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
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

	//开始录制
	dwStart=0;
	dwEnd=MAXLONGLONG;
	hResult = m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, NULL, &dwStart, &dwEnd, wStartCookie, wEndCookie );

	TRACE(L"开始录制\n");
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
*函数介绍：停止录像
*入口参数： (无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
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

	//停止视频捕捉流，并存入到文件中
	dwStart = 0;
	hResult = m_pMediaSeeking->GetCurrentPosition( &dwEnd );
	hResult = m_pCaptureGraphBuilder->ControlStream( &PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, NULL, &dwStart, &dwEnd, wStartCookie, wEndCookie );

	//检测录像文件生成结束
	while (true)
	{
		m_pMediaEvent->GetEvent( &lEventCode, &lParam1, &lParam2, INFINITE );
		m_pMediaEvent->FreeEventParams( lEventCode, lParam1, lParam2 );

		if( lEventCode == EC_STREAM_CONTROL_STOPPED ) {
			TRACE(L"录像停止\n");
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
*函数介绍：抓拍
*入口参数： strFileName：抓拍保存的文件名，图象格式为JPG.
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricCamera::SnapPicture(LPCTSTR strFileName /*图象文件名，格式为JPG*/)
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
	//得到IFileSinkFilter接口
	CHK( m_pImageSinkFilter.QueryInterface( &pFileSink ));
	//设置抓拍保存的图象文件名
	CHK( pFileSink->SetFileName( strFileName, NULL ));
	//得到StillPin
	CHK( m_pVideoCaptureFilter.QueryInterface( &pUnkCaptureFilter ));
	CHK( m_pCaptureGraphBuilder->FindPin( pUnkCaptureFilter, PINDIR_OUTPUT, &PIN_CATEGORY_STILL, &MEDIATYPE_Video, FALSE, 0, &pStillPin ));
	//设置抓拍动作
	CHK( m_pVideoCaptureFilter.QueryInterface( &pVideoControl ));
	CHK( pVideoControl->SetMode( pStillPin, VideoControlFlag_Trigger ));

Cleanup:
	//释放DSHOW接口
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
