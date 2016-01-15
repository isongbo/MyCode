// TaskListDlg.h : 头文件
//

#pragma once

//定义用到的常量
#define TITLE_SIZE          64        //标题字符串的大小 
#define PROCESS_SIZE        MAX_PATH  //进程名字符串的大小
#define MAX_TASKS           25        //最大进程数

//定义进程信息结构
typedef struct _TASK_LIST {  
  DWORD dwProcessId;// 进程标识 
  DWORD cntThreads; // 此进程中的线程数
  HWND        hwnd; // 进程主窗口句柄
  TCHAR       ProcessName[PROCESS_SIZE]; //进程Exe文件名 
  TCHAR       WindowTitle[TITLE_SIZE]; //主窗口标题名
} TASK_LIST, *PTASK_LIST; 

//定义进程信息列表结构
typedef struct _TASK_LIST_ENUM { 
  PTASK_LIST  tlist; //进程信息列表
  DWORD       numtasks; //进程数
} TASK_LIST_ENUM, *PTASK_LIST_ENUM;


// CTaskListDlg 对话框
class CTaskListDlg : public CDialog
{
// 构造
public:
	CTaskListDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TASKLIST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
private:
	//定义存储进程信息机构体数组
	TASK_LIST g_tlist[MAX_TASKS];
public:
  //得到系统进程列表
  static DWORD GetTaskListCE(PTASK_LIST pList);

public:
	//得到进程主窗体标题
	static void  GetWindowTitles( PTASK_LIST_ENUM pe );
protected:
  static BOOL CALLBACK EnumWindowsProc( HWND hwnd, DWORD lParam );

private:
	//激活进程
	bool ActivateProcess(PTASK_LIST tlist);
	//终止进程
	bool KillProcess( PTASK_LIST tlist );

public:
	afx_msg void OnBnClickedBtnactive();
	afx_msg void OnBnClickedBtnterminate();
	afx_msg void OnBnClickedBtnrefresh();
};
