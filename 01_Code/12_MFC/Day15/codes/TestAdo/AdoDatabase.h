// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__A2DAE8B0_8517_4D79_ADA6_A377F9ACDEBE__INCLUDED_)
#define AFX_ADODATABASE_H__A2DAE8B0_8517_4D79_ADA6_A377F9ACDEBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoDatabase  
{
public:
	CAdoDatabase();
	virtual ~CAdoDatabase();
public:
	//连接数据库
	BOOL OpenMDB(CString strPath);
	//关闭数据库
	void Close();

public:
	_ConnectionPtr m_pConn;
};

#endif // !defined(AFX_ADODATABASE_H__A2DAE8B0_8517_4D79_ADA6_A377F9ACDEBE__INCLUDED_)
