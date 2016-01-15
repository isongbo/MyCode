// FileSendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FeiQ.h"
#include "FileSendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileSendDlg dialog


CFileSendDlg::CFileSendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileSendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileSendDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFileSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileSendDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_wndProgress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileSendDlg, CDialog)
	//{{AFX_MSG_MAP(CFileSendDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileSendDlg message handlers

BOOL CFileSendDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	OnSend( );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFileSendDlg::OnSend() 
{
    if( FALSE == m_FileClient.InitClient( ) )
    {
        AfxMessageBox( "初始化文件客户端失败");
        return;
    }
    //连接服务器
    if( FALSE == m_FileClient.ConnectServer( m_strIP ) )
    {
        AfxMessageBox( "连接失败");
        return;
    }
    //启动发送线程
    AfxBeginThread( SendThread, this );
}

UINT CFileSendDlg::SendThread( LPVOID pParam )
{
    CFileSendDlg * pThis = 
        (CFileSendDlg *)pParam;
    pThis->m_FileClient.SendFile( 
        pThis->m_strFile, 
        &pThis->m_wndProgress );	
    return 0;
}
