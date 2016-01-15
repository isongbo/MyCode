// ThreadSynByCriticalSectionsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadSynByCriticalSections.h"
#include "ThreadSynByCriticalSectionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//���������С
#define MAXDATASIZE 100 

int g_incNum; //����
int g_aGlobalData[MAXDATASIZE]; //�߳���Ҫ���ʵ�����

//�߳�ͬ���ٽ�������
CRITICAL_SECTION g_critical_Section;


// CThreadSynByCriticalSectionsDlg �Ի���

CThreadSynByCriticalSectionsDlg::CThreadSynByCriticalSectionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynByCriticalSectionsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynByCriticalSectionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadSynByCriticalSectionsDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNEXEC, &CThreadSynByCriticalSectionsDlg::OnBnClickedBtnexec)
END_MESSAGE_MAP()


// CThreadSynByCriticalSectionsDlg ��Ϣ�������

BOOL CThreadSynByCriticalSectionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ʼ���ٽ�������
	InitializeCriticalSection(&g_critical_Section);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CThreadSynByCriticalSectionsDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_THREADSYNBYCRITICALSECTIONS_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_THREADSYNBYCRITICALSECTIONS_DIALOG));
	}
}
#endif


void CThreadSynByCriticalSectionsDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//�ͷ��ٽ���������Դ
	DeleteCriticalSection(&g_critical_Section);	

}

/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadSynByCriticalSectionsDlg::OnBnClickedBtnexec()
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
DWORD  CThreadSynByCriticalSectionsDlg::ThreadProc(PVOID pArg)
{

	CListBox* pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];

	//�����ٽ���
	EnterCriticalSection(&(g_critical_Section));


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

	//�뿪�ٽ���
	LeaveCriticalSection(&(g_critical_Section));

	return 1;

}
