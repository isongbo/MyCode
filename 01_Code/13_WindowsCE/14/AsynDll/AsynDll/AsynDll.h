// AsynDll.h : AsynDll DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CAsynDllApp
// 有关此类实现的信息，请参阅 AsynDll.cpp
//

//定义DLL函数导出类型
#define ASynDLL_EXPORT_API __declspec(dllexport)

//导出Dll函数
extern "C" 
{
	//查询数据，异步方法
	long ASynDLL_EXPORT_API QueryData(void); 
	//设置回调函数
    long ASynDLL_EXPORT_API SetCallbackProcAddr(long); 
}

//定义回调函数类型
typedef void (* TDataReadNotify)(long);


class CAsynDllApp : public CWinApp
{
public:
	CAsynDllApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

