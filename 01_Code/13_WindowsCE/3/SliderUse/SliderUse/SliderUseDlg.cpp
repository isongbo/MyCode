// SliderUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SliderUse.h"
#include "SliderUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSliderUseDlg �Ի���

CSliderUseDlg::CSliderUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSliderUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSliderUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSliderUseDlg ��Ϣ�������

BOOL CSliderUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//���ú�ɫֵ������
	CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
	ASSERT(pSliderRed!=NULL);
	//���û�����ȡֵ��Χ
	pSliderRed->SetRange(0,255);
	pSliderRed->SetPos(128);

	//������ɫֵ������
	CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
	ASSERT(pSliderGreen!=NULL);
	//���û�����ȡֵ��Χ
	pSliderGreen->SetRange(0,255);
	pSliderGreen->SetPos(128);

	//������ɫֵ������
	CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);
	ASSERT(pSliderBlue!=NULL);
	//���û�����ȡֵ��Χ
	pSliderBlue->SetRange(0,255);
	pSliderBlue->SetPos(128);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSliderUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SLIDERUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SLIDERUSE_DIALOG));
	}
}
#endif


void CSliderUseDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int iRed,iGreen,iBlue;
	//�õ���ɫ����ɫ����ɫ�����������¼�
	if ((pScrollBar->GetDlgCtrlID() == IDC_SLIDER_RED) 
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_GREEN)
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_BLUE))
	{
		CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
		CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
		CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);

		iRed = pSliderRed->GetPos();
		iGreen = pSliderGreen->GetPos();
		iBlue = pSliderBlue->GetPos();

	}

	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//�õ�RGB��ɫֵ
    clRGB = RGB(iRed,iGreen,iBlue);
	CClientDC * pClientDC;
	//�õ���ͼ����
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//��ʾ��ɫ
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
