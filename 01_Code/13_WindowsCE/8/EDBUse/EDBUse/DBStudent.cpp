/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： DBStudent.cpp
* 文件标识： 
* 摘要： 封装学生数据库
*
* 当前版本： 1.0
* 作者： 汪兵 Eric Wong
* 完成日期： 2008年1月6日
*
* 取代版本：
* 原作者： 
* 完成日期： 
----------------------------------------*/
#include "StdAfx.h"
#include "DBStudent.h"

//构造函数
CDBStudent::CDBStudent(void)
{
	ZeroMemory(&m_VolGUID,sizeof(m_VolGUID));	//存储数据库文件卷标识
	m_hDB = INVALID_HANDLE_VALUE;				//存储数据库句柄
	m_ceOid = 0;								//存储数据库对象标识
	m_hSession = INVALID_HANDLE_VALUE;			//会话句柄
}

//析构函数
CDBStudent::~CDBStudent(void)
{
}

/*--------------------------------------------------------------------
【函数介绍】:  在数据库卷中，新建数据库
【入口参数】:	pCeGuid ： 数据库卷ID
				strDBName ： 数据库名
【出口参数】:  
【返回  值】:  TRUE：成功； FALSE：失败
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Create_Student(  CEGUID * pCeGuid, /*数据库文件卷名称*/
							const LPCTSTR strDBName /*数据库名称*/)
{
	//定义数据库基本信息
	CEDBASEINFOEX     DBInfo;
	//填充DBInfo信息
	memset(&DBInfo, 0, sizeof(CEDBASEINFOEX)) ;
	DBInfo.wVersion = CEDBASEINFOEX_VERSION;  //版本
	DBInfo.dwFlags |= CEDB_VALIDDBFLAGS | CEDB_VALIDNAME | CEDB_VALIDSORTSPEC; //标识
	DBInfo.wNumSortOrder = 2;   //索引个数
	wcscpy(DBInfo.szDbaseName , DBTABLENAME);  //数据库名
	//定义第1个排序方式
	DBInfo.rgSortSpecs[0].wVersion = SORTORDERSPECEX_VERSION;
	DBInfo.rgSortSpecs[0].wNumProps = 1;
	//指定PID_NO为唯一索引
	DBInfo.rgSortSpecs[0].wKeyFlags = CEDB_SORT_UNIQUE;
	DBInfo.rgSortSpecs[0].rgPropID[0] = PID_NO;		  //学生编号
	DBInfo.rgSortSpecs[0].rgdwFlags[0] = CEDB_SORT_DESCENDING;

	//定义第2个排序方式
	DBInfo.rgSortSpecs[1].wVersion = SORTORDERSPECEX_VERSION;
	DBInfo.rgSortSpecs[1].wNumProps = 1;
	DBInfo.rgSortSpecs[1].wKeyFlags = 0;
	DBInfo.rgSortSpecs[1].rgPropID[0] = PID_NAME;   //学生姓名
	DBInfo.rgSortSpecs[1].rgdwFlags[0] = CEDB_SORT_DESCENDING;

	//设置字段属性
	CEPROPSPEC dbPropInfo[5];
	//学生编号
	dbPropInfo[0].wVersion = 1;
	dbPropInfo[0].propid = PID_NO;
	dbPropInfo[0].pwszPropName = L"编号";
	dbPropInfo[0].cchPropName = wcslen(dbPropInfo[0].pwszPropName);
	dbPropInfo[0].dwFlags = 0;
	//学生姓名
	dbPropInfo[1].wVersion = 1;
	dbPropInfo[1].propid = PID_NAME;
	dbPropInfo[1].pwszPropName = L"姓名";
	dbPropInfo[1].cchPropName = wcslen(dbPropInfo[1].pwszPropName);
	dbPropInfo[1].dwFlags = 0;
	//出生日期
	dbPropInfo[2].wVersion = 1;
	dbPropInfo[2].propid = PID_BIRTHDAY;
	dbPropInfo[2].pwszPropName = L"出生日期";
	dbPropInfo[2].cchPropName = wcslen(dbPropInfo[2].pwszPropName);
	dbPropInfo[2].dwFlags = 0;
	//身高
	dbPropInfo[3].wVersion = 1;
	dbPropInfo[3].propid = PID_STATURE;
	dbPropInfo[3].pwszPropName = L"身高";
	dbPropInfo[3].cchPropName = wcslen(dbPropInfo[3].pwszPropName);
	dbPropInfo[3].dwFlags = 0;

	//照片
	dbPropInfo[4].wVersion = 1;
	dbPropInfo[4].propid = PID_IMAGE;
	dbPropInfo[4].pwszPropName = L"照片";
	dbPropInfo[4].cchPropName = wcslen(dbPropInfo[4].pwszPropName);
	dbPropInfo[4].dwFlags = 0;

	//创建数据库
	m_ceOid = CeCreateDatabaseWithProps(pCeGuid, &DBInfo, 5, dbPropInfo);
	if (m_ceOid == 0)
	{
		TRACE(L"创建数据库失败,The Error Code =%d \n",GetLastError());
		return FALSE;
	}
	//
	return TRUE;
}

