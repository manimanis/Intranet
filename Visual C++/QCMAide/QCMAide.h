// QCMAide.h : main header file for the QCMAIDE application
//

#if !defined(AFX_QCMAIDE_H__6670AF25_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QCMAIDE_H__6670AF25_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CQCMAideApp:
// See QCMAide.cpp for the implementation of this class
//

#define TYPE_QUESTION		1
#define TYPE_PROPOSITION	2
#define TYPE_GOOD_ANSWER	4

typedef struct {
	int iType;
	CString szText;
} CDataStorage;

class CQCMAideApp : public CWinApp
{
public:
	CQCMAideApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQCMAideApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CQCMAideApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QCMAIDE_H__6670AF25_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
