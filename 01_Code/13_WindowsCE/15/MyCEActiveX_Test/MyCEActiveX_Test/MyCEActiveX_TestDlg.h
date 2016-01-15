// MyCEActiveX_TestDlg.h : 头文件
//

#pragma once

#include "CDMyCEActiveX.h"

// CMyCEActiveX_TestDlg 对话框
class CMyCEActiveX_TestDlg : public CDialog
{
// 构造
public:
	CMyCEActiveX_TestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYCEACTIVEX_TEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	//MyCEActiveX控件OnMsgChange事件
	afx_msg void OnMsgChangeMyceactivexctrl();	
	//定义OLE COM 事件映射
	DECLARE_EVENTSINK_MAP()
	DECLARE_MESSAGE_MAP()

private:
	//定义MyCEActiveX控件对象
	CDMyCEActiveX m_myCEActiveX;
public:
	afx_msg void OnBnClickedBtnTest();
};
