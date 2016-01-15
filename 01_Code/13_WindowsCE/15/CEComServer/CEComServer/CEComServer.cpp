// CEComServer.cpp : DLL ������ʵ�֡�


#include "stdafx.h"

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

#include "CEComServer.h"


class CCEComServerModule : public CAtlDllModuleT< CCEComServerModule >
{
public :
	DECLARE_LIBID(LIBID_CEComServerLib)
#ifndef _CE_DCOM
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CECOMSERVER, "{BD0F5E12-B390-4867-8FC7-9D386630050D}")
#endif
};

CCEComServerModule _AtlModule;

class CCEComServerApp : public CWinApp
{
public:

// ��д
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCEComServerApp, CWinApp)
END_MESSAGE_MAP()

CCEComServerApp theApp;

BOOL CCEComServerApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CCEComServerApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// ����ȷ�� DLL �Ƿ���� OLE ж��
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// ����һ���๤���Դ������������͵Ķ���
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - ������ӵ�ϵͳע���
STDAPI DllRegisterServer(void)
{
    // ע��������Ϳ�����Ϳ��е����нӿ�
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - �����ϵͳע������Ƴ�
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer(FALSE);
	return hr;
}

