// Draw2DGraph.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CDraw2DGraphApp:
// �йش����ʵ�֣������ Draw2DGraph.cpp
//

class CDraw2DGraphApp : public CWinApp
{
public:
	CDraw2DGraphApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDraw2DGraphApp theApp;
