// TaskListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TaskList.h"
#include "TaskListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTaskListDlg 对话框

CTaskListDlg::CTaskListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTaskListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTaskListDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNACTIVE, &CTaskListDlg::OnBnClickedBtnactive)
	ON_BN_CLICKED(IDC_BTNTERMINATE, &CTaskListDlg::OnBnClickedBtnterminate)
	ON_BN_CLICKED(IDC_BTNREFRESH, &CTaskListDlg::OnBnClickedBtnrefresh)
END_MESSAGE_MAP()


// CTaskListDlg 消息处理程序

BOOL CTaskListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//设置进程列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("进程名"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(1,_T("主窗体标题"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(2, _T("线程数"), LVCFMT_LEFT, rt.Width() * 0.30);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CTaskListDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_TASKLIST_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_TASKLIST_DIALOG));
	}
}
#endif

/*
*函数介绍：得到CE系统中运行的任务列表
*入口参数：(无)
*出口参数：pList ：存储得到任务列表信息
*返回值：返回得到的任务数
*/
DWORD CTaskListDlg::GetTaskListCE( PTASK_LIST pList) { 

  HINSTANCE         hKernel        = NULL; 
  HINSTANCE         hProcessSnap   = NULL; 
  PROCESSENTRY32 pe32           = {0}; 
  DWORD          dwTaskCount    = 0; 
  

  //状态toolhelp.dll动态连接库
  hKernel = LoadLibrary(_T("toolhelp.dll")); 
  
  if (!hKernel) {
	  ::MessageBox(NULL, L"Toolhelp.dll加载失败", L"进程列举", MB_OK);
    return 0;
  }
  
  //创建进程映射
  hProcessSnap = (HINSTANCE)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
  
  //如果失败，就退出
  if (hProcessSnap == (HANDLE)-1) 
    return 0; 
  
  dwTaskCount = 0; 
  
  //设置保存进程相关内容的变量的结构大小            
  pe32.dwSize = sizeof(PROCESSENTRY32);
  //获取第一个进程，并将此进程信息写入进程结构的变量pe32中          
  if (Process32First(hProcessSnap, &pe32)) { 
    do { 
      LPTSTR pCurChar; 
 
      if(_tcsstr(pe32.szExeFile, L"\\")) 
        pCurChar = _tcsrchr(pe32.szExeFile, '\\'); 
      else
        pCurChar = pe32.szExeFile;
      
      lstrcpy(pList-> ProcessName, pCurChar); 
      
      pList ->dwProcessId = pe32.th32ProcessID; 
      pList ->cntThreads = pe32.cntThreads;
      
      ++dwTaskCount;   //进程数目加1
      ++pList;         //移到下一个结构内存块
    } 
    while (Process32Next(hProcessSnap, &pe32)); //移至下一个进程
  } 
  else 
    dwTaskCount = 0;    // 
 
  CloseHandle (hProcessSnap); 
  return dwTaskCount; 
}

/*
*函数介绍：得到任务的主窗体标题和句柄
*入口参数：te ：进程信息列表指针
*出口参数：te ：进程信息列表指针
*返回值: (无)
*/
void CTaskListDlg::GetWindowTitles( PTASK_LIST_ENUM te ) { 
  // enumerate all windows 
  EnumWindows((WNDENUMPROC) EnumWindowsProc, (LPARAM) te ); 
}
/*
*函数介绍：回调函数，被EnumWindows调用
*入口参数：hwnd ：窗体句柄
*          lParam : 进程信息列表指针
*出口参数：lParam ：进程信息列表指针
*返回值: True代表成功，False代表失败
*/
BOOL CALLBACK CTaskListDlg::EnumWindowsProc( HWND hwnd, DWORD lParam ) { 
  DWORD             pid = 0; 
  DWORD             i; 
  TCHAR             buf[TITLE_SIZE]; 
  PTASK_LIST_ENUM   te = (PTASK_LIST_ENUM)lParam; 
  PTASK_LIST        tlist = te->tlist; 
  DWORD             numTasks = te->numtasks; 
  
  // 根据窗口句柄，得到进程标识
  if (!GetWindowThreadProcessId( hwnd, &pid )) { 
    return TRUE; 
  } 
  //查找进程标识和列表中相同的进程标识
  for (i=0; i<numTasks; i++) { 
    if (tlist[i].dwProcessId == pid) {
	  if (::IsWindowVisible(hwnd)) {
      tlist[i].hwnd = hwnd; 
      int nCnt = ::GetWindowText( hwnd, buf, TITLE_SIZE );
      buf[nCnt] = '\0';
      if (nCnt) { 
        lstrcpy( tlist[i].WindowTitle, buf ); 
      } 
     }
      break; 
    } 
  } 
  //继续列举窗体
  return TRUE; 
}

