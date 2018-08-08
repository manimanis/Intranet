// Démonstration Tri.h : main header file for the DÉMONSTRATION TRI application
//

#if !defined(AFX_DMONSTRATIONTRI_H__89F281A4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DMONSTRATIONTRI_H__89F281A4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriApp:
// See Démonstration Tri.cpp for the implementation of this class
//

class CDmonstrationTriApp : public CWinApp
{
public:
	CDmonstrationTriApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDmonstrationTriApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDmonstrationTriApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DMONSTRATIONTRI_H__89F281A4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
