// SortSearch.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "SortSearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortSearch

IMPLEMENT_DYNCREATE(CSortSearch, CWinThread)

CSortSearch::CSortSearch()
{
	m_bEnd = FALSE;
	m_szName = "";
}

CSortSearch::~CSortSearch()
{
	m_bEnd = TRUE;
}

BOOL CSortSearch::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CSortSearch::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CSortSearch, CWinThread)
	//{{AFX_MSG_MAP(CSortSearch)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortSearch message handlers
