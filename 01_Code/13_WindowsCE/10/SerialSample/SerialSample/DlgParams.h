#pragma once


// CDlgParams �Ի���

class CDlgParams : public CDialog
{
	DECLARE_DYNAMIC(CDlgParams)

public:
	CDlgParams(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgParams();

// �Ի�������
	enum { IDD = IDD_DLGPARAMS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Ի����ʼ�����⺯��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	//
	UINT m_portNo;		//���ں�
	UINT m_baud;		//������
	UINT m_parity;		//��żУ��
	UINT m_databits;	//����λ
	UINT m_stopbits;	//ֹͣλ
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
};
