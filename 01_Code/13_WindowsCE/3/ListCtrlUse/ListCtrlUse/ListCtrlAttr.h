#pragma once


// CListCtrlAttr 对话框

class CListCtrlAttr : public CDialog
{
	DECLARE_DYNAMIC(CListCtrlAttr)

public:
	CListCtrlAttr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CListCtrlAttr();

// 对话框数据
	enum { IDD = IDD_LISTCTRLATTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bSingleSel;
	BOOL m_bEditLabels;
	BOOL m_bNoColumnHeader;
	CString m_cstrViewMode;
	CString m_cstrSort;
	CString m_cstrAlignMode;
};
