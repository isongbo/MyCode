// MFCListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCList.h"
#include "MFCListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg dialog

CMFCListDlg::CMFCListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCListDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCListDlg)
	DDX_Control(pDX, IDC_STYLE, m_wndStyle);
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCListDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_STYLE, OnSelchangeStyle)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg message handlers

BOOL CMFCListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_wndStyle.SetCurSel(3);
	//初始化列表控件
    InitListCtrl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCListDlg::InitListCtrl()
{
   // 1 创建图标列表
   m_ilNormal.Create(IDB_NORMAL,32,1,RGB(0,0,0));
   m_ilSmall.Create(IDB_SMALL,16,1,RGB(0,0,0));
   // 2 将图标列表设置到控件
   m_wndList.SetImageList(&m_ilNormal,LVSIL_NORMAL);
   m_wndList.SetImageList(&m_ilSmall,LVSIL_SMALL);
   // 3 添加列
   m_wndList.InsertColumn(0,"名称",LVCFMT_LEFT,100);
   m_wndList.InsertColumn(1,"大小",LVCFMT_LEFT,100);
   m_wndList.InsertColumn(2,"类型",LVCFMT_LEFT,100);
   m_wndList.InsertColumn(3,"创建日期",LVCFMT_LEFT,150);
   // 4 添加选项
   m_wndList.InsertItem(0,"毕业设计.doc",1);
   m_wndList.SetItemText(0,1,"125k");
   m_wndList.SetItemText(0,3,"2015-02-10");
   m_wndList.InsertItem(1,"软件安装包",0);
   m_wndList.SetItemText(1,2,"文件夹");
   m_wndList.SetItemText(1,3,"2014-10-10");
   //5 显示c:\的文件和文件夹
   ShowData("c:");

   // Ole库的初始化
    AfxOleInit();
   //6 设置控件的背景图片
   m_wndList.SetBkImage("你的图片路径");
   // 设置字体的背景色透明
   m_wndList.SetTextBkColor(CLR_NONE);


}

void CMFCListDlg::ShowData(CString strPath)
{
   // 添加新的数据前，首先将列表控件的数据清空
	m_wndList.DeleteAllItems();
   // 清空保存路径的字符串链表
	m_lstPath.RemoveAll();

	//结合CFileFind类，查找获取文件信息在列表
   //控件中显示
	CFileFind find;
	BOOL bRet=find.FindFile(strPath+"/*.*");
	int nItem=0;//列表控件的选项的索引
	while(bRet)
	{
		bRet=find.FindNextFile();
		CString strName=find.GetFileName();
		if(find.IsDirectory())
		{
           m_wndList.InsertItem(nItem,strName,0);
		   m_wndList.SetItemText(nItem,2,"文件夹");

		}
		else
		{
           m_wndList.InsertItem(nItem,strName,1);
		   //获取文件长度
		   DWORD nLen=find.GetLength();
		   CString strLen;
		   strLen.Format("%d k",nLen/1024);
		   m_wndList.SetItemText(nItem,1,strLen);
		}
		//添加创建日期
		CTime t;
		find.GetLastWriteTime(t);
        CString strTime=t.Format("%Y-%m-%d %H:%M");
		m_wndList.SetItemText(nItem,3,strTime);
	    /*
		//添加选项的同时，在附加数据中保存路径的地址
		CString *pPath=new CString;
		*pPath=find.GetFilePath();
		m_wndList.SetItemData(nItem,(DWORD)pPath);
        */
		m_lstPath.AddTail(find.GetFilePath());
        nItem++; 
	}
	//结束查找
	find.Close();
}

void CMFCListDlg::OnSelchangeStyle() 
{
	// 1 获取控件的当前选择项
	int nSel=m_wndStyle.GetCurSel();
	switch(nSel)
	{
	case 0://图标
		m_wndList.ModifyStyle(
			LVS_SMALLICON|LVS_REPORT|LVS_LIST,LVS_ICON);
		break;
	case 1://小图标
		m_wndList.ModifyStyle(
			LVS_ICON|LVS_REPORT|LVS_LIST,LVS_SMALLICON);
		break;
	case 2://列表
		m_wndList.ModifyStyle(
			LVS_ICON|LVS_REPORT|LVS_SMALLICON,LVS_LIST );
		break;
	case 3://报表
		m_wndList.ModifyStyle(
			LVS_ICON|LVS_LIST|LVS_SMALLICON,LVS_REPORT  );
		break;
	default:
		m_wndList.ModifyStyle(
			LVS_ICON|LVS_LIST|LVS_SMALLICON,LVS_REPORT  );
		break;
	}
}

void CMFCListDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 1 获取列表控件的当前选项的索引
    LPNMITEMACTIVATE pItem=(LPNMITEMACTIVATE)pNMHDR;
    int nItem=pItem->iItem;
	if (nItem==-1)return;
	/*
	// 2 根据索引，得到选项的附加数据
	CString* pPath=
		(CString*)m_wndList.GetItemData(nItem);
    // 3 显示指定路径下的文件和文件夹
	ShowData(*pPath);
	*/
    CString strPath=
		m_lstPath.GetAt(m_lstPath.FindIndex(nItem));
	ShowData(strPath);
	*pResult = 0;
}
