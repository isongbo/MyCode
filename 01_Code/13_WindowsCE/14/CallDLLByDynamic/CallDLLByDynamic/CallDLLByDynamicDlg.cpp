// CallDLLByDynamicDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallDLLByDynamic.h"
#include "CallDLLByDynamicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCallDLLByDynamicDlg �Ի���

CCallDLLByDynamicDlg::CCallDLLByDynamicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallDLLByDynamicDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallDLLByDynamicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallDLLByDynamicDlg, CDialog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CCallDLLByDynamicDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CCallDLLByDynamicDlg ��Ϣ�������

BOOL CCallDLLByDynamicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//��̬����DLLʾ��
void CCallDLLByDynamicDlg::OnBnClickedBtnCall()
{
	//1������DLL
	HINSTANCE	hModule = LoadLibrary(_T("MyCEDLL.dll"));
    if (hModule == NULL)
	{
		AfxMessageBox(_T("����DLLʧ��"));
		return;
	}
   //�õ�MyCEDLL��TestDll������ַ
	pTestDll pFun = (pTestDll)GetProcAddress(hModule,_T("TestDll"));
	if ( pFun == NULL )
	{
		AfxMessageBox(_T("��ȡTestDll����ʧ��"));
	}
	else
	{
		//ִ��MyCEDLL��TestDll����
		pFun();
	}

    //3���ͷ�DLL;
	FreeLibrary(hModule);
}
