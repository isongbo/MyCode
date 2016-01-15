// VODServer.h : main header file for the VODSERVER application
//

#if !defined(AFX_VODSERVER_H__1E3CC257_7429_478D_B461_B446CD8F296B__INCLUDED_)
#define AFX_VODSERVER_H__1E3CC257_7429_478D_B461_B446CD8F296B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVODServerApp:
// See VODServer.cpp for the implementation of this class
//

class CVODServerApp : public CWinApp
{
public:
	CVODServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODServerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVODServerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODSERVER_H__1E3CC257_7429_478D_B461_B446CD8F296B__INCLUDED_)
