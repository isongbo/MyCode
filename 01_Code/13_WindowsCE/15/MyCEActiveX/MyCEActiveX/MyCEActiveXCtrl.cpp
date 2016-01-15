// MyCEActiveXCtrl.cpp : CMyCEActiveXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXCtrl.h"
#include "MyCEActiveXPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyCEActiveXCtrl, COleControl)


// 消息映射

BEGIN_MESSAGE_MAP(CMyCEActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CMyCEActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CMyCEActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)

	DISP_PROPERTY_EX_ID(CMyCEActiveXCtrl, "MsgContext", dispidMsgContext, GetMsgContext, SetMsgContext, VT_BSTR)
	DISP_FUNCTION_ID(CMyCEActiveXCtrl, "ShowMessage", dispidShowMessage, ShowMessage, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CMyCEActiveXCtrl, COleControl)
	EVENT_CUSTOM_ID("OnMsgChange", eventidOnMsgChange, OnMsgChange, VTS_NONE)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CMyCEActiveXCtrl, 1)
	PROPPAGEID(CMyCEActiveXPropPage::guid)
END_PROPPAGEIDS(CMyCEActiveXCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXCtrl, "MYCEACTIVEX.MyCEActiveXCtrl.1",
	0xeb53d4d7, 0x35cf, 0x4ce3, 0x8a, 0x4, 0x97, 0x6e, 0x59, 0xeb, 0x35, 0x9f)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMyCEActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID BASED_CODE IID_DMyCEActiveX =
		{ 0x8EFBAF8F, 0x968F, 0x48DD, { 0xA8, 0xAC, 0x88, 0x2F, 0xE4, 0x57, 0x97, 0x2B } };
const IID BASED_CODE IID_DMyCEActiveXEvents =
		{ 0x7245A74E, 0x5F56, 0x4EF0, { 0xA1, 0x90, 0x6E, 0xD5, 0x17, 0xFE, 0xB6, 0x1 } };



// 控件类型信息

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
// 添加或移除 CMyCEActiveXCtrl 的系统注册表项

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



// CMyCEActiveXCtrl::CMyCEActiveXCtrl - 构造函数

CMyCEActiveXCtrl::CMyCEActiveXCtrl()
{
	// TODO: 需要时为 m_dwCurrentSafety 和 m_dwSupportedSafety 属性设置适当的值。
	// 可以是 INTERFACESAFE_FOR_UNTRUSTED_DATA 或 INTERFACESAFE_FOR_UNTRUSTED_CALLER 或这两者，
	// 具体取决于实际方案。
	m_dwCurrentSafety = 0;
	m_dwSupportedSafety = 0;
	InitializeIIDs(&IID_DMyCEActiveX, &IID_DMyCEActiveXEvents);
	// TODO: 在此初始化控件的实例数据。
}



// CMyCEActiveXCtrl::~CMyCEActiveXCtrl - 析构函数

CMyCEActiveXCtrl::~CMyCEActiveXCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CMyCEActiveXCtrl::OnDraw - 绘图函数

void CMyCEActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CMyCEActiveXCtrl::DoPropExchange - 持久性支持

void CMyCEActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_String(pPX,L"MsgContext",m_MsgContext,L"欢迎使用此Acitvex，呵呵");
	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CMyCEActiveXCtrl::OnResetState - 将控件重置为默认状态

void CMyCEActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}


// CMyCEActiveXCtrl::AboutBox - 向用户显示“关于”框

void CMyCEActiveXCtrl::AboutBox()
{
#ifdef _DEVICE_RESOLUTION_AWARE
	CDialog dlgAbout(IDD_ABOUTBOX_MYCEACTIVEX, IDD_ABOUTBOX_MYCEACTIVEX_WIDE);
#else
	CDialog dlgAbout(IDD_ABOUTBOX_MYCEACTIVEX);
#endif
	dlgAbout.DoModal();
}




// CMyCEActiveXCtrl 消息处理程序

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

	// 检查我们是否支持此接口
	IUnknown* pUnk;
	HRESULT hr = this->QueryInterface(riid, (void**)&pUnk);
	if (SUCCEEDED(hr))
	{
		// 我们支持此接口，因此可相应地设置安全选项
		*pdwSupportedOptions = pThis->m_dwSupportedSafety;
		*pdwEnabledOptions   = pThis->m_dwCurrentSafety;
	}
	else
	{
		// 我们不支持此接口
		*pdwSupportedOptions = 0;
		*pdwEnabledOptions   = 0;
	}
	return hr;
}

STDMETHODIMP CMyCEActiveXCtrl::XObjectSafety::SetInterfaceSafetyOptions(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions)
{
	// 如果已修改，则返回 S_OK，否则返回 S_FALSE。
	METHOD_PROLOGUE_EX_(CMyCEActiveXCtrl, ObjectSafety)

	// 检查我们是否支持该接口，如果不支持则返回 E_NOINTEFACE
	IUnknown* pUnk;
	if (FAILED(this->QueryInterface(riid, (void**)&pUnk)))
		return E_NOINTERFACE;

	// 如果要求我们设置不支持的选项，则会失败
	if (dwOptionSetMask & ~pThis->m_dwSupportedSafety)
		return E_FAIL;

	// 设置所要求的安全选项
	pThis->m_dwCurrentSafety = (pThis->m_dwCurrentSafety  & ~dwOptionSetMask)  |  (dwOptionSetMask & dwEnabledOptions);		
	return S_OK;
}

BSTR CMyCEActiveXCtrl::GetMsgContext(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
    return m_MsgContext.AllocSysString();
}

//设置MsgContext属性
void CMyCEActiveXCtrl::SetMsgContext(LPCTSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加属性处理程序代码
	if (m_MsgContext.Compare(newVal) != 0 )
	{
		m_MsgContext = newVal;
		//出发OnChange事件
		OnMsgChange();
		SetModifiedFlag();
	}
}

void CMyCEActiveXCtrl::ShowMessage(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

    AfxMessageBox(m_MsgContext);
}
