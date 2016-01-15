// CameraDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CameraDemo.h"
#include "CameraDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCameraDemoDlg 对话框

CCameraDemoDlg::CCameraDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCameraDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCameraDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCameraDemoDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_PREVIEW, &CCameraDemoDlg::OnBnClickedBtnPreview)
	ON_BN_CLICKED(IDC_BTN_SNAP, &CCameraDemoDlg::OnBnClickedBtnSnap)
	ON_BN_CLICKED(IDC_BTN_RECORD, &CCameraDemoDlg::OnBnClickedBtnRecord)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCameraDemoDlg 消息处理程序

BOOL CCameraDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


//预览视频
void CCameraDemoDlg::OnBnClickedBtnPreview()
{
	CWnd *pVideoWnd = (CWnd*)GetDlgItem(IDC_WND_VIDEO);

	m_Camera.PreviewCamera(pVideoWnd->m_hWnd,L"\\EricVideo.asf");

}
//抓拍图片
void CCameraDemoDlg::OnBnClickedBtnSnap()
{
	//定义媒体播放文件名
	CString strFileName;
	TCHAR szFilters[]= _T("Image File (*.jpg)|*.jpg||");
	CFileDialog fileDlg (FALSE, _T("Save Image files"), _T("\\My   Documents\\"),
		OFN_OVERWRITEPROMPT , szFilters, this);
	//打开文件选择对话框
	if( fileDlg.DoModal () !=IDOK )
	{
		return;
	}
	//得到要保存的图象文件名
	strFileName = fileDlg.GetPathName();
	//抓拍
	m_Camera.SnapPicture(strFileName);
}

//录像
void CCameraDemoDlg::OnBnClickedBtnRecord()
{
	if (m_Camera.StartRecord())
	{
		//启动定时器，录制5秒视频
		SetTimer(1,5000,NULL);
	}
}


//5秒后停止录像
void CCameraDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	KillTimer(1);
	if (m_Camera.StopRecord())
	{
		AfxMessageBox(L"录像完毕");
	}	
	else
	{
		AfxMessageBox(L"录像失败");
	}
	CDialog::OnTimer(nIDEvent);
}
