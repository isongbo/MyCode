#pragma once

// MyCEActiveXCtrl.h : CMyCEActiveXCtrl ActiveX 控件类的声明。
#include <objsafe.h>

// CMyCEActiveXCtrl : 有关实现的信息，请参阅 MyCEActiveXCtrl.cpp。

class CMyCEActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyCEActiveXCtrl)

// 构造函数
public:
	CMyCEActiveXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 数据成员
protected:
	DWORD m_dwCurrentSafety;
	DWORD m_dwSupportedSafety;

// 实现
protected:
	~CMyCEActiveXCtrl();

	DECLARE_OLECREATE_EX(CMyCEActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMyCEActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyCEActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMyCEActiveXCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 接口
public:

	// IObjectSafety
	BEGIN_INTERFACE_PART(ObjectSafety, IObjectSafety)
		INIT_INTERFACE_PART(CMyCEActiveXCtrl, ObjectSafety)
		STDMETHOD(GetInterfaceSafetyOptions)(REFIID, DWORD *, DWORD *);
		STDMETHOD(SetInterfaceSafetyOptions)(REFIID, DWORD, DWORD);
	END_INTERFACE_PART_STATIC(ObjectSafety)

	DECLARE_INTERFACE_MAP()

// 调度和事件 ID
public:

	enum {
		eventidOnMsgChange = 1L,
		dispidShowMessage = 2L,
		dispidMsgContext = 1
	};
protected:
	BSTR GetMsgContext(void);
	void SetMsgContext(LPCTSTR newVal);
	void ShowMessage(void);

private:
   CString m_MsgContext;

protected:

	void OnMsgChange(void)
	{
		FireEvent(eventidOnMsgChange, EVENT_PARAM(VTS_NONE));
	}
};

