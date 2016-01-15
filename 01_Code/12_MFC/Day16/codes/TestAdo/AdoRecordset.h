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
	//打开表
	BOOL OpenTable(CString strTable,CAdoDatabase* pDB);
  //执行Sql语句
	BOOL OpenSql(CString strSql,CAdoDatabase* pDB); 
	//获取记录集字段的数量
	long GetFieldCount();
	//根据字段的索引得到字段的名称
	void GetFieldName(long nIndex,CString& strName);
  //设置/获取字段的值
	void SetFieldValue(long nIndex,CString strValue);
	void GetFieldValue(long nIndex,CString& strValue);
  // 记录集的指针操作
	void MoveNext();
	void MovePrevious();
	void MoveFirst();
	void MoveLast();
	void Move(long nNums);
	BOOL IsBOF();
	BOOL IsEOF();
	// 添加新记录
	void AddNew();
	// 更新到数据库
	void Update();
	// 删除记录
	void Delete();
public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__DB2622B5_2D12_44EF_B48F_5B6C3690E379__INCLUDED_)
