// ASynDllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ASynDllTest.h"
#include "ASynDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CASynDllTestDlg �Ի���

CASynDllTestDlg::CASynDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CASynDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CASynDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CASynDllTestDlg, CDialog)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_CALL, &CASynDllTestDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CASynDllTestDlg ��Ϣ�������

BOOL CASynDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//����ASynDll
	m_hModule = LoadLibrary(_T("ASynDll.dll"));
    if (m_hModule == NULL)
	{
		AfxMessageBox(_T("����DLLʧ��"));
		return FALSE;
	}
	//�õ�ASynDll��QueryData������ַ
	m_pQueryData = (TQueryData)GetProcAddress(m_hModule,_T("QueryData"));
	if ( m_pQueryData == NULL )
	{
		AfxMessageBox(_T("��ȡQueryData����ʧ��"));
		FreeLibrary(m_hModule);
		return FALSE;
	}
	
	//�õ�ASynDll��SetCallbackProcAddr������ַ
	m_pSetCallbackProcAddr = 
		(TSetCallbackProcAddr)GetProcAddress(m_hModule,_T("SetCallbackProcAddr"));
	if ( m_pSetCallbackProcAddr == NULL )
	{
		AfxMessageBox(_T("��ȡSetCallbackProcAddr����ʧ��"));
		FreeLibrary(m_hModule);
		return FALSE ;
	}

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//�ص���������DLL��QueryData����ִ�����ʱִ��
void QueryReadNotify(long lDBData)
{
	TCHAR sDBData[11];
	TCHAR sMessage[64];
	_ltow(lDBData, sDBData, 10);
	wcscpy(sMessage, _T("DBData from DLL is: "));
	wcscat(sMessage, sDBData);
	::MessageBox(0, sMessage, 
		_T("Sample App"), MB_OK + MB_ICONINFORMATION);
};

void CASynDllTestDlg::OnDestroy()
{
	//�ͷ�AsynDll��
	FreeLibrary(m_hModule);
	CDialog::OnDestroy();	
}

//����DLL
void CASynDllTestDlg::OnBnClickedBtnCall()
{
	long lProcAdr;

   //���ûص�������ַ
   lProcAdr = (long)(&QueryReadNotify);
   m_pSetCallbackProcAddr(lProcAdr);
   
   //ִ���첽��ѯ����
   m_pQueryData();
}
