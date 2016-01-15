// TestAdo.h : main header file for the TESTADO application
//

#if !defined(AFX_TESTADO_H__1D82604A_3584_40E9_997B_6CA88A97DC1C__INCLUDED_)
#define AFX_TESTADO_H__1D82604A_3584_40E9_997B_6CA88A97DC1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestAdoApp:
// See TestAdo.cpp for the implementation of this class
//

class CTestAdoApp : public CWinApp
{
public:
	CTestAdoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestAdoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestAdoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTADO_H__1D82604A_3584_40E9_997B_6CA88A97DC1C__INCLUDED_)
