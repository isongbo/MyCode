// Control2.h : main header file for the CONTROL2 application
//

#if !defined(AFX_CONTROL2_H__2C887503_321F_448F_AA47_53F50246064A__INCLUDED_)
#define AFX_CONTROL2_H__2C887503_321F_448F_AA47_53F50246064A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CControl2App:
// See Control2.cpp for the implementation of this class
//

class CControl2App : public CWinApp
{
public:
	CControl2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CControl2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL2_H__2C887503_321F_448F_AA47_53F50246064A__INCLUDED_)
