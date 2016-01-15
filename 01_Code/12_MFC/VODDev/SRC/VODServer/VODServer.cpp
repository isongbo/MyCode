// VODServer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VODServer.h"

#include "MainFrm.h"
#include "VODServerDoc.h"
#include "VODServerView.h"
#include "UserManager.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODServerApp

BEGIN_MESSAGE_MAP(CVODServerApp, CWinApp)
	//{{AFX_MSG_MAP(CVODServerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODServerApp construction

CVODServerApp::CVODServerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVODServerApp object

CVODServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVODServerApp initialization

BOOL CVODServerApp::InitInstance()
{
	
	//COM库的初始化
	CoInitialize(NULL);
	//socket库的初始化
	if(!AfxSocketInit())
		AfxMessageBox("Failed to Initialize Sockets",MB_OK| MB_ICONSTOP);
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CVODServerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CVODServerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
    //加载皮肤
	VERIFY( 1 == InitSkinMagicLib(AfxGetInstanceHandle(), NULL, NULL, NULL));
	VERIFY( 1 == LoadSkinFile(_T("./skin/xpsteel.smf")));
	VERIFY( 1 == SetWindowSkin( m_pMainWnd->m_hWnd , _T("MainFrame") ));
    VERIFY( 1 == SetDialogSkin( _T("Dialog") ) );

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CVODServerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CVODServerApp message handlers


int CVODServerApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	ExitSkinMagicLib();
	CoUninitialize();
	return CWinApp::ExitInstance();
}
#include "UserManager.h"
void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	//测试
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CUserManager userMgr(&pWnd->m_adoConnection);
    CUser user;
	user.strUserName="admin";
	user.strPwd="456";
	user.fBalance=0;
	user.strRemark="";
	userMgr.InsertUser(user);
	MessageBox("插入成功！");
	/*
	if(userMgr.ValidateUser(user))
	{
		MessageBox("登录成功！");
	}
	else
	{
		MessageBox("登录失败！");

	}
	*/
	CDialog::OnOK();
}
