// ThreadSynByCriticalSectionsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ThreadSynByCriticalSections.h"
#include "ThreadSynByCriticalSectionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//定义数组大小
#define MAXDATASIZE 100 

int g_incNum; //记数
int g_aGlobalData[MAXDATASIZE]; //线程需要访问的数组

//线程同步临界区对象
CRITICAL_SECTION g_critical_Section;


// CThreadSynByCriticalSectionsDlg 对话框

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


// CThreadSynByCriticalSectionsDlg 消息处理程序

BOOL CThreadSynByCriticalSectionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//初始化临界区对象
	InitializeCriticalSection(&g_critical_Section);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

	//释放临界区对象资源
	DeleteCriticalSection(&g_critical_Section);	

}

/*
执行按钮单击事件，用于创建两个线程
*/
void CThreadSynByCriticalSectionsDlg::OnBnClickedBtnexec()
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




/*
*函数介绍：线程执行过程
*入口参数：pArg：创建线程时，传进来的参数，这里指的列表框控件指针
*出口参数：(无)
*返回值：这里只返回1。
*/
DWORD  CThreadSynByCriticalSectionsDlg::ThreadProc(PVOID pArg)
{

	CListBox* pLstBox = (CListBox*)pArg;

	TCHAR buffer[10];

	//进入临界区
	EnterCriticalSection(&(g_critical_Section));


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

	//离开临界区
	LeaveCriticalSection(&(g_critical_Section));

	return 1;

}