/*--------------------------------------------------------------------
【函数介绍】:  获取数据库的记录数目
【入口参数】:  pCeGuid : 数据库文件卷标识指针
			   ceOid   : 数据库对象标识
【出口参数】:  (无)
【返回  值】: -1 :代表失败。成功的话，返回实际的记录数
---------------------------------------------------------------------*/
int CDBStudent::GetRecordCount(CEGUID *pCeGuid,CEOID ceOid)
{
	int iCount;
	CEOIDINFOEX  oidinfo;
    oidinfo.wVersion = CEOIDINFOEX_VERSION;
	//获取数据库信息
	if (!CeOidGetInfoEx2(pCeGuid,ceOid,&oidinfo))
	{
		TRACE(L"获取信息失败\n");
		return -1;
	}

	//判断oidinfo.wObjType是否是数据库类型
	if (oidinfo.wObjType != OBJTYPE_DATABASE)
	{
		return -1;
	}

	//得到记录数
	iCount = oidinfo.infDatabase.dwNumRecords;
	return iCount;
}

/*--------------------------------------------------------------------
【函数介绍】:  打开数据库
【入口参数】:	strVolumeName ： 数据库卷文件名
				strDBName ： 数据库名
【出口参数】:  
【返回  值】:  TRUE：成功； FALSE：失败
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Open_Student(const LPCTSTR strVolumeName, /*数据库文件卷名称*/
							const LPCTSTR strDBName /*数据库名称*/)
{
	BOOL bResult = FALSE;
	DWORD dwErrorCode = 0;
	//定义排序方式
    SORTORDERSPECEX rgSortSpecs;
    rgSortSpecs.wVersion = SORTORDERSPECEX_VERSION;
    rgSortSpecs.wNumProps = 1;
    rgSortSpecs.wKeyFlags = CEDB_SORT_UNIQUE;
    rgSortSpecs.rgPropID[0] = PID_NO;
    rgSortSpecs.rgdwFlags[0] = CEDB_SORT_DESCENDING;


	//1、挂载数据库卷，如果存在则打开，不存在，就新建一个
	if (!CeMountDBVolEx(&m_VolGUID,DBFILENAME,NULL,OPEN_ALWAYS))
	{
		TRACE(_T("打开或新建数据卷失败 \n"));
		return FALSE;
	}

	//2,创建会话句柄
    m_hSession = CeCreateSession(&m_VolGUID);

	//3、接着打开数据库
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
		//4、如果数据库不存在，就新建之
		if ( dwErrorCode== ERROR_FILE_NOT_FOUND) 
		{
			//创建新数据库
			if (!DB_Create_Student(&m_VolGUID,DBTABLENAME))
			{

				TRACE(L"打开数据库失败\n");
				goto error;
			}
			//5、创建数据库后，应紧接着打开数据库
			m_hDB = CeOpenDatabaseInSession( m_hSession,
									&m_VolGUID, 
									&m_ceOid, 
									DBTABLENAME, 
									&rgSortSpecs, 
									0,//CEDB_AUTOINCREMENT,
									NULL) ;	

			if (m_hDB == INVALID_HANDLE_VALUE)
			{

				TRACE(L"打开数据库失败\n");
				goto error;
			}
		}
		else
		{
			TRACE(L"打开数据库失败\n");
			goto error;
		}
	}

	return TRUE;

error:
	//此处得卸载数据库卷
	if (!CeUnmountDBVol(&m_VolGUID))
	{
		TRACE(_T("卸载数据库文件卷失败"));
	}
	return FALSE;
}

