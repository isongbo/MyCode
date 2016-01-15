// ASynDllTestDlg.h : ͷ�ļ�
//

#pragma once

//����ASynDll�еĺ�������
typedef long (*TQueryData)(void);
typedef long (*TSetCallbackProcAddr)(long);


// CASynDllTestDlg �Ի���
class CASynDllTestDlg : public CDialog
{
// ����
public:
	CASynDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ASYNDLLTEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	//�洢Dll���
    HINSTANCE	m_hModule;
	//����Dll�е����뺯��
	TQueryData m_pQueryData;
    TSetCallbackProcAddr m_pSetCallbackProcAddr;

public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnCall();
};
