#if !defined(AFX_MCD_H__096288CC_994C_4C54_AAA5_D593CE06EE3B__INCLUDED_)
#define AFX_MCD_H__096288CC_994C_4C54_AAA5_D593CE06EE3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Mcd.h : main header file for MCD.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMcdApp : See Mcd.cpp for implementation.

class CMcdApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCD_H__096288CC_994C_4C54_AAA5_D593CE06EE3B__INCLUDED)
