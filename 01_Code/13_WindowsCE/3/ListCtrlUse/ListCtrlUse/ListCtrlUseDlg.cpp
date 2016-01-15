// ListCtrlUseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ListCtrlUse.h"
#include "ListCtrlUseDlg.h"
#include "ListCtrlAttr.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CListCtrlUseDlg 对话框

CListCtrlUseDlg::CListCtrlUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_LISTCTRL, &CListCtrlUseDlg::OnNMDblclkListctrl)
END_MESSAGE_MAP()


// CListCtrlUseDlg 消息处理程序

BOOL CListCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CListCtrlUseApp *pApp;
	pApp = (CListCtrlUseApp*)AfxGetApp();
	//创建图标列表控件
	m_pImageList = new CImageList();		
	m_pImageListSmall = new CImageList();
	
	m_pImageList->Create(32, 32, TRUE,	4, 4);
	m_pImageListSmall->Create(16, 16, TRUE, 4, 4);

	//加载正常图标
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL1));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL2));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL3));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL4));

	//加载小图标
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL1));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL2));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL3));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL4));

	//设置列表视图样式
	m_bSingleSel      = FALSE;
	m_bEditLabels     = FALSE;
	m_bNoColumnHeader = FALSE;

	m_cstrViewMode = _T("报表");
	m_cstrSort = _T("无");
	m_cstrAlignMode = _T("上对齐");


	SetListCtrl();



	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CListCtrlUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_LISTCTRLUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_LISTCTRLUSE_DIALOG));
	}
}
#endif


//填充列表视图
void CListCtrlUseDlg::FillListCtrl(void)
{
	CRect			rect;
	int				i, iIcon, iItem, iSubItem, iActualItem;
	LV_ITEM			lvitem;
	LV_COLUMN		lvcolumn;
	TCHAR			rgtsz[2][10];
	CListCtrlUseApp	*pApp;
	TCHAR			rgtszIconType[4][12];
	TCHAR			rgtszIconDescrip[4][50];

	_tcscpy(rgtsz[0], _T("类型"));
	_tcscpy(rgtsz[1], _T("描述"));

	_tcscpy(rgtszIconType[0], _T("信息"));
	_tcscpy(rgtszIconType[1], _T("错误"));
	_tcscpy(rgtszIconType[2], _T("提示"));
	_tcscpy(rgtszIconType[3], _T("哈哈"));

	_tcscpy(rgtszIconDescrip[0], _T("欢迎使用列表视图控件"));
	_tcscpy(rgtszIconDescrip[1], _T("非法使用列表视图控件"));
	_tcscpy(rgtszIconDescrip[2], _T("呵呵，使用此功能要消息"));
	_tcscpy(rgtszIconDescrip[3], _T("放轻松点，只是逗你玩"));

	pApp = (CListCtrlUseApp *)AfxGetApp();

	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTCTRL);
	pListCtrl->SetImageList(m_pImageList, LVSIL_NORMAL);
	pListCtrl->SetImageList(m_pImageListSmall, LVSIL_SMALL);
	pListCtrl->GetWindowRect(&rect);

	//定义列表视图的列
	for (i = 0; i < 2; i++)  
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = rect.Width() * (i + 1) / 4;	//将第2列宽度设置成第1列宽度3倍
		pListCtrl->InsertColumn(i, &lvcolumn);		//插入列     
	}

	//向列表视图里，添加内容
	for (iItem = 0; iItem < 50; iItem++)  
		for (iSubItem = 0; iSubItem < 2; iSubItem++)
		{
			if (iSubItem == 0)
				iIcon = Random() % 4;

			lvitem.mask = LVIF_TEXT | (iSubItem == 0? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0)? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			lvitem.pszText = iSubItem == 0? rgtszIconType[iIcon] : rgtszIconDescrip[iIcon];

			lvitem.iImage = iIcon;
			//判断，如果是添加第1列，则应该添加一行，否则，只要设置这一行即可。
			if (iSubItem == 0)
				iActualItem = pListCtrl->InsertItem(&lvitem);
			else
				pListCtrl->SetItem(&lvitem);
		}
}

