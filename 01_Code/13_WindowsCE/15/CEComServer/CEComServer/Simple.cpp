// Simple.cpp : CSimple ��ʵ��

#include "stdafx.h"
#include "Simple.h"


// CSimple


STDMETHODIMP CSimple::ShowSvrMsg(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ����ʵ�ִ���
	::MessageBox(NULL,_T("����Ϣ����COM"),_T("COM����"),MB_OK);
	return S_OK;
}
