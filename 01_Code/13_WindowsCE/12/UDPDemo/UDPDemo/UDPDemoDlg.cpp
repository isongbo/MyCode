// UDPDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UDPDemo.h"
#include "UDPDemoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CUDPDemoDlg 对话框

CUDPDemoDlg::CUDPDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUDPDemoDlg::IDD, pParent)
	, m_RemoteHost(_T(""))
	, m_RemotePort(0)
	, m_LocalPort(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDPDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_REMOTEHOST, m_RemoteHost);
	DDX_Text(pDX, IDC_EDIT_REMOTEPORT, m_RemotePort);
	DDX_Text(pDX, IDC_EDIT_LOCALPORT, m_LocalPort);
}

BEGIN_MESSAGE_MAP(CUDPDemoDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_OPEN, &CUDPDemoDlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CUDPDemoDlg::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND, &CUDPDemoDlg::OnBnClickedBtnSend)
	ON_MESSAGE(WM_RECV_UDP_DATA,OnRecvUdpData)
END_MESSAGE_MAP()


// CUDPDemoDlg 消息处理程序

BOOL CUDPDemoDlg::OnInitDialog()
{
	//禁止自动全屏
	m_bFullScreen = false;
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


//打开UDP
void CUDPDemoDlg::OnBnClickedBtnOpen()
{
   UpdateData(TRUE);
   m_CEUdp.m_OnUdpRecv = OnUdpCERecv;
   m_CEUdp.m_OnUdpError = OnUdpCEError;
   DWORD nResult = m_CEUdp.Open(this,m_LocalPort,m_RemoteHost.GetBuffer(m_RemoteHost.GetLength()),m_RemotePort);
   if (nResult <=0) 
   {
	   AfxMessageBox(_T("打开端口失败"));
   }
}

//关闭UDP
void CUDPDemoDlg::OnBnClickedBtnClose()
{
  m_CEUdp.Close();	
}

//发送数据
void CUDPDemoDlg::OnBnClickedBtnSend()
{
	char * buf  =NULL;  //定义发送缓冲区
	DWORD dwBufLen = 0;   //定义发送缓冲区长度
	CString strSend = L"";

	//得到发送输入框
	CEdit *pEdtSendMsg = (CEdit*)GetDlgItem(IDC_EDT_SEND);
	ASSERT(pEdtSendMsg != NULL);

	//得到待发送的字符串
	pEdtSendMsg->GetWindowTextW(strSend);

	//将待发送的字符串转换成单字节，进行发送
	buf = new char[strSend.GetLength()*2+1];
	ZeroMemory(buf,strSend.GetLength()*2+1);
	//转换成单字节进行发送	
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,strSend.GetBuffer(strSend.GetLength())
	   ,strSend.GetLength(),buf,strSend.GetLength()*2,NULL,NULL);

	dwBufLen = strlen(buf) + 1;

	//发送数据
    m_CEUdp.SendData(buf,dwBufLen);	

	//释放内存
	delete[] buf;
	buf = NULL;
}

//UDP数据接收回调函数
void CALLBACK CUDPDemoDlg::OnUdpCERecv(void * pOwner,char* buf,DWORD dwBufLen,sockaddr * addr)
{
	BYTE *pRecvBuf = NULL; //接收缓冲区
	//得到父对象指针
	CUDPDemoDlg* pThis = (CUDPDemoDlg*)pOwner;
	//将接收的缓冲区拷贝到pRecvBuf种
	pRecvBuf = new BYTE[dwBufLen];
	CopyMemory(pRecvBuf,buf,dwBufLen);

	//发送异步消息，表示收到串口数据，消息处理完，应释放内存
	pThis->PostMessage(WM_RECV_UDP_DATA,WPARAM(pRecvBuf),dwBufLen);
} 

//UDP报错回调函数
void CALLBACK CUDPDemoDlg::OnUdpCEError(void * pOwner,int nErrorCode)
{

}


// UDP接收数据处理函数
LONG CUDPDemoDlg::OnRecvUdpData(WPARAM wParam,LPARAM lParam)
{
	CString strOldRecv = L"";
	CString strRecv = L"";
	//串口接收到的BUF
	CHAR *pBuf = (CHAR*)wParam;
	//串口接收到的BUF长度
	DWORD dwBufLen = lParam;
	
	//接收框
	CEdit *pEdtRecvMsg = (CEdit*)GetDlgItem(IDC_EDT_RECV);
	ASSERT(pEdtRecvMsg != NULL);

	//得到接收框中的历史文本
	pEdtRecvMsg->GetWindowTextW(strOldRecv);
	
	//
    strRecv = CString(pBuf);
	//将新接收到的文本添加到接收框中
	strOldRecv = strOldRecv + strRecv +L"\r\n";
	pEdtRecvMsg->SetWindowTextW(strOldRecv);

	//释放内存
	delete[] pBuf;
	pBuf = NULL;
	return 0;
}
