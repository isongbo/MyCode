// TestAdoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestAdo.h"
#include "TestAdoDlg.h"

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
// CTestAdoDlg dialog

CTestAdoDlg::CTestAdoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestAdoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestAdoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestAdoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestAdoDlg)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestAdoDlg, CDialog)
	//{{AFX_MSG_MAP(CTestAdoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_DB, OnOpenDb)
	ON_BN_CLICKED(IDC_OPEN_TABLE, OnOpenTable)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_SQL, OnSql)
	ON_BN_CLICKED(IDC_TRANS, OnTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestAdoDlg message handlers

BOOL CTestAdoDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestAdoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestAdoDlg::OnPaint() 
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
HCURSOR CTestAdoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestAdoDlg::OnOpenDb() 
{
	// 连接指定的数据库
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDCANCEL)return;
	CString strPath=dlg.GetPathName();
	if(!m_db.OpenMDB(strPath))
	{
     MessageBox("连接数据库失败！");
	}
}

void CTestAdoDlg::OnOpenTable() 
{
	// TODO: Add your control notification handler code here
	CAdoRecordset set;
	if (!set.OpenTable("TBL_MSG",&m_db))
	{
     MessageBox("打开表失败！");
	}
	//获取记录集的数据添加到列表控件
  ShowData(&set); 
}

void CTestAdoDlg::ShowData(CAdoRecordset *pSet)
{
    // 1 清空列表控件的行和列
    m_wndList.DeleteAllItems();
		while(m_wndList.DeleteColumn(0));
	  // 2 获取记录集的字段名称设置控件的列
		int nCount=pSet->GetFieldCount();
		CString strName;
    for (int i=0;i<nCount;i++)
    {
      pSet->GetFieldName(i,strName);
			m_wndList.InsertColumn(i,strName,
				LVCFMT_LEFT,100);
    }
		//3 获取记录集的数据设置控件的选项
    if(!pSet->IsBOF())//表不为空
		{
       pSet->MoveFirst();
		}
		int nItem=0;
		while(!pSet->IsEOF())
		{
			CString strValue;
			for (int i=0;i<nCount;i++)
			{
         pSet->GetFieldValue(i,strValue);
				 if (0==i)
				 {
					 m_wndList.InsertItem(nItem,strValue);
				 }
				 else
				 {
					 m_wndList.SetItemText(nItem,i,strValue);
				 }
			}
			nItem++;
			pSet->MoveNext();//移动到下一条记录 
		}

}

void CTestAdoDlg::OnAdd() 
{
   //1 获取表的数据到记录集
	 CAdoRecordset set;
	 set.OpenTable("TBL_MSG",&m_db);
	 //2 在记录集中添加一条记录
	 set.AddNew();
	 //3 设置每个字段的值
	 set.SetFieldValue(0,"99");
	 set.SetFieldValue(1,"99");
	 set.SetFieldValue(2,"999");
	 set.SetFieldValue(3,"9999");
	 set.SetFieldValue(4,"99999");
	 //4 更新到数据库
	 set.Update();
	 //5 重新显示
	 ShowData(&set);

}

void CTestAdoDlg::OnDel() 
{
   //1 获取表的数据到记录集
	 CAdoRecordset set;
	 set.OpenTable("TBL_MSG",&m_db);
	 //2 将指针移动到要删除的记录
	 set.MoveLast();
	 //3 执行删除操作
	 set.Delete();
	 //4 更新到数据库
	 set.Update();
	 //5 重新显示
	 ShowData(&set);
}

void CTestAdoDlg::OnUpdate() 
{
	// 修改最后一条记录的第二个字段的值为789
	//1 获取表的数据到记录集
	CAdoRecordset set;
	set.OpenTable("TBL_MSG",&m_db);
	//2 将记录集的指针移动到要修改的记录
	set.MoveLast();
	//3 重设字段的值
	set.SetFieldValue(1,"789");
	//4 更新到数据库
	set.Update();
	//5 重新显示
	ShowData(&set);

	
}

void CTestAdoDlg::OnSql() 
{
   CString strSql=
		 "insert into TBL_MSG(msg_id,msg_sender) values('999','999')";
	 m_db.OpenSql(strSql);
	 CAdoRecordset set;
	 set.OpenSql("select * from TBL_MSG",&m_db);
	 ShowData(&set);



}

void CTestAdoDlg::OnTrans() 
{
   // 1 启动事务
	 m_db.BeginTrans();
	 // 2 执行删除操作
	 CString strSql="delete from TBL_MSG";
	 m_db.OpenSql(strSql);
	 //3 打开表查看删除后的结果
	 OnOpenTable();
	 MessageBox("马上执行回滚操作!");
	 //4 执行回滚操作
	 m_db.EndTrans(FALSE);
	 //5 打开表查看回滚后的结果
	 OnOpenTable();
	 
}
