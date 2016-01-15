// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "VODClient.h"
#include "resource.h"
#include "MainFrm.h"
#include "VODClientView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, 100, OnDblclkTree)
	ON_NOTIFY(NM_RCLICK, 100, OnRclickTree)
	ON_NOTIFY(TVN_SELCHANGED, 100, OnSelchangedTree)
	ON_NOTIFY(NM_CLICK, 100, OnClickTree)

//	ON_COMMAND(ID_VIDEO_DOWNLOAD, OnVideoDownload)
//	ON_COMMAND(ID_VIDEO_PLAYER, OnVideoPlayer)
	ON_COMMAND(ID_PLAY, OnPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
//全局函数，拆分字符串，返回拆分的字符串数量
int AnalyseStr(CStringArray &strarray , CString str, CString flag)
{
    int nCount ;
    int iStart ;
    int iEnd ;
    CString sTemp ;
    nCount = 0 ;
    iEnd = 0 ;
    iStart = 0 ;
    while ( iEnd >= 0 )
    {
        iEnd = str.Find( flag, iStart ) ;
        if ( iEnd >= 0 )
        {
            sTemp = str.Mid( iStart, (iEnd-iStart ) ) ;
            strarray.Add( sTemp ) ;
            iStart = iEnd + 1 ;
        }
        else if ( iEnd < 0 )
        {
            sTemp = str.Mid( iStart, (str.GetLength() - iStart) ) ;
            strarray.Add( sTemp ) ;
        }
        
    }
    nCount = strarray.GetSize() ;
    return nCount ;
}
/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//控制条的创建和停靠
	if (!m_LeftCtrBar.Create(_T("导航控制条"), this, CSize(230,260),TRUE,123))
	{
		TRACE0("Failed to create mybar\n");
		return -1;
	}
	m_LeftCtrBar.SetBarStyle(m_LeftCtrBar.GetBarStyle() | CBRS_TOOLTIPS
		| CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	m_LeftCtrBar.EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_LeftCtrBar, AFX_IDW_DOCKBAR_LEFT);      //停靠在左边
#ifdef _SCB_REPLACE_MINIFRAME
    m_pFloatingFrameClass = RUNTIME_CLASS(CSCBMiniDockFrameWnd);
#endif //_SCB_REPLACE_MINIFRAME

	//树控件
	if (!m_wndTree.Create(WS_CHILD|WS_VISIBLE|
		TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,
		CRect(0, 0, 0, 0), &m_LeftCtrBar, 100))
	{
		TRACE0("Failed to create instant bar child\n");
		return -1;
	}
	m_wndTree.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
   //
   InitTreeCtrlData();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//去掉标题栏中的文档名
     cs.style&=~FWS_ADDTOTITLE;
	 return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	/*
	if (m_wndTree.GetSafeHwnd())
	{
		m_wndTree.SetBkColor(RGB(134,119,202));

	}
	*/
}



