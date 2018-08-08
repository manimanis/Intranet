// BackSide.cpp : implementation file
//

#include "stdafx.h"
#include "CD Label.h"
#include "BackSide.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackSide

IMPLEMENT_DYNCREATE(CBackSide, CScrollView)

CBackSide::CBackSide()
{
}

CBackSide::~CBackSide()
{
}


BEGIN_MESSAGE_MAP(CBackSide, CScrollView)
	//{{AFX_MSG_MAP(CBackSide)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackSide drawing

void CBackSide::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CBackSide::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CBackSide diagnostics

#ifdef _DEBUG
void CBackSide::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBackSide::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBackSide message handlers
