// LedCtrlUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedCtrlUse.h"
#include "LedCtrlUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLedCtrlUseDlg �Ի���

CLedCtrlUseDlg::CLedCtrlUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLedCtrlUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLedCtrlUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LED, m_led);
}

BEGIN_MESSAGE_MAP(CLedCtrlUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLedCtrlUseDlg ��Ϣ�������

BOOL CLedCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//���ñ���ɫ
	m_led.SetColorBackGround(RGB(255,0,0));
	//����ǰ��ɫ
	m_led.SetColorForeGround(RGB(0,255,255));
    //���ö�ʱ��
	SetTimer(100,1000,NULL);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CLedCtrlUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_LEDCTRLUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_LEDCTRLUSE_DIALOG));
	}
}
#endif

//��ʱ����Ϣ�¼�
void CLedCtrlUseDlg::OnTimer(UINT nIDEvent) 
{
	//����LED��ʾ����
    m_led.Display(Random());  	
	CDialog::OnTimer(nIDEvent);
}
