// CEComClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CEComClient.h"
#include "CEComClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCEComClientDlg �Ի���

CCEComClientDlg::CCEComClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCEComClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCEComClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCEComClientDlg, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL, &CCEComClientDlg::OnBnClickedBtnCall)
END_MESSAGE_MAP()


// CCEComClientDlg ��Ϣ�������

BOOL CCEComClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//����COM  ����
void CCEComClientDlg::OnBnClickedBtnCall()
{
	HRESULT hr; 
	CLSID clsid;
	ISimple *pSimple = NULL;
	//��ʼ��COM��,�����ʵ����
	hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//�õ�CLSID
	hr = CLSIDFromProgID(OLESTR("CEComServer.Simple.1"),&clsid); 
	if(FAILED(hr)) 
	{
		AfxMessageBox(L"δ�ҵ�ID");  
		goto error;
	}
	//�õ�ISimple COM�ӿ�
	CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,__uuidof(ISimple),(void**)&pSimple);  
	if(pSimple == NULL)    
	{
		AfxMessageBox(L"�ӿ�ָ��ʧ��"); 
		goto error ;
	}

	//����ISimple����
	 pSimple->ShowSvrMsg();	

error:
	 //�ͷ�ISimple�ӿ�
	 if (pSimple != NULL)
	 {
		pSimple->Release();
		pSimple = NULL;
	 }

	 //�ͷ�COM�����
	 CoUninitialize();
}
