// IPC_MapFileDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "IPC_MapFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIPC_MapFileDlg 对话框

CIPC_MapFileDlg::CIPC_MapFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MapFileDlg::IDD, pParent)
	, m_Exist(FALSE)
	, m_Syn(FALSE)
	, m_Open(FALSE)
	, m_MemData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MapFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CKEXIST, m_Exist);
	DDX_Check(pDX, IDC_CKSYN, m_Syn);
	DDX_Check(pDX, IDC_CKOPEN, m_Open);
	DDX_Text(pDX, IDC_EDTDATA, m_MemData);
}

BEGIN_MESSAGE_MAP(CIPC_MapFileDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNOPEN, &CIPC_MapFileDlg::OnBnClickedBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, &CIPC_MapFileDlg::OnBnClickedBtnclose)
	ON_BN_CLICKED(IDC_BTNREAD, &CIPC_MapFileDlg::OnBnClickedBtnread)
	ON_BN_CLICKED(IDC_BTNWRITE, &CIPC_MapFileDlg::OnBnClickedBtnwrite)
	ON_BN_CLICKED(IDC_CKSYN, &CIPC_MapFileDlg::OnBnClickedCksyn)
END_MESSAGE_MAP()


// CIPC_MapFileDlg 消息处理程序

BOOL CIPC_MapFileDlg::OnInitDialog()
{
	// 禁止全屏显示
	m_bFullScreen = FALSE;

	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//初始化m_memFileMap变量
    if (!m_memFileMap.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("创建通讯窗口失败"));
	}
	m_memFileMap.m_OnMemDataChange = OnMemDataChange;

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

/***************************程序清单6-11***********************/
/*
*函数介绍：内存映射文件内容变化事件函数
*入口参数：pWnd指向窗体指针
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MapFileDlg::OnMemDataChange(CWnd *pWnd)
{
	CIPC_MapFileDlg * pDlg;
	pDlg = (CIPC_MapFileDlg*)pWnd;
	pDlg->m_MemData = pDlg->m_memFileMap.ReadBuffer();
	pDlg->UpdateData(FALSE);
}



/*
*函数介绍：打开内存映射按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBnClickedBtnopen() 
{
   WORD dReturnCode;
   m_memFileMap.m_MapName = _T("IPCMemFile");
   m_memFileMap.m_MaxSize = 1024;
   //打开内存映射文件
   dReturnCode = m_memFileMap.OpenFileMap(this);
   if (dReturnCode <= 0)
   {
	   AfxMessageBox(_T("创建失败"));
   }
   if (dReturnCode >=1)
   {
	   m_Open = true;
   }
   if (dReturnCode == 2) 
   {
	   m_Exist = true;
   }
   UpdateData(false);

}

/*
*函数介绍：关闭内存映射按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBnClickedBtnclose() 
{
   m_memFileMap.CloseFileMap();
   m_Open = false;
   m_Exist = false;
   UpdateData(false);
}

/*
*函数介绍：读取按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBnClickedBtnread() 
{
	m_MemData = m_memFileMap.ReadBuffer();
	UpdateData(FALSE);
}

/*
*函数介绍：写入数据按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBnClickedBtnwrite() 
{
   UpdateData(TRUE);
   m_memFileMap.WriteBuffer(m_MemData.GetBuffer(m_MemData.GetLength()));
}


/*
*函数介绍：是否同步复选框单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBnClickedCksyn() 
{
   UpdateData(TRUE);
   m_memFileMap.m_Syn = m_Syn;
}
