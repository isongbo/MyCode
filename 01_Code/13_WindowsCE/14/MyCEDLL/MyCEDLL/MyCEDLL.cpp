// MyCEDLL.cpp : ���� DLL Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyCEDLL.h"
#include <windows.h>
#include <commctrl.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

// ���ǵ���������һ��ʾ��
MYCEDLL_API int nMyCEDLL=0;

// ���ǵ���������һ��ʾ����
MYCEDLL_API int fnMyCEDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyCEDLL.h
CMyCEDLL::CMyCEDLL()
{ 
	return; 
}

extern "C" MYCEDLL_API void TestDll(void)
{
	MessageBox(NULL,_T("����Ϣ����DLL"),_T("��������DLL"),MB_OK);
}
