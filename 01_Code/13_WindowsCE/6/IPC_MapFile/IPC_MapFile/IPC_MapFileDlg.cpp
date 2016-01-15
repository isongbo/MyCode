// IPC_MapFileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "IPC_MapFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MapFileDlg �Ի���

CIPC_MapFileDlg::CIPC_MapFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MapFileDlg::IDD, pParent)
	, m_Exist(FALSE)
	, m_Syn(FALSE)
	, m_Open(FALSE)
	, m_MemData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MapFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CKEXIST, m_Exist);
	DDX_Check(pDX, IDC_CKSYN, m_Syn);
	DDX_Check(pDX, IDC_CKOPEN, m_Open);
	DDX_Text(pDX, IDC_EDTDATA, m_MemData);
}

BEGIN_MESSAGE_MAP(CIPC_MapFileDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNOPEN, &CIPC_MapFileDlg::OnBnClickedBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, &CIPC_MapFileDlg::OnBnClickedBtnclose)
	ON_BN_CLICKED(IDC_BTNREAD, &CIPC_MapFileDlg::OnBnClickedBtnread)
	ON_BN_CLICKED(IDC_BTNWRITE, &CIPC_MapFileDlg::OnBnClickedBtnwrite)
	ON_BN_CLICKED(IDC_CKSYN, &CIPC_MapFileDlg::OnBnClickedCksyn)
END_MESSAGE_MAP()


// CIPC_MapFileDlg ��Ϣ�������

BOOL CIPC_MapFileDlg::OnInitDialog()
{
	// ��ֹȫ����ʾ
	m_bFullScreen = FALSE;

	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ʼ��m_memFileMap����
    if (!m_memFileMap.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("����ͨѶ����ʧ��"));
	}
	m_memFileMap.m_OnMemDataChange = OnMemDataChange;

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

/***************************�����嵥6-11***********************/
/*
*�������ܣ��ڴ�ӳ���ļ����ݱ仯�¼�����
*��ڲ�����pWndָ����ָ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MapFileDlg::OnMemDataChange(CWnd *pWnd)
{
	CIPC_MapFileDlg * pDlg;
	pDlg = (CIPC_MapFileDlg*)pWnd;
	pDlg->m_MemData = pDlg->m_memFileMap.ReadBuffer();
	pDlg->UpdateData(FALSE);
}



/*
*�������ܣ����ڴ�ӳ�䰴ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBnClickedBtnopen() 
{
   WORD dReturnCode;
   m_memFileMap.m_MapName = _T("IPCMemFile");
   m_memFileMap.m_MaxSize = 1024;
   //���ڴ�ӳ���ļ�
   dReturnCode = m_memFileMap.OpenFileMap(this);
   if (dReturnCode <= 0)
   {
	   AfxMessageBox(_T("����ʧ��"));
   }
   if (dReturnCode >=1)
   {
	   m_Open = true;
   }
   if (dReturnCode == 2) 
   {
	   m_Exist = true;
   }
   UpdateData(false);

}

/*
*�������ܣ��ر��ڴ�ӳ�䰴ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBnClickedBtnclose() 
{
   m_memFileMap.CloseFileMap();
   m_Open = false;
   m_Exist = false;
   UpdateData(false);
}

/*
*�������ܣ���ȡ��ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBnClickedBtnread() 
{
	m_MemData = m_memFileMap.ReadBuffer();
	UpdateData(FALSE);
}

/*
*�������ܣ�д�����ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBnClickedBtnwrite() 
{
   UpdateData(TRUE);
   m_memFileMap.WriteBuffer(m_MemData.GetBuffer(m_MemData.GetLength()));
}


/*
*�������ܣ��Ƿ�ͬ����ѡ�򵥻��¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBnClickedCksyn() 
{
   UpdateData(TRUE);
   m_memFileMap.m_Syn = m_Syn;
}
