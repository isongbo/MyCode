// SpeciallyEffectDlg.h : ͷ�ļ�
//

#pragma once

// CSpeciallyEffectDlg �Ի���
class CSpeciallyEffectDlg : public CDialog
{
// ����
public:
	CSpeciallyEffectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SPECIALLYEFFECT_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCmbStyle();
};
