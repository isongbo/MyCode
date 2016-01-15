// CallDLLByStaticDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallDLLByStatic.h"
#include "CallDLLByStaticDlg.h"
#include "MyCEDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCallDLLByStaticDlg 对话框

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


// CCallDLLByStaticDlg 消息处理程序

BOOL CCallDLLByStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


//演示静态调用DLL
void CCallDLLByStaticDlg::OnBnClickedBtnCall()
{
	//TestDll函数为MyCEDLL.dll中的一个输出函数
	TestDll();
}
