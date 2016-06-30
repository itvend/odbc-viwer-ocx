#pragma once

// odbc-viewerPropPage.h : Declaration of the CodbcviewerPropPage property page class.


// CodbcviewerPropPage : See odbc-viewerPropPage.cpp for implementation.

class CodbcviewerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CodbcviewerPropPage)
	DECLARE_OLECREATE_EX(CodbcviewerPropPage)

// Constructor
public:
	CodbcviewerPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_ODBCVIEWER };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

