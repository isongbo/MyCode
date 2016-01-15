// IPC_MSGCLIENTDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MSGCLIENT.h"
#include "IPC_MSGCLIENTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MSGCLIENTDlg �Ի���

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


// CIPC_MSGCLIENTDlg ��Ϣ�������

BOOL CIPC_MSGCLIENTDlg::OnInitDialog()
{
	//��ֹ����ȫ��
	m_bFullScreen = false;

	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

 if (!m_IPCClient.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("��������ͨѶ�ͻ�����ʧ��"));
	}

	m_IPCClient.m_ClientConnected = OnClientConnected;
	m_IPCClient.m_ClientDisConnected = OnClientDisConnected;
	m_IPCClient.m_ClientDataArrive = OnClientDataArrive;


	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
*�������ܣ��ͻ������ӽ����¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientConnected(CWnd* parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_Status = _T("����״̬�����ӳɹ�");
   pDlg->UpdateData(FALSE);
}

/*
*�������ܣ��ͻ������ӶϿ��¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDisConnected(CWnd * parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   pDlg->m_Status = _T("����״̬�����Ӳ��ɹ�");
   pDlg->UpdateData(FALSE);  
}

/*
*�������ܣ��ͻ��˽��������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           pData : ��������ָ��
		   bufLen : �������ݳ���
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
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
*�������ܣ��������Ӱ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtnconnect() 
{
	UpdateData(TRUE);
	m_IPCClient.m_SessionName = m_SessionName;
	m_IPCClient.Open(this);
}

/*
*�������ܣ��Ͽ����Ӱ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtndisconnect() 
{
   m_IPCClient.Close();			
}

/*
*�������ܣ��������ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBnClickedBtnsenddata() 
{
   UpdateData(TRUE);
   m_IPCClient.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_SendData.GetLength()*2);	
}
