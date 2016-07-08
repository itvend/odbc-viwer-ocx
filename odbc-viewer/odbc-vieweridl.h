

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 08 21:29:50 2016
 */
/* Compiler settings for odbcviewer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __odbc2Dvieweridl_h__
#define __odbc2Dvieweridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___Dodbcviewer_FWD_DEFINED__
#define ___Dodbcviewer_FWD_DEFINED__
typedef interface _Dodbcviewer _Dodbcviewer;

#endif 	/* ___Dodbcviewer_FWD_DEFINED__ */


#ifndef ___DodbcviewerEvents_FWD_DEFINED__
#define ___DodbcviewerEvents_FWD_DEFINED__
typedef interface _DodbcviewerEvents _DodbcviewerEvents;

#endif 	/* ___DodbcviewerEvents_FWD_DEFINED__ */


#ifndef __odbcviewer_FWD_DEFINED__
#define __odbcviewer_FWD_DEFINED__

#ifdef __cplusplus
typedef class odbcviewer odbcviewer;
#else
typedef struct odbcviewer odbcviewer;
#endif /* __cplusplus */

#endif 	/* __odbcviewer_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_odbcviewer_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_odbcviewer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_odbcviewer_0000_0000_v0_0_s_ifspec;


#ifndef __odbcviewerLib_LIBRARY_DEFINED__
#define __odbcviewerLib_LIBRARY_DEFINED__

/* library odbcviewerLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_odbcviewerLib;

#ifndef ___Dodbcviewer_DISPINTERFACE_DEFINED__
#define ___Dodbcviewer_DISPINTERFACE_DEFINED__

/* dispinterface _Dodbcviewer */
/* [uuid] */ 


EXTERN_C const IID DIID__Dodbcviewer;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7BE98449-97C1-4DE3-A46B-6E17FAC2DB41")
    _Dodbcviewer : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DodbcviewerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Dodbcviewer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Dodbcviewer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Dodbcviewer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Dodbcviewer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Dodbcviewer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Dodbcviewer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Dodbcviewer * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DodbcviewerVtbl;

    interface _Dodbcviewer
    {
        CONST_VTBL struct _DodbcviewerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Dodbcviewer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Dodbcviewer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Dodbcviewer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Dodbcviewer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Dodbcviewer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Dodbcviewer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Dodbcviewer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Dodbcviewer_DISPINTERFACE_DEFINED__ */


#ifndef ___DodbcviewerEvents_DISPINTERFACE_DEFINED__
#define ___DodbcviewerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DodbcviewerEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DodbcviewerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("837D500B-1818-4827-B04C-FF027F0FE8DD")
    _DodbcviewerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DodbcviewerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DodbcviewerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DodbcviewerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DodbcviewerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DodbcviewerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DodbcviewerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DodbcviewerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DodbcviewerEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DodbcviewerEventsVtbl;

    interface _DodbcviewerEvents
    {
        CONST_VTBL struct _DodbcviewerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DodbcviewerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DodbcviewerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DodbcviewerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DodbcviewerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DodbcviewerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DodbcviewerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DodbcviewerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DodbcviewerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_odbcviewer;

#ifdef __cplusplus

class DECLSPEC_UUID("C824C924-A567-48C0-B493-61385D9518E7")
odbcviewer;
#endif
#endif /* __odbcviewerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


