// EDB_Sample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CEDB_SampleApp:
// �йش����ʵ�֣������ EDB_Sample.cpp
//

class CEDB_SampleApp : public CWinApp
{
public:
	CEDB_SampleApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEDB_SampleApp theApp;
