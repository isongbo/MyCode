// VODClient.h : main header file for the VODCLIENT application
//

#if !defined(AFX_VODCLIENT_H__4FD453E2_6A7E_4A56_B52D_B1F686F33CB1__INCLUDED_)
#define AFX_VODCLIENT_H__4FD453E2_6A7E_4A56_B52D_B1F686F33CB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVODClientApp:
// See VODClient.cpp for the implementation of this class
//

class CVODClientApp : public CWinApp
{
public:
	CVODClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVODClientApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODCLIENT_H__4FD453E2_6A7E_4A56_B52D_B1F686F33CB1__INCLUDED_)
