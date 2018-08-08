// CorrectionQCM.h : main header file for the CORRECTIONQCM application
//

#if !defined(AFX_CORRECTIONQCM_H__74DA7DA4_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_CORRECTIONQCM_H__74DA7DA4_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMApp:
// See CorrectionQCM.cpp for the implementation of this class
//

class CCorrectionQCMApp : public CWinApp
{
public:
	CCorrectionQCMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCorrectionQCMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCorrectionQCMApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CORRECTIONQCM_H__74DA7DA4_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
