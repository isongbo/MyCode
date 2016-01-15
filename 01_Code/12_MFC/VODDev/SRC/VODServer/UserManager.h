// UserManager.h: interface for the CUserManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERMANAGER_H__3B1091CB_25AA_441A_A159_5FEF9486D67C__INCLUDED_)
#define AFX_USERMANAGER_H__3B1091CB_25AA_441A_A159_5FEF9486D67C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct CUser
{
	int nUserID;
	CString strUserName;
	CString strPwd;
	double  fBalance;
    CString strRemark;
};
class CUserManager  
{
public:
	CUserManager(CAdoConnection *pConn);
	virtual ~CUserManager();
	BOOL ValidateUser(CUser user);
	void InsertUser(CUser user);
	CAdoConnection *m_pConn;
};

#endif // !defined(AFX_USERMANAGER_H__3B1091CB_25AA_441A_A159_5FEF9486D67C__INCLUDED_)
