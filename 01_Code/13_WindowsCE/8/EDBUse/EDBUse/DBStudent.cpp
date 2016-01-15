/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� DBStudent.cpp
* �ļ���ʶ�� 
* ժҪ�� ��װѧ�����ݿ�
*
* ��ǰ�汾�� 1.0
* ���ߣ� ���� Eric Wong
* ������ڣ� 2008��1��6��
*
* ȡ���汾��
* ԭ���ߣ� 
* ������ڣ� 
----------------------------------------*/
#include "StdAfx.h"
#include "DBStudent.h"

//���캯��
CDBStudent::CDBStudent(void)
{
	ZeroMemory(&m_VolGUID,sizeof(m_VolGUID));	//�洢���ݿ��ļ����ʶ
	m_hDB = INVALID_HANDLE_VALUE;				//�洢���ݿ���
	m_ceOid = 0;								//�洢���ݿ�����ʶ
	m_hSession = INVALID_HANDLE_VALUE;			//�Ự���
}

//��������
CDBStudent::~CDBStudent(void)
{
}

/*--------------------------------------------------------------------
���������ܡ�:  �����ݿ���У��½����ݿ�
����ڲ�����:	pCeGuid �� ���ݿ��ID
				strDBName �� ���ݿ���
�����ڲ�����:  
������  ֵ��:  TRUE���ɹ��� FALSE��ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Create_Student(  CEGUID * pCeGuid, /*���ݿ��ļ�������*/
							const LPCTSTR strDBName /*���ݿ�����*/)
{
	//�������ݿ������Ϣ
	CEDBASEINFOEX     DBInfo;
	//���DBInfo��Ϣ
	memset(&DBInfo, 0, sizeof(CEDBASEINFOEX)) ;
	DBInfo.wVersion = CEDBASEINFOEX_VERSION;  //�汾
	DBInfo.dwFlags |= CEDB_VALIDDBFLAGS | CEDB_VALIDNAME | CEDB_VALIDSORTSPEC; //��ʶ
	DBInfo.wNumSortOrder = 2;   //��������
	wcscpy(DBInfo.szDbaseName , DBTABLENAME);  //���ݿ���
	//�����1������ʽ
	DBInfo.rgSortSpecs[0].wVersion = SORTORDERSPECEX_VERSION;
	DBInfo.rgSortSpecs[0].wNumProps = 1;
	//ָ��PID_NOΪΨһ����
	DBInfo.rgSortSpecs[0].wKeyFlags = CEDB_SORT_UNIQUE;
	DBInfo.rgSortSpecs[0].rgPropID[0] = PID_NO;		  //ѧ�����
	DBInfo.rgSortSpecs[0].rgdwFlags[0] = CEDB_SORT_DESCENDING;

	//�����2������ʽ
	DBInfo.rgSortSpecs[1].wVersion = SORTORDERSPECEX_VERSION;
	DBInfo.rgSortSpecs[1].wNumProps = 1;
	DBInfo.rgSortSpecs[1].wKeyFlags = 0;
	DBInfo.rgSortSpecs[1].rgPropID[0] = PID_NAME;   //ѧ������
	DBInfo.rgSortSpecs[1].rgdwFlags[0] = CEDB_SORT_DESCENDING;

	//�����ֶ�����
	CEPROPSPEC dbPropInfo[5];
	//ѧ�����
	dbPropInfo[0].wVersion = 1;
	dbPropInfo[0].propid = PID_NO;
	dbPropInfo[0].pwszPropName = L"���";
	dbPropInfo[0].cchPropName = wcslen(dbPropInfo[0].pwszPropName);
	dbPropInfo[0].dwFlags = 0;
	//ѧ������
	dbPropInfo[1].wVersion = 1;
	dbPropInfo[1].propid = PID_NAME;
	dbPropInfo[1].pwszPropName = L"����";
	dbPropInfo[1].cchPropName = wcslen(dbPropInfo[1].pwszPropName);
	dbPropInfo[1].dwFlags = 0;
	//��������
	dbPropInfo[2].wVersion = 1;
	dbPropInfo[2].propid = PID_BIRTHDAY;
	dbPropInfo[2].pwszPropName = L"��������";
	dbPropInfo[2].cchPropName = wcslen(dbPropInfo[2].pwszPropName);
	dbPropInfo[2].dwFlags = 0;
	//���
	dbPropInfo[3].wVersion = 1;
	dbPropInfo[3].propid = PID_STATURE;
	dbPropInfo[3].pwszPropName = L"���";
	dbPropInfo[3].cchPropName = wcslen(dbPropInfo[3].pwszPropName);
	dbPropInfo[3].dwFlags = 0;

	//��Ƭ
	dbPropInfo[4].wVersion = 1;
	dbPropInfo[4].propid = PID_IMAGE;
	dbPropInfo[4].pwszPropName = L"��Ƭ";
	dbPropInfo[4].cchPropName = wcslen(dbPropInfo[4].pwszPropName);
	dbPropInfo[4].dwFlags = 0;

	//�������ݿ�
	m_ceOid = CeCreateDatabaseWithProps(pCeGuid, &DBInfo, 5, dbPropInfo);
	if (m_ceOid == 0)
	{
		TRACE(L"�������ݿ�ʧ��,The Error Code =%d \n",GetLastError());
		return FALSE;
	}
	//
	return TRUE;
}