void CMainFrame::InitTreeCtrlData()
{
   HTREEITEM hRoot= m_wndTree.InsertItem("所有类型");
   CString strAllTypes;
   m_clientSock.GetAllVideoTypes(strAllTypes);
  // MessageBox(strAllTypes);
   CStringArray strArray;
   //收到的字符串最后的字符是,去掉最后被拆分的空字符串
   int typeCount=AnalyseStr(strArray,strAllTypes,",")-1;
   HTREEITEM hItem=NULL;
   for (int i=0;i<typeCount;i++)
   {
	   if (i%2==0)
	   {
		   CString strTypeName=strArray.GetAt(i); 
           hItem=m_wndTree.InsertItem(strTypeName,hRoot);
	   }
	   else
	   {
		   DWORD typeID=atoi(strArray.GetAt(i));
		   m_wndTree.SetItemData(hItem,typeID);
	   }
   }
   
   m_wndTree.SetItemHeight(25);
   m_wndTree.Expand(hRoot,TVE_EXPAND);

}
void CMainFrame::OnClickTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	*pResult = 0;
}
void CMainFrame::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	//2选中某一类型，发送类型ID，返回该类型下所有影片名称和ID
	CString strVideos;
    // find the currently selected item
	HTREEITEM hCurSel = m_wndTree.GetNextItem(TVI_ROOT, TVGN_CARET);
	if (hCurSel == NULL)
	{
		AfxMessageBox(_T("请选中相关节点！"));
		return;
	}
	if (m_wndTree.GetParentItem(hCurSel)==NULL)//排除根节点
	{
		return;
	}
	if (m_wndTree.GetParentItem(m_wndTree.GetParentItem(hCurSel))!=NULL)//排除第3层目录
	{
		return;
	}
	if (m_wndTree.ItemHasChildren(hCurSel))//防止重复添加
	{
		return;
	}
     DWORD nTypeID=m_wndTree.GetItemData(hCurSel);
     m_clientSock.GetVideosByTypeID(nTypeID,strVideos);
	 CStringArray strArray;
	 //收到的字符串最后的字符是,去掉最后被拆分的空字符串
	 int typeCount=AnalyseStr(strArray,strVideos,",")-1;
	 HTREEITEM hItem=NULL;
	 for (int i=0;i<typeCount;i++)
	 {
		 if (i%2==0)
		 {
			 CString strVideoName=strArray.GetAt(i); 
			 hItem=m_wndTree.InsertItem(strVideoName,hCurSel);
		 }
		 else
		 {
			 DWORD videoID=atoi(strArray.GetAt(i));
			 m_wndTree.SetItemData(hItem,videoID);
		 }
   }
	 m_wndTree.Expand(hCurSel,TVE_EXPAND );
	*pResult = 0;
}
void CMainFrame::OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	//3 双击某一部电影，发送ID,后台下载该电影并播放
	HTREEITEM hSelItem=m_wndTree.GetSelectedItem( );
	if (hSelItem==NULL)
	{
		return;
	}
	if (m_wndTree.GetParentItem(hSelItem)==NULL)//排除根节点
	{
		return;
	}
	if (m_wndTree.GetParentItem(m_wndTree.GetParentItem(hSelItem))==NULL)//排除第2层目录
	{
		return;
	}

	//第三层节点是电影名称列表
    DWORD videoID=m_wndTree.GetItemData(hSelItem);
	CString strID;
	strID.Format("%d",videoID);
	//MessageBox(strID);
	m_clientSock.GetMediaData(videoID,"c:\\",m_strFullPath);
    MessageBox(m_strFullPath);
    CVODClientView* pView=(CVODClientView*)GetActiveView();
	pView->m_wndPlayer.SetUrl(m_strFullPath);

	/*
	CString strFullPath="C:\\相亲2.wmv";
	CVODClientView* pView=(CVODClientView*)GetActiveView();
	if (pView->m_wndPlayer.GetSafeHwnd())
	{
		pView->m_wndPlayer.SetUrl(strFullPath);
	}
   	*/
  	*pResult = 0;
}

void CMainFrame::OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	/*
	右键菜单
	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_POPUPMENU));
	CPoint point;
	GetCursorPos(&point);
	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);
	CWnd* pWndPopupOwner = this;
	
	while (pWndPopupOwner->GetStyle() & WS_CHILD)
		pWndPopupOwner = pWndPopupOwner->GetParent();
	
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,
			pWndPopupOwner);
	*/
	*pResult = 0;
}
/*
void CMainFrame::OnVideoDownload() 
{
	// TODO: Add your command handler code here
	//显示选择目录对话框
	BROWSEINFO bi={0};
	bi.hwndOwner=GetSafeHwnd();
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	//从ITEMIDLIST结构中获取所选择的目录
	CString strPath;
	SHGetPathFromIDList(idl,strPath.GetBuffer(MAX_PATH));
	strPath.ReleaseBuffer();
	//在路径后加"\"
	if(strPath.GetAt(strPath.GetLength()-1)!='\\')
	{
		strPath+="\\";
	}
	MessageBox(strPath);


}

void CMainFrame::OnVideoPlayer() 
{
	// TODO: Add your command handler code here
	
}
*/
void CMainFrame::OnPlay() 
{
	// TODO: Add your command handler code here

}
