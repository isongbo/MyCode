// MyCEActiveX_Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CMyCEActiveX_TestApp:
// �йش����ʵ�֣������ MyCEActiveX_Test.cpp
//

class CMyCEActiveX_TestApp : public CWinApp
{
public:
	CMyCEActiveX_TestApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyCEActiveX_TestApp theApp;
