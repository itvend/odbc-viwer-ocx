// odbc-viewerPropPage.cpp : Implementation of the CodbcviewerPropPage property page class.

#include "stdafx.h"
#include "odbc-viewer.h"
#include "odbc-viewerPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CodbcviewerPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CodbcviewerPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CodbcviewerPropPage, "ODBCVIEWER.odbcviewerPropPage.1",
	0x1ee0ad25, 0x2c9f, 0x4a42, 0x83, 0xa2, 0xfc, 0xe7, 0xf6, 0xcc, 0x27, 0x91)

// CodbcviewerPropPage::CodbcviewerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CodbcviewerPropPage

BOOL CodbcviewerPropPage::CodbcviewerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ODBCVIEWER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CodbcviewerPropPage::CodbcviewerPropPage - Constructor

CodbcviewerPropPage::CodbcviewerPropPage() :
	COlePropertyPage(IDD, IDS_ODBCVIEWER_PPG_CAPTION)
{
}

// CodbcviewerPropPage::DoDataExchange - Moves data between page and properties

void CodbcviewerPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CodbcviewerPropPage message handlers
