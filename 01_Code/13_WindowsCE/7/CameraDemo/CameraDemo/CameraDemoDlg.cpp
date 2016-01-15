// CameraDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CameraDemo.h"
#include "CameraDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCameraDemoDlg �Ի���

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


// CCameraDemoDlg ��Ϣ�������

BOOL CCameraDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


//Ԥ����Ƶ
void CCameraDemoDlg::OnBnClickedBtnPreview()
{
	CWnd *pVideoWnd = (CWnd*)GetDlgItem(IDC_WND_VIDEO);

	m_Camera.PreviewCamera(pVideoWnd->m_hWnd,L"\\EricVideo.asf");

}
//ץ��ͼƬ
void CCameraDemoDlg::OnBnClickedBtnSnap()
{
	//����ý�岥���ļ���
	CString strFileName;
	TCHAR szFilters[]= _T("Image File (*.jpg)|*.jpg||");
	CFileDialog fileDlg (FALSE, _T("Save Image files"), _T("\\My   Documents\\"),
		OFN_OVERWRITEPROMPT , szFilters, this);
	//���ļ�ѡ��Ի���
	if( fileDlg.DoModal () !=IDOK )
	{
		return;
	}
	//�õ�Ҫ�����ͼ���ļ���
	strFileName = fileDlg.GetPathName();
	//ץ��
	m_Camera.SnapPicture(strFileName);
}

//¼��
void CCameraDemoDlg::OnBnClickedBtnRecord()
{
	if (m_Camera.StartRecord())
	{
		//������ʱ����¼��5����Ƶ
		SetTimer(1,5000,NULL);
	}
}


//5���ֹͣ¼��
void CCameraDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	KillTimer(1);
	if (m_Camera.StopRecord())
	{
		AfxMessageBox(L"¼�����");
	}	
	else
	{
		AfxMessageBox(L"¼��ʧ��");
	}
	CDialog::OnTimer(nIDEvent);
}
