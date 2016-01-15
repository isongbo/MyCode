/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 24 11:22:16 2008
 */
/* Compiler settings for .\MyCEActiveX.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __MyCEActiveXidl_h__
#define __MyCEActiveXidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef ___DMyCEActiveX_FWD_DEFINED__
#define ___DMyCEActiveX_FWD_DEFINED__
typedef interface _DMyCEActiveX _DMyCEActiveX;
#endif 	/* ___DMyCEActiveX_FWD_DEFINED__ */


#ifndef ___DMyCEActiveXEvents_FWD_DEFINED__
#define ___DMyCEActiveXEvents_FWD_DEFINED__
typedef interface _DMyCEActiveXEvents _DMyCEActiveXEvents;
#endif 	/* ___DMyCEActiveXEvents_FWD_DEFINED__ */


#ifndef __MyCEActiveX_FWD_DEFINED__
#define __MyCEActiveX_FWD_DEFINED__

#ifdef __cplusplus
typedef class MyCEActiveX MyCEActiveX;
#else
typedef struct MyCEActiveX MyCEActiveX;
#endif /* __cplusplus */

#endif 	/* __MyCEActiveX_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __MyCEActiveXLib_LIBRARY_DEFINED__
#define __MyCEActiveXLib_LIBRARY_DEFINED__

/* library MyCEActiveXLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_MyCEActiveXLib;

#ifndef ___DMyCEActiveX_DISPINTERFACE_DEFINED__
#define ___DMyCEActiveX_DISPINTERFACE_DEFINED__

/* dispinterface _DMyCEActiveX */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DMyCEActiveX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8EFBAF8F-968F-48DD-A8AC-882FE457972B")
    _DMyCEActiveX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMyCEActiveXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _DMyCEActiveX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _DMyCEActiveX __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _DMyCEActiveX __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _DMyCEActiveX __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _DMyCEActiveX __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _DMyCEActiveX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _DMyCEActiveX __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _DMyCEActiveXVtbl;

    interface _DMyCEActiveX
    {
        CONST_VTBL struct _DMyCEActiveXVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMyCEActiveX_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DMyCEActiveX_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DMyCEActiveX_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DMyCEActiveX_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DMyCEActiveX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DMyCEActiveX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DMyCEActiveX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMyCEActiveX_DISPINTERFACE_DEFINED__ */


#ifndef ___DMyCEActiveXEvents_DISPINTERFACE_DEFINED__
#define ___DMyCEActiveXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DMyCEActiveXEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DMyCEActiveXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7245A74E-5F56-4EF0-A190-6ED517FEB601")
    _DMyCEActiveXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMyCEActiveXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _DMyCEActiveXEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _DMyCEActiveXEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _DMyCEActiveXEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _DMyCEActiveXEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _DMyCEActiveXEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _DMyCEActiveXEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _DMyCEActiveXEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _DMyCEActiveXEventsVtbl;

    interface _DMyCEActiveXEvents
    {
        CONST_VTBL struct _DMyCEActiveXEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMyCEActiveXEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DMyCEActiveXEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DMyCEActiveXEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DMyCEActiveXEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DMyCEActiveXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DMyCEActiveXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DMyCEActiveXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMyCEActiveXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MyCEActiveX;

#ifdef __cplusplus

class DECLSPEC_UUID("EB53D4D7-35CF-4CE3-8A04-976E59EB359F")
MyCEActiveX;
#endif
#endif /* __MyCEActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
