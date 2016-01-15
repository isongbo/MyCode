#pragma once

#include "..\\..\\ConnectionCom\\ConnectionCom\\ConnectionCom.h"
class CSink :
	public _IAddEvents
{
public:
	CSink(void);
	~CSink(void);
private:
	DWORD       m_dwRefCount;//���ʼ�������
public:
	//1��ʵ��_IAddEvents�ӿڵ�ExecutionOver����
	STDMETHODIMP ExecutionOver(LONG lResult);

	//2��ʵ��_IAddEvents�ӿڵ�QueryInterface����
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void
		**ppvObject);

	//3��ʵ��_IAddEvents�ӿڵ�AddRef����
	ULONG STDMETHODCALLTYPE AddRef();

	//4��ʵ��_IAddEvents�ӿڵ�Release����
	ULONG STDMETHODCALLTYPE Release();

	//5,ʵ��_IAddEvents�ӿڵ�Invoke����
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
