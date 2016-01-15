// EDBUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EDBUse.h"
#include "EDBUseDlg.h"

#include "DBStudent.h"
#include "StudentInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEDBUseDlg 对话框

CEDBUseDlg::CEDBUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEDBUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEDBUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEDBUseDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNREFRESH, &CEDBUseDlg::OnBnClickedBtnrefresh)
	ON_BN_CLICKED(IDC_BTNADD, &CEDBUseDlg::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTNEDIT, &CEDBUseDlg::OnBnClickedBtnedit)
	ON_BN_CLICKED(IDC_BTNDELETE, &CEDBUseDlg::OnBnClickedBtndelete)
END_MESSAGE_MAP()


// CEDBUseDlg 消息处理程序

BOOL CEDBUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("ID"), LVCFMT_LEFT, rt.Width() * 0.2);
    pListCtrl->InsertColumn(1,_T("NAME"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(2, _T("BIRTHDAY"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(3, _T("STATUE"), LVCFMT_LEFT, rt.Width() * 0.2);

	//全行选择
	::SendMessage(pListCtrl->m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
	LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	//刷新显示记录
	OnBnClickedBtnrefresh();

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//刷新记录
void CEDBUseDlg::OnBnClickedBtnrefresh()
{
	//定义学生记录对象
	REC_STUDENT *pRecStudent = NULL;
	DWORD iRecCount = 0;

	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	//先删除全部显示
	pListCtrl->DeleteAllItems();
	//查询所有学生记录
	if (CDBStudent::QueryAllRecords(&iRecCount,&pRecStudent))
	{
		//显示记录
		for (int i=0;i< iRecCount ; i++)
		{
			pListCtrl->InsertItem(i,L"");
			//添加学生编号
			pListCtrl->SetItemText(i,0,(pRecStudent+i)->szNo);
			//添加学生姓名
			pListCtrl->SetItemText(i,1,(pRecStudent+i)->szName);
			//添加学生生日，此处需要做些转换
			SYSTEMTIME systime;
			FileTimeToSystemTime(&((pRecStudent+i)->ftBirthday),&systime);
			TCHAR szBirthday[11];
			swprintf(szBirthday,_T("%d-%d-%d"),systime.wYear,systime.wMonth,systime.wDay);
			pListCtrl->SetItemText(i,2,szBirthday);
			//添加学生身高，此处需要将数字转换成字符串
			TCHAR szStature[5];
			_itow((pRecStudent+i)->iStature,szStature,10);
			pListCtrl->SetItemText(i,3,szStature);
		}
		//释放内存
		for (int i=0; i<iRecCount;i++)
		{
			//释放IMAGE动态内存
			if ((pRecStudent+i)->blImage.lpb != NULL)
			{
				LocalFree(HLOCAL((pRecStudent+i)->blImage.lpb));
				(pRecStudent+i)->blImage.lpb = NULL;
			}

			//释放学生记录数组内存
			delete[] pRecStudent;
			pRecStudent = NULL;
		}
	}
}

//添加记录
void CEDBUseDlg::OnBnClickedBtnadd()
{
	//定义学生记录
	REC_STUDENT rec_stu;
	//打开学生记录添加对话框
	CStudentInputDlg inputDlg;
	if (inputDlg.DoModal() == IDOK)
	{
		//得到编号
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//得到姓名
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//得到出生日期
		SYSTEMTIME timeDest;
		FILETIME ftTime;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		ZeroMemory(&(rec_stu.ftBirthday),sizeof(rec_stu.ftBirthday));
		SystemTimeToFileTime(&timeDest, &ftTime);
		rec_stu.ftBirthday = ftTime;
		//得到身高值
		rec_stu.iStature = inputDlg.m_stature;

		//学生照片
		rec_stu.blImage = inputDlg.m_blImage;

		//添加学生记录
		if (!CDBStudent::AddNewStudent(&rec_stu))
		{
			AfxMessageBox(L"添加记录失败");
		}
	}
	//添加完成之后，调用刷新按钮单击方法
	OnBnClickedBtnrefresh();
}

//编辑记录
void CEDBUseDlg::OnBnClickedBtnedit()
{
	//定义学生记录
	REC_STUDENT rec_stu;
	DWORD dwRead = 0;
	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	//得到待编辑的学生编号
	CString strNo = pListCtrl->GetItemText(iItemIndex,0);
	ZeroMemory(&rec_stu,sizeof(rec_stu));
	
	//得到对应学生编号的学生信息
	if (!CDBStudent::QueryStudent(strNo,&rec_stu))
	{
		AfxMessageBox(L"获取该学生信息失败");
		return;
	}

	//打开学生信息编辑框
	CStudentInputDlg inputDlg;
	//同步编辑对话框输入框值
	inputDlg.m_no = rec_stu.szNo;
	inputDlg.m_name = rec_stu.szName;
	SYSTEMTIME tmpTime;
	FileTimeToSystemTime(&(rec_stu.ftBirthday),&tmpTime);
	inputDlg.m_birthday = tmpTime;
	inputDlg.m_stature = rec_stu.iStature;
	inputDlg.m_blImage = rec_stu.blImage;
	
	if (inputDlg.DoModal() == IDOK)
	{
		ZeroMemory(&rec_stu,sizeof(rec_stu));
		//得到编号
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//得到姓名
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//得到出生日期
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//得到身高值
		rec_stu.iStature = inputDlg.m_stature;

		//设置照片
		rec_stu.blImage = inputDlg.m_blImage;
		
		//存入修改后的学生信息
		if (!CDBStudent::EditStudent(strNo,&rec_stu))
		{
			AfxMessageBox(L"编辑记录失败");
		}
		//
	}
	//释放内存
	if (rec_stu.blImage.lpb != NULL)
	{
		LocalFree(HLOCAL(rec_stu.blImage.lpb));
		rec_stu.blImage.lpb = NULL;
	}
	//刷新记录
	OnBnClickedBtnrefresh();	

}

//删除记录
void CEDBUseDlg::OnBnClickedBtndelete()
{
	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	//得到学生编号
	CString strNo = pListCtrl->GetItemText(iItemIndex,0);
	//删除学生记录
	if (!CDBStudent::DeleteStudent(strNo))
	{
		AfxMessageBox(L"删除记录失败");
	}
	//刷新记录
	OnBnClickedBtnrefresh();		
}


