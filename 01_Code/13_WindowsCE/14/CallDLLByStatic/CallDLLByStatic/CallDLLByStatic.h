// CallDLLByStatic.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CCallDLLByStaticApp:
// �йش����ʵ�֣������ CallDLLByStatic.cpp
//

class CCallDLLByStaticApp : public CWinApp
{
public:
	CCallDLLByStaticApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCallDLLByStaticApp theApp;
