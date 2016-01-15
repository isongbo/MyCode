// EDB_SampleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EDB_Sample.h"
#include "EDB_SampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEDB_SampleDlg 对话框

CEDB_SampleDlg::CEDB_SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEDB_SampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEDB_SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEDB_SampleDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_ENUM_VOLUMES, &CEDB_SampleDlg::OnBnClickedBtnEnumVolumes)

END_MESSAGE_MAP()


// CEDB_SampleDlg 消息处理程序

BOOL CEDB_SampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CEDB_SampleDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_EDB_SAMPLE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_EDB_SAMPLE_DIALOG));
	}
}
#endif

//根据数据库卷GUID，列举其中的数据库
void EnumDatabasesInVolume(CEGUID *pGuid)
{
	DWORD dwError;          // GetLastError函数返回值
	TCHAR szMsg[128];       // 错误信息
	HANDLE hEnumDB;         // 列举数据库句柄
	CEOID CeOid;            // 数据库对象标识
	CEOIDINFOEX CeObjectInfo; // 数据库对象基本信息

	//查找所有数据库卷，以及所有数据库卷中的数据库
	hEnumDB = CeFindFirstDatabaseEx (pGuid, 0);

	//枚举句柄无效
	if (hEnumDB == INVALID_HANDLE_VALUE)
	{
		if (GetLastError () == ERROR_OUTOFMEMORY)
			TRACE(L"Out of memory.\n");
		else
			TRACE(L"Unknown error.\n");

		return;
	}

	//开始枚举数据库
	while ((CeOid = CeFindNextDatabaseEx(hEnumDB, NULL)) != 0)
	{
		ZeroMemory(&CeObjectInfo,sizeof(CeObjectInfo));
		CeObjectInfo.wVersion = 2;
		// 得到数据库信息
		if (!CeOidGetInfoEx2(pGuid, CeOid, &CeObjectInfo))
		{
			dwError = GetLastError();
			TRACE(L"the last error :%d\n",dwError);
			// 关闭查找句柄
			CloseHandle (hEnumDB);  

			return;
		}
		else
		{
			//判断是数据库类型
			if (CeObjectInfo.wObjType == OBJTYPE_DATABASE)
			{
				TRACE(L"The name of the database is: %s \n",
					CeObjectInfo.infDatabase.szDbaseName);
			}
		}
	}

	//关闭查找句柄
	CloseHandle (hEnumDB);

}

//枚举系统的所有已经装载的数据库卷以及数据库卷中的数据库
void CEDB_SampleDlg::OnBnClickedBtnEnumVolumes()
{
   CEGUID ceguid;  
   TCHAR szVolumeName[CEDB_MAXDBASENAMELEN];
   //创建无效的GUID

   CREATE_INVALIDEDBGUID(&ceguid);
   //列举已装载的数据库卷
   while (CeEnumDBVolumes(&ceguid,szVolumeName,CEDB_MAXDBASENAMELEN-1))
   {
	   TRACE(L"Enum mounted volumes: %s\n",szVolumeName);

		ZeroMemory(szVolumeName,CEDB_MAXDBASENAMELEN * 2);
	   //列举其中的数据库
		EnumDatabasesInVolume(&ceguid);
	   //
   }
}
