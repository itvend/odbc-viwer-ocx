#pragma once

// odbc-viewerCtrl.h : Declaration of the CodbcviewerCtrl ActiveX Control class.

#include "MainDialog1.h"

// CodbcviewerCtrl : See odbc-viewerCtrl.cpp for implementation.

class CodbcviewerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CodbcviewerCtrl)

// Constructor
public:
	CodbcviewerCtrl();
	MainDialog1 m_mainDialog1;

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// Implementation
protected:
	~CodbcviewerCtrl();

	DECLARE_OLECREATE_EX(CodbcviewerCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CodbcviewerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CodbcviewerCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CodbcviewerCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		dispidUpdateLVExtended = 8L,
		dispidUpdateLV = 7L,
		dispidUpdate = 6,
		dispidsupresserrors = 5,
		dispidsqlquery = 4,
		dispidcolremapwith = 3,
		dispidcolremap = 2,
		dispidSQLQuery = 4,
		dispidColumnremapWith = 3,
		dispidColumnremap = 2,
		dispidodbcdnsname = 1
	};
protected:
	BSTR Getodbcdnsname();
	void Setodbcdnsname(LPCTSTR newVal);
public:
	CString gstrResult;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	BSTR Getcolremap();
	void Setcolremap(LPCTSTR newVal);
	BSTR Getcolremapwith();
	void Setcolremapwith(LPCTSTR newVal);
	BSTR Getsqlquery();
	void Setsqlquery(LPCTSTR newVal);
	void OnsupresserrorsChanged();
	VARIANT_BOOL m_supresserrors;
	void OnUpdateChanged();
	LONG m_Update;
	LONGLONG UpdateLV();
	void UpdateLVExtended(LPCTSTR dsn, LPCTSTR sql, LPCTSTR colmap, LPCTSTR colmapw, VARIANT_BOOL supresserrors);
};

