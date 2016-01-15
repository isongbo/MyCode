// ThreadSynBySemaphoreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadSynBySemaphore.h"
#include "ThreadSynBySemaphoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//���������С
#define MAXDATASIZE 100 

int g_incNum; //����
int g_aGlobalData[MAXDATASIZE]; //�߳���Ҫ���ʵ�����
HANDLE g_hSynSemaphore;//�����ź���ͬ��

// CThreadSynBySemaphoreDlg �Ի���

CThreadSynBySemaphoreDlg::CThreadSynBySemaphoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynBySemaphoreDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynBySemaphoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadSynBySemaphoreDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNEXEC, &CThreadSynBySemaphoreDlg::OnBnClickedBtnexec)
END_MESSAGE_MAP()


// CThreadSynBySemaphoreDlg ��Ϣ�������

BOOL CThreadSynBySemaphoreDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//�����ź�������,��ʼ���ź�������Ϊ1������ź�������ҲΪ1
	g_hSynSemaphore = CreateSemaphore(NULL,1,1,NULL);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CThreadSynBySemaphoreDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_THREADSYNBYSEMAPHORE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_THREADSYNBYSEMAPHORE_DIALOG));
	}
}
#endif


void CThreadSynBySemaphoreDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//�ر��ź�������
	CloseHandle(g_hSynSemaphore);

}

/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadSynBySemaphoreDlg::OnBnClickedBtnexec() 
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
   Sleep(5);
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



/*
*�������ܣ��߳�ִ�й���
*��ڲ�����pArg�������߳�ʱ���������Ĳ���������ָ���б��ؼ�ָ��
*���ڲ�����(��)
*����ֵ������ֻ����1��
*/
DWORD  CThreadSynBySemaphoreDlg::ThreadProc(PVOID pArg)
{

	CListBox* pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];
	//�ȴ��ź������ã����ź�����������0ʱ������
	if (WaitForSingleObject(g_hSynSemaphore,INFINITE) == WAIT_OBJECT_0)
	{

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
	}
	//��Ϊ�ȴ������Զ����ź���������1
	//���Ը��ź���������1��ʹ�ź�����������
	ReleaseSemaphore(g_hSynSemaphore,1,NULL);
	return 1;
}
