// PingExamDlg.cpp : ʵ���ļ�
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

// CPingExamDlg �Ի���

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


// CPingExamDlg ��Ϣ�������

BOOL CPingExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
*�������ܣ�CE��Ping����
*��ڲ�����cIPAddr  : IP��ַ
*���ڲ�����pListBox : CListBox����������ʾPing��Ϣ
*����ֵ��(��)
*/
void CEPing(CString cIPAddr,CListBox * pListBox)
{
   	WSAData wsaData;
	//��ʼ��Socket��̬���ӿ�
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return ;
    }
	
	/*��IP��ַת���ɵ��ֽ�*/
    char szDestIPAddr[255];
	ZeroMemory(szDestIPAddr,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK
		,cIPAddr.GetBuffer(cIPAddr.GetLength()),cIPAddr.GetLength()
		,szDestIPAddr,cIPAddr.GetLength(),NULL,NULL);
	
	IPAddr ipAddr;
	//��Ŀ���ַ���IP��ַת����IPAddr�ṹ
    ipAddr = inet_addr(szDestIPAddr);      
	
	if (ipAddr == INADDR_NONE) 
	{
		AfxMessageBox(_T("��ַ��Ч"));
		return ;
	}
	
	// ��ping����
    HANDLE hIP = IcmpCreateFile();
    if (hIP == INVALID_HANDLE_VALUE) {
        AfxMessageBox(_T("���ܴ�Ping����"));
        return ;
    }
	
	
	// ����ping���ݰ�
    char acPingBuffer[64];
    memset(acPingBuffer, '*', sizeof(acPingBuffer));
    PICMP_ECHO_REPLY pIpe = (PICMP_ECHO_REPLY)GlobalAlloc( GMEM_FIXED | GMEM_ZEROINIT,
		sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer)); 
    if (pIpe == 0) {
		AfxMessageBox(_T("����ping��������ʧ��"));
        return ;
    }
    
	CString m_recv;
    // ����ping���ݰ�
	m_recv = CString(L"ping ")+cIPAddr+CString(L" with 64 Bytes");
	pListBox->AddString(m_recv);
    for (int i=0;i<4;i++)
	{
		//����ping��������ȴ�����ʱ��Ϊ1��
		DWORD dwStatus = IcmpSendEcho(hIP,ipAddr, 
            acPingBuffer, sizeof(acPingBuffer), NULL, pIpe, 
            sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer), 1000);
		//��dwStatus������0��������յ���Ӧ
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
    //�ͷ��ѷ�����ڴ�
    GlobalFree(pIpe);
	//�ر�Ping����
    IcmpCloseHandle(hIP);
    //�ͷ�Socket��Դ
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
