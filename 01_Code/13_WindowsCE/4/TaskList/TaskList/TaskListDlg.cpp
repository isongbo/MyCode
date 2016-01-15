// TaskListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskList.h"
#include "TaskListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTaskListDlg �Ի���

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


// CTaskListDlg ��Ϣ�������

BOOL CTaskListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//���ý����б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("������"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(1,_T("���������"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(2, _T("�߳���"), LVCFMT_LEFT, rt.Width() * 0.30);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
*�������ܣ��õ�CEϵͳ�����е������б�
*��ڲ�����(��)
*���ڲ�����pList ���洢�õ������б���Ϣ
*����ֵ�����صõ���������
*/
DWORD CTaskListDlg::GetTaskListCE( PTASK_LIST pList) { 

  HINSTANCE         hKernel        = NULL; 
  HINSTANCE         hProcessSnap   = NULL; 
  PROCESSENTRY32 pe32           = {0}; 
  DWORD          dwTaskCount    = 0; 
  

  //״̬toolhelp.dll��̬���ӿ�
  hKernel = LoadLibrary(_T("toolhelp.dll")); 
  
  if (!hKernel) {
	  ::MessageBox(NULL, L"Toolhelp.dll����ʧ��", L"�����о�", MB_OK);
    return 0;
  }
  
  //��������ӳ��
  hProcessSnap = (HINSTANCE)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
  
  //���ʧ�ܣ����˳�
  if (hProcessSnap == (HANDLE)-1) 
    return 0; 
  
  dwTaskCount = 0; 
  
  //���ñ������������ݵı����Ľṹ��С            
  pe32.dwSize = sizeof(PROCESSENTRY32);
  //��ȡ��һ�����̣������˽�����Ϣд����̽ṹ�ı���pe32��          
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
      
      ++dwTaskCount;   //������Ŀ��1
      ++pList;         //�Ƶ���һ���ṹ�ڴ��
    } 
    while (Process32Next(hProcessSnap, &pe32)); //������һ������
  } 
  else 
    dwTaskCount = 0;    // 
 
  CloseHandle (hProcessSnap); 
  return dwTaskCount; 
}

/*
*�������ܣ��õ���������������;��
*��ڲ�����te ��������Ϣ�б�ָ��
*���ڲ�����te ��������Ϣ�б�ָ��
*����ֵ: (��)
*/
void CTaskListDlg::GetWindowTitles( PTASK_LIST_ENUM te ) { 
  // enumerate all windows 
  EnumWindows((WNDENUMPROC) EnumWindowsProc, (LPARAM) te ); 
}
/*
*�������ܣ��ص���������EnumWindows����
*��ڲ�����hwnd ��������
*          lParam : ������Ϣ�б�ָ��
*���ڲ�����lParam ��������Ϣ�б�ָ��
*����ֵ: True����ɹ���False����ʧ��
*/
BOOL CALLBACK CTaskListDlg::EnumWindowsProc( HWND hwnd, DWORD lParam ) { 
  DWORD             pid = 0; 
  DWORD             i; 
  TCHAR             buf[TITLE_SIZE]; 
  PTASK_LIST_ENUM   te = (PTASK_LIST_ENUM)lParam; 
  PTASK_LIST        tlist = te->tlist; 
  DWORD             numTasks = te->numtasks; 
  
  // ���ݴ��ھ�����õ����̱�ʶ
  if (!GetWindowThreadProcessId( hwnd, &pid )) { 
    return TRUE; 
  } 
  //���ҽ��̱�ʶ���б�����ͬ�Ľ��̱�ʶ
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
  //�����оٴ���
  return TRUE; 
}

/*
*�������ܣ�������̷���
*��ڲ�����tlist �� ������Ϣ
*���ڲ�����(��)
*����ֵ: True���ɹ���False��ʧ��
*/
bool CTaskListDlg::ActivateProcess(PTASK_LIST tlist)
{
  //�ж��Ƿ���������ڣ�����ھͼ�����
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
*�������ܣ���ֹ���̷���
*��ڲ�����tlist �� ������Ϣ
*���ڲ�����(��)
*����ֵ: True���ɹ���False��ʧ��
*/
bool CTaskListDlg::KillProcess( PTASK_LIST tlist ) 
{ 
  HANDLE            hProcess; 

  //���û��������,����TerminateProcess��ֹ����
  if (!tlist->hwnd)  
  { 
	//���ݽ��̱�ʶ�����ؽ��̾��
    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, tlist->dwProcessId ); 
    //�ɹ��Ļ�����ֹ����
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
  //�������壬���������ڹر���Ϣ����ֹ�߳� 
  else
  {
    ::PostMessage( tlist->hwnd, WM_CLOSE, 0, 0 ); 
    return TRUE;
  }
}


/*
*�������ܣ�ˢ�°�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBnClickedBtnrefresh() 
{
	TASK_LIST_ENUM processList; //�����б���Ϣ
	TCHAR numBuf[10]; //�洢�����е��߳���

	memset(&g_tlist, 0, sizeof(TASK_LIST) * MAX_TASKS);
	//�õ������б���Ϣ
	DWORD nNumTasks = GetTaskListCE(g_tlist);
	processList.numtasks = nNumTasks;
	processList.tlist = g_tlist;
	//���½����б���Ϣ����ȡ�����ھ���ͱ���
	GetWindowTitles(&processList);

    CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	//����б��������Ŀ
	pListCtrl->DeleteAllItems();
    memset(&numBuf,0,sizeof(numBuf));

	//���б������ӽ��������Ϣ
	for (int i=0;i<processList.numtasks;i++)
	{
        //����exe�������������߳���
      pListCtrl->InsertItem(i,_T("Test"));
	  pListCtrl->SetItemText(i,0,processList.tlist[i].ProcessName);
	  pListCtrl->SetItemText(i,1,processList.tlist[i].WindowTitle);	 
	  _itow(processList.tlist[i].cntThreads,numBuf,10);
	  pListCtrl->SetItemText(i,2,numBuf);
	}

}

/***************************�����嵥4-10***********************/
/*
*�������ܣ�������̰�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBnClickedBtnactive() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //�������
	 ActivateProcess(&g_tlist[nItemIndex]);
   }
}

/***************************�����嵥4-11***********************/
/*
*�������ܣ���ֹ���̰�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBnClickedBtnterminate() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //��ֹ����
	 KillProcess(&g_tlist[nItemIndex]);
   }
   //ˢ�½����б�
   SendMessage(WM_COMMAND, (WPARAM)IDC_BTNREFRESH, 0);
}
