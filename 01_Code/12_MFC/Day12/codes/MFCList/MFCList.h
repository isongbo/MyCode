// MFCList.h : main header file for the MFCLIST application
//

#if !defined(AFX_MFCLIST_H__B0E31B47_CF2B_4AB3_A553_870C493931F9__INCLUDED_)
#define AFX_MFCLIST_H__B0E31B47_CF2B_4AB3_A553_870C493931F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCListApp:
// See MFCList.cpp for the implementation of this class
//

class CMFCListApp : public CWinApp
{
public:
	CMFCListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLIST_H__B0E31B47_CF2B_4AB3_A553_870C493931F9__INCLUDED_)
