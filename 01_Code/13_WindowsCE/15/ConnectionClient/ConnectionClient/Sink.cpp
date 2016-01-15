#include "StdAfx.h"
#include "Sink.h"


const IID IID_IAdd = {0x7C20780D,0x056A,0x4B4C,{0xA0,0xCB,0x0E,0x11,0x0F,0x5C,0x68,0xCF}};


const IID LIBID_ConnectionComLib = {0x6C01534B,0x653C,0x435B,{0x8A,0x8A,0xC2,0x6B,0xC7,0x7D,0xA6,0x5F}};


const IID DIID__IAddEvents = {0x6D98CC76,0xF53F,0x4DC3,{0xA0,0xF1,0x69,0x15,0x15,0x0B,0xEF,0xED}};


const CLSID CLSID_Add = {0x16753E3A,0x3279,0x4704,{0xA0,0x5B,0x44,0xDA,0xA9,0x4A,0x5C,0x9C}};

CSink::CSink(void)
{
	 m_dwRefCount =0;
}

CSink::~CSink(void)
{
}

//1、实现_IAddEvents接口的ExecutionOver方法
STDMETHODIMP CSink::ExecutionOver(LONG lResult)
{
	CString strTemp;
	strTemp.Format(L"结果是: %d", lResult);
	AfxMessageBox(strTemp);
	return S_OK;;
};

//2、实现_IAddEvents接口的QueryInterface方法
HRESULT STDMETHODCALLTYPE CSink::QueryInterface(REFIID iid, void
												**ppvObject)
{
	if (iid == DIID__IAddEvents)
	{
		m_dwRefCount++;
		*ppvObject = (void *)this;
		return S_OK;
	}
	if (iid == IID_IUnknown)
	{
		m_dwRefCount++;
		*ppvObject = (void *)this;
		return S_OK;
	}
	return E_NOINTERFACE;
}

//3、实现_IAddEvents接口的AddRef方法
ULONG STDMETHODCALLTYPE CSink::AddRef()
{
	m_dwRefCount++;
	return m_dwRefCount;
}

//4、实现_IAddEvents接口的Release方法
ULONG STDMETHODCALLTYPE CSink::Release()
{
	ULONG l;
	l  = m_dwRefCount--;
	if ( 0 == m_dwRefCount)
		delete this;

	return l;
}

//5,实现Invoke方法
HRESULT STDMETHODCALLTYPE CSink::Invoke( 
	/* [in] */ DISPID dispIdMember,
	/* [in] */ REFIID riid,
	/* [in] */ LCID lcid,
	/* [in] */ WORD wFlags,
	/* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
	/* [out] */ VARIANT __RPC_FAR *pVarResult,
	/* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
	/* [out] */ UINT __RPC_FAR *puArgErr)
{
	switch (dispIdMember)
	{
	//ExecutionOver方法
	case 1:
		{
			LONG lResult = (pDispParams->rgvarg)->lVal;
			ExecutionOver(lResult);
		}
		break;
	default:
		return DISP_E_BADINDEX;
	}
}


HRESULT STDMETHODCALLTYPE CSink::GetTypeInfoCount( 
	/* [out] */ UINT __RPC_FAR *pctinfo)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CSink::GetTypeInfo( 
	/* [in] */ UINT iTInfo,
	/* [in] */ LCID lcid,
	/* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CSink::GetIDsOfNames( 
	/* [in] */ REFIID riid,
	/* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
	/* [in] */ UINT cNames,
	/* [in] */ LCID lcid,
	/* [size_is][out] */ DISPID __RPC_FAR *rgDispId)
{
	return S_OK;
}
