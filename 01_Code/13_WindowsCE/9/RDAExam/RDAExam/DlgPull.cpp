// DlgPull.cpp : 实现文件
//

#include "stdafx.h"
#include "RDAExam.h"
#include "DlgPull.h"


// CDlgPull 对话框

IMPLEMENT_DYNAMIC(CDlgPull, CDialog)

CDlgPull::CDlgPull(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPull::IDD, pParent)
	, m_internetURL(_T("http://192.168.1.47/sqlce/sqlcesa30.dll"))
	, m_internetUsername(_T(""))
	, m_internetPassword(_T(""))
	, m_tracking(_T(""))
	, m_errorTableName(_T("tblErrors"))
	, m_connectStr(_T("provider=sqloledb; data source=wang; Initial Catalog=dbtest; user id=sa; password=123456"))
	, m_localConnectStr(_T("Provider=microsoft.sqlserver.oledb.ce.3.0;Data Source=\\My Documents\\DB_Students.sdf"))
	, m_localTableName(_T("students"))
	, m_queryStr(_T("select * from students"))
{
	//
}

CDlgPull::~CDlgPull()
{
}

void CDlgPull::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_INTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDT_INTERNETUSERNAME, m_internetUsername);
	DDX_Text(pDX, IDC_EDT_INTERNETPASSWORD, m_internetPassword);
	DDX_CBString(pDX, IDC_CMB_TRACKING, m_tracking);
	DDX_Text(pDX, IDC_EDT_ERRORTABLENAME, m_errorTableName);
	DDX_Text(pDX, IDC_EDT_CONNECTSTR, m_connectStr);
	DDX_Text(pDX, IDC_EDT_LOCALCONNECTSTR, m_localConnectStr);
	DDX_Text(pDX, IDC_EDT_LOCALTABLENAME, m_localTableName);
	DDX_Text(pDX, IDC_EDT_QUERYSTR, m_queryStr);
}


BEGIN_MESSAGE_MAP(CDlgPull, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CDlgPull::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CDlgPull::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CDlgPull 消息处理程序

//
void CDlgPull::OnBnClickedBtnOk()
{
	OnOK();
}

//
void CDlgPull::OnBnClickedBtnCancel()
{
	OnCancel();
}
