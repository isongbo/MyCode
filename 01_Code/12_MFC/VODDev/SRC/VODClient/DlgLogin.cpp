// DlgLogin.cpp : implementation file
//

#include "stdafx.h"
#include "VODClient.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog


CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogin)
	m_strPwd = _T("");
	m_strUserName = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogin)
	DDX_Text(pDX, IDC_PASSWORD, m_strPwd);
	DDX_Text(pDX, IDC_USERNAME, m_strUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	//{{AFX_MSG_MAP(CDlgLogin)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin message handlers



void CDlgLogin::OnOK() 
{
	// TODO: Add extra validation here
	//登录验证
    UpdateData(TRUE);
	if(!m_clientSock.Login(m_strUserName,m_strPwd))
	{
        MessageBox("用户名称或密码错误，请重新登录！");
		return;
	}
	CDialog::OnOK();
}
