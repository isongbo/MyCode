// AsynDll.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "AsynDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//


// CAsynDllApp

BEGIN_MESSAGE_MAP(CAsynDllApp, CWinApp)
END_MESSAGE_MAP()


// CAsynDllApp 构造

CAsynDllApp::CAsynDllApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAsynDllApp 对象

CAsynDllApp theApp;

// CAsynDllApp 初始化

BOOL CAsynDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//定义回调函数
TDataReadNotify DataReadNotify;

//线程处理函数
DWORD DoTheWork(LPVOID lpParameter)
{
  long lDBData;

  Sleep(5000);
  lDBData = Random();
  

  //通知用户，函数执行完成
  if (DataReadNotify != NULL) 
  {
	  //执行回调函数
	  DataReadNotify(lDBData);
  }

  return 0;
};

//查询数据
long ASynDLL_EXPORT_API QueryData(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HANDLE hThread;
	DWORD pThreadId;
	long lProcAdr;
	
	//设置线程函数
	lProcAdr = (long)(&DoTheWork);
	//创建线程，并执行线程
	hThread = CreateThread(NULL, 
		0,
		(LPTHREAD_START_ROUTINE)lProcAdr,
		NULL,
		0,
		&pThreadId);
	
	
	return 0;
};

//设置回调函数指针
long ASynDLL_EXPORT_API SetCallbackProcAddr(long lProcAddress)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long Result = 0;
	
	//设置回调函数
	DataReadNotify = (TDataReadNotify)lProcAddress;
	
	if (DataReadNotify != NULL) 
	{
		Result = 1;
	}
	return Result;
};
