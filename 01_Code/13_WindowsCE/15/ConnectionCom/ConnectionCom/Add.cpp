// Add.cpp : CAdd 的实现

#include "stdafx.h"
#include "Add.h"


// CAdd

//IAdd 接口的Add方法
STDMETHODIMP CAdd::Add(LONG a, LONG b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	Sleep(1000);
	//触发执行完毕命令
	Fire_ExecutionOver(a+b);

	return S_OK;
}
