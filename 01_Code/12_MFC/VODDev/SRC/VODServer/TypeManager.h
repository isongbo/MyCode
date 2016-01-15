// TypeManager.h: interface for the CTypeManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPEMANAGER_H__1933BB49_A18F_4FD0_9EFA_93DAAFAC28D1__INCLUDED_)
#define AFX_TYPEMANAGER_H__1933BB49_A18F_4FD0_9EFA_93DAAFAC28D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include ".\ado\Ado.h"
struct CType
{
	int nTypeID;
	CString strTypeName;
};
class CTypeManager  
{
public:
	void GetAllType(CList<CType,CType> *pLstType);

	CTypeManager(CAdoConnection *pConn);
	virtual ~CTypeManager();
	CAdoConnection *m_pConn;

};

#endif // !defined(AFX_TYPEMANAGER_H__1933BB49_A18F_4FD0_9EFA_93DAAFAC28D1__INCLUDED_)