/*--------------------------------------------------------------------
【函数介绍】:  关闭数据库
【入口参数】:  (无)
【出口参数】:  (无)
【返回  值】:  TRUE：成功； FALSE：失败
---------------------------------------------------------------------*/
BOOL CDBStudent::DB_Close_Student()
{
 
	//1、关闭数据库
	if (m_hDB != INVALID_HANDLE_VALUE )
	{
		if (!CloseHandle(m_hDB))
		{
			TRACE(L"关闭数据库失败\n");
			return FALSE;
		}
	}
	//2、将数据库卷的数据缓冲到永久存储介质上
	if ((m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0))
	{
		if (!CeFlushDBVol(&m_VolGUID))
		{
			TRACE(L"缓冲介质失败\n");
			return FALSE;
		}
	}

	//3 、关闭回话对象
	if (m_hSession != INVALID_HANDLE_VALUE )
	{
		if (!CloseHandle(m_hSession))
		{
			TRACE(L"关闭回话对象失败\n");
			return FALSE;
		}
	}

	//4、卸载数据库卷
	if ((m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0) 
		|| (m_VolGUID.Data1 != 0))
	{
		if (!CeUnmountDBVol(&m_VolGUID))
		{
			TRACE(L"卸载数据库文件卷失败\n");
			return FALSE ;
		}
	}
	return TRUE;
}


/*--------------------------------------------------------------------
【函数介绍】:  添加一条新记录
【入口参数】:  pRecStudent : 学生数据库表结构
【出口参数】:  (无)
【返回  值】:  TRUE:添加成功;FALSE:添加失败
---------------------------------------------------------------------*/
BOOL CDBStudent::AddNewStudent(const REC_STUDENT *pRecStudent)
{
	//定义学生数据库对象
	CDBStudent tblStudent; 
	CEOID ceOid;
	//定义字段属性
	CEPROPVAL pProps[4];
	DWORD dwErrorCode = 0;

	DWORD dwWritten = 0;
	//定义内存流句柄，用于写入照片数据
	HANDLE hStream = INVALID_HANDLE_VALUE ;

	//1,打开学生数据库
	if (!tblStudent.DB_Open_Student())
	{
		//打开学生数据库失败
		return FALSE;
	}

	//给字段属性赋值
	ZeroMemory(&pProps[0],sizeof(CEPROPVAL)*4);

	//学生学号
	pProps[0].propid = PID_NO; 
	pProps[0].val.lpwstr = LPWSTR(pRecStudent->szNo);
	pProps[0].wFlags = 0;

	//学生姓名
	pProps[1].propid = PID_NAME ; 
	pProps[1].val.lpwstr = LPWSTR(pRecStudent->szName);
	pProps[1].wFlags = 0;

	//学生出生日期
	pProps[2].propid = PID_BIRTHDAY;
	pProps[2].val.filetime  = pRecStudent->ftBirthday;
	pProps[2].wFlags = 0;

	//学生身高
	pProps[3].propid = PID_STATURE;
	pProps[3].val.lVal = pRecStudent->iStature;
	pProps[3].wFlags = 0;

	//写入记录
	ceOid = CeWriteRecordProps(tblStudent.m_hDB,0,4,pProps);

	if (ceOid == 0)
	{
		dwErrorCode = GetLastError();
		//如果 dwErrorCode  = 183, 表示学生编号重复
		if (dwErrorCode == ERROR_ALREADY_EXISTS)
		{
			TRACE(L"学生编号重复\n");
		}
		else
		{
			TRACE(L"写入记录失败 , Error Code = %d \n",dwErrorCode);
		}
		goto error;
	}

	//此时在写入学生照片
	//如果学生照片字段无数据，则返回
	if (pRecStudent->blImage.dwCount == 0)
	{
		//关闭数据库
		tblStudent.DB_Close_Student();
		//
		return TRUE;
	}
	//打开流
	hStream = CeOpenStream(tblStudent.m_hDB,PID_IMAGE,GENERIC_WRITE);

	if (hStream == INVALID_HANDLE_VALUE)
	{
		TRACE(L"打开PID_IMAGE 流失败\n");
		goto error;
	}
	
	//将学生照片数据写入流中
	if (!CeStreamWrite(hStream,pRecStudent->blImage.lpb,pRecStudent->blImage.dwCount,&dwWritten))
	{
		TRACE(L"将学生照片写入流失败\n");
		goto error;
	}

	//保存流数据
	if (!CeStreamSaveChanges(hStream))
	{
		TRACE(L"保存流数据失败\n");
		goto error;
	}

	//最后，关闭打开的流句柄
	CloseHandle(hStream);

	//关闭数据库
	tblStudent.DB_Close_Student();

	return TRUE;
error:
	//关闭数据库
	tblStudent.DB_Close_Student();

	if (hStream != INVALID_HANDLE_VALUE )
	{
		//关闭打开的流句柄
		CloseHandle(hStream);
	}
	return FALSE;
}

