// Login.h : main header file for the LOGIN application
//

#if !defined(AFX_LOGIN_H__637AFDFB_BB30_4C78_950C_655B756DC7E0__INCLUDED_)
#define AFX_LOGIN_H__637AFDFB_BB30_4C78_950C_655B756DC7E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLoginApp:
// See Login.cpp for the implementation of this class
//

class CLoginApp : public CWinApp
{
public:
	CLoginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLoginApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__637AFDFB_BB30_4C78_950C_655B756DC7E0__INCLUDED_)
