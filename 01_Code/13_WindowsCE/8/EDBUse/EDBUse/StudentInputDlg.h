#pragma once
#include "afxwin.h"


// CStudentInputDlg 对话框
#include "ImageST.h"
class CStudentInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentInputDlg)

public:
	CStudentInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudentInputDlg();

// 对话框数据
	enum { IDD = IDD_STUDENTINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
	//定义学生照片
	CEBLOB m_blImage;
public:
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancel();
private:
	//将文件内容读取到内存缓冲区中
	BOOL ReadFileToBlob(LPCTSTR strFileName, /*in 文件名*/
		CEBLOB *pBlob /*out 输出的缓冲区*/); 
public:
	afx_msg void OnStnClickedImgPicture();
};
