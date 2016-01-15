// SpinUseDlg.h : ͷ�ļ�
//

#pragma once

// CSpinUseDlg �Ի���
class CSpinUseDlg : public CDialog
{
// ����
public:
	CSpinUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SPINUSE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	BYTE m_red;  //��ɫֵ
	BYTE m_green; //��ɫֵ
	BYTE m_blue; //��ɫֵ
public:
	afx_msg void OnEnChangeEdtRed();
	afx_msg void OnEnChangeEdtGreen();
	afx_msg void OnEnChangeEdtBlue();

private:
	//����ɫֵ�ı�ʱ��������ɫֵ
	void RGBColorChange() ;
};
