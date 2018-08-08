// MediaPlayerTest.h : main header file for the MEDIAPLAYERTEST application
//

#if !defined(AFX_MEDIAPLAYERTEST_H__E4655C44_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_MEDIAPLAYERTEST_H__E4655C44_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerTestApp:
// See MediaPlayerTest.cpp for the implementation of this class
//

class CMediaPlayerTestApp : public CWinApp
{
public:
	CMediaPlayerTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayerTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMediaPlayerTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYERTEST_H__E4655C44_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_)
