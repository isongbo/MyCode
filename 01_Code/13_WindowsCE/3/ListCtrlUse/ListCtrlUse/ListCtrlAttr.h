#pragma once


// CListCtrlAttr �Ի���

class CListCtrlAttr : public CDialog
{
	DECLARE_DYNAMIC(CListCtrlAttr)

public:
	CListCtrlAttr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CListCtrlAttr();

// �Ի�������
	enum { IDD = IDD_LISTCTRLATTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bSingleSel;
	BOOL m_bEditLabels;
	BOOL m_bNoColumnHeader;
	CString m_cstrViewMode;
	CString m_cstrSort;
	CString m_cstrAlignMode;
};