/*--------------------------------------------------------------------
【函数介绍】:  编辑记录； 根据学生编号，修改记录
【入口参数】:  strNo : 学生编号
			   pRecStudent : 学生数据库表结构
【出口参数】:  (无)
【返回  值】:  TRUE:编辑成功;FALSE:编辑失败
---------------------------------------------------------------------*/
BOOL CDBStudent::EditStudent(LPCTSTR strNo,const REC_STUDENT *pRecStudent)
{
	//定义学生数据库对象
	CDBStudent tblStudent;
	CEOID tmpCeOid;
	CEOID ceOid;
	DWORD dwIndex = 0;
	DWORD dwWritten = 0;
	//定义流句柄
	HANDLE hStream = INVALID_HANDLE_VALUE ;

	//定义字段属性
	CEPROPVAL pProps[4];
	//定义学生编号查找字段属性
	CEPROPVAL seekPropVal;
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//1,打开学生数据库
	if (!tblStudent.DB_Open_Student())
	{
		//打开学生数据库失败
		return FALSE;
	}

	//给字段属性赋值
	ZeroMemory(&pProps[0],sizeof(CEPROPVAL)*4);

	//学生学号
	pProps[0].propid = PID_NO; 
	pProps[0].val.lpwstr = LPWSTR(pRecStudent->szNo);
	pProps[0].wFlags = 0;

	//学生姓名
	pProps[1].propid = PID_NAME ; 
	pProps[1].val.lpwstr = LPWSTR(pRecStudent->szName);
	pProps[1].wFlags = 0;

	//学生出生日期
	pProps[2].propid = PID_BIRTHDAY;
	pProps[2].val.filetime  = pRecStudent->ftBirthday;
	pProps[2].wFlags = 0;

	//学生身高
	pProps[3].propid = PID_STATURE;
	pProps[3].val.lVal = pRecStudent->iStature;
	pProps[3].wFlags = 0;

	//
	//2,根据学生编号，查找到待修改的记录指针
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);

	if (ceOid == 0)
	{
		TRACE(L"未查找到此记录\n");
		goto error;

	}
	
	//3,写入记录
	tmpCeOid = CeWriteRecordProps(tblStudent.m_hDB,ceOid,4,pProps);

	if (tmpCeOid == 0)
	{
		TRACE(L"写入记录失败\n");
		goto error;
	}

	//4,修改学生照片

	//打开流
	hStream = CeOpenStream(tblStudent.m_hDB,PID_IMAGE,GENERIC_WRITE);

	if (hStream == INVALID_HANDLE_VALUE)
	{
		TRACE(L"打开PID_IMAGE 流失败");
		goto error;
	}

	//将流字段清0
	if (!CeStreamSetSize(hStream,0))
	{
		TRACE(L"将流字段置0失败\n");
		goto error;
	}

	//如果照片数据不为0,写入照片数据
	if (pRecStudent->blImage.dwCount != 0)
	{
		//将学生照片数据写入流中
		if (!CeStreamWrite(hStream,pRecStudent->blImage.lpb,pRecStudent->blImage.dwCount,&dwWritten))
		{
			TRACE(L"将学生照片写入流，失败\n");
			goto error;
		}
	}

	//保存流数据
	if (!CeStreamSaveChanges(hStream))
	{
		TRACE(L"保存流数据失败\n");
		goto error;
	}

	//最后，关闭打开的流句柄
	CloseHandle(hStream);

	//关闭数据库
	tblStudent.DB_Close_Student();

	return TRUE;

error:
	//关闭数据库
	tblStudent.DB_Close_Student();

	if (hStream != INVALID_HANDLE_VALUE )
	{
		//关闭打开的流句柄
		CloseHandle(hStream);
	}
	return FALSE;
}

