// CallDLLByDynamicDlg.h : 头文件
//

#pragma once

//定义MyCEDLL.dll中TestDll输出函数原型
typedef void (*pTestDll)(void);

// CCallDLLByDynamicDlg 对话框
class CCallDLLByDynamicDlg : public CDialog
{
// 构造
public:
	CCallDLLByDynamicDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALLDLLBYDYNAMIC_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCall();
};
