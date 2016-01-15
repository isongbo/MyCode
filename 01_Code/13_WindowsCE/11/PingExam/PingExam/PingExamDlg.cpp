// PingExamDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PingExam.h"
#include "PingExamDlg.h"

#include <icmpapi.h>
#include <winsock.h>
#include <ipExport.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPingExamDlg 对话框

CPingExamDlg::CPingExamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPingExamDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPingExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPingExamDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_PING, &CPingExamDlg::OnBnClickedBtnPing)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CPingExamDlg::OnBnClickedBtnClear)
END_MESSAGE_MAP()


// CPingExamDlg 消息处理程序

BOOL CPingExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CPingExamDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_PINGEXAM_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_PINGEXAM_DIALOG));
	}
}
#endif

/*
*函数介绍：CE下Ping方法
*入口参数：cIPAddr  : IP地址
*出口参数：pListBox : CListBox对象，用于显示Ping信息
*返回值：(无)
*/
void CEPing(CString cIPAddr,CListBox * pListBox)
{
   	WSAData wsaData;
	//初始化Socket动态链接库
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return ;
    }
	
	/*将IP地址转换成单字节*/
    char szDestIPAddr[255];
	ZeroMemory(szDestIPAddr,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK
		,cIPAddr.GetBuffer(cIPAddr.GetLength()),cIPAddr.GetLength()
		,szDestIPAddr,cIPAddr.GetLength(),NULL,NULL);
	
	IPAddr ipAddr;
	//将目标字符串IP地址转换成IPAddr结构
    ipAddr = inet_addr(szDestIPAddr);      
	
	if (ipAddr == INADDR_NONE) 
	{
		AfxMessageBox(_T("地址无效"));
		return ;
	}
	
	// 打开ping服务
    HANDLE hIP = IcmpCreateFile();
    if (hIP == INVALID_HANDLE_VALUE) {
        AfxMessageBox(_T("不能打开Ping服务"));
        return ;
    }
	
	
	// 构造ping数据包
    char acPingBuffer[64];
    memset(acPingBuffer, '*', sizeof(acPingBuffer));
    PICMP_ECHO_REPLY pIpe = (PICMP_ECHO_REPLY)GlobalAlloc( GMEM_FIXED | GMEM_ZEROINIT,
		sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer)); 
    if (pIpe == 0) {
		AfxMessageBox(_T("分配ping包缓冲区失败"));
        return ;
    }
    
	CString m_recv;
    // 发送ping数据包
	m_recv = CString(L"ping ")+cIPAddr+CString(L" with 64 Bytes");
	pListBox->AddString(m_recv);
    for (int i=0;i<4;i++)
	{
		//发送ping服务包，等待接收时间为1秒
		DWORD dwStatus = IcmpSendEcho(hIP,ipAddr, 
            acPingBuffer, sizeof(acPingBuffer), NULL, pIpe, 
            sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer), 1000);
		//当dwStatus不等于0，代表接收到回应
		if (dwStatus != 0) {
			m_recv.Format(_T("Reply From %d.%d.%d.%d :bytes=%d time=%d TTL")
				,int(LOBYTE(LOWORD(pIpe->Address)))
				,int(HIBYTE(LOWORD(pIpe->Address)))
				,int(LOBYTE(HIWORD(pIpe->Address)))
				,int(HIBYTE(HIWORD(pIpe->Address)))
				,int(pIpe->DataSize)
				,int(pIpe->RoundTripTime)
				,int(pIpe->Options.Ttl));
			pListBox->AddString(m_recv);
		}
		else 
		{
			pListBox->AddString(_T("Error obtaining info from ping packet."));
		}
	}
    //释放已分配的内存
    GlobalFree(pIpe);
	//关闭Ping服务
    IcmpCloseHandle(hIP);
    //释放Socket资源
	WSACleanup();
}


//ping button
void CPingExamDlg::OnBnClickedBtnPing()
{
	CString strIPAddr = L"";
	CEdit *pEdtIP = (CEdit*)GetDlgItem(IDC_EDT_IPADDRESS);
	CListBox *pLstResult = (CListBox*)GetDlgItem(IDC_LST_PING_RESULT);

	pEdtIP->GetWindowText(strIPAddr);
	CEPing(strIPAddr,pLstResult);
}

//clear button
void CPingExamDlg::OnBnClickedBtnClear()
{
	CListBox *pLstResult = (CListBox*)GetDlgItem(IDC_LST_PING_RESULT);
	pLstResult->ResetContent();
}
