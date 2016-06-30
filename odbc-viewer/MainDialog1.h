#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#include    <sql.h>
#include    <sqlext.h>
#include    <sqltypes.h>
#include    <stdio.h>

using namespace std;

// MainDialog1 dialog

class MainDialog1 : public CDialog
{
	DECLARE_DYNAMIC(MainDialog1)

public:
	MainDialog1(CWnd* pParent = NULL);   // standard constructor
	virtual ~MainDialog1();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	/*vector<string> explode(const string &delimiter, const string &explodeme);*/
	void genHeaders();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_EditBox1;
	CEdit m_EditBox11;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CListCtrl m_ListView1;
	CButton m_Button1;

	CString dsn;
	CString rmap;
	CString rmapw;
	CString sql;

	short supresserrors;

	void CheckForUpdate();
};
