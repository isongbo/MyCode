// CallDLLByStaticDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallDLLByStatic.h"
#include "CallDLLByStaticDlg.h"
#include "MyCEDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCallDLLByStaticDlg �Ի���

CCallDLLByStaticDlg::CCallDLLByStaticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallDLLByStaticDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallDLLByStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallDLLByStaticDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CCallDLLByStaticDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CCallDLLByStaticDlg ��Ϣ�������

BOOL CCallDLLByStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


//��ʾ��̬����DLL
void CCallDLLByStaticDlg::OnBnClickedBtnCall()
{
	//TestDll����ΪMyCEDLL.dll�е�һ���������
	TestDll();
}
