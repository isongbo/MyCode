// DrawDemo.h : main header file for the DRAWDEMO application
//

#if !defined(AFX_DRAWDEMO_H__92AB4349_963B_434B_AB1C_B994094C96ED__INCLUDED_)
#define AFX_DRAWDEMO_H__92AB4349_963B_434B_AB1C_B994094C96ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawDemoApp:
// See DrawDemo.cpp for the implementation of this class
//

class CDrawDemoApp : public CWinApp
{
public:
	CDrawDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDEMO_H__92AB4349_963B_434B_AB1C_B994094C96ED__INCLUDED_)
