// VODServerView.cpp : implementation of the CVODServerView class
//

#include "stdafx.h"
#include "VODServer.h"

#include "VODServerDoc.h"
#include "VODServerView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODServerView

IMPLEMENT_DYNCREATE(CVODServerView, CFormView)

BEGIN_MESSAGE_MAP(CVODServerView, CFormView)
	//{{AFX_MSG_MAP(CVODServerView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODServerView construction/destruction

CVODServerView::CVODServerView()
	: CFormView(CVODServerView::IDD)
{
	//{{AFX_DATA_INIT(CVODServerView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here


}

CVODServerView::~CVODServerView()
{
}

void CVODServerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVODServerView)
	DDX_Control(pDX, IDC_DATAGRID, m_wndGrid);
	//}}AFX_DATA_MAP
}

BOOL CVODServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CVODServerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//数据绑定
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
   	m_adoRecordSet.SetAdoConnection(&pWnd->m_adoConnection);
	m_adoRecordSet.SetCursorLocation();
	CString strSql=
		"select videoInfo.id as 编号,videoName as 视频名称,videoDesp as 视频描述,videoPath as 视频路径,typeName as 所属类型 from videoInfo,TypeInfo where videoInfo.typeid=TypeInfo.id";
	m_adoRecordSet.Open(strSql, adCmdText);
	BindDataGrid(&m_adoRecordSet);
	



}

/////////////////////////////////////////////////////////////////////////////
// CVODServerView printing

BOOL CVODServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVODServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVODServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVODServerView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CVODServerView diagnostics

#ifdef _DEBUG
void CVODServerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CVODServerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CVODServerDoc* CVODServerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVODServerDoc)));
	return (CVODServerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODServerView message handlers

void CVODServerView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	CRect rcClient;
	GetClientRect(&rcClient);
	CWnd* pWnd=GetDlgItem(IDC_DATAGRID);
	if (pWnd)
		pWnd->MoveWindow(0,0,rcClient.Width(),rcClient.Height());
    
	if (m_wndGrid.GetSafeHwnd())
    {
		m_wndGrid.SetScrollBars(0);
    }
     
}

BEGIN_EVENTSINK_MAP(CVODServerView, CFormView)
    //{{AFX_EVENTSINK_MAP(CVODServerView)
	ON_EVENT(CVODServerView, IDC_DATAGRID, 221 /* SelChange */, OnSelChangeDatagrid, VTS_PI2)
	ON_EVENT(CVODServerView, IDC_DATAGRID, 218 /* RowColChange */, OnRowColChangeDatagrid, VTS_PVARIANT VTS_I2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()
#include "column.h"
#include "columns.h"
void CVODServerView::OnSelChangeDatagrid(short FAR* Cancel) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrame=(CMainFrame*)AfxGetMainWnd();
	_variant_t varRow((long)(m_wndGrid.GetRow()+1));

   	CString strID=m_wndGrid.GetColumns().GetItem(_variant_t((long)0)).CellText(varRow);
   	CString strName=m_wndGrid.GetColumns().GetItem(_variant_t((long)1)).CellText(varRow);
	CString strDesp=m_wndGrid.GetColumns().GetItem(_variant_t((long)2)).CellText(varRow);
	CString strPath=m_wndGrid.GetColumns().GetItem(_variant_t((long)3)).CellText(varRow);
	CString strType=m_wndGrid.GetColumns().GetItem(_variant_t((long)4)).CellText(varRow);

	pMainFrame->m_dlgVideo.m_strVideoID=strID;
	pMainFrame->m_dlgVideo.m_strVideoName=strName;
	pMainFrame->m_dlgVideo.m_strVideoType=strType;
    pMainFrame->m_dlgVideo.m_strVideoPath=strPath;
    pMainFrame->m_dlgVideo.m_strVideoDesp=strDesp;
	pMainFrame->m_dlgVideo.UpdateData(FALSE);
	//设置按钮的文本由插入变为更新
	pMainFrame->m_dlgVideo.m_wndOK.SetWindowText("更新");
}

void CVODServerView::OnRowColChangeDatagrid(VARIANT FAR* LastRow, short LastCol) 
{
	// TODO: Add your control notification handler code here
	
}

void CVODServerView::BindDataGrid(CAdoRecordSet *pSet)
{
	m_wndGrid.SetRefDataSource((LPUNKNOWN)m_adoRecordSet.GetRecordset());
	m_wndGrid.Refresh();
}

BOOL CVODServerView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam==VK_ESCAPE)
		{
			return TRUE;
		}
		if (pMsg->wParam==VK_RETURN)
		{
			return TRUE;
		}
	}
	return CFormView::PreTranslateMessage(pMsg);
}
