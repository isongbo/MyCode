// ListCtrlUseDlg.h : ͷ�ļ�
//

#pragma once

// CListCtrlUseDlg �Ի���
class CListCtrlUseDlg : public CDialog
{
// ����
public:
	CListCtrlUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LISTCTRLUSE_DIALOG };


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
	BOOL	m_bSingleSel;		//�Ƿ�֧�ֶ�ѡ
	BOOL	m_bEditLabels;		//�Ƿ���Ա༭��ǩ
	BOOL	m_bNoColumnHeader;	//�Ƿ��б�ͷ //����ֻ�Ա�����ʽ��Ч
	CString	m_cstrViewMode;		//ָ��������ʽ
	CString	m_cstrSort;			//ָ��������ʽ
	CString	m_cstrAlignMode;	//ָ��������ʽ
private:
	CImageList * m_pImageList ;		// �洢�б���ͼ����ͼ���б�
	CImageList * m_pImageListSmall;	// �洢�б���ͼСͼ���б�
	
private:
	//����б���ͼ
	void FillListCtrl(void);
private:
	//�����б���ͼ
	void SetListCtrl(void);


public:
	afx_msg void OnDestroy();
	afx_msg void OnNMDblclkListctrl(NMHDR *pNMHDR, LRESULT *pResult);
};
