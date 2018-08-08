// Demarrer Windows.h : main header file for the DEMARRER WINDOWS application
//

#if !defined(AFX_DEMARRERWINDOWS_H__CD42BD84_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DEMARRERWINDOWS_H__CD42BD84_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemarrerWindowsApp:
// See Demarrer Windows.cpp for the implementation of this class
//

class CDemarrerWindowsApp : public CWinApp
{
public:
	CDemarrerWindowsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemarrerWindowsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDemarrerWindowsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMARRERWINDOWS_H__CD42BD84_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_)
