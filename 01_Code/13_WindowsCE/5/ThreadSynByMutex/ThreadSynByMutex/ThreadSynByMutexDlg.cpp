// ThreadSynByMutexDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadSynByMutex.h"
#include "ThreadSynByMutexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//���������С
#define MAXDATASIZE 100 

int g_incNum; //����
int g_aGlobalData[MAXDATASIZE]; //�߳���Ҫ���ʵ�����

HANDLE g_hSynMutex; //�߳�ͬ��������
// CThreadSynByMutexDlg �Ի���

CThreadSynByMutexDlg::CThreadSynByMutexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynByMutexDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynByMutexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadSynByMutexDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNEXEC, &CThreadSynByMutexDlg::OnBnClickedBtnexec)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CThreadSynByMutexDlg ��Ϣ�������

BOOL CThreadSynByMutexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//�����������Ĭ��״̬Ϊ��δ���߳�ӵ�С�
	g_hSynMutex = CreateMutex(NULL,FALSE,L"MUTEX_FOR_DEMO_SYNC");

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CThreadSynByMutexDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_THREADSYNBYMUTEX_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_THREADSYNBYMUTEX_DIALOG));
	}
}
#endif


/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadSynByMutexDlg::OnBnClickedBtnexec() 
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


void CThreadSynByMutexDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//�رջ������
	CloseHandle(g_hSynMutex);
}

/*
*�������ܣ��߳�ִ�й���
*��ڲ�����pArg�������߳�ʱ���������Ĳ���������ָ���б��ؼ�ָ��
*���ڲ�����(��)
*����ֵ������ֻ����1��
*/
DWORD  CThreadSynByMutexDlg::ThreadProc(PVOID pArg)
{

	CListBox* pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];
	//�ȴ�ͬ���¼��ź�
	if (WaitForSingleObject(g_hSynMutex,INFINITE) == WAIT_OBJECT_0)
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
	//�ͷŶԻ�������ӵ��Ȩ
	ReleaseMutex(g_hSynMutex);

	return 1;

}
