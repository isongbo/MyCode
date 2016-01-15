// ResDllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ResDllTest.h"
#include "ResDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//�����Դ�����ʶ
#define IDB_RESBMP                      101
#define IDI_RESICON                     102

// CResDllTestDlg �Ի���

CResDllTestDlg::CResDllTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CResDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CResDllTestDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_LOAD, &CResDllTestDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_FREE, &CResDllTestDlg::OnBnClickedBtnFree)
	ON_BN_CLICKED(IDC_BTN_BMP, &CResDllTestDlg::OnBnClickedBtnBmp)
	ON_BN_CLICKED(IDC_BTN_ICON, &CResDllTestDlg::OnBnClickedBtnIcon)
END_MESSAGE_MAP()


// CResDllTestDlg ��Ϣ�������

BOOL CResDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//������ԴDLL
void CResDllTestDlg::OnBnClickedBtnLoad()
{
	//����DLL
	m_hDll = LoadLibrary(_T("ResDll.dll"));
	if (m_hDll == NULL)
	{
		AfxMessageBox(_T("����Dllʧ��"));
	}	
}

//�ͷ���ԴDLL
void CResDllTestDlg::OnBnClickedBtnFree()
{
	//�ͷ�DLL
	if (m_hDll != NULL)	
	{
		FreeLibrary(m_hDll);
	}	
}

//��ʾ��Դ���λͼ
void CResDllTestDlg::OnBnClickedBtnBmp()
{
	HBITMAP hOldBmp;
	//��DLL�����ָ������Դ
	HBITMAP bmp = LoadBitmap(m_hDll,MAKEINTRESOURCE(IDB_RESBMP));	
	if (bmp == NULL)
	{
		AfxMessageBox(_T("����λͼ��Դʧ��"));
		return;
	}

	//��û�ͼ������Դ
	CDC memdc;
	CDC *pDC = new CClientDC(this);
	memdc.CreateCompatibleDC(pDC);
	hOldBmp = (HBITMAP)memdc.SelectObject(bmp);
	pDC->BitBlt(0,0,200,200,&memdc,0,0,SRCCOPY);
	memdc.SelectObject(hOldBmp);
	//�ͷ���Դ
	DeleteObject(bmp);
	//�ͷ�DC
	delete pDC;
	pDC = NULL;
}

//��ʾ��Դ���ͼ��
void CResDllTestDlg::OnBnClickedBtnIcon()
{
	//��DLL�����ָ������Դ
	HICON icn = LoadIcon(m_hDll,MAKEINTRESOURCE(IDI_RESICON));
	if (icn == NULL)
	{
		AfxMessageBox(_T("����ͼ����Դʧ��"));
		return;
	}
	CDC *pDC = new CClientDC(this);
	//����ͼ��
	pDC->DrawIcon(CPoint(100,100),icn);
	DeleteObject(icn);
	//�ͷ�CDC����
	delete pDC;		
	pDC = NULL;
}
