// HelloWorld.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CHelloWorldApp:
// 有关此类的实现，请参阅 HelloWorld.cpp
//

class CHelloWorldApp : public CWinApp
{
public:
	CHelloWorldApp();
	
// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CHelloWorldApp theApp;
