// EricMeidaPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EricMeidaPlayer.h"
#include "EricMeidaPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEricMeidaPlayerDlg �Ի���

CEricMeidaPlayerDlg::CEricMeidaPlayerDlg(CWnd* pParent /*=NULL*/)
: CDialog(CEricMeidaPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEricMeidaPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEricMeidaPlayerDlg, CDialog)

	//}}AFX_MSG_MAP

	ON_BN_CLICKED(IDC_BTN_OPEN, &CEricMeidaPlayerDlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_PLAY, &CEricMeidaPlayerDlg::OnBnClickedBtnPlay)
	ON_BN_CLICKED(IDC_BTN_PAUSE, &CEricMeidaPlayerDlg::OnBnClickedBtnPause)
	ON_BN_CLICKED(IDC_BTN_STOP, &CEricMeidaPlayerDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_FULL, &CEricMeidaPlayerDlg::OnBnClickedBtnFull)
	ON_STN_CLICKED(IDC_WND_VIDEO, &CEricMeidaPlayerDlg::OnStnClickedWndVideo)
	ON_MESSAGE(WM_GRAPHNOTIFY, OnNotifyMedia)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CEricMeidaPlayerDlg ��Ϣ�������

BOOL CEricMeidaPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//������ʱ�������ڸ���ý�岥�Ž���
	SetTimer(1,1000,NULL);	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//����Ƶ�ļ�
void CEricMeidaPlayerDlg::OnBnClickedBtnOpen()
{
	DWORD dwMax = 0;
	//�õ�ý�岥�Ŵ���
	CWnd *pVideoWnd = GetDlgItem(IDC_WND_VIDEO);
	//�õ�����������
	CProgressCtrl *pPrgWnd = (CProgressCtrl*)GetDlgItem(IDC_PRG_VIDEO);
	//����ý�岥���ļ���
	CString strFileName;

	TCHAR szFilters[]= _T("windows media video Files (*.wmv)|*.wmv|video Files (*.avi)|*.avi|All Files (*.*)|*.*||");
	CFileDialog fileDlg (TRUE, _T("Open video files"), _T("*.wmv"),
		OFN_FILEMUSTEXIST , szFilters, this);

	//���ļ�ѡ��Ի���
	if( fileDlg.DoModal () !=IDOK )
	{
		return;
	}

	//�õ�Ҫ���ŵ���Ƶ�ļ���
	strFileName = fileDlg.GetPathName();

	//����Ƶ�ļ�
	if (m_VideoControl.OpenFile(strFileName,pVideoWnd->m_hWnd,m_hWnd))
	{
		//������Ƶ�ߴ�
		m_VideoControl.FitVideoWindow(1.0);
		//�õ���Ƶ�ļ�ʱ�䳤��
		m_VideoControl.GetDuration(dwMax);
		//���ý�������Χ
		pPrgWnd->SetRange(0,dwMax);
		pPrgWnd->SetPos(0);
	}
	else
	{
		AfxMessageBox(L"Can't play the video,because the system can't find some codec program!");
	}
}

//������Ƶ
void CEricMeidaPlayerDlg::OnBnClickedBtnPlay()
{
	m_VideoControl.VideoRun();
}

//��ͣ��Ƶ
void CEricMeidaPlayerDlg::OnBnClickedBtnPause()
{
	m_VideoControl.VideoPause();
}

//ֹͣ��Ƶ
void CEricMeidaPlayerDlg::OnBnClickedBtnStop()
{
	m_VideoControl.VideoStop();
}

//ȫ��
void CEricMeidaPlayerDlg::OnBnClickedBtnFull()
{
	m_VideoControl.FullScreen();
}

//��Ƶ���ڵ����¼�
//���ڴ�ȫ��״̬�ص�����״̬
void CEricMeidaPlayerDlg::OnStnClickedWndVideo()
{
	if (m_VideoControl.GetFullScreenStatus())
	{
		//�л�������״̬
		m_VideoControl.FullScreen();
	}
}


//ý�岥���¼�֪ͨ
LRESULT CEricMeidaPlayerDlg::OnNotifyMedia(WPARAM WParam, LPARAM LParam)
{
	long lEventCode;
	if (m_VideoControl.GetMediaEvent(&lEventCode))
	{
		//�յ����Ž����¼�
		if (lEventCode == EC_COMPLETE)
		{
			if (m_VideoControl.VideoStop())
			{
				//
			}
		}
	}
	return (LRESULT)0;
} 

//WM_TIMER,��ʱ��������
void CEricMeidaPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	//�õ�����������
	CProgressCtrl *pPrgWnd = (CProgressCtrl*)GetDlgItem(IDC_PRG_VIDEO);

	DWORD dwPos = 0;
	//�õ�ý�嵱ǰ���Ž���
	m_VideoControl.GetCurrentPos(dwPos);
	//���ý�����λ��
	pPrgWnd->SetPos(dwPos);

	CDialog::OnTimer(nIDEvent);
}
