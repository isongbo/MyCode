// MyCEActiveX.cpp : CMyCEActiveXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "MyCEActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMyCEActiveXApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x9778890F, 0xD6D3, 0x4CAC, { 0x8F, 0x75, 0xC4, 0x86, 0xCA, 0xA5, 0x19, 0xB1 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMyCEActiveXApp::InitInstance - DLL 初始化

BOOL CMyCEActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMyCEActiveXApp::ExitInstance - DLL 终止

int CMyCEActiveXApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
