#pragma once


// CTreeAttrDlg �Ի���

class CTreeAttrDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeAttrDlg)

public:
	CTreeAttrDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeAttrDlg();

// �Ի�������
	enum { IDD = IDD_TREEATTR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bEditLabels;
	BOOL m_bHasButtons;
	BOOL m_bHasLines;
	BOOL m_bLinesAtRoot;
	BOOL m_bShowSelAlways;


};
