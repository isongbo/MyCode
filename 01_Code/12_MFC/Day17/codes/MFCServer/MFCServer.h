// MFCServer.h : main header file for the MFCSERVER application
//

#if !defined(AFX_MFCSERVER_H__476D4198_105B_4D68_B384_522B2E1364C9__INCLUDED_)
#define AFX_MFCSERVER_H__476D4198_105B_4D68_B384_522B2E1364C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCServerApp:
// See MFCServer.cpp for the implementation of this class
//

class CMFCServerApp : public CWinApp
{
public:
	CMFCServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSERVER_H__476D4198_105B_4D68_B384_522B2E1364C9__INCLUDED_)
