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
	//´ò¿ª±í
	BOOL OpenTable(CString strTable,CAdoDatabase* pDB);

public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__DB2622B5_2D12_44EF_B48F_5B6C3690E379__INCLUDED_)
