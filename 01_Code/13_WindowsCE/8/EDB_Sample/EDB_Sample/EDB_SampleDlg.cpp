// EDB_SampleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EDB_Sample.h"
#include "EDB_SampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEDB_SampleDlg �Ի���

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


// CEDB_SampleDlg ��Ϣ�������

BOOL CEDB_SampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

//�������ݿ��GUID���о����е����ݿ�
void EnumDatabasesInVolume(CEGUID *pGuid)
{
	DWORD dwError;          // GetLastError��������ֵ
	TCHAR szMsg[128];       // ������Ϣ
	HANDLE hEnumDB;         // �о����ݿ���
	CEOID CeOid;            // ���ݿ�����ʶ
	CEOIDINFOEX CeObjectInfo; // ���ݿ���������Ϣ

	//�����������ݿ���Լ��������ݿ���е����ݿ�
	hEnumDB = CeFindFirstDatabaseEx (pGuid, 0);

	//ö�پ����Ч
	if (hEnumDB == INVALID_HANDLE_VALUE)
	{
		if (GetLastError () == ERROR_OUTOFMEMORY)
			TRACE(L"Out of memory.\n");
		else
			TRACE(L"Unknown error.\n");

		return;
	}

	//��ʼö�����ݿ�
	while ((CeOid = CeFindNextDatabaseEx(hEnumDB, NULL)) != 0)
	{
		ZeroMemory(&CeObjectInfo,sizeof(CeObjectInfo));
		CeObjectInfo.wVersion = 2;
		// �õ����ݿ���Ϣ
		if (!CeOidGetInfoEx2(pGuid, CeOid, &CeObjectInfo))
		{
			dwError = GetLastError();
			TRACE(L"the last error :%d\n",dwError);
			// �رղ��Ҿ��
			CloseHandle (hEnumDB);  

			return;
		}
		else
		{
			//�ж������ݿ�����
			if (CeObjectInfo.wObjType == OBJTYPE_DATABASE)
			{
				TRACE(L"The name of the database is: %s \n",
					CeObjectInfo.infDatabase.szDbaseName);
			}
		}
	}

	//�رղ��Ҿ��
	CloseHandle (hEnumDB);

}

//ö��ϵͳ�������Ѿ�װ�ص����ݿ���Լ����ݿ���е����ݿ�
void CEDB_SampleDlg::OnBnClickedBtnEnumVolumes()
{
   CEGUID ceguid;  
   TCHAR szVolumeName[CEDB_MAXDBASENAMELEN];
   //������Ч��GUID

   CREATE_INVALIDEDBGUID(&ceguid);
   //�о���װ�ص����ݿ��
   while (CeEnumDBVolumes(&ceguid,szVolumeName,CEDB_MAXDBASENAMELEN-1))
   {
	   TRACE(L"Enum mounted volumes: %s\n",szVolumeName);

		ZeroMemory(szVolumeName,CEDB_MAXDBASENAMELEN * 2);
	   //�о����е����ݿ�
		EnumDatabasesInVolume(&ceguid);
	   //
   }
}
