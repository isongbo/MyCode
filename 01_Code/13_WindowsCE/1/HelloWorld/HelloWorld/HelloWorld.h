// HelloWorld.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CHelloWorldApp:
// �йش����ʵ�֣������ HelloWorld.cpp
//

class CHelloWorldApp : public CWinApp
{
public:
	CHelloWorldApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHelloWorldApp theApp;