/*--------------------------------------------------------------------
���������ܡ�:  ��ȡ���ݿ�ļ�¼��Ŀ
����ڲ�����:  pCeGuid : ���ݿ��ļ����ʶָ��
			   ceOid   : ���ݿ�����ʶ
�����ڲ�����:  (��)
������  ֵ��: -1 :����ʧ�ܡ��ɹ��Ļ�������ʵ�ʵļ�¼��
---------------------------------------------------------------------*/
int CDBStudent::GetRecordCount(CEGUID *pCeGuid,CEOID ceOid)
{
	int iCount;
	CEOIDINFOEX  oidinfo;
    oidinfo.wVersion = CEOIDINFOEX_VERSION;
	//��ȡ���ݿ���Ϣ
	if (!CeOidGetInfoEx2(pCeGuid,ceOid,&oidinfo))
	{
		TRACE(L"��ȡ��Ϣʧ��\n");
		return -1;
	}

	//�ж�oidinfo.wObjType�Ƿ������ݿ�����
	if (oidinfo.wObjType != OBJTYPE_DATABASE)
	{
		return -1;
	}

	//�õ���¼��
	iCount = oidinfo.infDatabase.dwNumRecords;
	return iCount;
}

/*--------------------------------------------------------------------
���������ܡ�:  �����ݿ�
����ڲ�����:	strVolumeName �� ���ݿ���ļ���
				strDBName �� ���ݿ���
�����ڲ�����:  
������  ֵ��:  TRUE���ɹ��� FALSE��ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Open_Student(const LPCTSTR strVolumeName, /*���ݿ��ļ�������*/
							const LPCTSTR strDBName /*���ݿ�����*/)
{
	BOOL bResult = FALSE;
	DWORD dwErrorCode = 0;
	//��������ʽ
    SORTORDERSPECEX rgSortSpecs;
    rgSortSpecs.wVersion = SORTORDERSPECEX_VERSION;
    rgSortSpecs.wNumProps = 1;
    rgSortSpecs.wKeyFlags = CEDB_SORT_UNIQUE;
    rgSortSpecs.rgPropID[0] = PID_NO;
    rgSortSpecs.rgdwFlags[0] = CEDB_SORT_DESCENDING;


	//1���������ݿ�����������򿪣������ڣ����½�һ��
	if (!CeMountDBVolEx(&m_VolGUID,DBFILENAME,NULL,OPEN_ALWAYS))
	{
		TRACE(_T("�򿪻��½����ݾ�ʧ�� \n"));
		return FALSE;
	}

	//2,�����Ự���
    m_hSession = CeCreateSession(&m_VolGUID);

	//3�����Ŵ����ݿ�
    m_hDB = CeOpenDatabaseInSession( m_hSession,
                            &m_VolGUID, 
                            &m_ceOid, 
                            DBTABLENAME, 
                            &rgSortSpecs, 
                            0,//CEDB_AUTOINCREMENT,
                            NULL) ;	
	if (m_hDB == INVALID_HANDLE_VALUE)
	{
		dwErrorCode = GetLastError();
		//4��������ݿⲻ���ڣ����½�֮
		if ( dwErrorCode== ERROR_FILE_NOT_FOUND) 
		{
			//���������ݿ�
			if (!DB_Create_Student(&m_VolGUID,DBTABLENAME))
			{

				TRACE(L"�����ݿ�ʧ��\n");
				goto error;
			}
			//5���������ݿ��Ӧ�����Ŵ����ݿ�
			m_hDB = CeOpenDatabaseInSession( m_hSession,
									&m_VolGUID, 
									&m_ceOid, 
									DBTABLENAME, 
									&rgSortSpecs, 
									0,//CEDB_AUTOINCREMENT,
									NULL) ;	

			if (m_hDB == INVALID_HANDLE_VALUE)
			{

				TRACE(L"�����ݿ�ʧ��\n");
				goto error;
			}
		}
		else
		{
			TRACE(L"�����ݿ�ʧ��\n");
			goto error;
		}
	}

	return TRUE;

error:
	//�˴���ж�����ݿ��
	if (!CeUnmountDBVol(&m_VolGUID))
	{
		TRACE(_T("ж�����ݿ��ļ���ʧ��"));
	}
	return FALSE;
}

