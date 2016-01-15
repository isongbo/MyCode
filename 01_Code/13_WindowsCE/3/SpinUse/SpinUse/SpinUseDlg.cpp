// SpinUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SpinUse.h"
#include "SpinUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSpinUseDlg �Ի���

CSpinUseDlg::CSpinUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinUseDlg::IDD, pParent)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpinUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_RED, m_red);
	DDV_MinMaxByte(pDX, m_red, 0, 255);
	DDX_Text(pDX, IDC_EDT_GREEN, m_green);
	DDV_MinMaxByte(pDX, m_green, 0, 255);
	DDX_Text(pDX, IDC_EDT_BLUE, m_blue);
	DDV_MinMaxByte(pDX, m_blue, 0, 255);
}

BEGIN_MESSAGE_MAP(CSpinUseDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDT_RED, &CSpinUseDlg::OnEnChangeEdtRed)
	ON_EN_CHANGE(IDC_EDT_GREEN, &CSpinUseDlg::OnEnChangeEdtGreen)
	ON_EN_CHANGE(IDC_EDT_BLUE, &CSpinUseDlg::OnEnChangeEdtBlue)
END_MESSAGE_MAP()


// CSpinUseDlg ��Ϣ�������

BOOL CSpinUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

//���ú�ɫֵ΢����ť
	CSpinButtonCtrl *pSpinRed = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_RED);
	ASSERT(pSpinRed!=NULL);
	//���û�鴰��
	pSpinRed->SetBuddy(GetDlgItem(IDC_EDT_RED));
	pSpinRed->SetRange(0,255);
	pSpinRed->SetPos(128);

	//������ɫֵ΢����ť
	CSpinButtonCtrl *pSpinGreen = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_GREEN);
	ASSERT(pSpinGreen!=NULL);
	//���û�鴰��
	pSpinGreen->SetBuddy(GetDlgItem(IDC_EDT_GREEN));
	pSpinGreen->SetRange(0,255);
	pSpinGreen->SetPos(128);

	//������ɫֵ΢����ť
	CSpinButtonCtrl *pSpinBlue = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_BLUE);
	ASSERT(pSpinBlue!=NULL);
	//���û�鴰��
	pSpinBlue->SetBuddy(GetDlgItem(IDC_EDT_BLUE));
	pSpinBlue->SetRange(0,255);
	pSpinBlue->SetPos(128);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSpinUseDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SPINUSE_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SPINUSE_DIALOG));
	}
}
#endif

//����ɫֵ�ı�ʱ��������ɫֵ
void CSpinUseDlg::RGBColorChange() 
{
	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//�õ�RGB��ɫֵ
    clRGB = RGB(m_red,m_green,m_blue);
	CClientDC * pClientDC;
	//�õ���ͼ����
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//��ʾ��ɫ
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;
}


//��ɫֵ�仯�¼�
void CSpinUseDlg::OnEnChangeEdtRed()
{
	RGBColorChange();
}

//��ɫֵ�仯�¼�
void CSpinUseDlg::OnEnChangeEdtGreen()
{
	RGBColorChange();
}

//��ɫֵ�仯�¼�
void CSpinUseDlg::OnEnChangeEdtBlue()
{
	RGBColorChange();
}
