// MyCEActiveX_TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCEActiveX_Test.h"
#include "MyCEActiveX_TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyCEActiveX_TestDlg 对话框

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

// CMyCEActiveX_TestDlg 消息处理程序

BOOL CMyCEActiveX_TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//创建MyCEActiveX控件对象
	CRect rc(0,0,100,100);
	m_myCEActiveX.CreateControl(m_myCEActiveX.GetClsid(), L" ", 
	WS_VISIBLE,rc,this,5678,NULL,FALSE,NULL); 
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//测试MyCEActiveX控件使用
void CMyCEActiveX_TestDlg::OnBnClickedBtnTest()
{
   m_myCEActiveX.SetMsgContext(L"欢迎使用Eric制作的ACTIVEX控件");
   m_myCEActiveX.ShowMessage();
}

//MyCEActiveX控件MsgContext属性被改变事件
void CMyCEActiveX_TestDlg::OnMsgChangeMyceactivexctrl() 
{
	AfxMessageBox(L"MsgContext属性已被改变");	
}
