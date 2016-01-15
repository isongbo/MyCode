// CDMyCEActiveXEvents.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDMyCEActiveXEvents

class CDMyCEActiveXEvents : public COleDispatchDriver
{
public:
	CDMyCEActiveXEvents() {}		// 调用 COleDispatchDriver 默认构造函数
	CDMyCEActiveXEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDMyCEActiveXEvents(const CDMyCEActiveXEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 属性
public:

// 操作
public:

	void OnMsgChange()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
