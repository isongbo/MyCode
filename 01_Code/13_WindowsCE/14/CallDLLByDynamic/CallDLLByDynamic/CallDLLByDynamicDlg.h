// CallDLLByDynamicDlg.h : ͷ�ļ�
//

#pragma once

//����MyCEDLL.dll��TestDll�������ԭ��
typedef void (*pTestDll)(void);

// CCallDLLByDynamicDlg �Ի���
class CCallDLLByDynamicDlg : public CDialog
{
// ����
public:
	CCallDLLByDynamicDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALLDLLBYDYNAMIC_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCall();
};
