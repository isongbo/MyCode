// UDPDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UDPDemo.h"
#include "UDPDemoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CUDPDemoDlg �Ի���

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


// CUDPDemoDlg ��Ϣ�������

BOOL CUDPDemoDlg::OnInitDialog()
{
	//��ֹ�Զ�ȫ��
	m_bFullScreen = false;
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


//��UDP
void CUDPDemoDlg::OnBnClickedBtnOpen()
{
   UpdateData(TRUE);
   m_CEUdp.m_OnUdpRecv = OnUdpCERecv;
   m_CEUdp.m_OnUdpError = OnUdpCEError;
   DWORD nResult = m_CEUdp.Open(this,m_LocalPort,m_RemoteHost.GetBuffer(m_RemoteHost.GetLength()),m_RemotePort);
   if (nResult <=0) 
   {
	   AfxMessageBox(_T("�򿪶˿�ʧ��"));
   }
}

//�ر�UDP
void CUDPDemoDlg::OnBnClickedBtnClose()
{
  m_CEUdp.Close();	
}

//��������
void CUDPDemoDlg::OnBnClickedBtnSend()
{
	char * buf  =NULL;  //���巢�ͻ�����
	DWORD dwBufLen = 0;   //���巢�ͻ���������
	CString strSend = L"";

	//�õ����������
	CEdit *pEdtSendMsg = (CEdit*)GetDlgItem(IDC_EDT_SEND);
	ASSERT(pEdtSendMsg != NULL);

	//�õ������͵��ַ���
	pEdtSendMsg->GetWindowTextW(strSend);

	//�������͵��ַ���ת���ɵ��ֽڣ����з���
	buf = new char[strSend.GetLength()*2+1];
	ZeroMemory(buf,strSend.GetLength()*2+1);
	//ת���ɵ��ֽڽ��з���	
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,strSend.GetBuffer(strSend.GetLength())
	   ,strSend.GetLength(),buf,strSend.GetLength()*2,NULL,NULL);

	dwBufLen = strlen(buf) + 1;

	//��������
    m_CEUdp.SendData(buf,dwBufLen);	

	//�ͷ��ڴ�
	delete[] buf;
	buf = NULL;
}

//UDP���ݽ��ջص�����
void CALLBACK CUDPDemoDlg::OnUdpCERecv(void * pOwner,char* buf,DWORD dwBufLen,sockaddr * addr)
{
	BYTE *pRecvBuf = NULL; //���ջ�����
	//�õ�������ָ��
	CUDPDemoDlg* pThis = (CUDPDemoDlg*)pOwner;
	//�����յĻ�����������pRecvBuf��
	pRecvBuf = new BYTE[dwBufLen];
	CopyMemory(pRecvBuf,buf,dwBufLen);

	//�����첽��Ϣ����ʾ�յ��������ݣ���Ϣ�����꣬Ӧ�ͷ��ڴ�
	pThis->PostMessage(WM_RECV_UDP_DATA,WPARAM(pRecvBuf),dwBufLen);
} 

//UDP����ص�����
void CALLBACK CUDPDemoDlg::OnUdpCEError(void * pOwner,int nErrorCode)
{

}


// UDP�������ݴ�����
LONG CUDPDemoDlg::OnRecvUdpData(WPARAM wParam,LPARAM lParam)
{
	CString strOldRecv = L"";
	CString strRecv = L"";
	//���ڽ��յ���BUF
	CHAR *pBuf = (CHAR*)wParam;
	//���ڽ��յ���BUF����
	DWORD dwBufLen = lParam;
	
	//���տ�
	CEdit *pEdtRecvMsg = (CEdit*)GetDlgItem(IDC_EDT_RECV);
	ASSERT(pEdtRecvMsg != NULL);

	//�õ����տ��е���ʷ�ı�
	pEdtRecvMsg->GetWindowTextW(strOldRecv);
	
	//
    strRecv = CString(pBuf);
	//���½��յ����ı���ӵ����տ���
	strOldRecv = strOldRecv + strRecv +L"\r\n";
	pEdtRecvMsg->SetWindowTextW(strOldRecv);

	//�ͷ��ڴ�
	delete[] pBuf;
	pBuf = NULL;
	return 0;
}
