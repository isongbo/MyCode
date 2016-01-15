/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： EricMediaControl.cpp
* 文件标识： 
* 摘要：用于封装DSHOW 播放视频文件
*
* 当前版本： 1.0
* 作者： 汪兵 Eric Wong
* 完成日期： 2008年2月2日
*
* 取代版本：
* 原作者： 
* 完成日期： 
----------------------------------------*/
#include "StdAfx.h"
#include "EricMediaControl.h"

//构造函数
CEricMediaControl::CEricMediaControl(void)
{
	//将DSHOW接口置空
	m_pGB = NULL;
	m_pMC = NULL;
	m_pME = NULL;
	m_pVW = NULL;
	m_pBA = NULL;
	m_pBV = NULL;
	m_pMS = NULL;
	//初始化 COM 环境
	CoInitialize(NULL); 
}

//析构函数
CEricMediaControl::~CEricMediaControl(void)
{
	//释放DSHOW接口
	UnInitDShow();
	//释放COM 环境
	CoUninitialize();
}


/*
*函数介绍： 初始化DShow接口，并渲染好视频文件
*入口参数： strFileName:	视频文件名
			hOwnerWnd:		显示视频的窗口句柄
			hNotifyWnd:		接收DSHOW事件消息的串口句柄
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::InitDShow(LPCTSTR strFileName  /*视频文件名*/
		,HWND hOwnerWnd  /*显示视频的窗口句柄*/
		,HWND hNotifyWnd /*接收DSHOW事件消息的串口句柄*/
		)
{
	HRESULT hResult;
	//第1步：创建IGraphBuilder接口
	hResult = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&m_pGB);
	if (hResult != S_OK)
	{
		return FALSE;
	}
	//第2步：利用IGraphBuilder渲染视频文件
	hResult = m_pGB->RenderFile(strFileName,NULL);
	if (hResult != S_OK )
	{
		//
		if (hResult == VFW_S_PARTIAL_RENDER)
		{
			TRACE(L"Some of the streams in this movie are in an unsupported format.\n");			
		}
		else if (hResult == VFW_S_AUDIO_NOT_RENDERED)
		{
			TRACE(L"Partial success; the audio was not rendered.\n");		
		}
		else if (hResult == VFW_S_DUPLICATE_NAME)
		{
			TRACE(L"Success; the Filter Graph Manager modified the filter name to avoid duplication..\n");	
		}
		else if (hResult == VFW_S_VIDEO_NOT_RENDERED)
		{
			TRACE(L"Partial success; some of the streams in this movie are in an unsupported format.\n");
		}
		else
		{
			//释放DSHOW接口
			UnInitDShow();
			return FALSE;
		}
	}
	//第3步：得到媒体播放控制接口
	hResult = m_pGB->QueryInterface(IID_IMediaControl, (void **)&m_pMC); 
	if (hResult != S_OK)
	{
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	}
	//第4步：得到媒体播放位置搜索接口
	hResult = m_pGB->QueryInterface(IID_IMediaSeeking,(void**)&m_pMS);
	if (hResult != S_OK)
	{
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	}
	
	//设置查找定位的时间单位，这里设置：100纳秒（十亿分之一秒）
	GUID guid_timeFormat = TIME_FORMAT_MEDIA_TIME;
	m_pMS->SetTimeFormat(&guid_timeFormat);

	//第5步：得到Filter Graph媒体事件接口
	hResult = m_pGB->QueryInterface(IID_IMediaEventEx,(void**)&m_pME);
	if (hResult != S_OK)
	{
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	}
	//设置媒体事件通知消息窗口
	m_pME->SetNotifyWindow((OAHWND)hNotifyWnd, WM_GRAPHNOTIFY, 0);

	//第6步：得到视频播放窗口接口
	 hResult = m_pGB->QueryInterface(IID_IVideoWindow, (void **)&m_pVW);
	 if (hResult != S_OK)
	 {
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	 }
	 //设置视频播放窗口句柄
	 m_pVW->put_Owner((OAHWND)hOwnerWnd);
	 //设置视频窗口格式
     m_pVW->put_WindowStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

	 //第7步：得到基础视频流接口
	 hResult = m_pGB->QueryInterface(IID_IBasicVideo, (void **)&m_pBV);
  	 if (hResult != S_OK)
	 {
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	 }

	 //第8步：得到基础音频流接口
	 hResult = m_pGB->QueryInterface(IID_IBasicAudio, (void **)&m_pBA);
  	 if (hResult != S_OK)
	 {
		//释放DSHOW接口
		UnInitDShow();
		return FALSE;
	 }

	return TRUE;
}


