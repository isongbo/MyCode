#if !defined(AFX_SETUPSHEET_H__5344E5F4_D520_475E_ADC7_982915D3E0E0__INCLUDED_)
#define AFX_SETUPSHEET_H__5344E5F4_D520_475E_ADC7_982915D3E0E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetupSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetupSheet
#include "Page1.h"
#include "Page2.h"
class CSetupSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetupSheet)

// Construction
public:
	CSetupSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSetupSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
   CPage1 m_page1;
	 CPage2 m_page2;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetupSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetupSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSetupSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETUPSHEET_H__5344E5F4_D520_475E_ADC7_982915D3E0E0__INCLUDED_)
