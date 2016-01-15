// IPC_MSGServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPC_MSGServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MSGServerDlg �Ի���

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


// CIPC_MSGServerDlg ��Ϣ�������

BOOL CIPC_MSGServerDlg::OnInitDialog()
{
	//��ֹ����ȫ��
	m_bFullScreen = false;

	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	if (!m_IPCServer.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("��������ͨѶ��������ʧ��"));
	}

	m_IPCServer.m_ServerConnected = OnServerConnected;
	m_IPCServer.m_ServerDisConnected = OnServerDisConnected;
	m_IPCServer.m_ServerDataArrive = OnServerDataArrive;

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
*�������ܣ������������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_ClientWnd = hWnd;
   pDlg->m_Status = _T("����״̬�����ӳɹ�");
   pDlg->UpdateData(FALSE);
}

/*
*�������ܣ��������Ͽ������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerDisConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_Status = _T("����״̬�����Ӳ��ɹ�");
   pDlg->UpdateData(FALSE);  
}

/*
*�������ܣ����������������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           pData : ��������ָ��
		   bufLen : �������ݳ���
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
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
*�������ܣ�������ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnopen()
{
	UpdateData(TRUE);
	m_IPCServer.m_SessionName = m_SessionName;
	m_IPCServer.Open(this);
}

/*
*�������ܣ��رհ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnclose()
{
   m_IPCServer.Close();	
}

/*
*�������ܣ��������ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBnClickedBtnsenddata()
{
   UpdateData(TRUE);
   m_IPCServer.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_ClientWnd,m_SendData.GetLength()*2);
}
