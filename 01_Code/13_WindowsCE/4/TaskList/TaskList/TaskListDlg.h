// TaskListDlg.h : ͷ�ļ�
//

#pragma once

//�����õ��ĳ���
#define TITLE_SIZE          64        //�����ַ����Ĵ�С 
#define PROCESS_SIZE        MAX_PATH  //�������ַ����Ĵ�С
#define MAX_TASKS           25        //��������

//���������Ϣ�ṹ
typedef struct _TASK_LIST {  
  DWORD dwProcessId;// ���̱�ʶ 
  DWORD cntThreads; // �˽����е��߳���
  HWND        hwnd; // ���������ھ��
  TCHAR       ProcessName[PROCESS_SIZE]; //����Exe�ļ��� 
  TCHAR       WindowTitle[TITLE_SIZE]; //�����ڱ�����
} TASK_LIST, *PTASK_LIST; 

//���������Ϣ�б�ṹ
typedef struct _TASK_LIST_ENUM { 
  PTASK_LIST  tlist; //������Ϣ�б�
  DWORD       numtasks; //������
} TASK_LIST_ENUM, *PTASK_LIST_ENUM;


// CTaskListDlg �Ի���
class CTaskListDlg : public CDialog
{
// ����
public:
	CTaskListDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TASKLIST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
private:
	//����洢������Ϣ����������
	TASK_LIST g_tlist[MAX_TASKS];
public:
  //�õ�ϵͳ�����б�
  static DWORD GetTaskListCE(PTASK_LIST pList);

public:
	//�õ��������������
	static void  GetWindowTitles( PTASK_LIST_ENUM pe );
protected:
  static BOOL CALLBACK EnumWindowsProc( HWND hwnd, DWORD lParam );

private:
	//�������
	bool ActivateProcess(PTASK_LIST tlist);
	//��ֹ����
	bool KillProcess( PTASK_LIST tlist );

public:
	afx_msg void OnBnClickedBtnactive();
	afx_msg void OnBnClickedBtnterminate();
	afx_msg void OnBnClickedBtnrefresh();
};
