/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* ����������߲ο������������κ���ҵ��Ϊ
*
* �ļ����ƣ� DBStudent.h
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
#pragma once

//�������ݿ��ļ���
#define DBFILENAME  L"\\My Documents\\student.vol"
//�������ݿ���
#define DBTABLENAME  L"Student"

//����ѧ�����ݿ��ṹ
typedef struct
{
	TCHAR szNo[7];			//ѧ�����
	TCHAR szName[20] ;		//ѧ������
	FILETIME ftBirthday;	//ѧ������
    int iStature ;          //ѧ�����
	CEBLOB blImage;		//ѧ����Ƭ
}REC_STUDENT,*PREC_STUDENT;

//����ѧ������ֶα�ʶ,ѧ����������ݿ��У�����Ψһ���ֶ�
#define PID_NO		MAKELONG(CEVT_LPWSTR,1)
//����ѧ�������ֶα�ʶ
#define PID_NAME	MAKELONG(CEVT_LPWSTR,2)
//����ѧ�������ֶα�ʶ
#define PID_BIRTHDAY MAKELONG(CEVT_FILETIME,3)
//����ѧ������ֶα�ʶ
#define PID_STATURE  MAKELONG(CEVT_I4,4)
//����ѧ����Ƭ�ֶ�
#define PID_IMAGE	MAKELONG(CEVT_STREAM,5)

class CDBStudent
{
public:
	//���캯��
	CDBStudent(void);
	//��������
	~CDBStudent(void);
private:
	CEGUID m_VolGUID;	//�洢���ݿ��ļ����ʶ
	HANDLE m_hDB;		//�洢���ݿ���
	CEOID  m_ceOid;     //�洢���ݿ�����ʶ
	HANDLE m_hSession; //�Ự���
private:
	//�½����ݿ�
	BOOL DB_Create_Student(  CEGUID * pCeGuid, /*���ݿ��ļ�������*/
							const LPCTSTR strDBName /*���ݿ�����*/);
	//��ȡ���ݿ�ļ�¼��Ŀ
	int GetRecordCount(CEGUID *pCeGuid,CEOID ceOid);

public:
	//�����ݿ�
	BOOL DB_Open_Student(const LPCTSTR strVolumeName = DBFILENAME, /*���ݿ��ļ�������*/
							const LPCTSTR strDBName = DBTABLENAME/*���ݿ�����*/);
	//�ر����ݿ�
	BOOL DB_Close_Student();
public:
	//��Ӽ�¼
	static BOOL AddNewStudent(const REC_STUDENT *pRecStudent);
	//�༭��¼
	static BOOL EditStudent(LPCTSTR strNo,const REC_STUDENT *pRecStudent);
	//ɾ����¼
	static BOOL DeleteStudent(LPCTSTR strNo);
public:
	//����ѧ����ţ���ѯ��¼
	static BOOL QueryStudent(const LPCTSTR strNo,REC_STUDENT *pRecStudent);
	//��ѯ���м�¼
	static BOOL QueryAllRecords(DWORD *pRecordCount,REC_STUDENT **pRecStudent);
};
