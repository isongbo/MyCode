#include "stdafx.h"
#include "MFCDynamic.h"

class CAnimal : public CObject
{
	DECLARE_DYNAMIC( CAnimal )
};
IMPLEMENT_DYNAMIC( CAnimal, CObject )

class CDog : public CAnimal
{
//	DECLARE_DYNAMIC( CDog )
public: 
	static const AFX_DATA CRuntimeClass classCDog;
	virtual CRuntimeClass* GetRuntimeClass() const; 
};
//IMPLEMENT_DYNAMIC( CDog, CAnimal )
//一次展开
//IMPLEMENT_RUNTIMECLASS(CDog, CAnimal, 0xFFFF, NULL)
//二次展开
AFX_COMDAT const AFX_DATADEF 
CRuntimeClass CDog::classCDog = { 
	"CDog", 
	sizeof(class CDog), 
	0xFFFF, 
	NULL, 
//	RUNTIME_CLASS(CAnimal), 
	((CRuntimeClass*)(&CAnimal::classCAnimal)),
	NULL 
}; 
CRuntimeClass* CDog::GetRuntimeClass() const 
{ 
//	return RUNTIME_CLASS(CDog); 
	return ((CRuntimeClass*)(&CDog::classCDog));
} 


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	CDog yellowdog;
	if( yellowdog.IsKindOf( RUNTIME_CLASS(CWnd) ) )
	{
		printf( "yellowdog is CWnd\n" );
	}else{
		printf( "yellowdog isnot CWnd\n" );
	}
	return 0;
}


