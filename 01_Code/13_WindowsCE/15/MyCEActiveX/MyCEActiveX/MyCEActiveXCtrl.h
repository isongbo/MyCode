#pragma once

// MyCEActiveXCtrl.h : CMyCEActiveXCtrl ActiveX �ؼ����������
#include <objsafe.h>

// CMyCEActiveXCtrl : �й�ʵ�ֵ���Ϣ������� MyCEActiveXCtrl.cpp��

class CMyCEActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyCEActiveXCtrl)

// ���캯��
public:
	CMyCEActiveXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ���ݳ�Ա
protected:
	DWORD m_dwCurrentSafety;
	DWORD m_dwSupportedSafety;

// ʵ��
protected:
	~CMyCEActiveXCtrl();

	DECLARE_OLECREATE_EX(CMyCEActiveXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMyCEActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyCEActiveXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMyCEActiveXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// �ӿ�
public:

	// IObjectSafety
	BEGIN_INTERFACE_PART(ObjectSafety, IObjectSafety)
		INIT_INTERFACE_PART(CMyCEActiveXCtrl, ObjectSafety)
		STDMETHOD(GetInterfaceSafetyOptions)(REFIID, DWORD *, DWORD *);
		STDMETHOD(SetInterfaceSafetyOptions)(REFIID, DWORD, DWORD);
	END_INTERFACE_PART_STATIC(ObjectSafety)

	DECLARE_INTERFACE_MAP()

// ���Ⱥ��¼� ID
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