/*--------------------------------------------------------------------
【函数介绍】:  删除一条学生记录
【入口参数】:  strNo : 学生编号
【出口参数】:  (无)
【返回  值】:  TRUE : 成功 ; FALSE :失败
---------------------------------------------------------------------*/
BOOL CDBStudent::DeleteStudent(LPCTSTR strNo)
{
	//定义学生数据库对象
	CDBStudent tblStudent; 
	//定义学生编号查找字段属性
	CEPROPVAL seekPropVal;  //
	CEOID ceOid;
	DWORD dwIndex = 0;

	//1,打开学生数据库
	if (!tblStudent.DB_Open_Student())
	{
		//打开学生数据库失败
		return FALSE;
	}
	
	//赋值学生编号查找字段属性
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//根据学生编号，查找对应要删除的记录
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);

	if (ceOid == 0)
	{
		TRACE(L"未查找到此记录\n");
		goto error;

	}
	
	//删除当前记录
	if (!CeDeleteRecord(tblStudent.m_hDB,ceOid))
	{
		TRACE(L"删除记录失败\n");
		goto error;
	}

	return TRUE;
error:
	//关闭数据库
	tblStudent.DB_Close_Student();
	return FALSE;
}



/*--------------------------------------------------------------------
【函数介绍】:  根据学生编号，查询记录
【入口参数】:  strNo : 学生编号
			   pRecStudent   : 查询到的学生记录信息
【出口参数】:  pRecStudent	 : 查询到的学生记录信息
			   备注：使用完该函数，还得动态释放pRecStudent->blImage.lpb内存，
			   采用LocalFree方法释放
【返回  值】:  TRUE : 成功 ; FALSE :失败
---------------------------------------------------------------------*/
BOOL CDBStudent::QueryStudent(const LPCTSTR strNo,REC_STUDENT *pRecStudent)
{
	//定义学生数据库对象
	CDBStudent tblStudent; 

	CEOID ceOid = 0;
	WORD wProps = 0;
	DWORD dwRecSize = 0;
	PBYTE pBuff = 0;
	DWORD dwIndex = 0;
	PCEPROPVAL pRecord = NULL;

	//定义学生编号查找字段属性
	CEPROPVAL seekPropVal;
	ZeroMemory(&seekPropVal,sizeof(seekPropVal));
	seekPropVal.propid = PID_NO;
	seekPropVal.val.lpwstr = (LPWSTR)strNo;

	//1,打开学生数据库
	if (!tblStudent.DB_Open_Student())
	{
		//打开学生数据库失败
		return FALSE;
	}

	//
	//根据学生编号查找记录
	ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_VALUEFIRSTEQUAL,(DWORD)&seekPropVal,1,&dwIndex);
	if (ceOid != 0)
	{
		//读取所有字段值
		ceOid = CeReadRecordPropsEx(tblStudent.m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize,NULL);
		
		pRecord = (PCEPROPVAL)pBuff;
		
		for (int i=0;i<wProps;i++)
		{
			switch((pRecord+i)->propid)
			{
			//学生编号
			case PID_NO:
				{
					wcscpy(pRecStudent->szNo,(pRecord+i)->val.lpwstr);
					break;
				}
			//学生姓名
			case PID_NAME:
				{
					wcscpy(pRecStudent->szName,(pRecord+i)->val.lpwstr);
					break;
				}
			//出生日期
			case PID_BIRTHDAY:
				{
					pRecStudent->ftBirthday = (pRecord+i)->val.filetime;
					break;
				}
			//身高
			case PID_STATURE:
				{
					pRecStudent->iStature = (pRecord+i)->val.lVal;
					break;
				}
			//照片
			case PID_IMAGE:
				{
					if (pRecStudent->blImage.lpb != NULL)
					{
						//先释放内存
						LocalFree((HLOCAL)pRecStudent->blImage.lpb);
						pRecStudent->blImage.lpb = NULL;
					}

					//赋值，照片大小
					pRecStudent->blImage.dwCount = (pRecord+i)->val.blob.dwCount;
					//分配内存
					pRecStudent->blImage.lpb = (BYTE*)LocalAlloc(LMEM_ZEROINIT,pRecStudent->blImage.dwCount);
					
					//拷贝内存
					CopyMemory(pRecStudent->blImage.lpb,(pRecord+i)->val.blob.lpb,pRecStudent->blImage.dwCount);
				}
			default:
				{

				}
			}

		}
		//释放内存
		LocalFree(pBuff);
	}
	else
	{
		goto error;
	}
	
	//关闭数据库
	tblStudent.DB_Close_Student();
	return TRUE;
