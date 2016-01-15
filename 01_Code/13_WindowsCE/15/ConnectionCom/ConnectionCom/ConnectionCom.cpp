// ConnectionCom.cpp : DLL ������ʵ�֡�


#include "stdafx.h"

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

#include "ConnectionCom.h"


class CConnectionComModule : public CAtlDllModuleT< CConnectionComModule >
{
public :
	DECLARE_LIBID(LIBID_ConnectionComLib)
#ifndef _CE_DCOM
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CONNECTIONCOM, "{E86D0A0D-A2DE-449B-A228-998FD5D6E6F4}")
#endif
};

CConnectionComModule _AtlModule;

class CConnectionComApp : public CWinApp
{
public:

// ��д
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CConnectionComApp, CWinApp)
END_MESSAGE_MAP()

CConnectionComApp theApp;

BOOL CConnectionComApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CConnectionComApp::ExitInstance()
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

