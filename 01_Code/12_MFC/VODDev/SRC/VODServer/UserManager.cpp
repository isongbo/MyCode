// UserManager.cpp: implementation of the CUserManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vodserver.h"
#include "UserManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserManager::CUserManager(CAdoConnection *pConn)
{
     m_pConn=pConn;
}

CUserManager::~CUserManager()
{

}
BOOL CUserManager::ValidateUser(CUser user)
{
    CString strSql;
	strSql.Format("select * from userInfo where userName='%s' and pwd='%s'",
		user.strUserName,user.strPwd);
	CAdoRecordSet set(m_pConn);
	set.Open(strSql);
	if(set.GetRecordCount()>0)
	{
       return TRUE;
	}
	return FALSE;
}
void CUserManager::InsertUser(CUser user)
{
	CString strSql;
	strSql.Format("insert into userInfo(userName,pwd,balance,remark) values('%s','%s',%f,'%s')",
		user.strUserName,user.strPwd,user.fBalance,user.strRemark);
	m_pConn->Execute(strSql);
	 
}
