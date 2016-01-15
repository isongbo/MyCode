// TreeCtrlUseDlg.h : 头文件
//

#pragma once

// CTreeCtrlUseDlg 对话框
class CTreeCtrlUseDlg : public CDialog
{
// 构造
public:
	CTreeCtrlUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TREECTRLUSE_DIALOG };


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
private:
	BOOL	m_bHasButtons; //是否按钮显示 
	BOOL	m_bHasLines;   //是否显示连接线
	BOOL	m_bLinesAtRoot;  //连接线是否从根开始
	BOOL	m_bEditLabels;   //是否可以编辑标签
	BOOL	m_bShowSelAlways; //是否始终显示选择

	CImageList *m_pImgList;	//用于存储图片列表
private:
	//初始化树，这里主要用来加载树
	void InitTree();

public:
	afx_msg void OnDestroy();
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnset();
private:
	//设置树的某个属性
	void SetNewStyle(long lStyleMask, BOOL bSetBits);
	//设置树样式
	void SetTreeCtrlStyle();
};
