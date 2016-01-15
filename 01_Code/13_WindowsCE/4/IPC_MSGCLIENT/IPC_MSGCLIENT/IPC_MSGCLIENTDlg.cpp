// IPC_MSGCLIENTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MSGCLIENT.h"
#include "IPC_MSGCLIENTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MSGCLIENTDlg 对话框

CIPC_MSGCLIENTDlg::CIPC_MSGCLIENTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MSGCLIENTDlg::IDD, pParent)
	, m_SessionName(_T(""))
	, m_SendData(_T(""))
	, m_RecvData(_T(""))
	, m_Status(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MSGCLIENTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDTSESSIONNAME, m_SessionName);
	DDX_Text(pDX, IDC_EDTSEND, m_SendData);
	DDX_Text(pDX, IDC_EDTRECV, m_RecvData);
	DDX_Text(pDX, IDC_STATICSTATUS, m_Status);
}

BEGIN_MESSAGE_MAP(CIPC_MSGCLIENTDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNCONNECT, &CIPC_MSGCLIENTDlg::OnBnClickedBtnconnect)
	ON_BN_CLICKED(IDC_BTNDISCONNECT, &CIPC_MSGCLIENTDlg::OnBnClickedBtndisconnect)
	ON_BN_CLICKED(IDC_BTNSENDDATA, &CIPC_MSGCLIENTDlg::OnBnClickedBtnsenddata)
END_MESSAGE_MAP()


// CIPC_MSGCLIENTDlg 消息处理程序

BOOL CIPC_MSGCLIENTDlg::OnInitDialog()
{
	//禁止程序全屏
	m_bFullScreen = false;

	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

 if (!m_IPCClient.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("创建进程通讯客户端类失败"));
	}

	m_IPCClient.m_ClientConnected = OnClientConnected;
	m_IPCClient.m_ClientDisConnected = OnClientDisConnected;
	m_IPCClient.m_ClientDataArrive = OnClientDataArrive;


	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CIPC_MSGCLIENTDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_IPC_MSGCLIENT_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_IPC_MSGCLIENT_DIALOG));
	}
}
#endif

/*
*函数介绍：客户端连接建立事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientConnected(CWnd* parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_Status = _T("连接状态：连接成功");
   pDlg->UpdateData(FALSE);
}

/*
*函数介绍：客户端连接断开事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDisConnected(CWnd * parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   pDlg->m_Status = _T("连接状态：连接不成功");
   pDlg->UpdateData(FALSE);  
}

/*
*函数介绍：客户端接收数据事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           pData : 接收数据指针
		   bufLen : 接收数据长度
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDataArrive(CWnd* parentWnd
													,LPVOID pData,DWORD bufLen)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_RecvData = LPCTSTR(pData);
   pDlg->UpdateData(FALSE);
}



/*
*函数介绍：建立连接按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtnconnect() 
{
	UpdateData(TRUE);
	m_IPCClient.m_SessionName = m_SessionName;
	m_IPCClient.Open(this);
}

/*
*函数介绍：断开连接按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtndisconnect() 
{
   m_IPCClient.Close();			
}

/*
*函数介绍：发送数据按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtnsenddata() 
{
   UpdateData(TRUE);
   m_IPCClient.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_SendData.GetLength()*2);	
}
