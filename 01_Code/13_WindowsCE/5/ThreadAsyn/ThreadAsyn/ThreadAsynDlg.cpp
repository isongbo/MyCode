// ThreadAsynDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadAsyn.h"
#include "ThreadAsynDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//���������С
#define MAXDATASIZE 100 

int g_incNum; //����
int g_aGlobalData[MAXDATASIZE]; //�߳���Ҫ���ʵ�����

// CThreadAsynDlg �Ի���

CThreadAsynDlg::CThreadAsynDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadAsynDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadAsynDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadAsynDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNEXEC, &CThreadAsynDlg::OnBnClickedBtnexec)
END_MESSAGE_MAP()


// CThreadAsynDlg ��Ϣ�������

BOOL CThreadAsynDlg::OnInitDialog()
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
void CThreadAsynDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_THREADASYN_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_THREADASYN_DIALOG));
	}
}
#endif


/*
*�������ܣ��߳�ִ�й���
*��ڲ�����pArg�������߳�ʱ���������Ĳ���������ָ���б��ؼ�ָ��
*���ڲ�����(��)
*����ֵ������ֻ����1��
*/
DWORD  CThreadAsynDlg::ThreadProc(PVOID pArg)
{
	CListBox * pLstBox = NULL;

	pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];
	//�����鸳ֵ
	for (int i=0;i<MAXDATASIZE;i++)
	{
		g_incNum++;  //��1
		g_aGlobalData[i] = g_incNum;  //��ֵ
		Sleep(5);
	}
	
	//��ʾ�Ѿ���ֵ������
	for(int i = 0 ; i < MAXDATASIZE ; i++)
	{
		_itow(g_aGlobalData[i],buffer,10);
		pLstBox->AddString(buffer);  //
	}

	return 1;
}



/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadAsynDlg::OnBnClickedBtnexec() 
{
   DWORD dwThreadId1,dwThreadId2;
   HANDLE handle1,handle2;
	
   CListBox * pLstOne;
   CListBox * pLstTwo;
   pLstOne = (CListBox*)GetDlgItem(IDC_LISTONE);
   pLstTwo = (CListBox*)GetDlgItem(IDC_LISTTWO);

   //��ʼ������ֵ
   g_incNum = 0;

   //���������߳�
   handle1 = CreateThread(NULL,0,ThreadProc,pLstOne,0,&dwThreadId1);
   //
   Sleep(5);
   //
   handle2 = CreateThread(NULL,0,ThreadProc,pLstTwo,0,&dwThreadId2);

   if (!handle1)
   {
	   AfxMessageBox(_T("�߳�1����ʧ��"));
   }
	
   if (!handle2)
   {
	   AfxMessageBox(_T("�߳�2����ʧ��"));
   }

   CloseHandle(handle1);
   CloseHandle(handle2);
}