/*
*函数介绍：激活进程方法
*入口参数：tlist ： 进程信息
*出口参数：(无)
*返回值: True：成功；False：失败
*/
bool CTaskListDlg::ActivateProcess(PTASK_LIST tlist)
{
  //判断是否存在主窗口，如存在就激活它
  if (tlist->hwnd && tlist->WindowTitle) 
  {
	::SetForegroundWindow(tlist->hwnd);
	::SetActiveWindow(tlist->hwnd);
    return TRUE; 
  }
  else
  { 
	return FALSE;
  } 
} 

/*
*函数介绍：终止进程方法
*入口参数：tlist ： 进程信息
*出口参数：(无)
*返回值: True：成功；False：失败
*/
bool CTaskListDlg::KillProcess( PTASK_LIST tlist ) 
{ 
  HANDLE            hProcess; 

  //如果没有主窗体,则用TerminateProcess终止进程
  if (!tlist->hwnd)  
  { 
	//根据进程标识，返回进程句柄
    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, tlist->dwProcessId ); 
    //成功的话，终止进程
	if (hProcess) 
	{ 
      if (!TerminateProcess( hProcess, 1 )) 
	  { 
        CloseHandle( hProcess ); 
        return FALSE; 
      } 
      CloseHandle( hProcess ); 
      return TRUE; 
    }
	else
	{
	  return FALSE;
	}
  }
  //有主窗体，发送主窗口关闭消息，终止线程 
  else
  {
    ::PostMessage( tlist->hwnd, WM_CLOSE, 0, 0 ); 
    return TRUE;
  }
}


/*
*函数介绍：刷新按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CTaskListDlg::OnBnClickedBtnrefresh() 
{
	TASK_LIST_ENUM processList; //进程列表信息
	TCHAR numBuf[10]; //存储进程中的线程数

	memset(&g_tlist, 0, sizeof(TASK_LIST) * MAX_TASKS);
	//得到进程列表信息
	DWORD nNumTasks = GetTaskListCE(g_tlist);
	processList.numtasks = nNumTasks;
	processList.tlist = g_tlist;
	//更新进程列表信息，获取主窗口句柄和标题
	GetWindowTitles(&processList);

    CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	//清除列表框所有项目
	pListCtrl->DeleteAllItems();
    memset(&numBuf,0,sizeof(numBuf));

	//向列表框中添加进程相关信息
	for (int i=0;i<processList.numtasks;i++)
	{
        //进程exe名，标题名，线程数
      pListCtrl->InsertItem(i,_T("Test"));
	  pListCtrl->SetItemText(i,0,processList.tlist[i].ProcessName);
	  pListCtrl->SetItemText(i,1,processList.tlist[i].WindowTitle);	 
	  _itow(processList.tlist[i].cntThreads,numBuf,10);
	  pListCtrl->SetItemText(i,2,numBuf);
	}

}

/***************************程序清单4-10***********************/
/*
*函数介绍：激活进程按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CTaskListDlg::OnBnClickedBtnactive() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //激活进程
	 ActivateProcess(&g_tlist[nItemIndex]);
   }
}

/***************************程序清单4-11***********************/
/*
*函数介绍：终止进程按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CTaskListDlg::OnBnClickedBtnterminate() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //终止进程
	 KillProcess(&g_tlist[nItemIndex]);
   }
   //刷新进程列表
   SendMessage(WM_COMMAND, (WPARAM)IDC_BTNREFRESH, 0);
}
