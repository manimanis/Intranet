// Rebooter.h : main header file for the REBOOTER application
//

#if !defined(AFX_REBOOTER_H__07882F04_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_REBOOTER_H__07882F04_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRebooterApp:
// See Rebooter.cpp for the implementation of this class
//

class CRebooterApp : public CWinApp
{
public:
	CRebooterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRebooterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRebooterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REBOOTER_H__07882F04_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
