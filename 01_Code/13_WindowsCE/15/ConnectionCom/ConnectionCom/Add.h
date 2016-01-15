// Add.h : CAdd µÄÉùÃ÷

#pragma once
#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif
#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif
#ifdef SMARTPHONE2003_UI_MODEL
#include "resourcesp.h"
#endif
#ifdef AYGSHELL_UI_MODEL
#include "resourceayg.h"
#endif

#include "ConnectionCom.h"
#include "_IAddEvents_CP.h"




// CAdd

class ATL_NO_VTABLE CAdd :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CAdd, &CLSID_Add>,
	public IConnectionPointContainerImpl<CAdd>,
	public CProxy_IAddEvents<CAdd>,
	public IDispatchImpl<IAdd, &IID_IAdd, &LIBID_ConnectionComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAdd()
	{
	}

#ifndef _CE_DCOM
DECLARE_REGISTRY_RESOURCEID(IDR_ADD)
#endif


BEGIN_COM_MAP(CAdd)
	COM_INTERFACE_ENTRY(IAdd)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CAdd)
	CONNECTION_POINT_ENTRY(__uuidof(_IAddEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(Add)(LONG a, LONG b);
};

OBJECT_ENTRY_AUTO(__uuidof(Add), CAdd)
