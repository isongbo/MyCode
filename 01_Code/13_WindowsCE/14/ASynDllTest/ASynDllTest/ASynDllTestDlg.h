// ASynDllTestDlg.h : 头文件
//

#pragma once

//定义ASynDll中的函数类型
typedef long (*TQueryData)(void);
typedef long (*TSetCallbackProcAddr)(long);


// CASynDllTestDlg 对话框
class CASynDllTestDlg : public CDialog
{
// 构造
public:
	CASynDllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ASYNDLLTEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	//存储Dll句柄
    HINSTANCE	m_hModule;
	//定义Dll中的输入函数
	TQueryData m_pQueryData;
    TSetCallbackProcAddr m_pSetCallbackProcAddr;

public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnCall();
};
