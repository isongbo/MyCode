// FileExamDlg.h : ͷ�ļ�
//

#pragma once

#pragma pack(push,1)
//����ѧ��������Ϣ�ṹ
typedef struct _CStudentData
{
   TCHAR xsbh[7];  //ѧ�����
   TCHAR xsxm[21]; //ѧ������
   TCHAR xb[3];    //ѧ���Ա�
   TCHAR csrq[11]; //��������
   TCHAR bjmc[21]; //�༶����
}CStudentData;
#pragma pack(pop)

const LPCTSTR STUDENTFILEPATH = _T("\\My Documents\\student.dat");
// CFileExamDlg �Ի���
class CFileExamDlg : public CDialog
{
// ����
public:
	CFileExamDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FILEEXAM_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString m_xsbh;
	CString m_xsxm;
	CString m_xsxb;
	CString m_csrq;
	CString m_bjmc;

private:
	//����洢ѧ�����ݱ�Ķ���
	CList<CStudentData,CStudentData&> m_lstStudent;

	//���������ʶ, 0 - �������; 1 - ����༭
	int m_operID ; 
	//�洢ָ��λ��
	int m_iCurPos;
private:
	//���ÿؼ���Ч��
	void SetControlEnable(bool aValue);
    //����ָ���ƶ���ť����Ч��
	void SetNavigatorButton(int aValue);

public:
	afx_msg void OnBnClickedBtnfirst();
	afx_msg void OnBnClickedBtnprior();
	afx_msg void OnBnClickedBtnnext();
	afx_msg void OnBnClickedBtnlast();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtnedit();
	afx_msg void OnBnClickedBtncancel();
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnBnClickedBtndelete();
};
