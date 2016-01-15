// ScrollBmpUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScrollBmpUse.h"
#include "ScrollBmpUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CScrollBmpUseDlg �Ի���

CScrollBmpUseDlg::CScrollBmpUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollBmpUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBmpUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBMP, m_scrollBmp);
}

BEGIN_MESSAGE_MAP(CScrollBmpUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CScrollBmpUseDlg ��Ϣ�������

BOOL CScrollBmpUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ʼ������λͼ�ؼ�
	m_scrollBmp.InitBmpCtrl();
	//�����ļ���������ͼ��
	m_scrollBmp.LoadBmp(_T("\\My Documents\\abc.bmp"));


	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CScrollBmpUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SCROLLBMPUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SCROLLBMPUSE_DIALOG));
	}
}
#endif

