// AdoRecordset.cpp: implementation of the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoRecordset::CAdoRecordset()
{

}

CAdoRecordset::~CAdoRecordset()
{

}
BOOL CAdoRecordset::OpenTable(CString strTable,
															CAdoDatabase* pDB)
{
	//1 ����Recordset����
	HRESULT nRet=
		m_pSet.CreateInstance(__uuidof(Recordset));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//2 �򿪱�
	nRet=m_pSet->Open(_variant_t(strTable),
		(IDispatch*)pDB->m_pConn,//�����
		adOpenKeyset,adLockOptimistic,adCmdTable);
  if (FAILED(nRet))
  {
		return FALSE;
  }
	return TRUE;
		
}
