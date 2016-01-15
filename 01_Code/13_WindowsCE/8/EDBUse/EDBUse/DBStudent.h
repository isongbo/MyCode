/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： DBStudent.h
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
#pragma once

//定义数据库文件名
#define DBFILENAME  L"\\My Documents\\student.vol"
//定义数据库名
#define DBTABLENAME  L"Student"

//定义学生数据库表结构
typedef struct
{
	TCHAR szNo[7];			//学生编号
	TCHAR szName[20] ;		//学生姓名
	FILETIME ftBirthday;	//学生生日
    int iStature ;          //学生身高
	CEBLOB blImage;		//学生照片
}REC_STUDENT,*PREC_STUDENT;

//定义学生编号字段标识,学生编号在数据库中，将是唯一型字段
#define PID_NO		MAKELONG(CEVT_LPWSTR,1)
//定义学生姓名字段标识
#define PID_NAME	MAKELONG(CEVT_LPWSTR,2)
//定义学生生日字段标识
#define PID_BIRTHDAY MAKELONG(CEVT_FILETIME,3)
//定义学生身高字段标识
#define PID_STATURE  MAKELONG(CEVT_I4,4)
//定义学生照片字段
#define PID_IMAGE	MAKELONG(CEVT_STREAM,5)

class CDBStudent
{
public:
	//构造函数
	CDBStudent(void);
	//析构函数
	~CDBStudent(void);
private:
	CEGUID m_VolGUID;	//存储数据库文件卷标识
	HANDLE m_hDB;		//存储数据库句柄
	CEOID  m_ceOid;     //存储数据库对象标识
	HANDLE m_hSession; //会话句柄
private:
	//新建数据库
	BOOL DB_Create_Student(  CEGUID * pCeGuid, /*数据库文件卷名称*/
							const LPCTSTR strDBName /*数据库名称*/);
	//获取数据库的记录数目
	int GetRecordCount(CEGUID *pCeGuid,CEOID ceOid);

public:
	//打开数据库
	BOOL DB_Open_Student(const LPCTSTR strVolumeName = DBFILENAME, /*数据库文件卷名称*/
							const LPCTSTR strDBName = DBTABLENAME/*数据库名称*/);
	//关闭数据库
	BOOL DB_Close_Student();
public:
	//添加记录
	static BOOL AddNewStudent(const REC_STUDENT *pRecStudent);
	//编辑记录
	static BOOL EditStudent(LPCTSTR strNo,const REC_STUDENT *pRecStudent);
	//删除记录
	static BOOL DeleteStudent(LPCTSTR strNo);
public:
	//根据学生编号，查询记录
	static BOOL QueryStudent(const LPCTSTR strNo,REC_STUDENT *pRecStudent);
	//查询所有记录
	static BOOL QueryAllRecords(DWORD *pRecordCount,REC_STUDENT **pRecStudent);
};
