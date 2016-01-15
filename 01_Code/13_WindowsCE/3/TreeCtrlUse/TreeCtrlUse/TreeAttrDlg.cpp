// TreeAttrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TreeCtrlUse.h"
#include "TreeAttrDlg.h"


// CTreeAttrDlg 对话框

IMPLEMENT_DYNAMIC(CTreeAttrDlg, CDialog)

CTreeAttrDlg::CTreeAttrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeAttrDlg::IDD, pParent)
	, m_bEditLabels(FALSE)
	, m_bHasButtons(FALSE)
	, m_bHasLines(FALSE)
	, m_bLinesAtRoot(FALSE)
	, m_bShowSelAlways(FALSE)
{

}

CTreeAttrDlg::~CTreeAttrDlg()
{
}

void CTreeAttrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bEditLabels);
	DDX_Check(pDX, IDC_CHECK2, m_bHasButtons);
	DDX_Check(pDX, IDC_CHECK3, m_bHasLines);
	DDX_Check(pDX, IDC_CHECK4, m_bLinesAtRoot);
	DDX_Check(pDX, IDC_CHECK5, m_bShowSelAlways);
}


BEGIN_MESSAGE_MAP(CTreeAttrDlg, CDialog)
END_MESSAGE_MAP()


// CTreeAttrDlg 消息处理程序
