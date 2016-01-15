// DlgPush.cpp : 实现文件
//

#include "stdafx.h"
#include "RDAExam.h"
#include "DlgPush.h"


// CDlgPush 对话框

IMPLEMENT_DYNAMIC(CDlgPush, CDialog)

CDlgPush::CDlgPush(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPush::IDD, pParent)
	, m_internetURL(_T("http://192.168.1.47/sqlce/sqlcesa30.dll"))
	, m_internetUsername(_T(""))
	, m_internetPassword(_T(""))
	, m_connectStr(_T("provider=sqloledb; data source=wang; Initial Catalog=dbtest; user id=sa; password=123456"))
	, m_localConnectStr(_T("Provider=microsoft.sqlserver.oledb.ce.3.0;Data Source=\\My Documents\\DB_Students.sdf"))
	, m_localTableName(_T("students"))
{

}

CDlgPush::~CDlgPush()
{
}

void CDlgPush::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_INTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDT_INTERNETUSERNAME, m_internetUsername);
	DDX_Text(pDX, IDC_EDT_INTERNETPASSWORD, m_internetPassword);
	DDX_Text(pDX, IDC_EDT_CONNECTSTR, m_connectStr);
	DDX_Text(pDX, IDC_EDT_LOCALCONNECTSTR, m_localConnectStr);
	DDX_Text(pDX, IDC_EDT_LOCALTABLENAME, m_localTableName);
}


BEGIN_MESSAGE_MAP(CDlgPush, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CDlgPush::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CDlgPush::OnBnClickedBtnCancel)
END_MESSAGE_MAP()




//ok
void CDlgPush::OnBnClickedBtnOk()
{
	OnOK();
}

//cancel
void CDlgPush::OnBnClickedBtnCancel()
{
	OnCancel();
}
