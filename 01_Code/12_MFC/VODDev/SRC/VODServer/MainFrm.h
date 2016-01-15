// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4A9750FA_3D3F_4036_9F3B_722463869F58__INCLUDED_)
#define AFX_MAINFRM_H__4A9750FA_3D3F_4036_9F3B_722463869F58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgVideo.h"
#include ".\ado\Ado.h"//数据库封装类的头文件
#include "NetServer.h"
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
    CAdoConnection m_adoConnection;
// Operations
public:
    BOOL m_bSvrStart;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitTypeTreeCtrl();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
     
	CCoolBar m_LeftCtrBar; //左面的控制窗口
	CCoolBar m_BottomCtrBar; //最下面的控制窗口
    
	CTreeCtrl m_wndTree;
public:
    CDlgVideo m_dlgVideo;
	CNetServer m_NetServer;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnToolbarNavigate();
	afx_msg void OnUpdateToolbarNavigate(CCmdUI* pCmdUI);
	afx_msg void OnToolbarEdit();
	afx_msg void OnUpdateToolbarEdit(CCmdUI* pCmdUI);
	afx_msg void OnSvrStart();
	afx_msg void OnSvrStop();
	afx_msg void OnUpdateSvrStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSvrStop(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4A9750FA_3D3F_4036_9F3B_722463869F58__INCLUDED_)
