// Simple.cpp : CSimple 的实现

#include "stdafx.h"
#include "Simple.h"


// CSimple


STDMETHODIMP CSimple::ShowSvrMsg(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加实现代码
	::MessageBox(NULL,_T("此消息来自COM"),_T("COM测试"),MB_OK);
	return S_OK;
}
