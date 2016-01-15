// ConnectionClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConnectionClient.h"
#include "ConnectionClientDlg.h"
#include "sink.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CConnectionClientDlg �Ի���

CConnectionClientDlg::CConnectionClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectionClientDlg::IDD, pParent)
	, m_number1(0)
	, m_number2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConnectionClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_NUMBER1, m_number1);
	DDX_Text(pDX, IDC_EDT_NUMBER2, m_number2);
}

BEGIN_MESSAGE_MAP(CConnectionClientDlg, CDialog)

	ON_BN_CLICKED(IDC_BTN_EXEC, &CConnectionClientDlg::OnBnClickedBtnExec)
END_MESSAGE_MAP()


// CConnectionClientDlg ��Ϣ�������

BOOL CConnectionClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

//ִ�а�ť�����¼�������IAdd��Add����
void CConnectionClientDlg::OnBnClickedBtnExec()
{
	HRESULT  hr;
	IUnknown *pSinkUnk;
	CSink *pSink = NULL;
	CComPtr<IAdd> pAdd;
	//�������ӵ�����ָ��
	IConnectionPointContainer   * pCPC;
	//�������ӵ�ָ��
    IConnectionPoint          * pCP;   
    DWORD				        dwAdvise; 

	UpdateData(TRUE);
	//��ʼ��COM��,�����ʵ����
	hr = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	//�õ�IAdd COM�ӿ�
	hr =pAdd.CoCreateInstance(CLSID_Add);
	ASSERT(hr == S_OK);

    //�ж�IAdd�ӿ��Ƿ������ӵ��¼������õ����ӵ���������
    hr = pAdd->QueryInterface(IID_IConnectionPointContainer,(void **)&pCPC);
    ASSERT(SUCCEEDED(hr));
	//�õ����ӵ����
    hr = pCPC->FindConnectionPoint(DIID__IAddEvents,&pCP);
	ASSERT(SUCCEEDED(hr));
	//��CSink�ഴ��һ�����ӵ�֪ͨ����
    pSink = new CSink();
    ASSERT(pSink !=NULL);
	//�õ�CSink��Ľӿ�ָ��
	hr = pSink->QueryInterface (IID_IUnknown,(void **)&pSinkUnk);
	//ͬ���ӵ����������
	hr = pCP->Advise(pSinkUnk,&dwAdvise); 
    //ִ��IAdd�ӿڵ�Add����
    pAdd->Add(m_number1 ,m_number2);

	////�Ͽ������ӵ���������
	pCP->Unadvise(dwAdvise); 									
	pCP->Release();	
	//�ͷ����ӵ���������
	pCPC->Release();
	//�ͷ�COM��
	CoUninitialize();
}