error:
	//关闭数据库
	tblStudent.DB_Close_Student();

	return FALSE;
}

/*--------------------------------------------------------------------
【函数介绍】:  查询所有记录
【入口参数】:  (无)
【出口参数】:  pRecordCount :返回记录数
			   pRecStudent : 返回查询到的所有学生记录
【返回  值】:  TRUE : 成功 ; FALSE :失败
---------------------------------------------------------------------*/
BOOL CDBStudent::QueryAllRecords(DWORD *pRecordCount,REC_STUDENT **pRecStudent)
{
	//定义学生数据库对象
	CDBStudent tblStudent; 

	CEOID ceOid = 0;
	WORD wProps = 0;
	DWORD dwRecSize = 0;
	PBYTE pBuff = 0;
	DWORD dwIndex = 0;
	PCEPROPVAL pRecord = NULL;
	DWORD dwRecordCount = 0;


	//1,打开学生数据库
	if (!tblStudent.DB_Open_Student())
	{
		//打开学生数据库失败
		return FALSE;
	}

	//得到数据库记录数
	dwRecordCount = tblStudent.GetRecordCount(&tblStudent.m_VolGUID,tblStudent.m_ceOid);

	//返回记录数
	*pRecordCount = dwRecordCount;

	//如果记录数为0，返回
	if (dwRecordCount ==0)	
	{
		//关闭数据库
		tblStudent.DB_Close_Student();
		return TRUE;
	}

	//分配记录数组
	*pRecStudent = new REC_STUDENT[dwRecordCount];

	//置0
	ZeroMemory(*pRecStudent,sizeof(REC_STUDENT)*dwRecordCount);

	//读取所有记录
	for (int i=0;i<dwRecordCount;i++)
	{
		//移动记录指针
		ceOid = CeSeekDatabaseEx(tblStudent.m_hDB,CEDB_SEEK_BEGINNING,i,0,&dwIndex);

		ASSERT(ceOid !=0);
		pBuff = 0;	
		//读取所有字段值
		ceOid = CeReadRecordPropsEx(tblStudent.m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize,NULL);
		
		ASSERT(ceOid != 0);
		
		pRecord = (PCEPROPVAL)pBuff;
		
		//读取所有字段值
		for (int j=0;j<wProps;j++)
		{
			switch((pRecord+j)->propid)
			{
			//学生编号
			case PID_NO:
				{
					wcscpy((*pRecStudent+i)->szNo,(pRecord+j)->val.lpwstr);
					break;
				}
			//学生姓名
			case PID_NAME:
				{
					wcscpy((*pRecStudent+i)->szName,(pRecord+j)->val.lpwstr);
					break;
				}
			//出生日期
			case PID_BIRTHDAY:
				{
					(*pRecStudent+i)->ftBirthday = (pRecord+j)->val.filetime;
					break;
				}
			//身高
			case PID_STATURE:
				{
					(*pRecStudent+i)->iStature = (pRecord+j)->val.lVal;
					break;
				}
			//照片
			case PID_IMAGE:
				{
					if ((*pRecStudent+i)->blImage.lpb != NULL)
					{
						//先释放内存
						LocalFree((HLOCAL)(*pRecStudent+i)->blImage.lpb);
						(*pRecStudent+i)->blImage.lpb = NULL;
					}

					//赋值，照片数据大小
					(*pRecStudent+i)->blImage.dwCount = (pRecord+j)->val.blob.dwCount;
					//分配内存
					(*pRecStudent+i)->blImage.lpb = (BYTE*)LocalAlloc(LMEM_ZEROINIT,(*pRecStudent+i)->blImage.dwCount);
					
					//拷贝内存
					CopyMemory((*pRecStudent+i)->blImage.lpb,(pRecord+j)->val.blob.lpb,(*pRecStudent+i)->blImage.dwCount);
				}
			default:
				{

				}
			}
		}
		//释放内存
		LocalFree(pBuff);
		
	}

	//关闭数据库
	tblStudent.DB_Close_Student();
	return TRUE;
error:
	//关闭数据库
	tblStudent.DB_Close_Student();

	return FALSE;
}

