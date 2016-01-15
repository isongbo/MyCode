// SpeciallyEffectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SpeciallyEffect.h"
#include "SpeciallyEffectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSpeciallyEffectDlg 对话框

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


// CSpeciallyEffectDlg 消息处理程序

BOOL CSpeciallyEffectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CComboBox * pCmbStyle = (CComboBox*)GetDlgItem(IDC_CMB_STYLE);

	pCmbStyle->AddString(_T("水平向右扫描"));
    pCmbStyle->AddString(_T("水平向左扫描"));
	pCmbStyle->AddString(_T("水平百叶窗"));
	pCmbStyle->AddString(_T("垂直百叶窗"));



	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//根据特效方式显示
void CSpeciallyEffectDlg::OnCbnSelchangeCmbStyle()
{
	CDC memdc; 
    CBitmap m_bitmap;
	int width;            // 位图的宽度
	int height;           //位图的高度
	CBitmap *pOldBmp = NULL;
	//
	CComboBox * pCmbStyle = (CComboBox*)GetDlgItem(IDC_CMB_STYLE);

    //得到位图
	m_bitmap.LoadBitmap(IDB_BITMAP1);

	//获得绘图环境资源
	CDC *pDC = new CClientDC(this);
	memdc.CreateCompatibleDC(pDC);
	pOldBmp = memdc.SelectObject(&m_bitmap);

	//获取位图大小信息
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	width=bm.bmWidth;
	height=bm.bmHeight;
	
	//pDC->Rectangle(0,0,width,height);

	pDC->FillSolidRect(0,0,width,height,RGB(255,255,255));
	
	int nIndex = pCmbStyle->GetCurSel();
	
	switch(nIndex)
	{
	case 0://水平向左扫描
		{
			for(int i=0;i<width;i++)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 1://水平向右扫描
		{
			
			for(int i=width-1;i>=0;i--)
			{
				pDC->BitBlt(i,0,1,height,&memdc,i,0,SRCCOPY);
				Sleep(1);
			}
			break;
		}
	case 2://水平百叶窗
		{
			//每条20象素宽
			int num=width/20;
			for(int i=0;i<20;i++)
			{
				//分别扫描每条
				for(int j=0;j<num+1;j++)
				{
					pDC->BitBlt(j*20+i,0,1,height,&memdc,j*20+i,0,SRCCOPY);
					Sleep(1);
					
				}
				Sleep(1);
			}
			break;
		}
	case 3://垂直百叶窗
		{
			int num=height/20;
			for(int i=0;i<20;i++)
			{
				//分别扫描每条
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
	//还原GDI对象
	memdc.SelectObject(pOldBmp);
	//删除位图GDI对象
	m_bitmap.DeleteObject();
	//删除内存绘图环境
    memdc.DeleteDC();
    delete pDC;
	pDC = NULL;

}
