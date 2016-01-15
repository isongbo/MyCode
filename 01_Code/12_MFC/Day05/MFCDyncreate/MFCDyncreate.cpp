#include "stdafx.h"
#include "MFCDyncreate.h"
class CAnimal : public CObject
{
	DECLARE_DYNCREATE( CAnimal )
};
IMPLEMENT_DYNCREATE( CAnimal, CObject )

class CDog : public CAnimal
{
//	DECLARE_DYNCREATE( CDog )
public: 
	static const AFX_DATA CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 
	static CObject* PASCAL CreateObject();
};
//IMPLEMENT_DYNCREATE( CDog, CAnimal )
CObject* PASCAL CDog::CreateObject() 
{
	return new CDog; 
} 
AFX_COMDAT const AFX_DATADEF 
CRuntimeClass CDog::classCDog = { 
	"CDog", 
	sizeof(class CDog), 
	0xFFFF, 
	CDog::CreateObject, 
	RUNTIME_CLASS(CAnimal), 
	NULL 
}; 
CRuntimeClass* CDog::GetRuntimeClass() const 
{ 
	return RUNTIME_CLASS(CDog); 
} 



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	CObject *pObj = RUNTIME_CLASS(CDog)->CreateObject( );
	//对象加工厂
	if( pObj->IsKindOf( RUNTIME_CLASS(CDog) ) )
	{
		printf( "%p\n", pObj );
	}else{
		printf( "pObj isnot CDog\n" );
	}
	return 0;
}


