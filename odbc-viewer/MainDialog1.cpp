// MainDialog1.cpp : implementation file
//

#include "stdafx.h"
#include "odbc-viewer.h"
#include "MainDialog1.h"
#include "afxdialogex.h"

/*
Good people of ethernet code!!!! Ty mate START
*/
wchar_t *strdup(const wchar_t *src)
{
	wchar_t *tmp = (wchar_t *)malloc(wcslen(src)+128);
	if (tmp)
		wcscpy(tmp, src);
	return tmp;
}
void explode(wchar_t *src, const wchar_t *tokens, wchar_t ***list, size_t *len)
{
	if (src == NULL || list == NULL || len == NULL)
		return;


	wchar_t *str, *copy, **_list = NULL, **tmp;
	*list = NULL;
	*len = 0;

	copy = _wcsdup(src);
	if (copy == NULL)
		return;

	str = wcstok(copy, tokens);
	
	if (str == NULL)
		goto free_and_exit;

	_list = (wchar_t **)realloc(NULL, (sizeof *_list)+128);
	if (_list == NULL)
		goto free_and_exit;

	_list[*len] = strdup(str);
	if (_list[*len] == NULL)
		goto free_and_exit;
	(*len)++;


	while ((str = wcstok(NULL, tokens)))
	{
		tmp = (wchar_t **)realloc(_list, (sizeof *_list) * (*len + 128));
		if (tmp == NULL)
			goto free_and_exit;

		_list = tmp;

		_list[*len] = strdup(str);
		if (_list[*len] == NULL)
			goto free_and_exit;
		(*len)++;
	}


free_and_exit:
	*list = _list;
	free(copy);
}

/*
Good people of ethernet code!!!! Ty mate END
*/

// MainDialog1 dialog

IMPLEMENT_DYNAMIC(MainDialog1, CDialog)

MainDialog1::MainDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(MainDialog1::IDD, pParent)
	, dsn(_T(""))
{
	//wchar_t PTR_IDS_STRING2[255];
	//LoadString(NULL, IDS_STRING3, PTR_IDS_STRING2, 255);
	//m_Button1.SetWindowText(PTR_IDS_STRING2);
}

MainDialog1::~MainDialog1()
{
}

void MainDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListView1);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);

}


