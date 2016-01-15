// TreeCtrlUseDlg.h : ͷ�ļ�
//

#pragma once

// CTreeCtrlUseDlg �Ի���
class CTreeCtrlUseDlg : public CDialog
{
// ����
public:
	CTreeCtrlUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TREECTRLUSE_DIALOG };


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
	BOOL	m_bHasButtons; //�Ƿ�ť��ʾ 
	BOOL	m_bHasLines;   //�Ƿ���ʾ������
	BOOL	m_bLinesAtRoot;  //�������Ƿ�Ӹ���ʼ
	BOOL	m_bEditLabels;   //�Ƿ���Ա༭��ǩ
	BOOL	m_bShowSelAlways; //�Ƿ�ʼ����ʾѡ��

	CImageList *m_pImgList;	//���ڴ洢ͼƬ�б�
private:
	//��ʼ������������Ҫ����������
	void InitTree();

public:
	afx_msg void OnDestroy();
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnset();
private:
	//��������ĳ������
	void SetNewStyle(long lStyleMask, BOOL bSetBits);
	//��������ʽ
	void SetTreeCtrlStyle();
};
