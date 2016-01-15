// McdCtl.cpp : Implementation of the CMcdCtrl ActiveX Control class.

#include "stdafx.h"
#include "Mcd.h"
#include "McdCtl.h"
#include "McdPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMcdCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMcdCtrl, COleControl)
	//{{AFX_MSG_MAP(CMcdCtrl)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CMcdCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CMcdCtrl)
	DISP_PROPERTY_NOTIFY(CMcdCtrl, "Direction", m_direction, OnDirectionChanged, VT_BOOL)
	DISP_FUNCTION(CMcdCtrl, "SetNumbers", SetNumbers, VT_EMPTY, VTS_I4 VTS_I4)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CMcdCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CMcdCtrl, COleControl)
	//{{AFX_EVENT_MAP(CMcdCtrl)
	EVENT_CUSTOM("MyMsg", FireMyMsg, VTS_NONE)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMcdCtrl, 1)
	PROPPAGEID(CMcdPropPage::guid)
END_PROPPAGEIDS(CMcdCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMcdCtrl, "MCD.McdCtrl.1",
	0x9df944f1, 0xff6, 0x4ecc, 0xb0, 0xd9, 0xfb, 0x97, 0x7, 0x33, 0xb, 0x83)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CMcdCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DMcd =
		{ 0x34cec94a, 0xa68d, 0x4a30, { 0x89, 0x35, 0x5d, 0xf5, 0x4d, 0xad, 0xe1, 0x84 } };
const IID BASED_CODE IID_DMcdEvents =
		{ 0x9e53b3f3, 0x8f1c, 0x42c3, { 0xaf, 0x4d, 0x1c, 0x9c, 0x7f, 0x18, 0xfe, 0xc9 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwMcdOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMcdCtrl, IDS_MCD, _dwMcdOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::CMcdCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMcdCtrl

BOOL CMcdCtrl::CMcdCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MCD,
			IDB_MCD,
			afxRegApartmentThreading,
			_dwMcdOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::CMcdCtrl - Constructor

CMcdCtrl::CMcdCtrl()
{
	InitializeIIDs(&IID_DMcd, &IID_DMcdEvents);
  //设置控件大小
	SetInitialSize(230,230);
	m_a=16;
	m_b=12;
	m_direction=FALSE;
  
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::~CMcdCtrl - Destructor

CMcdCtrl::~CMcdCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::OnDraw - Drawing function

void CMcdCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
   //绘制控件
	 //1 设置控件的背景色
	 CBrush brush(RGB(255,255,0));
   pdc->FillRect(rcBounds,&brush);
	 //2 设置圆的背景色
	 CBrush brush2(RGB(0,0,0));
	 CBrush* pOldBrush=pdc->SelectObject(&brush2);
   //3 圆心位置
	 POINT p1={40,110};
	 POINT p2={190,p1.y};
	 POINT p3={(p1.x+p2.x)/2,
		 m_direction?p1.y-60:p1.y+60};
	 int r=15;//半径
	 pdc->Ellipse(p1.x-r,p1.y-r,p1.x+r,p1.y+r);
	 pdc->Ellipse(p2.x-r,p2.y-r,p2.x+r,p2.y+r);
	 pdc->Ellipse(p3.x-r,p3.y-r,p3.x+r,p3.y+r);
	 //4 连线
	 pdc->MoveTo(p1);
	 pdc->LineTo(p3);
	 pdc->LineTo(p2);
	 //5 在圆中显示数值
	 pdc->SetBkMode(TRANSPARENT);
	 pdc->SetTextAlign(TA_CENTER);
	 pdc->SetTextColor(RGB(255,255,255));
	

	 CString strInfo;
	 strInfo.Format(_T("%d"),m_a);
	 pdc->TextOut(p1.x,p1.y-9,strInfo);
	 strInfo.Format(_T("%d"),m_b);
	 pdc->TextOut(p2.x,p2.y-9,strInfo);
	 strInfo.Format(_T("%d"),Mcd(m_a,m_b));
	 pdc->TextOut(p3.x,p3.y-9,strInfo);
   pdc->SelectObject(pOldBrush);

	 
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::DoPropExchange - Persistence support

void CMcdCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::OnResetState - Reset control to default state

void CMcdCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl::AboutBox - Display an "About" box to the user

void CMcdCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MCD);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CMcdCtrl message handlers

int CMcdCtrl::Mcd(int a, int b)
{
   if (b==0)
   {
		 return a;
   }
	 return Mcd(b,a%b);
}

void CMcdCtrl::SetNumbers(long x, long y) 
{
    m_a=x;
		m_b=y;
		InvalidateControl();
}

void CMcdCtrl::OnDirectionChanged() 
{
	// TODO: Add notification handler code
  InvalidateControl();
	SetModifiedFlag();
}

void CMcdCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	FireMyMsg();
//	COleControl::OnRButtonDown(nFlags, point);
}
