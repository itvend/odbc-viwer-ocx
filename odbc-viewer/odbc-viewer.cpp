// odbc-viewer.cpp : Implementation of CodbcviewerApp and DLL registration.

#include "stdafx.h"
#include "odbc-viewer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CodbcviewerApp theApp;

const GUID CDECL _tlid = { 0x873EAFF7, 0x7237, 0x498D, { 0xA6, 0xB4, 0x2C, 0x83, 0xC8, 0xBE, 0x8E, 0x70 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CodbcviewerApp::InitInstance - DLL initialization

BOOL CodbcviewerApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CodbcviewerApp::ExitInstance - DLL termination

int CodbcviewerApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
