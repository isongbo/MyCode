// MyCEActiveX.cpp : CMyCEActiveXApp �� DLL ע���ʵ�֡�

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



// CMyCEActiveXApp::InitInstance - DLL ��ʼ��

BOOL CMyCEActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CMyCEActiveXApp::ExitInstance - DLL ��ֹ

int CMyCEActiveXApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
