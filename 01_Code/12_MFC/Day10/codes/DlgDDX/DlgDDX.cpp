// DlgDDX.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

// дһ������ģʽ�Ի����Ӧ�ó���
// Dlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
// 2 �Ի�����
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){};
    virtual BOOL OnInitDialog( );
	virtual void DoDataExchange( CDataExchange* pDX );
    virtual void OnOK();
public:
	CButton m_wndOK;//�ؼ����͵ĳ�Ա����
	CString m_strEdit;//ֵ���͵ı���
};
void CMyDlg::OnOK()
{
	//��ʾ�û����ı����е�����
    UpdateData(TRUE);
	MessageBox(m_strEdit);

	CDialog::OnOK();
}
void CMyDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
	//�ؼ����͵İ󶨣�
	DDX_Control(pDX,IDOK,m_wndOK);
	DDX_Text(pDX,IDC_EDIT1,m_strEdit);
}
BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//��ɿؼ��ĳ�ʼ��
    CWnd* pWnd=GetDlgItem(IDCANCEL);
	pWnd->EnableWindow(FALSE);
	//�޸�OK��ť���ı���λ�úʹ�С 
    m_wndOK.SetWindowText("ȷ��");
	m_wndOK.MoveWindow(0,0,100,100);

	m_strEdit="Hello World";
    UpdateData(FALSE);
    return TRUE;
}
// 1 Ӧ�ó�����
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;//ȫ�ֵ�Ӧ�ó������
BOOL CMyWinApp::InitInstance()
{
	//ģʽ�Ի���
	CMyDlg dlg;
	m_pMainWnd=&dlg;
    dlg.DoModal();
	return TRUE;
}







