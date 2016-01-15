#pragma once


// CTreeAttrDlg 对话框

class CTreeAttrDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeAttrDlg)

public:
	CTreeAttrDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTreeAttrDlg();

// 对话框数据
	enum { IDD = IDD_TREEATTR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bEditLabels;
	BOOL m_bHasButtons;
	BOOL m_bHasLines;
	BOOL m_bLinesAtRoot;
	BOOL m_bShowSelAlways;


};