BEGIN_MESSAGE_MAP(MainDialog1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDialog1::OnBnClickedButton1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// MainDialog1 message handlers



void MainDialog1::OnBnClickedButton1()
{
	MainDialog1::genHeaders();

	m_ListView1.DeleteAllItems();

	int nColumnCount = m_ListView1.GetHeaderCtrl()->GetItemCount();

	int nIndex;

	SQLHENV         henv;
	SQLHDBC         hdbc;
	SQLHSTMT        hstmt;
	SQLRETURN       sqlrc;
	/*wchar_t         sql[1025];*/
	wchar_t         svalue[2049];
	SQLINTEGER      inum;
	SQLSMALLINT     cols;
	int             i;

	//wchar_t            uid[24];
	//wchar_t            pwd[24];
	//wchar_t            dsn[24];

	//CStringW dsn_l = dsn.GetBuffer(0);
	//CStringW sql_l = sql.GetBuffer(0);

	// connection strings
	//wcscpy(dsn, dsn);

	//// SQL strings
	//wcscpy(sql, sql);

	// environment handle

	sqlrc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLAllocHandle SQL_HANDLE_ENV Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLAllocHandle SQL_HANDLE_ENV Error\n");
		//return 9;
	}

	// environment variables settings
	sqlrc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLSetEnvAttr Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLSetEnvAttr Error\n");
		//return 9;
	}

	// connection handle
	sqlrc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLAllocHandle SQL_HANDLE_DBC Erro"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLAllocHandle SQL_HANDLE_DBC Error\n");
		//return 9;
	}

	/*MessageBox(dsn_l.GetString(), TEXT("SQL"), MB_ICONINFORMATION);*/

	// connect
	sqlrc = SQLConnect(hdbc, (SQLWCHAR *)dsn.GetBuffer(0), SQL_NTS, NULL, SQL_NULL_DATA, NULL, SQL_NULL_DATA);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLConnect Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLConnect Error\n");
		//return 9;
	}

	// statement handle
	sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLAllocHandle SQL_HANDLE_STMT Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLAllocHandle SQL_HANDLE_STMT Error\n");
		//return 9;
	}

	/*MessageBox(sql_l.GetString(), TEXT("SQL"), MB_ICONINFORMATION);*/

	// statement prepare
	sqlrc = SQLPrepare(hstmt, (SQLWCHAR *)sql.GetBuffer(0), SQL_NTS);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLPrepare Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLPrepare Error\n");
		//return 9;
	}

	// get result columns
	sqlrc = SQLNumResultCols(hstmt, &cols);
	if (sqlrc != SQL_SUCCESS && sqlrc != SQL_SUCCESS_WITH_INFO) {
		if (!supresserrors){
			MessageBox(TEXT("SQLNumResultCols Error"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
		//printf("SQLNumResultCols Error\n");
		//return 9;
	}

	if (nColumnCount != cols){
		if (!supresserrors){
			MessageBox(TEXT("SQLNumResultCols != listview header count"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
	}
	// execute

	sqlrc = SQLExecDirect(hstmt, (SQLWCHAR *)sql.GetBuffer(0), SQL_NTS);

	while (TRUE) {
		sqlrc = SQLFetch(hstmt);

		if (sqlrc == SQL_SUCCESS || sqlrc == SQL_SUCCESS_WITH_INFO) {

			for (i = 1; i < cols + 1; i++) {

				SQLGetData(hstmt, i, SQL_WCHAR, (SQLWCHAR *)svalue, 2046, &inum);
				/*temporal = svalue;*/
				if (i == 1){
					nIndex = m_ListView1.InsertItem(i - 1, svalue);
				}

				if (i > 1){
					m_ListView1.SetItemText(nIndex, i - 1, svalue);
				}

			}
		}
		else {
			if (sqlrc == SQL_NO_DATA) {
				goto end;
			}
			else {
				if (!supresserrors){
					MessageBox(TEXT("SQLFetch ERROR"), TEXT("Error!"), MB_ICONERROR);
				}
			}
			break;
			
		}

	}
	// free all HSTMT-s
	SQLDisconnect(hdbc);

end:
	{
		dsn.ReleaseBuffer();
		sql.ReleaseBuffer();
		// free handles
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
	}
}

void MainDialog1::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (!m_ListView1.SetWindowPos(NULL, 10, 10, cx - 20, cy - 40, SWP_SHOWWINDOW)){
		return;
	}
	

	CRect rect, rect2;

	m_ListView1.GetWindowRect(&rect2);

	m_Button1.GetWindowRect(&rect);

	if (!m_Button1.SetWindowPos(NULL, 10, (rect2.Height() + 15), rect2.Width(), 20, SWP_SHOWWINDOW)){
		return;
	}

}

void MainDialog1::genHeaders(){

	//LPTSTR pString = rmap.GetBuffer(0);
	//LPTSTR pString2 = rmapw.GetBuffer(0);

	wchar_t **list, **list2;
	size_t len, len2;

	explode(rmap.GetBuffer(0), (const wchar_t *)",", &list, &len);
	explode(rmapw.GetBuffer(0), (const wchar_t *)",", &list2, &len2);

	if (len != len2){
		if (!supresserrors){
			MessageBox(TEXT("listview header count != listview header width count"), TEXT("Error!"), MB_ICONERROR);
		}
		goto end;
	}

	size_t nCol = 0;

	m_ListView1.DeleteAllItems();

	int nColumnCount = m_ListView1.GetHeaderCtrl()->GetItemCount();

	// Delete all of the columns.
	for (int i = 0; i < nColumnCount; i++)
	{
		m_ListView1.DeleteColumn(0);
	}

	for (nCol = 0; nCol < len; nCol++){
		if ( _wtoi(list2[nCol]) != 0 ){
			m_ListView1.InsertColumn(nCol, list[nCol], LVCFMT_LEFT, _wtoi(list2[nCol]));
		}
		else{
			m_ListView1.InsertColumn(nCol, list[nCol], LVCFMT_LEFT, 100);
		}
	}
	goto end;

end:
	{
		size_t i;
		for (i = 0; i < len; ++i)
			free(list[i]);
		free(list);
	
		rmap.ReleaseBuffer();
		rmapw.ReleaseBuffer();
	}
}

//
//vector<string> MainDialog1::explode(const string &delimiter, const string &explodeme){
//	vector<string> arr;
//
//	int strleng = explodeme.length();
//	int delleng = delimiter.length();
//	if (delleng == 0)
//		return arr;//no change
//
//	int i = 0;
//	int k = 0;
//	while (i<strleng)
//	{
//		int j = 0;
//		while (i + j<strleng && j<delleng && explodeme[i + j] == delimiter[j])
//			j++;
//		if (j == delleng)//found delimiter
//		{
//			arr.push_back(explodeme.substr(k, i - k));
//			i += delleng;
//			k = i;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	arr.push_back(explodeme.substr(k, i - k));
//	return arr;
//}
void MainDialog1::CheckForUpdate(){

	//LPTSTR pString = rmap.GetBuffer(0);
	//LPTSTR pString2 = rmapw.GetBuffer(0);

	wchar_t **list, **list2;
	size_t len, len2;

	explode(rmap.GetBuffer(0), (const wchar_t *)",", &list, &len);
	explode(rmapw.GetBuffer(0), (const wchar_t *)",", &list2, &len2);

	if (len == len2 && !dsn.IsEmpty() && !sql.IsEmpty()){

		//MainDialog1::genHeaders();
		MainDialog1::OnBnClickedButton1();

	}

	rmap.ReleaseBuffer();
	rmapw.ReleaseBuffer();

	//pString2 = NULL;
	//pString = NULL;

	size_t i;
	for (i = 0; i < len; ++i)
		free(list[i]);
	free(list);
}