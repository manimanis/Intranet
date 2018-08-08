// ImgViewer.h : main header file for the IMGVIEWER application
//

#if !defined(AFX_IMGVIEWER_H__198FDAE5_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
#define AFX_IMGVIEWER_H__198FDAE5_4508_11D4_98A6_E5B5D3962525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CImgViewerApp:
// See ImgViewer.cpp for the implementation of this class
//

class CImgViewerApp : public CWinApp
{
public:
	CImgViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImgViewerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGVIEWER_H__198FDAE5_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
