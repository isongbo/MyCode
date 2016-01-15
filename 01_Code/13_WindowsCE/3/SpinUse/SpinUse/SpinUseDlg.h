// SpinUseDlg.h : 头文件
//

#pragma once

// CSpinUseDlg 对话框
class CSpinUseDlg : public CDialog
{
// 构造
public:
	CSpinUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SPINUSE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	BYTE m_red;  //红色值
	BYTE m_green; //绿色值
	BYTE m_blue; //蓝色值
public:
	afx_msg void OnEnChangeEdtRed();
	afx_msg void OnEnChangeEdtGreen();
	afx_msg void OnEnChangeEdtBlue();

private:
	//当颜色值改变时，重显颜色值
	void RGBColorChange() ;
};
