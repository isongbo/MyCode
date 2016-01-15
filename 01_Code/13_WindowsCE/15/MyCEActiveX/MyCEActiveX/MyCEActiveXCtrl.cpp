// MyCEActiveXCtrl.cpp : CMyCEActiveXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXCtrl.h"
#include "MyCEActiveXPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyCEActiveXCtrl, COleControl)


// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMyCEActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CMyCEActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CMyCEActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)

	DISP_PROPERTY_EX_ID(CMyCEActiveXCtrl, "MsgContext", dispidMsgContext, GetMsgContext, SetMsgContext, VT_BSTR)
	DISP_FUNCTION_ID(CMyCEActiveXCtrl, "ShowMessage", dispidShowMessage, ShowMessage, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CMyCEActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("OnMsgChange", eventidOnMsgChange, OnMsgChange, VTS_NONE)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMyCEActiveXCtrl, 1)
	PROPPAGEID(CMyCEActiveXPropPage::guid)
END_PROPPAGEIDS(CMyCEActiveXCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXCtrl, "MYCEACTIVEX.MyCEActiveXCtrl.1",
	0xeb53d4d7, 0x35cf, 0x4ce3, 0x8a, 0x4, 0x97, 0x6e, 0x59, 0xeb, 0x35, 0x9f)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMyCEActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID BASED_CODE IID_DMyCEActiveX =
		{ 0x8EFBAF8F, 0x968F, 0x48DD, { 0xA8, 0xAC, 0x88, 0x2F, 0xE4, 0x57, 0x97, 0x2B } };
const IID BASED_CODE IID_DMyCEActiveXEvents =
		{ 0x7245A74E, 0x5F56, 0x4EF0, { 0xA1, 0x90, 0x6E, 0xD5, 0x17, 0xFE, 0xB6, 0x1 } };



// �ؼ�������Ϣ

static const DWORD BASED_CODE _dwMyCEActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyCEActiveXCtrl, IDS_MYCEACTIVEX, _dwMyCEActiveXOleMisc)

BEGIN_INTERFACE_MAP(CMyCEActiveXCtrl, COleControl)
	INTERFACE_PART(CMyCEActiveXCtrl, IID_IObjectSafety, ObjectSafety)
END_INTERFACE_MAP()

// CMyCEActiveXCtrl::CMyCEActiveXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMyCEActiveXCtrl ��ϵͳע�����

BOOL CMyCEActiveXCtrl::CMyCEActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
#ifndef _CE_DCOM
	int nRegFlags = afxRegFreeThreading;
#else
	int nRegFlags = afxRegApartmentThreading;
#endif // !_CE_DCOM

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MYCEACTIVEX,
			IDB_MYCEACTIVEX,
			nRegFlags,
			_dwMyCEActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMyCEActiveXCtrl::CMyCEActiveXCtrl - ���캯��

CMyCEActiveXCtrl::CMyCEActiveXCtrl()
{
	// TODO: ��ҪʱΪ m_dwCurrentSafety �� m_dwSupportedSafety ���������ʵ���ֵ��
	// ������ INTERFACESAFE_FOR_UNTRUSTED_DATA �� INTERFACESAFE_FOR_UNTRUSTED_CALLER �������ߣ�
	// ����ȡ����ʵ�ʷ�����
	m_dwCurrentSafety = 0;
	m_dwSupportedSafety = 0;
	InitializeIIDs(&IID_DMyCEActiveX, &IID_DMyCEActiveXEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}



// CMyCEActiveXCtrl::~CMyCEActiveXCtrl - ��������

CMyCEActiveXCtrl::~CMyCEActiveXCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CMyCEActiveXCtrl::OnDraw - ��ͼ����

void CMyCEActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CMyCEActiveXCtrl::DoPropExchange - �־���֧��

void CMyCEActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_String(pPX,L"MsgContext",m_MsgContext,L"��ӭʹ�ô�Acitvex���Ǻ�");
	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CMyCEActiveXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMyCEActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}


// CMyCEActiveXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CMyCEActiveXCtrl::AboutBox()
{
#ifdef _DEVICE_RESOLUTION_AWARE
	CDialog dlgAbout(IDD_ABOUTBOX_MYCEACTIVEX, IDD_ABOUTBOX_MYCEACTIVEX_WIDE);
#else
	CDialog dlgAbout(IDD_ABOUTBOX_MYCEACTIVEX);
#endif
	dlgAbout.DoModal();
}




// CMyCEActiveXCtrl ��Ϣ�������

// CMyCEActiveXCtrl::XObjectSafety
STDMETHODIMP_(ULONG) CMyCEActiveXCtrl::XObjectSafety::AddRef()
{
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)
	return (ULONG)pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CMyCEActiveXCtrl::XObjectSafety::Release()
{
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)
	return (ULONG)pThis->ExternalRelease();
}

STDMETHODIMP CMyCEActiveXCtrl::XObjectSafety::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CMyCEActiveXCtrl::XObjectSafety::GetInterfaceSafetyOptions(REFIID riid, DWORD *pdwSupportedOptions, DWORD *pdwEnabledOptions)
{
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)

	if (pdwSupportedOptions == NULL || pdwEnabledOptions == NULL)
		return E_POINTER;

	// ��������Ƿ�֧�ִ˽ӿ�
	IUnknown* pUnk;
	HRESULT hr = this->QueryInterface(riid, (void**)&pUnk);
	if (SUCCEEDED(hr))
	{
		// ����֧�ִ˽ӿڣ���˿���Ӧ�����ð�ȫѡ��
		*pdwSupportedOptions = pThis->m_dwSupportedSafety;
		*pdwEnabledOptions   = pThis->m_dwCurrentSafety;
	}
	else
	{
		// ���ǲ�֧�ִ˽ӿ�
		*pdwSupportedOptions = 0;
		*pdwEnabledOptions   = 0;
	}
	return hr;
}

STDMETHODIMP CMyCEActiveXCtrl::XObjectSafety::SetInterfaceSafetyOptions(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions)
{
	// ������޸ģ��򷵻� S_OK�����򷵻� S_FALSE��
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)

	// ��������Ƿ�֧�ָýӿڣ������֧���򷵻� E_NOINTEFACE
	IUnknown* pUnk;
	if (FAILED(this->QueryInterface(riid, (void**)&pUnk)))
		return E_NOINTERFACE;

	// ���Ҫ���������ò�֧�ֵ�ѡ����ʧ��
	if (dwOptionSetMask & ~pThis->m_dwSupportedSafety)
		return E_FAIL;

	// ������Ҫ��İ�ȫѡ��
	pThis->m_dwCurrentSafety = (pThis->m_dwCurrentSafety  & ~dwOptionSetMask)  |  (dwOptionSetMask & dwEnabledOptions);		
	return S_OK;
}

BSTR CMyCEActiveXCtrl::GetMsgContext(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
    return m_MsgContext.AllocSysString();
}

//����MsgContext����
void CMyCEActiveXCtrl::SetMsgContext(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ�������Դ���������
	if (m_MsgContext.Compare(newVal) != 0 )
	{
		m_MsgContext = newVal;
		//����OnChange�¼�
		OnMsgChange();
		SetModifiedFlag();
	}
}

void CMyCEActiveXCtrl::ShowMessage(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

    AfxMessageBox(m_MsgContext);
}
