// Discover Password.h : main header file for the DISCOVER PASSWORD application
//

#if !defined(AFX_DISCOVERPASSWORD_H__5ED05A04_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DISCOVERPASSWORD_H__5ED05A04_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiscoverPasswordApp:
// See Discover Password.cpp for the implementation of this class
//

class CDiscoverPasswordApp : public CWinApp
{
public:
	CDiscoverPasswordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiscoverPasswordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiscoverPasswordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISCOVERPASSWORD_H__5ED05A04_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_)
