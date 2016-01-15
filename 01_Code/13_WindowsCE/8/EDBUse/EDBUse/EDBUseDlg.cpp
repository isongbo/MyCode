// EDBUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EDBUse.h"
#include "EDBUseDlg.h"

#include "DBStudent.h"
#include "StudentInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEDBUseDlg �Ի���

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


// CEDBUseDlg ��Ϣ�������

BOOL CEDBUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("ID"), LVCFMT_LEFT, rt.Width() * 0.2);
    pListCtrl->InsertColumn(1,_T("NAME"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(2, _T("BIRTHDAY"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(3, _T("STATUE"), LVCFMT_LEFT, rt.Width() * 0.2);

	//ȫ��ѡ��
	::SendMessage(pListCtrl->m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
	LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	//ˢ����ʾ��¼
	OnBnClickedBtnrefresh();

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//ˢ�¼�¼
void CEDBUseDlg::OnBnClickedBtnrefresh()
{
	//����ѧ����¼����
	REC_STUDENT *pRecStudent = NULL;
	DWORD iRecCount = 0;

	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	//��ɾ��ȫ����ʾ
	pListCtrl->DeleteAllItems();
	//��ѯ����ѧ����¼
	if (CDBStudent::QueryAllRecords(&iRecCount,&pRecStudent))
	{
		//��ʾ��¼
		for (int i=0;i< iRecCount ; i++)
		{
			pListCtrl->InsertItem(i,L"");
			//���ѧ�����
			pListCtrl->SetItemText(i,0,(pRecStudent+i)->szNo);
			//���ѧ������
			pListCtrl->SetItemText(i,1,(pRecStudent+i)->szName);
			//���ѧ�����գ��˴���Ҫ��Щת��
			SYSTEMTIME systime;
			FileTimeToSystemTime(&((pRecStudent+i)->ftBirthday),&systime);
			TCHAR szBirthday[11];
			swprintf(szBirthday,_T("%d-%d-%d"),systime.wYear,systime.wMonth,systime.wDay);
			pListCtrl->SetItemText(i,2,szBirthday);
			//���ѧ����ߣ��˴���Ҫ������ת�����ַ���
			TCHAR szStature[5];
			_itow((pRecStudent+i)->iStature,szStature,10);
			pListCtrl->SetItemText(i,3,szStature);
		}
		//�ͷ��ڴ�
		for (int i=0; i<iRecCount;i++)
		{
			//�ͷ�IMAGE��̬�ڴ�
			if ((pRecStudent+i)->blImage.lpb != NULL)
			{
				LocalFree(HLOCAL((pRecStudent+i)->blImage.lpb));
				(pRecStudent+i)->blImage.lpb = NULL;
			}

			//�ͷ�ѧ����¼�����ڴ�
			delete[] pRecStudent;
			pRecStudent = NULL;
		}
	}
}

//��Ӽ�¼
void CEDBUseDlg::OnBnClickedBtnadd()
{
	//����ѧ����¼
	REC_STUDENT rec_stu;
	//��ѧ����¼��ӶԻ���
	CStudentInputDlg inputDlg;
	if (inputDlg.DoModal() == IDOK)
	{
		//�õ����
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//�õ�����
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//�õ���������
		SYSTEMTIME timeDest;
		FILETIME ftTime;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		ZeroMemory(&(rec_stu.ftBirthday),sizeof(rec_stu.ftBirthday));
		SystemTimeToFileTime(&timeDest, &ftTime);
		rec_stu.ftBirthday = ftTime;
		//�õ����ֵ
		rec_stu.iStature = inputDlg.m_stature;

		//ѧ����Ƭ
		rec_stu.blImage = inputDlg.m_blImage;

		//���ѧ����¼
		if (!CDBStudent::AddNewStudent(&rec_stu))
		{
			AfxMessageBox(L"��Ӽ�¼ʧ��");
		}
	}
	//������֮�󣬵���ˢ�°�ť��������
	OnBnClickedBtnrefresh();
}

//�༭��¼
void CEDBUseDlg::OnBnClickedBtnedit()
{
	//����ѧ����¼
	REC_STUDENT rec_stu;
	DWORD dwRead = 0;
	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	//�õ����༭��ѧ�����
	CString strNo = pListCtrl->GetItemText(iItemIndex,0);
	ZeroMemory(&rec_stu,sizeof(rec_stu));
	
	//�õ���Ӧѧ����ŵ�ѧ����Ϣ
	if (!CDBStudent::QueryStudent(strNo,&rec_stu))
	{
		AfxMessageBox(L"��ȡ��ѧ����Ϣʧ��");
		return;
	}

	//��ѧ����Ϣ�༭��
	CStudentInputDlg inputDlg;
	//ͬ���༭�Ի��������ֵ
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
		//�õ����
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//�õ�����
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//�õ���������
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//�õ����ֵ
		rec_stu.iStature = inputDlg.m_stature;

		//������Ƭ
		rec_stu.blImage = inputDlg.m_blImage;
		
		//�����޸ĺ��ѧ����Ϣ
		if (!CDBStudent::EditStudent(strNo,&rec_stu))
		{
			AfxMessageBox(L"�༭��¼ʧ��");
		}
		//
	}
	//�ͷ��ڴ�
	if (rec_stu.blImage.lpb != NULL)
	{
		LocalFree(HLOCAL(rec_stu.blImage.lpb));
		rec_stu.blImage.lpb = NULL;
	}
	//ˢ�¼�¼
	OnBnClickedBtnrefresh();	

}

//ɾ����¼
void CEDBUseDlg::OnBnClickedBtndelete()
{
	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	//�õ�ѧ�����
	CString strNo = pListCtrl->GetItemText(iItemIndex,0);
	//ɾ��ѧ����¼
	if (!CDBStudent::DeleteStudent(strNo))
	{
		AfxMessageBox(L"ɾ����¼ʧ��");
	}
	//ˢ�¼�¼
	OnBnClickedBtnrefresh();		
}


