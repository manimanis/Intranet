// Apache Starter.h : main header file for the APACHE STARTER application
//

#if !defined(AFX_APACHESTARTER_H__A2D8DBE6_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_APACHESTARTER_H__A2D8DBE6_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#define MYWM_NOTIFYICON (WM_APP+100) 

/////////////////////////////////////////////////////////////////////////////
// CApacheStarterApp:
// See Apache Starter.cpp for the implementation of this class
//

class CApacheStarterApp : public CWinApp
{
public:
	CApacheStarterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApacheStarterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CApacheStarterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APACHESTARTER_H__A2D8DBE6_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_)