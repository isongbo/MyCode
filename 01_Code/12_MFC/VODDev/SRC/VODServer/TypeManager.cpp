// TypeManager.cpp: implementation of the CTypeManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vodserver.h"
#include "TypeManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTypeManager::CTypeManager(CAdoConnection *pConn)
{
   m_pConn=pConn;
}

CTypeManager::~CTypeManager()
{

}
void CTypeManager::GetAllType(CList<CType,CType> *pLstType)
{
	CAdoRecordSet set;
	set.SetAdoConnection(m_pConn);
	set.SetCursorLocation();
	set.Open("TypeInfo",adCmdTable);
    CType type;
	while(!set.IsEOF())
	{
		set.GetCollect("id",type.nTypeID);
		set.GetCollect("typeName",type.strTypeName);
		pLstType->AddTail(type);
		set.MoveNext();
	}
}

