// ListCtrlAttr.cpp : 实现文件
//

#include "stdafx.h"
#include "ListCtrlUse.h"
#include "ListCtrlAttr.h"


// CListCtrlAttr 对话框

IMPLEMENT_DYNAMIC(CListCtrlAttr, CDialog)

CListCtrlAttr::CListCtrlAttr(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlAttr::IDD, pParent)
	, m_bSingleSel(FALSE)
	, m_bEditLabels(FALSE)
	, m_bNoColumnHeader(FALSE)
	, m_cstrViewMode(_T(""))
	, m_cstrSort(_T(""))
	, m_cstrAlignMode(_T(""))
{

}

CListCtrlAttr::~CListCtrlAttr()
{
}

void CListCtrlAttr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHK_SINGLESELECT, m_bSingleSel);
	DDX_Check(pDX, IDC_CHK_EDITLABEL, m_bEditLabels);
	DDX_Check(pDX, IDC_CHK_COLUMNHEADER, m_bNoColumnHeader);
	DDX_CBString(pDX, IDC_CMB_VIEWMODE, m_cstrViewMode);
	DDX_CBString(pDX, IDC_CMB_SORT, m_cstrSort);
	DDX_CBString(pDX, IDC_CMB_ALIGN, m_cstrAlignMode);
}


BEGIN_MESSAGE_MAP(CListCtrlAttr, CDialog)
END_MESSAGE_MAP()


// CListCtrlAttr 消息处理程序
