// Simple.h : CSimple µÄÉùÃ÷

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

#include "CEComServer.h"




// CSimple

class ATL_NO_VTABLE CSimple :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSimple, &CLSID_Simple>,
	public IDispatchImpl<ISimple, &IID_ISimple, &LIBID_CEComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSimple()
	{
	}

#ifndef _CE_DCOM
DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLE)
#endif


BEGIN_COM_MAP(CSimple)
	COM_INTERFACE_ENTRY(ISimple)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(ShowSvrMsg)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(Simple), CSimple)
