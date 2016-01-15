// AsynDll.h : AsynDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// CAsynDllApp
// �йش���ʵ�ֵ���Ϣ������� AsynDll.cpp
//

//����DLL������������
#define ASynDLL_EXPORT_API __declspec(dllexport)

//����Dll����
extern "C" 
{
	//��ѯ���ݣ��첽����
	long ASynDLL_EXPORT_API QueryData(void); 
	//���ûص�����
    long ASynDLL_EXPORT_API SetCallbackProcAddr(long); 
}

//����ص���������
typedef void (* TDataReadNotify)(long);


class CAsynDllApp : public CWinApp
{
public:
	CAsynDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

