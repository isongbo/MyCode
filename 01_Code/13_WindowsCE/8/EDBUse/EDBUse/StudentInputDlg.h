#pragma once
#include "afxwin.h"


// CStudentInputDlg �Ի���
#include "ImageST.h"
class CStudentInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentInputDlg)

public:
	CStudentInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudentInputDlg();

// �Ի�������
	enum { IDD = IDD_STUDENTINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
protected:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:

	CString m_no;
	CString m_name;
	CTime m_birthday;
	int m_stature;
	CImageST m_Image;
public:
	//����ѧ����Ƭ
	CEBLOB m_blImage;
public:
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
private:
	//���ļ����ݶ�ȡ���ڴ滺������
	BOOL ReadFileToBlob(LPCTSTR strFileName, /*in �ļ���*/
		CEBLOB *pBlob /*out ����Ļ�����*/); 
public:
	afx_msg void OnStnClickedImgPicture();
};
