// Add.cpp : CAdd ��ʵ��

#include "stdafx.h"
#include "Add.h"


// CAdd

//IAdd �ӿڵ�Add����
STDMETHODIMP CAdd::Add(LONG a, LONG b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	Sleep(1000);
	//����ִ���������
	Fire_ExecutionOver(a+b);

	return S_OK;
}
