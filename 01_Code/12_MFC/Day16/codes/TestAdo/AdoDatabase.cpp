// AdoDatabase.cpp: implementation of the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoDatabase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoDatabase::CAdoDatabase()
{

}

CAdoDatabase::~CAdoDatabase()
{
   Close();
}
BOOL CAdoDatabase::OpenMDB(CString strPath)
{
	 // 1 创建Connection对象
	 HRESULT hRet=
		 m_pConn.CreateInstance(__uuidof(Connection));
   if (FAILED(hRet))
   {
		 return FALSE;
   }
	 // 2 调用Open函数连接数据库
	 CString strConn;
	 strConn.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;",strPath);
	 hRet=m_pConn->Open(_bstr_t(strConn),"","",-1);
	 if (FAILED(hRet))
	 {
		 return FALSE;
	 }
	 return TRUE;
}
void CAdoDatabase::Close()
{
	m_pConn->Close();
}
void CAdoDatabase::OpenSql(CString strSql)
{
	m_pConn->Execute(_bstr_t(strSql),
		NULL,adCmdText);
}
void CAdoDatabase::BeginTrans()
{
	m_pConn->BeginTrans();
} 
void CAdoDatabase::EndTrans(BOOL bCommit)
{
	if (bCommit)
	{
		m_pConn->CommitTrans();
	} 
	else
	{
		m_pConn->RollbackTrans();
	}
}