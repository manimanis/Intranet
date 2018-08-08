// ComposantesRGB.cpp: implementation of the CComposantesRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtSensingDoc.h"
#include "ComposantesRGB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CComposantesRGB, CRmtSensingView)

BEGIN_MESSAGE_MAP(CComposantesRGB, CRmtSensingView)
	//{{AFX_MSG_MAP(CComposantesRGB)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComposantesRGB::CComposantesRGB()
{
	AndColor = 0xffffff;
}

CComposantesRGB::~CComposantesRGB()
{

}

void CComposantesRGB::OnDraw(CDC *pDC)
{
	CRmtSensingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect OutsideRect;

	if (copyMode)	
	{
		pDoc->bmpManip.DrawEx(pDC, 
			CRect(0, 0, pDoc->bmpManip.GetWidth(), pDoc->bmpManip.GetHeight()), AndColor);
		return;
	}

	if (pDC->IsPrinting())
	{
		pDC->SetMapMode(MM_HIMETRIC);
		OutsideRect.top = OutsideRect.left = 0;
		OutsideRect.right = 20000;
		OutsideRect.bottom = -15000;
		
		pDoc->bmpManip.DrawEx(pDC, OutsideRect, AndColor);

		return;
	}
	
	CBrush brush(HS_DIAGCROSS, RGB(220, 220, 220)), *oldBrush;
	CPen pen(PS_NULL, 1, RGB(0, 0, 0)), *oldPen;

	oldBrush = (CBrush*) pDC->SelectObject(&brush);
	oldPen = (CPen*) pDC->SelectObject(&pen);

	GetClientRect(&OutsideRect);

	pDC->Rectangle(&OutsideRect);
	PicRect = CRect(0, 0, 
					int(factor * pDoc->bmpManip.GetWidth()), 
					int(factor * pDoc->bmpManip.GetHeight()));

	if (OutsideRect.Width() > PicRect.Width()) 
	{
		PicRect.left = (OutsideRect.Width() - int(factor * pDoc->bmpManip.GetWidth()) / 2);
		PicRect.right = PicRect.left + int(factor * pDoc->bmpManip.GetWidth());
	}

	if (OutsideRect.Height() > PicRect.Height()) 
	{
		PicRect.top = (OutsideRect.Height() - int(factor * pDoc->bmpManip.GetHeight()) / 2);
		PicRect.bottom = PicRect.top + int(factor * pDoc->bmpManip.GetHeight());
	}

	pDoc->bmpManip.DrawEx(pDC, PicRect, AndColor);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);

	brush.DeleteObject();
	pen.DeleteObject();
}

void CComposantesRGB::OnInitialUpdate()
{
	CRmtSensingDoc *pDoc = (CRmtSensingDoc *)GetDocument();
	// CScrollView::OnInitialUpdate();
	
	SetScrollSizes(MM_TEXT, CSize(	int(factor * pDoc->bmpManip.GetWidth()), 
									int(factor * pDoc->bmpManip.GetHeight())));
	ResizeParentToFit();

	pDoc->bmpManip.GetHistogrammeInfo();
}
