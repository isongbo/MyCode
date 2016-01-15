/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： EricCamera.h
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
	//-----DSHOW接口-----------
	//视频捕捉图形管理器接口
	CComPtr<ICaptureGraphBuilder2>	m_pCaptureGraphBuilder;
	//图形管理器接口
	CComPtr<IGraphBuilder>			m_pGraphBuilder;
	//视频捕捉过滤器
	CComPtr<IBaseFilter>			m_pVideoCaptureFilter;
	//视频设备属性页
	CComPtr<IPersistPropertyBag>    m_pPropertyBag ;
	//静态捕捉PIN过滤器
	CComPtr<IBaseFilter>	        m_pImageSinkFilter;
	//媒体播放控制器
	CComPtr<IMediaControl>			m_pMediaControl  ;
	//视频窗口接口
	CComPtr<IVideoWindow>			m_pVideoWindow ;
	//视频播放进度控制接口
	CComPtr<IMediaSeeking>			m_pMediaSeeking;
	//媒体事件接口
	CComPtr<IMediaEvent>			m_pMediaEvent;

public:
	//释放DSHOW接口
	void FreeDShow();
public:
	//查找第1个摄像头设备名
	BOOL GetFirstCameraDriver( WCHAR *pwzName );
public:
	//预览视频
	BOOL PreviewCamera(HWND hVideoWnd /*视频显示窗口*/
		,LPCTSTR strFileName /*录像文件名*/);

public:
	//开始录像
	BOOL StartRecord();

	//停止录像
	BOOL StopRecord();
public:
	//抓拍
	BOOL SnapPicture(LPCTSTR strFileName /*图象文件名，格式为JPG*/);
};
