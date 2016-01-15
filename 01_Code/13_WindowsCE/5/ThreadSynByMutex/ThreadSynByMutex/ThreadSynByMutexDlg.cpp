// ThreadSynByMutexDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ThreadSynByMutex.h"
#include "ThreadSynByMutexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//定义数组大小
#define MAXDATASIZE 100 

int g_incNum; //记数
int g_aGlobalData[MAXDATASIZE]; //线程需要访问的数组

HANDLE g_hSynMutex; //线程同步互斥句柄
// CThreadSynByMutexDlg 对话框

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


// CThreadSynByMutexDlg 消息处理程序

BOOL CThreadSynByMutexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//创建互斥对象，默认状态为“未被线程拥有”
	g_hSynMutex = CreateMutex(NULL,FALSE,L"MUTEX_FOR_DEMO_SYNC");

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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
执行按钮单击事件，用于创建两个线程
*/
void CThreadSynByMutexDlg::OnBnClickedBtnexec() 
{
   DWORD dwThreadId1,dwThreadId2;
   HANDLE handle1,handle2;
	
   CListBox * pLstOne;
   CListBox * pLstTwo;
   pLstOne = (CListBox*)GetDlgItem(IDC_LISTONE);
   pLstTwo = (CListBox*)GetDlgItem(IDC_LISTTWO);

   //初始化计数值
   g_incNum = 0;

   //创建两个线程
   handle1 = CreateThread(NULL,0,ThreadProc,pLstOne,0,&dwThreadId1);
   Sleep(5);
   handle2 = CreateThread(NULL,0,ThreadProc,pLstTwo,0,&dwThreadId2);

   if (!handle1)
   {
	   AfxMessageBox(_T("线程1创建失败"));
   }
	
   if (!handle2)
   {
	   AfxMessageBox(_T("线程2创建失败"));
   }

   CloseHandle(handle1);
   CloseHandle(handle2);
}


void CThreadSynByMutexDlg::OnDestroy()
{
	CDialog::OnDestroy();

	//关闭互斥对象
	CloseHandle(g_hSynMutex);
}

/*
*函数介绍：线程执行过程
*入口参数：pArg：创建线程时，传进来的参数，这里指的列表框控件指针
*出口参数：(无)
*返回值：这里只返回1。
*/
DWORD  CThreadSynByMutexDlg::ThreadProc(PVOID pArg)
{

	CListBox* pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];
	//等待同步事件信号
	if (WaitForSingleObject(g_hSynMutex,INFINITE) == WAIT_OBJECT_0)
	{
		//给数组赋值
		for (int i=0;i<MAXDATASIZE;i++)
		{
			g_incNum++;  //加1
			g_aGlobalData[i] = g_incNum;  //赋值
			Sleep(5);
		}
		
		//显示已经赋值的数组
		for(int i = 0 ; i < MAXDATASIZE ; i++)
		{
			_itow(g_aGlobalData[i],buffer,10);
			pLstBox->AddString(buffer);  //
		}
	}
	//释放对互斥对象的拥有权
	ReleaseMutex(g_hSynMutex);

	return 1;

}
