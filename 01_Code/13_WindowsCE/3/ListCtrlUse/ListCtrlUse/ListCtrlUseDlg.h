// ListCtrlUseDlg.h : 头文件
//

#pragma once

// CListCtrlUseDlg 对话框
class CListCtrlUseDlg : public CDialog
{
// 构造
public:
	CListCtrlUseDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LISTCTRLUSE_DIALOG };


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
	BOOL	m_bSingleSel;		//是否支持多选
	BOOL	m_bEditLabels;		//是否可以编辑标签
	BOOL	m_bNoColumnHeader;	//是否有表头 //此项只对报表样式有效
	CString	m_cstrViewMode;		//指定报表样式
	CString	m_cstrSort;			//指定排序样式
	CString	m_cstrAlignMode;	//指定对齐样式
private:
	CImageList * m_pImageList ;		// 存储列表视图正常图标列表
	CImageList * m_pImageListSmall;	// 存储列表视图小图标列表
	
private:
	//填充列表视图
	void FillListCtrl(void);
private:
	//设置列表视图
	void SetListCtrl(void);


public:
	afx_msg void OnDestroy();
	afx_msg void OnNMDblclkListctrl(NMHDR *pNMHDR, LRESULT *pResult);
};
