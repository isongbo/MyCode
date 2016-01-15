// ConnectionClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ConnectionClient.h"
#include "ConnectionClientDlg.h"
#include "sink.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CConnectionClientDlg 对话框

CConnectionClientDlg::CConnectionClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectionClientDlg::IDD, pParent)
	, m_number1(0)
	, m_number2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConnectionClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_NUMBER1, m_number1);
	DDX_Text(pDX, IDC_EDT_NUMBER2, m_number2);
}

BEGIN_MESSAGE_MAP(CConnectionClientDlg, CDialog)

	ON_BN_CLICKED(IDC_BTN_EXEC, &CConnectionClientDlg::OnBnClickedBtnExec)
END_MESSAGE_MAP()


// CConnectionClientDlg 消息处理程序

BOOL CConnectionClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//执行按钮单击事件，调用IAdd的Add方法
void CConnectionClientDlg::OnBnClickedBtnExec()
{
	HRESULT  hr;
	IUnknown *pSinkUnk;
	CSink *pSink = NULL;
	CComPtr<IAdd> pAdd;
	//定义连接点容器指针
	IConnectionPointContainer   * pCPC;
	//定义连接点指针
    IConnectionPoint          * pCP;   
    DWORD				        dwAdvise; 

	UpdateData(TRUE);
	//初始化COM库,对组件实例化
	hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//得到IAdd COM接口
	hr =pAdd.CoCreateInstance(CLSID_Add);
	ASSERT(hr == S_OK);

    //判断IAdd接口是否有连接点事件，并得到连接点容器对象
    hr = pAdd->QueryInterface(IID_IConnectionPointContainer,(void **)&pCPC);
    ASSERT(SUCCEEDED(hr));
	//得到连接点对象
    hr = pCPC->FindConnectionPoint(DIID__IAddEvents,&pCP);
	ASSERT(SUCCEEDED(hr));
	//从CSink类创建一个连接点通知对象
    pSink = new CSink();
    ASSERT(pSink !=NULL);
	//得到CSink类的接口指针
	hr = pSink->QueryInterface (IID_IUnknown,(void **)&pSinkUnk);
	//同连接点对象建立连接
	hr = pCP->Advise(pSinkUnk,&dwAdvise); 
    //执行IAdd接口的Add方法
    pAdd->Add(m_number1 ,m_number2);

	////断开与连接点对象的连接
	pCP->Unadvise(dwAdvise); 									
	pCP->Release();	
	//释放连接点容器对象
	pCPC->Release();
	//释放COM库
	CoUninitialize();
}
