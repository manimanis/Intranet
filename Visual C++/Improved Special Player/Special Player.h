// Special Player.h : main header file for the SPECIAL PLAYER application
//

#if !defined(AFX_SPECIALPLAYER_H__40968DF4_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SPECIALPLAYER_H__40968DF4_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerApp:
// See Special Player.cpp for the implementation of this class
//

class CSpecialPlayerApp : public CWinApp
{
public:
	CSpecialPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSpecialPlayerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALPLAYER_H__40968DF4_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
