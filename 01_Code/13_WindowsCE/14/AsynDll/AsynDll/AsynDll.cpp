// AsynDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AsynDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CAsynDllApp

BEGIN_MESSAGE_MAP(CAsynDllApp, CWinApp)
END_MESSAGE_MAP()


// CAsynDllApp ����

CAsynDllApp::CAsynDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAsynDllApp ����

CAsynDllApp theApp;

// CAsynDllApp ��ʼ��

BOOL CAsynDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//����ص�����
TDataReadNotify DataReadNotify;

//�̴߳�����
DWORD DoTheWork(LPVOID lpParameter)
{
  long lDBData;

  Sleep(5000);
  lDBData = Random();
  

  //֪ͨ�û�������ִ�����
  if (DataReadNotify != NULL) 
  {
	  //ִ�лص�����
	  DataReadNotify(lDBData);
  }

  return 0;
};

//��ѯ����
long ASynDLL_EXPORT_API QueryData(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HANDLE hThread;
	DWORD pThreadId;
	long lProcAdr;
	
	//�����̺߳���
	lProcAdr = (long)(&DoTheWork);
	//�����̣߳���ִ���߳�
	hThread = CreateThread(NULL, 
		0,
		(LPTHREAD_START_ROUTINE)lProcAdr,
		NULL,
		0,
		&pThreadId);
	
	
	return 0;
};

//���ûص�����ָ��
long ASynDLL_EXPORT_API SetCallbackProcAddr(long lProcAddress)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long Result = 0;
	
	//���ûص�����
	DataReadNotify = (TDataReadNotify)lProcAddress;
	
	if (DataReadNotify != NULL) 
	{
		Result = 1;
	}
	return Result;
};
