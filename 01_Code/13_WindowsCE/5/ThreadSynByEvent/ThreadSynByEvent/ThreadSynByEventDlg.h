// ThreadSynByEventDlg.h : ͷ�ļ�
//

#pragma once

// CThreadSynByEventDlg �Ի���
class CThreadSynByEventDlg : public CDialog
{
// ����
public:
	CThreadSynByEventDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_THREADSYNBYEVENT_DIALOG };


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
   //�̺߳���
   static DWORD  ThreadProc(PVOID pArg);
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnexec();
};