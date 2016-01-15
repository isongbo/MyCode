// CEComClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CEComClient.h"
#include "CEComClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCEComClientDlg 对话框

CCEComClientDlg::CCEComClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCEComClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCEComClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCEComClientDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CCEComClientDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CCEComClientDlg 消息处理程序

BOOL CCEComClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//调用COM  方法
void CCEComClientDlg::OnBnClickedBtnCall()
{
	HRESULT hr; 
	CLSID clsid;
	ISimple *pSimple = NULL;
	//初始化COM库,对组件实例化
	hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//得到CLSID
	hr = CLSIDFromProgID(OLESTR("CEComServer.Simple.1"),&clsid); 
	if(FAILED(hr)) 
	{
		AfxMessageBox(L"未找到ID");  
		goto error;
	}
	//得到ISimple COM接口
	CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,__uuidof(ISimple),(void**)&pSimple);  
	if(pSimple == NULL)    
	{
		AfxMessageBox(L"接口指针失败"); 
		goto error ;
	}

	//调用ISimple方法
	 pSimple->ShowSvrMsg();	

error:
	 //释放ISimple接口
	 if (pSimple != NULL)
	 {
		pSimple->Release();
		pSimple = NULL;
	 }

	 //释放COM组件库
	 CoUninitialize();
}
