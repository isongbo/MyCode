// SerialSampleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SerialSample.h"
#include "SerialSampleDlg.h"
#include "DlgParams.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//定义串口数据接收消息常量
#define WM_RECV_SERIAL_DATA WM_USER + 101

// CSerialSampleDlg 对话框

CSerialSampleDlg::CSerialSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSerialSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pSerial = NULL;
}

void CSerialSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSerialSampleDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_OPEN, &CSerialSampleDlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CSerialSampleDlg::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND, &CSerialSampleDlg::OnBnClickedBtnSend)


	ON_MESSAGE(WM_RECV_SERIAL_DATA,OnRecvSerialData)
END_MESSAGE_MAP()


// CSerialSampleDlg 消息处理程序

BOOL CSerialSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


//打开串口
void CSerialSampleDlg::OnBnClickedBtnOpen()
{
	//判断串口是否已经打开
	if (m_pSerial != NULL)
	{
		m_pSerial->ClosePort();

		delete m_pSerial;
		m_pSerial = NULL;
	}

	//串口参数输入对话框
	CDlgParams dlgParams;

	if (dlgParams.DoModal() == IDOK)
	{
		//新建串口通讯对象
		m_pSerial = new CCESeries();
		m_pSerial->m_OnSeriesRead = OnSerialRead; //

		//打开串口
		if (m_pSerial->OpenPort(this,
			dlgParams.m_portNo,
			dlgParams.m_baud,
			dlgParams.m_parity,
			dlgParams.m_databits,
			dlgParams.m_stopbits))
		{
			AfxMessageBox(L"串口打开成功");
		}
		else
		{
			AfxMessageBox(L"串口打开失败");
		}
	}
}

//关闭串口
void CSerialSampleDlg::OnBnClickedBtnClose()
{
	//
	if (m_pSerial != NULL)
	{
		//关闭串口
		m_pSerial->ClosePort();

		//释放串口对象
		delete m_pSerial;
		m_pSerial = NULL;
	}
}

//发送数据
void CSerialSampleDlg::OnBnClickedBtnSend()
{
	char * buf  =NULL;  //定义发送缓冲区
	DWORD dwBufLen = 0;   //定义发送缓冲区长度
	CString strSend = L"";

	//得到发送输入框
	CEdit *pEdtSendMsg = (CEdit*)GetDlgItem(IDC_EDT_SEND);
	ASSERT(pEdtSendMsg != NULL);

	//串口如果没有打开，直接返回
	if (m_pSerial == NULL)
	{
		AfxMessageBox(L"串口未打开");
		return;
	}

	//得到待发送的字符串
	pEdtSendMsg->GetWindowTextW(strSend);

	//将待发送的字符串转换成单字节，进行发送
	buf = new char[strSend.GetLength()*2+1];
	ZeroMemory(buf,strSend.GetLength()*2+1);
	//转换成单字节进行发送	
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,strSend.GetBuffer(strSend.GetLength())
	   ,strSend.GetLength(),buf,strSend.GetLength()*2,NULL,NULL);

	dwBufLen = strlen(buf) + 1;
	//发送字符串
	m_pSerial->WriteSyncPort((BYTE*)buf,dwBufLen);

	//释放内存
	delete[] buf;
	buf = NULL;
}

//定义串口接收数据函数类型
void CALLBACK CSerialSampleDlg::OnSerialRead(void * pOwner,BYTE* buf,DWORD bufLen)
{
	BYTE *pRecvBuf = NULL; //接收缓冲区
	//得到父对象指针
	CSerialSampleDlg* pThis = (CSerialSampleDlg*)pOwner;
	//将接收的缓冲区拷贝到pRecvBuf种
	pRecvBuf = new BYTE[bufLen];
	CopyMemory(pRecvBuf,buf,bufLen);

	//发送异步消息，表示收到串口数据，消息处理完，应释放内存
	pThis->PostMessage(WM_RECV_SERIAL_DATA,WPARAM(pRecvBuf),bufLen);

}

// 串口接收数据处理函数
LONG CSerialSampleDlg::OnRecvSerialData(WPARAM wParam,LPARAM lParam)
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
	strOldRecv = strOldRecv +L"\r\n"+ strRecv;
	pEdtRecvMsg->SetWindowTextW(strOldRecv);

	//释放内存
	delete[] pBuf;
	pBuf = NULL;
	return 0;
}