//设置列表视图
void CListCtrlUseDlg::SetListCtrl(void)
{
	long lStyle = 0;
	long lMask = LVS_SINGLESEL | LVS_EDITLABELS |
		LVS_NOLABELWRAP | LVS_NOCOLUMNHEADER | LVS_NOSORTHEADER |
		LVS_ICON | LVS_SMALLICON | LVS_REPORT | LVS_LIST |
		LVS_SORTASCENDING | LVS_SORTDESCENDING | LVS_ALIGNLEFT;
				
	//设置是否只能单选属性
	if(m_bSingleSel)
		lStyle |= LVS_SINGLESEL;
	//设置是否可以编辑标签
	if(m_bEditLabels)
		lStyle |= LVS_EDITLABELS;
	//设置是否有表头
	if(m_bNoColumnHeader)
		lStyle |= LVS_NOCOLUMNHEADER;
	
	//设置报表样式
	if (m_cstrViewMode == _T("图标"))
		lStyle |= LVS_ICON;
	else if (m_cstrViewMode == _T("小图标"))
		lStyle |= LVS_SMALLICON;
	else if (m_cstrViewMode == _T("报表"))
		lStyle |= LVS_REPORT;
	else
	{
		ASSERT(m_cstrViewMode == _T("列表"));
		lStyle |= LVS_LIST;
	}
	
	//设置排序样式
	if (m_cstrSort == _T("升序"))
		lStyle |= LVS_SORTASCENDING;
	else if (m_cstrSort == _T("降序"))
		lStyle |= LVS_SORTDESCENDING;
	else
		ASSERT(m_cstrSort == _T("无"));
	
	//设置对齐样式
	if (m_cstrAlignMode == _T("左对齐"))
		lStyle |= LVS_ALIGNLEFT;
	else
		ASSERT(m_cstrAlignMode == _T("上对齐"));

	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTCTRL);
	
	//得到列表视图已有样式
	long lNewStyle = GetWindowLong(pListCtrl->m_hWnd, GWL_STYLE);
	lNewStyle &= ~lMask; 
	lNewStyle = lNewStyle | lStyle;
	
	//重新生成列表视图控件
	CRect rect;
	GetClientRect(&rect);
	pListCtrl->DestroyWindow();
	//重新创建列表视图控件
	pListCtrl->Create(lNewStyle, rect, this, IDC_LISTCTRL);
	//设置列表视图控件的图标列表
	pListCtrl->SetImageList(m_pImageList, LVSIL_NORMAL);
	pListCtrl->SetImageList(m_pImageListSmall, LVSIL_SMALL);
	
	//重新填充列表视图内容
	FillListCtrl();
}

//对话框销毁事件
void CListCtrlUseDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	//释放图片列表资源
    delete m_pImageList;
	m_pImageList = NULL;
	delete m_pImageListSmall;
	m_pImageListSmall = NULL;

}

//列表视图控件双击事件
void CListCtrlUseDlg::OnNMDblclkListctrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	CListCtrlAttr * pListCtrlAttr = new CListCtrlAttr();

	pListCtrlAttr->m_bSingleSel      = m_bSingleSel;
	pListCtrlAttr->m_bEditLabels     = m_bEditLabels;
	pListCtrlAttr->m_bNoColumnHeader = m_bNoColumnHeader;
	pListCtrlAttr->m_cstrViewMode    = m_cstrViewMode;
	pListCtrlAttr->m_cstrSort        = m_cstrSort;
	pListCtrlAttr->m_cstrAlignMode   = m_cstrAlignMode;
	if( pListCtrlAttr->DoModal() == IDOK)
	{
		m_bSingleSel      = pListCtrlAttr->m_bSingleSel;
		m_bEditLabels     = pListCtrlAttr->m_bEditLabels;
		m_bNoColumnHeader = pListCtrlAttr->m_bNoColumnHeader;
		m_cstrViewMode    = pListCtrlAttr->m_cstrViewMode;
		m_cstrSort        = pListCtrlAttr->m_cstrSort;
		m_cstrAlignMode   = pListCtrlAttr->m_cstrAlignMode;
		SetListCtrl();
	}
	delete pListCtrlAttr;
	pListCtrlAttr=NULL;	

}