/*
*函数介绍： 卸载DShow系列接口
*入口参数： (无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::UnInitDShow()
{
	//1,释放媒体播放控制接口
	if (m_pMC != NULL)
	{
		//停止视频播放
		m_pMC->Stop(); 
		m_pMC->Release();
		m_pMC = NULL;
	}
	
	//2,释放媒体事件接口
	if (m_pME != NULL)
	{
		//消息通知窗口置空
		m_pME->SetNotifyWindow(NULL, 0, 0);
		m_pME->Release();
		m_pME = NULL;
	}

	//3,释放视频播放窗口接口
	if (m_pVW != NULL)
	{
		//隐藏视频窗口
		m_pVW->put_Visible(OAFALSE);
		//设置视频播放窗口句柄为空
		m_pVW->put_Owner(NULL);
		m_pVW->Release();
		m_pVW = NULL;
	}

	//4,释放基础音频流接口
	if (m_pBA != NULL)
	{
		m_pBA->Release();
		m_pBA = NULL;
	}

	//5，释放基础视频流接口
	if (m_pBV != NULL)
	{
		m_pBV->Release();
		m_pBV = NULL;
	}

	//6，释放媒体搜索接口
	if (m_pMS != NULL)
	{
		m_pMS->Release();
		m_pMS = NULL;
	}

	//7,最后释放FilterGpaph接口
	if (m_pGB != NULL)
	{
		m_pGB->Release();
		m_pGB = NULL;
	}

	return TRUE;
}

/*
*函数介绍：打开视频文件
*入口参数： strFileName:	视频文件名
			hOwnerWnd:		显示视频的窗口句柄
			hNotifyWnd:		接收DSHOW事件消息的串口句柄
*出口参数：(无)
*返回值：TRUE:成功打开视频文件;FALSE:打开视频文件失败
*/
BOOL CEricMediaControl::OpenFile(LPCTSTR strFileName /*视频文件名*/
		,HWND hOwnerWnd  /*显示视频的窗口句柄*/
		,HWND hNotifyWnd /*接收DSHOW事件消息的串口句柄*/
		)
{
	//存储显示视频窗口句柄
	m_hOwnerWnd = hOwnerWnd;

	//重置DSHOW接口
	UnInitDShow();

	//打开视频文件，并对DSHOW接口做初始化工作
	return InitDShow(strFileName,hOwnerWnd,hNotifyWnd);
}

