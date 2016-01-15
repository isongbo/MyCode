// MyCEActiveXPropPage.cpp : CMyCEActiveXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "MyCEActiveX.h"
#include "MyCEActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMyCEActiveXPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMyCEActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMyCEActiveXPropPage, "MYCEACTIVEX.MyCEActiveXPropPage.1",
	0xe45f7b7a, 0x3e42, 0x436a, 0x80, 0x38, 0x88, 0x23, 0xd6, 0x5f, 0x6e, 0x9)



// CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMyCEActiveXPropPage ��ϵͳע�����

BOOL CMyCEActiveXPropPage::CMyCEActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYCEACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMyCEActiveXPropPage::CMyCEActiveXPropPage - ���캯��

CMyCEActiveXPropPage::CMyCEActiveXPropPage() :
	COlePropertyPage(IDD, IDS_MYCEACTIVEX_PPG_CAPTION)
		, m_Msg(_T(""))
	{
}



// CMyCEActiveXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMyCEActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_Text(pDX,IDC_EDT_MSG,m_Msg,L"MsgContext");
	DDX_Text(pDX, IDC_EDT_MSG, m_Msg);
	DDP_PostProcessing(pDX);
}



// CMyCEActiveXPropPage ��Ϣ�������
