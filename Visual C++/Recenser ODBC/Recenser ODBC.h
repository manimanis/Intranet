// Recenser ODBC.h : main header file for the RECENSER ODBC application
//

#if !defined(AFX_RECENSERODBC_H__0CED5744_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_RECENSERODBC_H__0CED5744_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecenserODBCApp:
// See Recenser ODBC.cpp for the implementation of this class
//

class CRecenserODBCApp : public CWinApp
{
public:
	CRecenserODBCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecenserODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRecenserODBCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECENSERODBC_H__0CED5744_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_)