/*
*函数介绍：播放视频
*入口参数：(无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::VideoRun()
{
	//检测IMediaControl控制接口有效性
	if (m_pMC == NULL)
	{
		return FALSE;
	}
	
	//播放视频
	HRESULT hResult = m_pMC->Run();
	if (hResult != S_OK)
	{
		return FALSE;
	}
	return TRUE;

}

/*
*函数介绍：暂停视频
*入口参数：(无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::VideoPause()
{
	//检测IMediaControl控制接口有效性
	if (m_pMC == NULL)
	{
		return FALSE;
	}

	//暂停视频
	HRESULT	hResult = m_pMC->Pause();
	if (hResult != S_OK)
	{
		return FALSE;
	}

	return TRUE;
}

/*
*函数介绍：停止视频
*入口参数：(无)
*出口参数：(无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::VideoStop()
{
	HRESULT hResult	;
	//检测IMediaControl控制接口有效性
	if (m_pMC == NULL)
	{
		return FALSE;
	}
	
	//停止视频
	hResult = m_pMC->Stop();
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//将当前播放位置置0
    LONGLONG pos=0;
	hResult = m_pMS->SetPositions(&pos, AM_SEEKING_AbsolutePositioning ,
                                   NULL, AM_SEEKING_NoPositioning);

	return TRUE;
}


/*
*函数介绍：  设置视频显示比例
*入口参数：  fScale ： 显示比例, <= 1.0
*出口参数： (无)
*返回值：TRUE:成功;FALSE:失败，此处有点问题
*/
BOOL CEricMediaControl::FitVideoWindow(FLOAT fScale)
{
    LONG lHeight, lWidth;
	int iSeek = 0;
	double dblScaleX,dblScaleY;
    HRESULT hr = S_OK;
	LONG lDeflateX = 0;
	LONG lDeflateY = 0;
    CRect clientRect;
	CRect dstRect;
	
	//
	if (m_pBV == NULL)
	{
		return FALSE;
	}
	
	//放缩比例必须小于等于1
	if (fScale > 1.0)
	{
		return FALSE;
	}

	//得到原始视频尺寸
    hr = m_pBV->GetVideoSize(&lWidth, &lHeight);
	if (hr != S_OK)
	{
		return FALSE;
	}

	//设置拉伸后的尺寸
	lWidth = lWidth * fScale;
	lHeight = lHeight * fScale;

	//得到视频播放窗口的尺寸
	GetClientRect(m_hOwnerWnd, &clientRect);

	lDeflateX = (clientRect.Width() - clientRect.Width() * fScale) / 2;
	lDeflateY = (clientRect.Height() - clientRect.Height() * fScale) / 2;

	//重新设置客户区域
	clientRect.DeflateRect(lDeflateX,lDeflateY);

    
	if ( (lWidth <= clientRect.Width())
		&& (lHeight <= clientRect.Height()))
	{
		dstRect.left = (clientRect.right - clientRect.left - lWidth) /2;
		dstRect.right = dstRect.left + lWidth;
		dstRect.top  = (clientRect.bottom - clientRect.top - lHeight) /2;
		dstRect.bottom = dstRect.top + lHeight;
	}
	else 
	{
		dblScaleX =double(clientRect.Width()) / double(lWidth) ;
		dblScaleY =  double(clientRect.Height()) / double(lHeight) ;
		
		if (dblScaleX <= dblScaleY)
		{
			dstRect.left = clientRect.left;
			dstRect.right = clientRect.right;

			iSeek =(clientRect.Height() - clientRect.Width()*(double(lHeight) / double(lWidth)))/2;
			dstRect.top = clientRect.top + iSeek;
			dstRect.bottom = dstRect.top + clientRect.Width()*(double(lHeight) / double(lWidth));
		}
		else
		{
			dstRect.top = clientRect.top;
			dstRect.bottom = clientRect.bottom;

			iSeek =(clientRect.Width() - clientRect.Height()*(double(lWidth) / double(lHeight)))/2;
			dstRect.left = clientRect.left + iSeek;
			dstRect.right = dstRect.left + clientRect.Height()*(double(lWidth) / double(lHeight));
		}
	}

	//设置视频播放位置
    m_pVW->SetWindowPosition(dstRect.left,dstRect.top,dstRect.Width(),dstRect.Height());

    return TRUE;
}

