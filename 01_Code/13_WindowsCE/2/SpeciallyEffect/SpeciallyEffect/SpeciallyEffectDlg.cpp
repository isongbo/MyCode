// SpeciallyEffectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SpeciallyEffect.h"
#include "SpeciallyEffectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSpeciallyEffectDlg �Ի���

CSpeciallyEffectDlg::CSpeciallyEffectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpeciallyEffectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpeciallyEffectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSpeciallyEffectDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_CMB_STYLE, &CSpeciallyEffectDlg::OnCbnSelchangeCmbStyle)
END_MESSAGE_MAP()


// CSpeciallyEffectDlg ��Ϣ�������

BOOL CSpeciallyEffectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CComboBox * pCmbStyle = (CComboBox*)GetDlgItem(IDC_CMB_STYLE);

	pCmbStyle->AddString(_T("ˮƽ����ɨ��"));
    pCmbStyle->AddString(_T("ˮƽ����ɨ��"));
	pCmbStyle->AddString(_T("ˮƽ��Ҷ��"));
	pCmbStyle->AddString(_T("��ֱ��Ҷ��"));



	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//������Ч��ʽ��ʾ
void CSpeciallyEffectDlg::OnCbnSelchangeCmbStyle()
{
	CDC memdc; 
    CBitmap m_bitmap;
	int width;            // λͼ�Ŀ��
	int height;           //λͼ�ĸ߶�
	CBitmap *pOldBmp = NULL;
	//
	CComboBox * pCmbStyle = (CComboBox*)GetDlgItem(IDC_CMB_STYLE);

    //�õ�λͼ
	m_bitmap.LoadBitmap(IDB_BITMAP1);

	//��û�ͼ������Դ
	CDC *pDC = new CClientDC(this);
	memdc.CreateCompatibleDC(pDC);
	pOldBmp = memdc.SelectObject(&m_bitmap);

	//��ȡλͼ��С��Ϣ
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	width=bm.bmWidth;
	height=bm.bmHeight;
	
	//pDC->Rectangle(0,0,width,height);

	pDC->FillSolidRect(0,0,width,height,RGB(255,255,255));
	
	int nIndex = pCmbStyle->GetCurSel();
	
	switch(nIndex)
	{
	case 0://ˮƽ����ɨ��
		{
			for(int i=0;i<width;i++)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 1://ˮƽ����ɨ��
		{
			
			for(int i=width-1;i>=0;i--)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 2://ˮƽ��Ҷ��
		{
			//ÿ��20���ؿ�
			int num=width/20;
			for(int i=0;i<20;i++)
			{
				//�ֱ�ɨ��ÿ��
				for(int j=0;j<num+1;j++)
				{
					pDC->BitBlt(j*20+i,0,1,height,&memdc,j*20+i,0,SRCCOPY);
					Sleep(1);
					
				}
				Sleep(1);
			}
			break;
		}
	case 3://��ֱ��Ҷ��
		{
			int num=height/20;
			for(int i=0;i<20;i++)
			{
				//�ֱ�ɨ��ÿ��
				for(int j=0;j<num+1;j++)
				{
					pDC->BitBlt(0,j*20+i,width,1,&memdc,0,j*20+i,SRCCOPY);
					Sleep(1);
				}
				Sleep(1);
			}
			break;
		}
	default:
		break;
	}
	//��ԭGDI����
	memdc.SelectObject(pOldBmp);
	//ɾ��λͼGDI����
	m_bitmap.DeleteObject();
	//ɾ���ڴ��ͼ����
    memdc.DeleteDC();
    delete pDC;
	pDC = NULL;

}
