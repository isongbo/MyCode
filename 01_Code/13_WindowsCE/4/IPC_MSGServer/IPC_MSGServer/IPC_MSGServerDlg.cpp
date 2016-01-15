// IPC_MSGServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPC_MSGServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MSGServerDlg 对话框

CIPC_MSGServerDlg::CIPC_MSGServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MSGServerDlg::IDD, pParent)
	, m_SessionName(_T(""))
	, m_SendData(_T(""))
	, m_RecvData(_T(""))
	, m_Status(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MSGServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDTSESSIONNAME, m_SessionName);
	DDX_Text(pDX, IDC_EDTSEND, m_SendData);
	DDX_Text(pDX, IDC_EDTRECV, m_RecvData);
	DDX_Text(pDX, IDC_STATICSTATUS, m_Status);
}

BEGIN_MESSAGE_MAP(CIPC_MSGServerDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNOPEN, &CIPC_MSGServerDlg::OnBnClickedBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, &CIPC_MSGServerDlg::OnBnClickedBtnclose)
	ON_BN_CLICKED(IDC_BTNSENDDATA, &CIPC_MSGServerDlg::OnBnClickedBtnsenddata)
END_MESSAGE_MAP()


// CIPC_MSGServerDlg 消息处理程序

BOOL CIPC_MSGServerDlg::OnInitDialog()
{
	//禁止程序全屏
	m_bFullScreen = false;

	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	if (!m_IPCServer.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("创建进程通讯服务器类失败"));
	}

	m_IPCServer.m_ServerConnected = OnServerConnected;
	m_IPCServer.m_ServerDisConnected = OnServerDisConnected;
	m_IPCServer.m_ServerDataArrive = OnServerDataArrive;

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CIPC_MSGServerDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_IPC_MSGSERVER_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_IPC_MSGSERVER_DIALOG));
	}
}
#endif

/*
*函数介绍：服务器连接事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 客户端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_ClientWnd = hWnd;
   pDlg->m_Status = _T("连接状态：连接成功");
   pDlg->UpdateData(FALSE);
}

/*
*函数介绍：服务器断开连接事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 客户端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerDisConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_Status = _T("连接状态：连接不成功");
   pDlg->UpdateData(FALSE);  
}

/*
*函数介绍：服务器接收数据事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           pData : 接收数据指针
		   bufLen : 接收数据长度
           hWnd : 客户端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerDataArrive(CWnd* parentWnd
													,LPVOID pData,DWORD bufLen,HWND hWnd)
{
   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   
   pDlg->m_RecvData = LPCTSTR(pData);
   pDlg->UpdateData(FALSE);
}




/*
*函数介绍：监听按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnopen()
{
	UpdateData(TRUE);
	m_IPCServer.m_SessionName = m_SessionName;
	m_IPCServer.Open(this);
}

/*
*函数介绍：关闭按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnclose()
{
   m_IPCServer.Close();	
}

/*
*函数介绍：发送数据按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnsenddata()
{
   UpdateData(TRUE);
   m_IPCServer.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_ClientWnd,m_SendData.GetLength()*2);
}
