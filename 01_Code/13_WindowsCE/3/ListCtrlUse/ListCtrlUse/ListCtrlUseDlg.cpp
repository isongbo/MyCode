// ListCtrlUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListCtrlUse.h"
#include "ListCtrlUseDlg.h"
#include "ListCtrlAttr.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CListCtrlUseDlg �Ի���

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


// CListCtrlUseDlg ��Ϣ�������

BOOL CListCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CListCtrlUseApp *pApp;
	pApp = (CListCtrlUseApp*)AfxGetApp();
	//����ͼ���б�ؼ�
	m_pImageList = new CImageList();		
	m_pImageListSmall = new CImageList();
	
	m_pImageList->Create(32, 32, TRUE,	4, 4);
	m_pImageListSmall->Create(16, 16, TRUE, 4, 4);

	//��������ͼ��
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL1));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL2));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL3));
	m_pImageList->Add(pApp->LoadIcon(IDI_NORMAL4));

	//����Сͼ��
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL1));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL2));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL3));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_SMALL4));

	//�����б���ͼ��ʽ
	m_bSingleSel      = FALSE;
	m_bEditLabels     = FALSE;
	m_bNoColumnHeader = FALSE;

	m_cstrViewMode = _T("����");
	m_cstrSort = _T("��");
	m_cstrAlignMode = _T("�϶���");


	SetListCtrl();



	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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


//����б���ͼ
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

	_tcscpy(rgtsz[0], _T("����"));
	_tcscpy(rgtsz[1], _T("����"));

	_tcscpy(rgtszIconType[0], _T("��Ϣ"));
	_tcscpy(rgtszIconType[1], _T("����"));
	_tcscpy(rgtszIconType[2], _T("��ʾ"));
	_tcscpy(rgtszIconType[3], _T("����"));

	_tcscpy(rgtszIconDescrip[0], _T("��ӭʹ���б���ͼ�ؼ�"));
	_tcscpy(rgtszIconDescrip[1], _T("�Ƿ�ʹ���б���ͼ�ؼ�"));
	_tcscpy(rgtszIconDescrip[2], _T("�Ǻǣ�ʹ�ô˹���Ҫ��Ϣ"));
	_tcscpy(rgtszIconDescrip[3], _T("�����ɵ㣬ֻ�Ƕ�����"));

	pApp = (CListCtrlUseApp *)AfxGetApp();

	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTCTRL);
	pListCtrl->SetImageList(m_pImageList, LVSIL_NORMAL);
	pListCtrl->SetImageList(m_pImageListSmall, LVSIL_SMALL);
	pListCtrl->GetWindowRect(&rect);

	//�����б���ͼ����
	for (i = 0; i < 2; i++)  
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = rect.Width() * (i + 1) / 4;	//����2�п�����óɵ�1�п��3��
		pListCtrl->InsertColumn(i, &lvcolumn);		//������     
	}

	//���б���ͼ��������
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
			//�жϣ��������ӵ�1�У���Ӧ�����һ�У�����ֻҪ������һ�м��ɡ�
			if (iSubItem == 0)
				iActualItem = pListCtrl->InsertItem(&lvitem);
			else
				pListCtrl->SetItem(&lvitem);
		}
}

//�����б���ͼ
void CListCtrlUseDlg::SetListCtrl(void)
{
	long lStyle = 0;
	long lMask = LVS_SINGLESEL | LVS_EDITLABELS |
		LVS_NOLABELWRAP | LVS_NOCOLUMNHEADER | LVS_NOSORTHEADER |
		LVS_ICON | LVS_SMALLICON | LVS_REPORT | LVS_LIST |
		LVS_SORTASCENDING | LVS_SORTDESCENDING | LVS_ALIGNLEFT;
				
	//�����Ƿ�ֻ�ܵ�ѡ����
	if(m_bSingleSel)
		lStyle |= LVS_SINGLESEL;
	//�����Ƿ���Ա༭��ǩ
	if(m_bEditLabels)
		lStyle |= LVS_EDITLABELS;
	//�����Ƿ��б�ͷ
	if(m_bNoColumnHeader)
		lStyle |= LVS_NOCOLUMNHEADER;
	
	//���ñ�����ʽ
	if (m_cstrViewMode == _T("ͼ��"))
		lStyle |= LVS_ICON;
	else if (m_cstrViewMode == _T("Сͼ��"))
		lStyle |= LVS_SMALLICON;
	else if (m_cstrViewMode == _T("����"))
		lStyle |= LVS_REPORT;
	else
	{
		ASSERT(m_cstrViewMode == _T("�б�"));
		lStyle |= LVS_LIST;
	}
	
	//����������ʽ
	if (m_cstrSort == _T("����"))
		lStyle |= LVS_SORTASCENDING;
	else if (m_cstrSort == _T("����"))
		lStyle |= LVS_SORTDESCENDING;
	else
		ASSERT(m_cstrSort == _T("��"));
	
	//���ö�����ʽ
	if (m_cstrAlignMode == _T("�����"))
		lStyle |= LVS_ALIGNLEFT;
	else
		ASSERT(m_cstrAlignMode == _T("�϶���"));

	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTCTRL);
	
	//�õ��б���ͼ������ʽ
	long lNewStyle = GetWindowLong(pListCtrl->m_hWnd, GWL_STYLE);
	lNewStyle &= ~lMask; 
	lNewStyle = lNewStyle | lStyle;
	
	//���������б���ͼ�ؼ�
	CRect rect;
	GetClientRect(&rect);
	pListCtrl->DestroyWindow();
	//���´����б���ͼ�ؼ�
	pListCtrl->Create(lNewStyle, rect, this, IDC_LISTCTRL);
	//�����б���ͼ�ؼ���ͼ���б�
	pListCtrl->SetImageList(m_pImageList, LVSIL_NORMAL);
	pListCtrl->SetImageList(m_pImageListSmall, LVSIL_SMALL);
	
	//��������б���ͼ����
	FillListCtrl();
}

//�Ի��������¼�
void CListCtrlUseDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	//�ͷ�ͼƬ�б���Դ
    delete m_pImageList;
	m_pImageList = NULL;
	delete m_pImageListSmall;
	m_pImageListSmall = NULL;

}

//�б���ͼ�ؼ�˫���¼�
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
