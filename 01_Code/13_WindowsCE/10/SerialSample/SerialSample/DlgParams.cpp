// DlgParams.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SerialSample.h"
#include "DlgParams.h"


// CDlgParams �Ի���

IMPLEMENT_DYNAMIC(CDlgParams, CDialog)

CDlgParams::CDlgParams(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgParams::IDD, pParent)
{

}

CDlgParams::~CDlgParams()
{
}

void CDlgParams::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgParams, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CDlgParams::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CDlgParams::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CDlgParams ��Ϣ�������
BOOL CDlgParams::OnInitDialog()
{
	CDialog::OnInitDialog();
	//
	//��ʼ�����ڲ��������������б�
	CString strItem = L"";
	CComboBox *pCmbComNo = (CComboBox*)GetDlgItem(IDC_CMB_COM_NO);
	CComboBox *pCmbComBaud = (CComboBox*)GetDlgItem(IDC_CMB_COM_BAUD);
	CComboBox *pCmbComParity = (CComboBox*)GetDlgItem(IDC_CMB_COM_PARITY);
	CComboBox *pCmbComDatabits = (CComboBox*)GetDlgItem(IDC_CMB_COM_DATABITS);
	CComboBox *pCmbComStopbits = (CComboBox*)GetDlgItem(IDC_CMB_COM_STOPBITS);

	//��ʼ������
	//���ں�
	pCmbComNo->ResetContent();
	for (int i=0; i < 20; i++)
	{
		strItem.Format(L"%d",i+1);
		pCmbComNo->AddString(strItem);
	}
	pCmbComNo->SetCurSel(0);// com1:

	//������
	pCmbComBaud->ResetContent();
	pCmbComBaud->AddString(L"300");
	pCmbComBaud->AddString(L"600");
	pCmbComBaud->AddString(L"1200");
	pCmbComBaud->AddString(L"2400");
	pCmbComBaud->AddString(L"4800");
	pCmbComBaud->AddString(L"9600");
	pCmbComBaud->AddString(L"19200");
	pCmbComBaud->AddString(L"38400");
	pCmbComBaud->AddString(L"43000");
	pCmbComBaud->AddString(L"56000");
	pCmbComBaud->AddString(L"57600");
	pCmbComBaud->AddString(L"115200");
	pCmbComBaud->SetCurSel(5) ; //9600

	//��żУ��
	pCmbComParity->ResetContent();
	pCmbComParity->AddString(L"None");
	pCmbComParity->AddString(L"Odd");
	pCmbComParity->AddString(L"Even");
	pCmbComParity->SetCurSel(0); // None

	//����λ
	pCmbComDatabits->ResetContent();
	pCmbComDatabits->AddString(L"8");
	pCmbComDatabits->AddString(L"7");
	pCmbComDatabits->AddString(L"6");
	pCmbComDatabits->SetCurSel(0); //8

	//ֹͣλ
	pCmbComStopbits->ResetContent();
	pCmbComStopbits->AddString(L"1");
	pCmbComStopbits->AddString(L"1.5");
	pCmbComStopbits->AddString(L"2");
	pCmbComStopbits->SetCurSel(0); //1

	return TRUE;
}

//������ť�¼�
void CDlgParams::OnBnClickedBtnOk()
{
	CString strTmp;
	CComboBox *pCmbComNo = (CComboBox*)GetDlgItem(IDC_CMB_COM_NO);
	CComboBox *pCmbComBaud = (CComboBox*)GetDlgItem(IDC_CMB_COM_BAUD);
	CComboBox *pCmbComParity = (CComboBox*)GetDlgItem(IDC_CMB_COM_PARITY);
	CComboBox *pCmbComDatabits = (CComboBox*)GetDlgItem(IDC_CMB_COM_DATABITS);
	CComboBox *pCmbComStopbits = (CComboBox*)GetDlgItem(IDC_CMB_COM_STOPBITS);

	pCmbComBaud->GetWindowTextW(strTmp);

	m_portNo = pCmbComNo->GetCurSel() + 1;		//���ں�
	m_baud = 	_wtoi(strTmp);					//������
	m_parity = pCmbComParity->GetCurSel();		//��żУ��
	pCmbComDatabits->GetWindowTextW(strTmp);
	m_databits = _wtoi(strTmp);					//����λ
	m_stopbits = pCmbComStopbits->GetCurSel();	//ֹͣλ
	
	//�رնԻ���
	OnOK();
}

//ȡ����ť
void CDlgParams::OnBnClickedBtnCancel()
{
	OnCancel();
}
