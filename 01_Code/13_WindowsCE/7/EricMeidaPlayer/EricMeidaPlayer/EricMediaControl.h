/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： EricMediaControl.h
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
#pragma once


#include <dshow.h>

//定义DSHOW 事件通知消息
#define WM_GRAPHNOTIFY  WM_USER + 101

class CEricMediaControl
{
public:
	CEricMediaControl(void);
	~CEricMediaControl(void);

private:
	//DSHOW 接口
	IGraphBuilder *m_pGB ;  
	IMediaControl *m_pMC ;
	IMediaEventEx *m_pME ;
	IVideoWindow  *m_pVW ;
	IBasicAudio *m_pBA ;
	IBasicVideo   *m_pBV ;
	IMediaSeeking *m_pMS ;

	//显示视频的窗口句柄
	HWND m_hOwnerWnd;
private:
	//初始化DSHOW接口
	BOOL InitDShow(LPCTSTR strFileName  /*视频文件名*/
		,HWND hOwnerWnd  /*显示视频的窗口句柄*/
		,HWND hNotifyWnd /*接收DSHOW事件消息的串口句柄*/
		);
	//释放DSHOW接口
	BOOL UnInitDShow();
public:
	//打开视频文件
	BOOL OpenFile(LPCTSTR strFileName /*视频文件名*/
		,HWND hOwnerWnd  /*显示视频的窗口句柄*/
		,HWND hNotifyWnd /*接收DSHOW事件消息的串口句柄*/
		);
	//播放视频
	BOOL VideoRun();
	//暂停视频
	BOOL VideoPause();
	//停止视频
	BOOL VideoStop();
public:
	//设置视频显示比例
	BOOL FitVideoWindow(FLOAT fScale);
	//全屏显示
	BOOL FullScreen();
	//得到是否是全屏显示
	BOOL GetFullScreenStatus();
	//得到DShow播放事件
	BOOL GetMediaEvent(long *lEventCode);
	//设置播放进度，单位: 秒
	BOOL SetPositions(DWORD dwPos /*设置当前播放进度*/);
	//得到视频播放当前的位置，单位：秒
	BOOL GetCurrentPos(DWORD &dwPos  /*out 当前播放进度*/);
	//得到视频文件时间长度，单位：秒
	BOOL GetDuration(DWORD &dwLength);
};
