// IPC_MSGServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CIPC_MSGServerApp:
// �йش����ʵ�֣������ IPC_MSGServer.cpp
//

class CIPC_MSGServerApp : public CWinApp
{
public:
	CIPC_MSGServerApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIPC_MSGServerApp theApp;
