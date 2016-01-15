// CreateProgressDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CreateProgress.h"
#include "CreateProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCreateProgressDlg �Ի���

CCreateProgressDlg::CCreateProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateProgressDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCreateProgressDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNEXEC, &CCreateProgressDlg::OnBnClickedBtnexec)
END_MESSAGE_MAP()


// CCreateProgressDlg ��Ϣ�������

BOOL CCreateProgressDlg::OnInitDialog()
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
void CCreateProgressDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CREATEPROGRESS_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CREATEPROGRESS_DIALOG));
	}
}
#endif


/*
*�������������ÿ�ִ���ļ�
*��ڲ�����FileName:�ַ���������ָ����ִ���ļ���
*���ڲ�����(��)
*����ֵ��true : ������óɹ���false���������ʧ��
*/
bool CCreateProgressDlg::WinExec(LPCTSTR FileName)
{
    PROCESS_INFORMATION processInfo; //���������Ϣ
    if (!CreateProcess(FileName, NULL, NULL, NULL, NULL
      , CREATE_NEW_CONSOLE
      , NULL, NULL, NULL, &processInfo))
    {
		return false;
	}
    CloseHandle(processInfo.hThread);
	CloseHandle(processInfo.hProcess);
	return true ;
}

//�����ⲿӦ�ó���
void CCreateProgressDlg::OnBnClickedBtnexec()
{
    WinExec(_T("iexplore"));	
}
