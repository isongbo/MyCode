// SpeciallyEffect.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CSpeciallyEffectApp:
// �йش����ʵ�֣������ SpeciallyEffect.cpp
//

class CSpeciallyEffectApp : public CWinApp
{
public:
	CSpeciallyEffectApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSpeciallyEffectApp theApp;
