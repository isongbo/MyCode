// MyCEActiveXPropPage.cpp : CMyCEActiveXPropPage 属性页类的实现。

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMyCEActiveXPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CMyCEActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXPropPage, "MYCEACTIVEX.MyCEActiveXPropPage.1",
	0xe45f7b7a, 0x3e42, 0x436a, 0x80, 0x38, 0x88, 0x23, 0xd6, 0x5f, 0x6e, 0x9)



// CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CMyCEActiveXPropPage 的系统注册表项

BOOL CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYCEACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMyCEActiveXPropPage::CMyCEActiveXPropPage - 构造函数

CMyCEActiveXPropPage::CMyCEActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MYCEACTIVEX_PPG_CAPTION)
		, m_Msg(_T(""))
	{
}



// CMyCEActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CMyCEActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_Text(pDX,IDC_EDT_MSG,m_Msg,L"MsgContext");
	DDX_Text(pDX, IDC_EDT_MSG, m_Msg);
	DDP_PostProcessing(pDX);
}



// CMyCEActiveXPropPage 消息处理程序
