// FileExamDlg.h : 头文件
//

#pragma once

#pragma pack(push,1)
//定义学生基本信息结构
typedef struct _CStudentData
{
   TCHAR xsbh[7];  //学生编号
   TCHAR xsxm[21]; //学生姓名
   TCHAR xb[3];    //学生性别
   TCHAR csrq[11]; //出生日期
   TCHAR bjmc[21]; //班级名称
}CStudentData;
#pragma pack(pop)

const LPCTSTR STUDENTFILEPATH = _T("\\My Documents\\student.dat");
// CFileExamDlg 对话框
class CFileExamDlg : public CDialog
{
// 构造
public:
	CFileExamDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FILEEXAM_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString m_xsbh;
	CString m_xsxm;
	CString m_xsxb;
	CString m_csrq;
	CString m_bjmc;

private:
	//定义存储学生数据表的队列
	CList<CStudentData,CStudentData&> m_lstStudent;

	//定义操作标识, 0 - 代表添加; 1 - 代表编辑
	int m_operID ; 
	//存储指针位置
	int m_iCurPos;
private:
	//设置控件有效性
	void SetControlEnable(bool aValue);
    //设置指针移动按钮的有效性
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
