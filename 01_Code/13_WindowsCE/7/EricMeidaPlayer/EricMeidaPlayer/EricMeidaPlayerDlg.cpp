// EricMeidaPlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EricMeidaPlayer.h"
#include "EricMeidaPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEricMeidaPlayerDlg 对话框

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


// CEricMeidaPlayerDlg 消息处理程序

BOOL CEricMeidaPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//启动定时器，用于更新媒体播放进度
	SetTimer(1,1000,NULL);	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//打开视频文件
void CEricMeidaPlayerDlg::OnBnClickedBtnOpen()
{
	DWORD dwMax = 0;
	//得到媒体播放窗口
	CWnd *pVideoWnd = GetDlgItem(IDC_WND_VIDEO);
	//得到进度条窗口
	CProgressCtrl *pPrgWnd = (CProgressCtrl*)GetDlgItem(IDC_PRG_VIDEO);
	//定义媒体播放文件名
	CString strFileName;

	TCHAR szFilters[]= _T("windows media video Files (*.wmv)|*.wmv|video Files (*.avi)|*.avi|All Files (*.*)|*.*||");
	CFileDialog fileDlg (TRUE, _T("Open video files"), _T("*.wmv"),
		OFN_FILEMUSTEXIST , szFilters, this);

	//打开文件选择对话框
	if( fileDlg.DoModal () !=IDOK )
	{
		return;
	}

	//得到要播放的视频文件名
	strFileName = fileDlg.GetPathName();

	//打开视频文件
	if (m_VideoControl.OpenFile(strFileName,pVideoWnd->m_hWnd,m_hWnd))
	{
		//设置视频尺寸
		m_VideoControl.FitVideoWindow(1.0);
		//得到视频文件时间长度
		m_VideoControl.GetDuration(dwMax);
		//设置进度条范围
		pPrgWnd->SetRange(0,dwMax);
		pPrgWnd->SetPos(0);
	}
	else
	{
		AfxMessageBox(L"Can't play the video,because the system can't find some codec program!");
	}
}

//播放视频
void CEricMeidaPlayerDlg::OnBnClickedBtnPlay()
{
	m_VideoControl.VideoRun();
}

//暂停视频
void CEricMeidaPlayerDlg::OnBnClickedBtnPause()
{
	m_VideoControl.VideoPause();
}

//停止视频
void CEricMeidaPlayerDlg::OnBnClickedBtnStop()
{
	m_VideoControl.VideoStop();
}

//全屏
void CEricMeidaPlayerDlg::OnBnClickedBtnFull()
{
	m_VideoControl.FullScreen();
}

//视频窗口单击事件
//用于从全屏状态回到正常状态
void CEricMeidaPlayerDlg::OnStnClickedWndVideo()
{
	if (m_VideoControl.GetFullScreenStatus())
	{
		//切换到正常状态
		m_VideoControl.FullScreen();
	}
}


//媒体播放事件通知
LRESULT CEricMeidaPlayerDlg::OnNotifyMedia(WPARAM WParam, LPARAM LParam)
{
	long lEventCode;
	if (m_VideoControl.GetMediaEvent(&lEventCode))
	{
		//收到播放结束事件
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

//WM_TIMER,定时器处理函数
void CEricMeidaPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	//得到进度条窗口
	CProgressCtrl *pPrgWnd = (CProgressCtrl*)GetDlgItem(IDC_PRG_VIDEO);

	DWORD dwPos = 0;
	//得到媒体当前播放进度
	m_VideoControl.GetCurrentPos(dwPos);
	//设置进度条位置
	pPrgWnd->SetPos(dwPos);

	CDialog::OnTimer(nIDEvent);
}
