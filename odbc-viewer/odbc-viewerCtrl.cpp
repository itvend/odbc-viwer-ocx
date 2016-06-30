// odbc-viewerCtrl.cpp : Implementation of the CodbcviewerCtrl ActiveX Control class.

#include "stdafx.h"
#include "odbc-viewer.h"
#include "odbc-viewerCtrl.h"
#include "odbc-viewerPropPage.h"
#include "afxdialogex.h"

#include "resource.h"

#include "MainDialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CodbcviewerCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CodbcviewerCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CodbcviewerCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CodbcviewerCtrl, COleControl)
	DISP_FUNCTION_ID(CodbcviewerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_EX_ID(CodbcviewerCtrl, "odbcdnsname", dispidodbcdnsname, Getodbcdnsname, Setodbcdnsname, VT_BSTR)
	DISP_PROPERTY_EX_ID(CodbcviewerCtrl, "colremap", dispidcolremap, Getcolremap, Setcolremap, VT_BSTR)
	DISP_PROPERTY_EX_ID(CodbcviewerCtrl, "colremapwith", dispidcolremapwith, Getcolremapwith, Setcolremapwith, VT_BSTR)
	DISP_PROPERTY_EX_ID(CodbcviewerCtrl, "sqlquery", dispidsqlquery, Getsqlquery, Setsqlquery, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CodbcviewerCtrl, "supresserrors", dispidsupresserrors, m_supresserrors, OnsupresserrorsChanged, VT_BOOL)
	DISP_STOCKFUNC_REFRESH()
	DISP_PROPERTY_NOTIFY_ID(CodbcviewerCtrl, "Update", dispidUpdate, m_Update, OnUpdateChanged, VT_I4)
	DISP_FUNCTION_ID(CodbcviewerCtrl, "UpdateLV", dispidUpdateLV, UpdateLV, VT_I8, VTS_NONE)
	DISP_FUNCTION_ID(CodbcviewerCtrl, "UpdateLVExtended", dispidUpdateLVExtended, UpdateLVExtended, VT_EMPTY, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CodbcviewerCtrl, COleControl)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CodbcviewerCtrl, 1)
	PROPPAGEID(CodbcviewerPropPage::guid)
END_PROPPAGEIDS(CodbcviewerCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CodbcviewerCtrl, "ODBCVIEWER.odbcviewerCtrl.1",
	0xc824c924, 0xa567, 0x48c0, 0xb4, 0x93, 0x61, 0x38, 0x5d, 0x95, 0x18, 0xe7)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CodbcviewerCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_Dodbcviewer = { 0x7BE98449, 0x97C1, 0x4DE3, { 0xA4, 0x6B, 0x6E, 0x17, 0xFA, 0xC2, 0xDB, 0x41 } };
const IID IID_DodbcviewerEvents = { 0x837D500B, 0x1818, 0x4827, { 0xB0, 0x4C, 0xFF, 0x2, 0x7F, 0xF, 0xE8, 0xDD } };

// Control type information

static const DWORD _dwodbcviewerOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CodbcviewerCtrl, IDS_ODBCVIEWER, _dwodbcviewerOleMisc)

// CodbcviewerCtrl::CodbcviewerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CodbcviewerCtrl

BOOL CodbcviewerCtrl::CodbcviewerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ODBCVIEWER,
			IDB_ODBCVIEWER,
			afxRegApartmentThreading,
			_dwodbcviewerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CodbcviewerCtrl::CodbcviewerCtrl - Constructor

CodbcviewerCtrl::CodbcviewerCtrl()
{
	InitializeIIDs(&IID_Dodbcviewer, &IID_DodbcviewerEvents);
	// TODO: Initialize your control's instance data here.
}

// CodbcviewerCtrl::~CodbcviewerCtrl - Destructor

CodbcviewerCtrl::~CodbcviewerCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CodbcviewerCtrl::OnDraw - Drawing function

void CodbcviewerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	CBrush brBackGnd(TranslateColor(AmbientBackColor()));
	pdc->FillRect(rcBounds, &brBackGnd);
	
	m_mainDialog1.MoveWindow(rcBounds, TRUE);

	DoSuperclassPaint(pdc, rcBounds);
}

int CodbcviewerCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_mainDialog1.Create(IDD_DIALOG1, this);

	return 0;
}

// CodbcviewerCtrl::DoPropExchange - Persistence support

void CodbcviewerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CodbcviewerCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
DWORD CodbcviewerCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control will not be redrawn when making the transition
	// between the active and inactivate state.
	dwFlags |= noFlickerActivate;
	return dwFlags;
}


// CodbcviewerCtrl::OnResetState - Reset control to default state

void CodbcviewerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CodbcviewerCtrl::AboutBox - Display an "About" box to the user

void CodbcviewerCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ODBCVIEWER);
	dlgAbout.DoModal();
}


// CodbcviewerCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CodbcviewerCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("STATIC");
	return COleControl::PreCreateWindow(cs);
}

// CodbcviewerCtrl::IsSubclassedControl - This is a subclassed control

BOOL CodbcviewerCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CodbcviewerCtrl::OnOcmCommand - Handle command messages

LRESULT CodbcviewerCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO: Switch on wNotifyCode here.

	return 0;
}


// CodbcviewerCtrl message handlers


BSTR CodbcviewerCtrl::Getodbcdnsname()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	/*m_mainDialog1.m_EditBox11.GetWindowTextW(strResult);*/

	strResult = gstrResult;
	
	return strResult.AllocSysString();
}


void CodbcviewerCtrl::Setodbcdnsname(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	m_mainDialog1.dsn = newVal;

	/*m_mainDialog1.CheckForUpdate();*/

	SetModifiedFlag();
}

BSTR CodbcviewerCtrl::Getcolremap()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}


void CodbcviewerCtrl::Setcolremap(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.rmap = newVal;

	/*m_mainDialog1.CheckForUpdate();*/

	SetModifiedFlag();
}


BSTR CodbcviewerCtrl::Getcolremapwith()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}


void CodbcviewerCtrl::Setcolremapwith(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.rmapw = newVal;

	/*m_mainDialog1.CheckForUpdate();*/

	SetModifiedFlag();
}


BSTR CodbcviewerCtrl::Getsqlquery()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	return strResult.AllocSysString();
}


void CodbcviewerCtrl::Setsqlquery(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.sql.Preallocate(4 * 255);

	m_mainDialog1.sql = newVal;
	
	/*prob some timing errors gona come out of the wood work*/
	/*m_mainDialog1.CheckForUpdate();*/

	SetModifiedFlag();
}


void CodbcviewerCtrl::OnsupresserrorsChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.supresserrors = m_supresserrors;

	SetModifiedFlag();
}


void CodbcviewerCtrl::OnUpdateChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.CheckForUpdate();

	SetModifiedFlag();
}


LONGLONG CodbcviewerCtrl::UpdateLV()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_mainDialog1.CheckForUpdate();
	return 0;
}


void CodbcviewerCtrl::UpdateLVExtended(LPCTSTR dsn, LPCTSTR sql, LPCTSTR colmap, LPCTSTR colmapw, VARIANT_BOOL supresserrors)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_mainDialog1.dsn = dsn;
	m_mainDialog1.sql = sql;

	m_mainDialog1.rmap = colmap;
	m_mainDialog1.rmapw = colmapw;

	m_mainDialog1.supresserrors = supresserrors;

	m_mainDialog1.CheckForUpdate();

}
