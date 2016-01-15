// SerialSampleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SerialSample.h"
#include "SerialSampleDlg.h"
#include "DlgParams.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//���崮�����ݽ�����Ϣ����
#define WM_RECV_SERIAL_DATA WM_USER + 101

// CSerialSampleDlg �Ի���

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


// CSerialSampleDlg ��Ϣ�������

BOOL CSerialSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


//�򿪴���
void CSerialSampleDlg::OnBnClickedBtnOpen()
{
	//�жϴ����Ƿ��Ѿ���
	if (m_pSerial != NULL)
	{
		m_pSerial->ClosePort();

		delete m_pSerial;
		m_pSerial = NULL;
	}

	//���ڲ�������Ի���
	CDlgParams dlgParams;

	if (dlgParams.DoModal() == IDOK)
	{
		//�½�����ͨѶ����
		m_pSerial = new CCESeries();
		m_pSerial->m_OnSeriesRead = OnSerialRead; //

		//�򿪴���
		if (m_pSerial->OpenPort(this,
			dlgParams.m_portNo,
			dlgParams.m_baud,
			dlgParams.m_parity,
			dlgParams.m_databits,
			dlgParams.m_stopbits))
		{
			AfxMessageBox(L"���ڴ򿪳ɹ�");
		}
		else
		{
			AfxMessageBox(L"���ڴ�ʧ��");
		}
	}
}

//�رմ���
void CSerialSampleDlg::OnBnClickedBtnClose()
{
	//
	if (m_pSerial != NULL)
	{
		//�رմ���
		m_pSerial->ClosePort();

		//�ͷŴ��ڶ���
		delete m_pSerial;
		m_pSerial = NULL;
	}
}

//��������
void CSerialSampleDlg::OnBnClickedBtnSend()
{
	char * buf  =NULL;  //���巢�ͻ�����
	DWORD dwBufLen = 0;   //���巢�ͻ���������
	CString strSend = L"";

	//�õ����������
	CEdit *pEdtSendMsg = (CEdit*)GetDlgItem(IDC_EDT_SEND);
	ASSERT(pEdtSendMsg != NULL);

	//�������û�д򿪣�ֱ�ӷ���
	if (m_pSerial == NULL)
	{
		AfxMessageBox(L"����δ��");
		return;
	}

	//�õ������͵��ַ���
	pEdtSendMsg->GetWindowTextW(strSend);

	//�������͵��ַ���ת���ɵ��ֽڣ����з���
	buf = new char[strSend.GetLength()*2+1];
	ZeroMemory(buf,strSend.GetLength()*2+1);
	//ת���ɵ��ֽڽ��з���	
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,strSend.GetBuffer(strSend.GetLength())
	   ,strSend.GetLength(),buf,strSend.GetLength()*2,NULL,NULL);

	dwBufLen = strlen(buf) + 1;
	//�����ַ���
	m_pSerial->WriteSyncPort((BYTE*)buf,dwBufLen);

	//�ͷ��ڴ�
	delete[] buf;
	buf = NULL;
}

//���崮�ڽ������ݺ�������
void CALLBACK CSerialSampleDlg::OnSerialRead(void * pOwner,BYTE* buf,DWORD bufLen)
{
	BYTE *pRecvBuf = NULL; //���ջ�����
	//�õ�������ָ��
	CSerialSampleDlg* pThis = (CSerialSampleDlg*)pOwner;
	//�����յĻ�����������pRecvBuf��
	pRecvBuf = new BYTE[bufLen];
	CopyMemory(pRecvBuf,buf,bufLen);

	//�����첽��Ϣ����ʾ�յ��������ݣ���Ϣ�����꣬Ӧ�ͷ��ڴ�
	pThis->PostMessage(WM_RECV_SERIAL_DATA,WPARAM(pRecvBuf),bufLen);

}

// ���ڽ������ݴ�����
LONG CSerialSampleDlg::OnRecvSerialData(WPARAM wParam,LPARAM lParam)
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
	strOldRecv = strOldRecv +L"\r\n"+ strRecv;
	pEdtRecvMsg->SetWindowTextW(strOldRecv);

	//�ͷ��ڴ�
	delete[] pBuf;
	pBuf = NULL;
	return 0;
}