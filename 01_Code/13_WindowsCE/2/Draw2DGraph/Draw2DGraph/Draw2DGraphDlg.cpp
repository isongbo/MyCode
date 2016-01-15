// Draw2DGraphDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw2DGraph.h"
#include "Draw2DGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDraw2DGraphDlg �Ի���

CDraw2DGraphDlg::CDraw2DGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDraw2DGraphDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDraw2DGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDraw2DGraphDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDraw2DGraphDlg ��Ϣ�������

BOOL CDraw2DGraphDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CRect rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 240;
	rect.bottom = 160;
	//�������߿ؼ�ʵ��
	m_2DGraph.Create(_T(""),_T(""),WS_VISIBLE | WS_CHILD, rect, this,0,NULL) ; 
	m_pointCount = 0;
	//������ӵ��ʱ��
	SetTimer(1,1000,NULL);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CDraw2DGraphDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_DRAW2DGRAPH_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_DRAW2DGRAPH_DIALOG));
	}
}
#endif


//��ʱ����Ϣ������
void CDraw2DGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int nRandomY;

	//����һ��1��10�������
	nRandomY = rand() % 10;

	//������ߵ�������10���㣬��ɾ����1���㡣
	if (m_pointCount > 10 )
	{
		m_2DGraph.DeleteFirstPoint();
		m_pointCount--;
	}

	//��������ӵ�
	m_2DGraph.AppendPoint(nRandomY);	
	
	TRACE(L" y = %d \n",nRandomY);
	m_pointCount++;
	
	CDialog::OnTimer(nIDEvent);

}
