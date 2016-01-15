// DlgSubmit.cpp : 实现文件
//

#include "stdafx.h"
#include "RDAExam.h"
#include "DlgSubmit.h"


// CDlgSubmit 对话框

IMPLEMENT_DYNAMIC(CDlgSubmit, CDialog)

CDlgSubmit::CDlgSubmit(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSubmit::IDD, pParent)
	, m_internetURL(_T("http://192.168.1.47/sqlce/sqlcesa30.dll"))
	, m_internetUsername(_T(""))
	, m_internetPassword(_T(""))
	, m_connectStr(_T("provider=sqloledb; data source=wang; Initial Catalog=dbtest; user id=sa; password=123456"))
	, m_queryStr(_T("UPDATE SERVERTIME SET CurTime=Getdate()"))
{

}

CDlgSubmit::~CDlgSubmit()
{
}

void CDlgSubmit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_INTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDT_INTERNETUSERNAME, m_internetUsername);
	DDX_Text(pDX, IDC_EDT_INTERNETPASSWORD, m_internetPassword);
	DDX_Text(pDX, IDC_EDT_CONNECTSTR, m_connectStr);
	DDX_Text(pDX, IDC_EDT_QUERYSTR, m_queryStr);
}


BEGIN_MESSAGE_MAP(CDlgSubmit, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CDlgSubmit::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CDlgSubmit::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CDlgSubmit 消息处理程序

void CDlgSubmit::OnBnClickedBtnOk()
{
	OnOK();
}

void CDlgSubmit::OnBnClickedBtnCancel()
{
	OnCancel();
}
