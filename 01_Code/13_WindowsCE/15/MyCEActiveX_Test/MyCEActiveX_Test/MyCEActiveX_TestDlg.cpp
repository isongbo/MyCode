// MyCEActiveX_TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyCEActiveX_Test.h"
#include "MyCEActiveX_TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyCEActiveX_TestDlg �Ի���

CMyCEActiveX_TestDlg::CMyCEActiveX_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyCEActiveX_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCEActiveX_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyCEActiveX_TestDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_TEST, &CMyCEActiveX_TestDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


BEGIN_EVENTSINK_MAP(CMyCEActiveX_TestDlg, CDialog)
	ON_EVENT(CMyCEActiveX_TestDlg, 5678, 1 /* OnMsgChange */, OnMsgChangeMyceactivexctrl, VTS_NONE)
END_EVENTSINK_MAP()

// CMyCEActiveX_TestDlg ��Ϣ�������

BOOL CMyCEActiveX_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//����MyCEActiveX�ؼ�����
	CRect rc(0,0,100,100);
	m_myCEActiveX.CreateControl(m_myCEActiveX.GetClsid(), L" ", 
	WS_VISIBLE,rc,this,5678,NULL,FALSE,NULL); 
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//����MyCEActiveX�ؼ�ʹ��
void CMyCEActiveX_TestDlg::OnBnClickedBtnTest()
{
   m_myCEActiveX.SetMsgContext(L"��ӭʹ��Eric������ACTIVEX�ؼ�");
   m_myCEActiveX.ShowMessage();
}

//MyCEActiveX�ؼ�MsgContext���Ա��ı��¼�
void CMyCEActiveX_TestDlg::OnMsgChangeMyceactivexctrl() 
{
	AfxMessageBox(L"MsgContext�����ѱ��ı�");	
}
