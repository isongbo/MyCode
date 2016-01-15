// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__DB2622B5_2D12_44EF_B48F_5B6C3690E379__INCLUDED_)
#define AFX_ADORECORDSET_H__DB2622B5_2D12_44EF_B48F_5B6C3690E379__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoDatabase.h"
class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	//�򿪱�
	BOOL OpenTable(CString strTable,CAdoDatabase* pDB);
  //ִ��Sql���
	BOOL OpenSql(CString strSql,CAdoDatabase* pDB); 
	//��ȡ��¼���ֶε�����
	long GetFieldCount();
	//�����ֶε������õ��ֶε�����
	void GetFieldName(long nIndex,CString& strName);
  //����/��ȡ�ֶε�ֵ
	void SetFieldValue(long nIndex,CString strValue);
	void GetFieldValue(long nIndex,CString& strValue);
  // ��¼����ָ�����
	void MoveNext();
	void MovePrevious();
	void MoveFirst();
	void MoveLast();
	void Move(long nNums);
	BOOL IsBOF();
	BOOL IsEOF();
	// ����¼�¼
	void AddNew();
	// ���µ����ݿ�
	void Update();
	// ɾ����¼
	void Delete();
public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__DB2622B5_2D12_44EF_B48F_5B6C3690E379__INCLUDED_)