/*
*函数介绍：  全屏显示
*入口参数： (无)
*出口参数： (无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::FullScreen()
{
	LONG lMode = 0;
	static HWND hDrain=0;
	if (m_pBV == NULL)
	{
		return FALSE;
	}
	//得到全屏状态
	m_pVW->get_FullScreenMode(&lMode);
	
	if (lMode == OAFALSE)
    {
		// Save current message drain
        m_pVW->get_MessageDrain((OAHWND *) &hDrain);

        // Set message drain to application main window
        m_pVW->put_MessageDrain((OAHWND)m_hOwnerWnd );
		
		//设置全屏幕
        lMode = OATRUE;
        m_pVW->put_FullScreenMode(lMode);
    }
    else
    {
        //切换到非全屏模式
        lMode = OAFALSE;
        m_pVW->put_FullScreenMode(lMode);

		 // Undo change of message drain
        m_pVW->put_MessageDrain((OAHWND) hDrain);
        // Reset video window
        FitVideoWindow(1);
        m_pVW->SetWindowForeground(-1);
	}
	return TRUE;
}

/*
*函数介绍：  得到是否全屏幕播放
*入口参数： (无)
*出口参数： (无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::GetFullScreenStatus()
{
	LONG lMode = 0;
	if (m_pBV == NULL)
	{
		return FALSE;
	}

	m_pVW->get_FullScreenMode(&lMode);

	if (lMode == OAFALSE)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*
*函数介绍：  得到媒体事件
*入口参数： (无)
*出口参数： lEventCode
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::GetMediaEvent(long *lEventCode)
{
    LONG evCode, evParam1, evParam2;
    HRESULT hr=S_OK;

	if (m_pME == NULL)
	{
		return FALSE;
	}

	hr = m_pME->GetEvent(&evCode, &evParam1, &evParam2, 0);
    if (SUCCEEDED(hr))
	{
        *lEventCode = evCode;
		// Spin through the events
        hr = m_pME->FreeEventParams(evCode, evParam1, evParam2);
		
		return TRUE;
	}
	return FALSE;
}


/*
*函数介绍：  设置播放进度
*入口参数： dwPos ：播放进度，单位秒
*出口参数： (无)
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::SetPositions(DWORD dwPos /*设置当前播放进度*/)
{
	//设置绝对位置,转化成纳秒为单位
	LONGLONG llPos = dwPos * 10000 * 1000;
	if (m_pMS == NULL)
	{
		return FALSE;
	}
	//设置视频播放当前位置
	HRESULT hr = m_pMS->SetPositions(&llPos,AM_SEEKING_AbsolutePositioning ,
                                   NULL, AM_SEEKING_NoPositioning);
	if (hr == S_OK)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
*函数介绍：  得到视频文件播放长度,单位秒
*入口参数： dwLength ：视频文件时间长度
*出口参数： dwLength ：视频文件时间长度
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::GetDuration(DWORD &dwLength)
{	
	dwLength = 0;
	if (m_pMS == NULL)
	{
		return FALSE;
	}

	//得到视频总时间长度
	LONGLONG llDuration;
	HRESULT hResult = m_pMS->GetDuration(&llDuration);
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//转换成以秒为单位
	llDuration = llDuration / 10000 ;
	llDuration = llDuration / 1000;
	dwLength  = (DWORD)llDuration;
	return TRUE;
}

/*
*函数介绍：  得到媒体当前播放进度位置,单位秒
*入口参数： dwPos ：当前播放进度，单位秒
*出口参数： dwPos ：当前播放进度，单位秒
*返回值：TRUE:成功;FALSE:失败
*/
BOOL CEricMediaControl::GetCurrentPos(DWORD &dwPos)
{
	dwPos = 0;
	LONGLONG llPos = 0;
	if (m_pMS== NULL)
	{
		return FALSE;
	}
	
	//得到当前视频播放位置
	HRESULT hResult = m_pMS->GetCurrentPosition(&llPos);
	if (hResult != S_OK)
	{
		return FALSE;
	}

	//转换成以秒为单位
	llPos = llPos / 10000 ;
	llPos = llPos / 1000;
	dwPos  = (DWORD)llPos;
	return TRUE;
}