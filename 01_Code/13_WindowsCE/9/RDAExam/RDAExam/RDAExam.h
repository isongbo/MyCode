// RDAExam.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CRDAExamApp:
// �йش����ʵ�֣������ RDAExam.cpp
//

class CRDAExamApp : public CWinApp
{
public:
	CRDAExamApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRDAExamApp theApp;
