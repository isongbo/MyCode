#pragma once

#include "..\\..\\ConnectionCom\\ConnectionCom\\ConnectionCom.h"
class CSink :
	public _IAddEvents
{
public:
	CSink(void);
	~CSink(void);
private:
	DWORD       m_dwRefCount;//访问记数变量
public:
	//1、实现_IAddEvents接口的ExecutionOver方法
	STDMETHODIMP ExecutionOver(LONG lResult);

	//2、实现_IAddEvents接口的QueryInterface方法
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void
		**ppvObject);

	//3、实现_IAddEvents接口的AddRef方法
	ULONG STDMETHODCALLTYPE AddRef();

	//4、实现_IAddEvents接口的Release方法
	ULONG STDMETHODCALLTYPE Release();

	//5,实现_IAddEvents接口的Invoke方法
	HRESULT STDMETHODCALLTYPE Invoke( 
		/* [in] */ DISPID dispIdMember,
		/* [in] */ REFIID riid,
		/* [in] */ LCID lcid,
		/* [in] */ WORD wFlags,
		/* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
		/* [out] */ VARIANT __RPC_FAR *pVarResult,
		/* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
		/* [out] */ UINT __RPC_FAR *puArgErr);

	//6,
	HRESULT STDMETHODCALLTYPE GetTypeInfoCount( 
		/* [out] */ UINT __RPC_FAR *pctinfo);

	//7,
	HRESULT STDMETHODCALLTYPE GetTypeInfo( 
		/* [in] */ UINT iTInfo,
		/* [in] */ LCID lcid,
		/* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	//8,
	HRESULT STDMETHODCALLTYPE GetIDsOfNames( 
		/* [in] */ REFIID riid,
		/* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
		/* [in] */ UINT cNames,
		/* [in] */ LCID lcid,
		/* [size_is][out] */ DISPID __RPC_FAR *rgDispId);

};