/*--------------------------------------------------------------------
���������ܡ�:  �ر����ݿ�
����ڲ�����:  (��)
�����ڲ�����:  (��)
������  ֵ��:  TRUE���ɹ��� FALSE��ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Close_Student()
{
 
	//1���ر����ݿ�
	if (m_hDB != INVALID_HANDLE_VALUE )
	{
		if (!CloseHandle(m_hDB))
		{
			TRACE(L"�ر����ݿ�ʧ��\n");
			return FALSE;
		}
	}
	//2�������ݿ������ݻ��嵽���ô洢������
	if ((m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0))
	{
		if (!CeFlushDBVol(&m_VolGUID))
		{
			TRACE(L"�������ʧ��\n");
			return FALSE;
		}
	}

	//3 ���رջػ�����
	if (m_hSession != INVALID_HANDLE_VALUE )
	{
		if (!CloseHandle(m_hSession))
		{
			TRACE(L"�رջػ�����ʧ��\n");
			return FALSE;
		}
	}

	//4��ж�����ݿ��
	if ((m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0))
	{
		if (!CeUnmountDBVol(&m_VolGUID))
		{
			TRACE(L"ж�����ݿ��ļ���ʧ��\n");
			return FALSE ;
		}
	}
	return TRUE;
}


/*--------------------------------------------------------------------
���������ܡ�:  ���һ���¼�¼
����ڲ�����:  pRecStudent : ѧ�����ݿ��ṹ
�����ڲ�����:  (��)
������  ֵ��:  TRUE:��ӳɹ�;FALSE:���ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::AddNewStudent(const REC_STUDENT *pRecStudent)
{
	//����ѧ�����ݿ����
	CDBStudent tblStudent; 
	CEOID ceOid;
	//�����ֶ�����
	CEPROPVAL pProps[4];
	DWORD dwErrorCode = 0;

	DWORD dwWritten = 0;
	//�����ڴ������������д����Ƭ����
	HANDLE hStream = INVALID_HANDLE_VALUE ;

	//1,��ѧ�����ݿ�
	if (!tblStudent.DB_Open_Student())
	{
		//��ѧ�����ݿ�ʧ��
		return FALSE;
	}

	//���ֶ����Ը�ֵ
	ZeroMemory(&pProps[0],sizeof(CEPROPVAL)*4);

	//ѧ��ѧ��
	pProps[0].propid = PID_NO; 
	pProps[0].val.lpwstr = LPWSTR(pRecStudent->szNo);
	pProps[0].wFlags = 0;

	//ѧ������
	pProps[1].propid = PID_NAME ; 
	pProps[1].val.lpwstr = LPWSTR(pRecStudent->szName);
	pProps[1].wFlags = 0;

	//ѧ����������
	pProps[2].propid = PID_BIRTHDAY;
	pProps[2].val.filetime  = pRecStudent->ftBirthday;
	pProps[2].wFlags = 0;

	//ѧ�����
	pProps[3].propid = PID_STATURE;
	pProps[3].val.lVal = pRecStudent->iStature;
	pProps[3].wFlags = 0;

	//д���¼
	ceOid = CeWriteRecordProps(tblStudent.m_hDB,0,4,pProps);

	if (ceOid == 0)
	{
		dwErrorCode = GetLastError();
		//��� dwErrorCode  = 183, ��ʾѧ������ظ�
		if (dwErrorCode == ERROR_ALREADY_EXISTS)
		{
			TRACE(L"ѧ������ظ�\n");
		}
		else
		{
			TRACE(L"д���¼ʧ�� , Error Code = %d \n",dwErrorCode);
		}
		goto error;
	}

	//��ʱ��д��ѧ����Ƭ
	//���ѧ����Ƭ�ֶ������ݣ��򷵻�
	if (pRecStudent->blImage.dwCount == 0)
	{
		//�ر����ݿ�
		tblStudent.DB_Close_Student();
		//
		return TRUE;
	}
	//����
	hStream = CeOpenStream(tblStudent.m_hDB,PID_IMAGE,GENERIC_WRITE);

	if (hStream == INVALID_HANDLE_VALUE)
	{
		TRACE(L"��PID_IMAGE ��ʧ��\n");
		goto error;
	}
	
	//��ѧ����Ƭ����д������
	if (!CeStreamWrite(hStream,pRecStudent->blImage.lpb,pRecStudent->blImage.dwCount,&dwWritten))
	{
		TRACE(L"��ѧ����Ƭд����ʧ��\n");
		goto error;
	}

	//����������
	if (!CeStreamSaveChanges(hStream))
	{
		TRACE(L"����������ʧ��\n");
		goto error;
	}

	//��󣬹رմ򿪵������
	CloseHandle(hStream);

	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	return TRUE;
error:
	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	if (hStream != INVALID_HANDLE_VALUE )
	{
		//�رմ򿪵������
		CloseHandle(hStream);
	}
	return FALSE;
}

/*--------------------------------------------------------------------
���������ܡ�:  �༭��¼�� ����ѧ����ţ��޸ļ�¼
����ڲ�����:  strNo : ѧ�����
			   pRecStudent : ѧ�����ݿ��ṹ
�����ڲ�����:  (��)
������  ֵ��:  TRUE:�༭�ɹ�;FALSE:�༭ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::EditStudent(LPCTSTR strNo,const REC_STUDENT *pRecStudent)
{
	//����ѧ�����ݿ����
	CDBStudent tblStudent;
	CEOID tmpCeOid;
	CEOID ceOid;
	DWORD dwIndex = 0;
	DWORD dwWritten = 0;
	//���������
	HANDLE hStream = INVALID_HANDLE_VALUE ;

	//�����ֶ�����
	CEPROPVAL pProps[4];
	//����ѧ����Ų����ֶ�����
	CEPROPVAL seekPropVal;
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//1,��ѧ�����ݿ�
	if (!tblStudent.DB_Open_Student())
	{
		//��ѧ�����ݿ�ʧ��
		return FALSE;
	}

	//���ֶ����Ը�ֵ
	ZeroMemory(&pProps[0],sizeof(CEPROPVAL)*4);

	//ѧ��ѧ��
	pProps[0].propid = PID_NO; 
	pProps[0].val.lpwstr = LPWSTR(pRecStudent->szNo);
	pProps[0].wFlags = 0;

	//ѧ������
	pProps[1].propid = PID_NAME ; 
	pProps[1].val.lpwstr = LPWSTR(pRecStudent->szName);
	pProps[1].wFlags = 0;

	//ѧ����������
	pProps[2].propid = PID_BIRTHDAY;
	pProps[2].val.filetime  = pRecStudent->ftBirthday;
	pProps[2].wFlags = 0;

	//ѧ�����
	pProps[3].propid = PID_STATURE;
	pProps[3].val.lVal = pRecStudent->iStature;
	pProps[3].wFlags = 0;

	//
	//2,����ѧ����ţ����ҵ����޸ĵļ�¼ָ��
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);

	if (ceOid == 0)
	{
		TRACE(L"δ���ҵ��˼�¼\n");
		goto error;

	}
	
	//3,д���¼
	tmpCeOid = CeWriteRecordProps(tblStudent.m_hDB,ceOid,4,pProps);

	if (tmpCeOid == 0)
	{
		TRACE(L"д���¼ʧ��\n");
		goto error;
	}

	//4,�޸�ѧ����Ƭ

	//����
	hStream = CeOpenStream(tblStudent.m_hDB,PID_IMAGE,GENERIC_WRITE);

	if (hStream == INVALID_HANDLE_VALUE)
	{
		TRACE(L"��PID_IMAGE ��ʧ��");
		goto error;
	}

	//�����ֶ���0
	if (!CeStreamSetSize(hStream,0))
	{
		TRACE(L"�����ֶ���0ʧ��\n");
		goto error;
	}

	//�����Ƭ���ݲ�Ϊ0,д����Ƭ����
	if (pRecStudent->blImage.dwCount != 0)
	{
		//��ѧ����Ƭ����д������
		if (!CeStreamWrite(hStream,pRecStudent->blImage.lpb,pRecStudent->blImage.dwCount,&dwWritten))
		{
			TRACE(L"��ѧ����Ƭд������ʧ��\n");
			goto error;
		}
	}

	//����������
	if (!CeStreamSaveChanges(hStream))
	{
		TRACE(L"����������ʧ��\n");
		goto error;
	}

	//��󣬹رմ򿪵������
	CloseHandle(hStream);

	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	return TRUE;

error:
	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	if (hStream != INVALID_HANDLE_VALUE )
	{
		//�رմ򿪵������
		CloseHandle(hStream);
	}
	return FALSE;
}

/*--------------------------------------------------------------------
���������ܡ�:  ɾ��һ��ѧ����¼
����ڲ�����:  strNo : ѧ�����
�����ڲ�����:  (��)
������  ֵ��:  TRUE : �ɹ� ; FALSE :ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::DeleteStudent(LPCTSTR strNo)
{
	//����ѧ�����ݿ����
	CDBStudent tblStudent; 
	//����ѧ����Ų����ֶ�����
	CEPROPVAL seekPropVal;  //
	CEOID ceOid;
	DWORD dwIndex = 0;

	//1,��ѧ�����ݿ�
	if (!tblStudent.DB_Open_Student())
	{
		//��ѧ�����ݿ�ʧ��
		return FALSE;
	}
	
	//��ֵѧ����Ų����ֶ�����
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//����ѧ����ţ����Ҷ�ӦҪɾ���ļ�¼
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);

	if (ceOid == 0)
	{
		TRACE(L"δ���ҵ��˼�¼\n");
		goto error;

	}
	
	//ɾ����ǰ��¼
	if (!CeDeleteRecord(tblStudent.m_hDB,ceOid))
	{
		TRACE(L"ɾ����¼ʧ��\n");
		goto error;
	}

	return TRUE;
error:
	//�ر����ݿ�
	tblStudent.DB_Close_Student();
	return FALSE;
}



/*--------------------------------------------------------------------
���������ܡ�:  ����ѧ����ţ���ѯ��¼
����ڲ�����:  strNo : ѧ�����
			   pRecStudent   : ��ѯ����ѧ����¼��Ϣ
�����ڲ�����:  pRecStudent	 : ��ѯ����ѧ����¼��Ϣ
			   ��ע��ʹ����ú��������ö�̬�ͷ�pRecStudent->blImage.lpb�ڴ棬
			   ����LocalFree�����ͷ�
������  ֵ��:  TRUE : �ɹ� ; FALSE :ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::QueryStudent(const LPCTSTR strNo,REC_STUDENT *pRecStudent)
{
	//����ѧ�����ݿ����
	CDBStudent tblStudent; 

	CEOID ceOid = 0;
	WORD wProps = 0;
	DWORD dwRecSize = 0;
	PBYTE pBuff = 0;
	DWORD dwIndex = 0;
	PCEPROPVAL pRecord = NULL;

	//����ѧ����Ų����ֶ�����
	CEPROPVAL seekPropVal;
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//1,��ѧ�����ݿ�
	if (!tblStudent.DB_Open_Student())
	{
		//��ѧ�����ݿ�ʧ��
		return FALSE;
	}

	//
	//����ѧ����Ų��Ҽ�¼
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);
	if (ceOid != 0)
	{
		//��ȡ�����ֶ�ֵ
		ceOid = CeReadRecordPropsEx(tblStudent.m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize,NULL);
		
		pRecord = (PCEPROPVAL)pBuff;
		
		for (int i=0;i<wProps;i++)
		{
			switch((pRecord+i)->propid)
			{
			//ѧ�����
			case PID_NO:
				{
					wcscpy(pRecStudent->szNo,(pRecord+i)->val.lpwstr);
					break;
				}
			//ѧ������
			case PID_NAME:
				{
					wcscpy(pRecStudent->szName,(pRecord+i)->val.lpwstr);
					break;
				}
			//��������
			case PID_BIRTHDAY:
				{
					pRecStudent->ftBirthday = (pRecord+i)->val.filetime;
					break;
				}
			//���
			case PID_STATURE:
				{
					pRecStudent->iStature = (pRecord+i)->val.lVal;
					break;
				}
			//��Ƭ
			case PID_IMAGE:
				{
					if (pRecStudent->blImage.lpb != NULL)
					{
						//���ͷ��ڴ�
						LocalFree((HLOCAL)pRecStudent->blImage.lpb);
						pRecStudent->blImage.lpb = NULL;
					}

					//��ֵ����Ƭ��С
					pRecStudent->blImage.dwCount = (pRecord+i)->val.blob.dwCount;
					//�����ڴ�
					pRecStudent->blImage.lpb = (BYTE*)LocalAlloc(LMEM_ZEROINIT,pRecStudent->blImage.dwCount);
					
					//�����ڴ�
					CopyMemory(pRecStudent->blImage.lpb,(pRecord+i)->val.blob.lpb,pRecStudent->blImage.dwCount);
				}
			default:
				{

				}
			}

		}
		//�ͷ��ڴ�
		LocalFree(pBuff);
	}
	else
	{
		goto error;
	}
	
	//�ر����ݿ�
	tblStudent.DB_Close_Student();
	return TRUE;
error:
	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	return FALSE;
}

/*--------------------------------------------------------------------
���������ܡ�:  ��ѯ���м�¼
����ڲ�����:  (��)
�����ڲ�����:  pRecordCount :���ؼ�¼��
			   pRecStudent : ���ز�ѯ��������ѧ����¼
������  ֵ��:  TRUE : �ɹ� ; FALSE :ʧ��
---------------------------------------------------------------------*/
BOOL CDBStudent::QueryAllRecords(DWORD *pRecordCount,REC_STUDENT **pRecStudent)
{
	//����ѧ�����ݿ����
	CDBStudent tblStudent; 

	CEOID ceOid = 0;
	WORD wProps = 0;
	DWORD dwRecSize = 0;
	PBYTE pBuff = 0;
	DWORD dwIndex = 0;
	PCEPROPVAL pRecord = NULL;
	DWORD dwRecordCount = 0;


	//1,��ѧ�����ݿ�
	if (!tblStudent.DB_Open_Student())
	{
		//��ѧ�����ݿ�ʧ��
		return FALSE;
	}

	//�õ����ݿ��¼��
	dwRecordCount = tblStudent.GetRecordCount(&tblStudent.m_VolGUID,tblStudent.m_ceOid);

	//���ؼ�¼��
	*pRecordCount = dwRecordCount;

	//�����¼��Ϊ0������
	if (dwRecordCount ==0)	
	{
		//�ر����ݿ�
		tblStudent.DB_Close_Student();
		return TRUE;
	}

	//�����¼����
	*pRecStudent = new REC_STUDENT[dwRecordCount];

	//��0
	ZeroMemory(*pRecStudent,sizeof(REC_STUDENT)*dwRecordCount);

	//��ȡ���м�¼
	for (int i=0;i<dwRecordCount;i++)
	{
		//�ƶ���¼ָ��
		ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_BEGINNING,i,0,&dwIndex);

		ASSERT(ceOid !=0);
		pBuff = 0;	
		//��ȡ�����ֶ�ֵ
		ceOid = CeReadRecordPropsEx(tblStudent.m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize,NULL);
		
		ASSERT(ceOid != 0);
		
		pRecord = (PCEPROPVAL)pBuff;
		
		//��ȡ�����ֶ�ֵ
		for (int j=0;j<wProps;j++)
		{
			switch((pRecord+j)->propid)
			{
			//ѧ�����
			case PID_NO:
				{
					wcscpy((*pRecStudent+i)->szNo,(pRecord+j)->val.lpwstr);
					break;
				}
			//ѧ������
			case PID_NAME:
				{
					wcscpy((*pRecStudent+i)->szName,(pRecord+j)->val.lpwstr);
					break;
				}
			//��������
			case PID_BIRTHDAY:
				{
					(*pRecStudent+i)->ftBirthday = (pRecord+j)->val.filetime;
					break;
				}
			//���
			case PID_STATURE:
				{
					(*pRecStudent+i)->iStature = (pRecord+j)->val.lVal;
					break;
				}
			//��Ƭ
			case PID_IMAGE:
				{
					if ((*pRecStudent+i)->blImage.lpb != NULL)
					{
						//���ͷ��ڴ�
						LocalFree((HLOCAL)(*pRecStudent+i)->blImage.lpb);
						(*pRecStudent+i)->blImage.lpb = NULL;
					}

					//��ֵ����Ƭ���ݴ�С
					(*pRecStudent+i)->blImage.dwCount = (pRecord+j)->val.blob.dwCount;
					//�����ڴ�
					(*pRecStudent+i)->blImage.lpb = (BYTE*)LocalAlloc(LMEM_ZEROINIT,(*pRecStudent+i)->blImage.dwCount);
					
					//�����ڴ�
					CopyMemory((*pRecStudent+i)->blImage.lpb,(pRecord+j)->val.blob.lpb,(*pRecStudent+i)->blImage.dwCount);
				}
			default:
				{

				}
			}
		}
		//�ͷ��ڴ�
		LocalFree(pBuff);
		
	}

	//�ر����ݿ�
	tblStudent.DB_Close_Student();
	return TRUE;
error:
	//�ر����ݿ�
	tblStudent.DB_Close_Student();

	return FALSE;
}

