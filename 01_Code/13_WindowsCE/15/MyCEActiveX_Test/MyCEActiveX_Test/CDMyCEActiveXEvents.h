// CDMyCEActiveXEvents.h : �� Microsoft Visual C++ ������ ActiveX �ؼ���װ�������

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDMyCEActiveXEvents

class CDMyCEActiveXEvents : public COleDispatchDriver
{
public:
	CDMyCEActiveXEvents() {}		// ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CDMyCEActiveXEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDMyCEActiveXEvents(const CDMyCEActiveXEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// ����
public:

// ����
public:

	void OnMsgChange()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
