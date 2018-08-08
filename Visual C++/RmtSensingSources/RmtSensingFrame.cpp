// RmtSensingFrame.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtSensingFrame.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame

IMPLEMENT_DYNCREATE(CRmtSensingFrame, CMDIChildWnd)

CRmtSensingFrame::CRmtSensingFrame()
{
	DoIShowHistogramme = TRUE;

	m_wndToolBar = &((CMainFrame *)AfxGetMainWnd())->m_wndToolBar;
}

CRmtSensingFrame::~CRmtSensingFrame()
{
}


BEGIN_MESSAGE_MAP(CRmtSensingFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CRmtSensingFrame)
	ON_WM_CREATE()
	ON_WM_WINDOWPOSCHANGING()
	ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame message handlers
int CRmtSensingFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

BOOL CRmtSensingFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	cs.cx = GetSystemMetrics(SM_CXSCREEN) * 3 / 5;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) * 3 / 5;

	return TRUE;
}


void CRmtSensingFrame::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
	CMDIChildWnd::OnWindowPosChanging(lpwndpos);

	int maxCx = GetSystemMetrics(SM_CXMAXIMIZED) - 13,
		maxCy = GetSystemMetrics(SM_CYMAXIMIZED) - 93;

	if (!IsZoomed())
	{
		if (lpwndpos->cx > maxCx)
		{
			lpwndpos->cx = maxCx;
		}

		if (lpwndpos->cy > maxCy)
		{
			lpwndpos->cy = maxCy;
		}
	}
}

void CRmtSensingFrame::OnViewToolbar() 
{
	BOOL bVisible = ((m_wndToolBar->GetStyle() & WS_VISIBLE) != 0);

	ShowControlBar(m_wndToolBar, !bVisible, FALSE);
	RecalcLayout();

}

void CRmtSensingFrame::OnUpdateViewToolbar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndToolBar->GetStyle() & WS_VISIBLE);	
}

BOOL CRmtSensingFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	return CreateSplitterWindow(pContext);
}

BOOL CRmtSensingFrame::CreateSplitterWindow(CCreateContext *pContext)
{
	if (!m_splitterWnd.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to create splitter 1)\n");
		return -1;      // fail to create
	}

	if (!m_splitterWnd2.CreateStatic(&m_splitterWnd, 2, 1,
		WS_CHILD | WS_VISIBLE | WS_BORDER, 
		m_splitterWnd.IdFromRowCol(0, 0)))
	{
		TRACE0("Failed to create splitter 2 on pane (0, 0)\n");
		return -1;      // fail to create
	}


	// add the second splitter pane - an input view in column 1
	if (!m_splitterWnd2.CreateView(1, 0,
		RUNTIME_CLASS(CRmtListForm), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create view (1, 0) on splitter 2\n");
		return FALSE;
	}

	// add the second splitter pane - an input view in column 1
	if (!m_splitterWnd2.CreateView(0, 0,
		RUNTIME_CLASS(CPictureHistogrammeView), CSize(0, 400), pContext))
	{
		TRACE0("Failed to create view (0, 0) on splitter 2\n");
		return FALSE;
	}


	// add the second splitter pane - an input view in column 1
	if (!m_splitterWnd.CreateView(0, 1,
		RUNTIME_CLASS(CRmtSensingView), CSize(1024, 50), pContext))
	{
		TRACE0("Failed to create view (0, 1) on splitter 1\n");
		return FALSE;
	}

	HistView = (CPictureHistogrammeView *)m_splitterWnd2.GetPane(0,0);
	PicView = (CRmtSensingView *)m_splitterWnd.GetPane(0,1);
	ListView = (CRmtListForm *)m_splitterWnd2.GetPane(1,0);

	// activate the input view
	SetActiveView((CView*)m_splitterWnd.GetPane(0,1));

	return TRUE;
}
