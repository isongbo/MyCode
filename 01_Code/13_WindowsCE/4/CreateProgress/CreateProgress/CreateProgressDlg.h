// CreateProgressDlg.h : ͷ�ļ�
//

#pragma once

// CCreateProgressDlg �Ի���
class CCreateProgressDlg : public CDialog
{
// ����
public:
	CCreateProgressDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CREATEPROGRESS_DIALOG };


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
private:
	//�����ⲿ��ִ�г���
	bool WinExec(LPCTSTR FILENAME);
public:
	afx_msg void OnBnClickedBtnexec();
};
