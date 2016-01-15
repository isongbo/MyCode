// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__4F4F4FCF_27C4_448A_85B5_03AA049C744E__INCLUDED_)
#define AFX_STDAFX_H__4F4F4FCF_27C4_448A_85B5_03AA049C744E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//#define _SCB_STYLE_FLAT	///平面类型还是VC的3D类型
#define	_SCB_REPLACE_MINIFRAME  ///浮动时候替换原来TOOL WINDOWS的框架
#include "thirdpart\sizecbar.h"
#include "thirdpart\scbarg.h"


//skin
#include "./skin/SkinMagicLib.h"
#pragma comment(lib, "./skin/SkinMagicTrial.lib")


#include ".\ado\Ado.h"//数据库封装类的头文件
//
#include "afxsock.h"//socket头文件
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__4F4F4FCF_27C4_448A_85B5_03AA049C744E__INCLUDED_)
