// Résistors.h : main header file for the RÉSISTORS application
//

#if !defined(AFX_RSISTORS_H__B100C1C4_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
#define AFX_RSISTORS_H__B100C1C4_2453_11D5_9911_A8DCADD2F70E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRsistorsApp:
// See Résistors.cpp for the implementation of this class
//

class CRsistorsApp : public CWinApp
{
public:
	CRsistorsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRsistorsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRsistorsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSISTORS_H__B100C1C4_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
