#if !defined(AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_

#include "PictureHistogrammeView.h"	// Added by ClassView
#include "RmtSensingView.h"
#include "RmtListForm.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RmtSensingFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame frame

class CRmtSensingFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CRmtSensingFrame)
public:
	CRmtSensingFrame();           // protected constructor used by dynamic creation
	virtual ~CRmtSensingFrame();

// Attributes
public:

// Operations
public:
	CRmtSensingView *PicView;
	CRmtListForm *ListView;
	CPictureHistogrammeView *HistView;
	CSplitterWnd m_splitterWnd;
	CSplitterWnd m_splitterWnd2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolBar *m_wndToolBar;
	BOOL DoIShowHistogramme;

public:
	BOOL CreateSplitterWindow(CCreateContext *pContext);
	// Generated message map functions
	//{{AFX_MSG(CRmtSensingFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnViewToolbar();
	afx_msg void OnUpdateViewToolbar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
