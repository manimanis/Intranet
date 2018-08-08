// PersButton.cpp : implementation file
//

#include "stdafx.h"
#include "Special Player.h"
#include "PersButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersButton

CPersButton::CPersButton()
{
	Over = Capturing = FALSE;
	memset(hBmp, 0, sizeof(hBmp));
}

CPersButton::~CPersButton()
{
	BmpNorm.Detach();
	BmpEnf.Detach();
	BmpOver.Detach();
}


BEGIN_MESSAGE_MAP(CPersButton, CButton)
	//{{AFX_MSG_MAP(CPersButton)
	ON_WM_MOUSEMOVE()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersButton message handlers

void CPersButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	LPDRAWITEMSTRUCT p = lpDrawItemStruct;

	switch(p->itemAction)
	{
	case ODA_DRAWENTIRE :
		DessinerImage(&BmpNorm);
		if (p->itemState & ODS_FOCUS) DessinerFocus();
		break;
	case ODA_FOCUS:
		if (p->itemState & ODS_FOCUS) DessinerFocus();
		break;
	case ODA_SELECT:
		switch (p->itemState & ODS_SELECTED)
		{
		case TRUE :
			DessinerImage(&BmpEnf);
			break;
		case FALSE :
			DessinerImage(&BmpNorm);
			break;
		}
		if (p->itemState & ODS_FOCUS) DessinerFocus();
		break;
	}
}

void CPersButton::SetImages(int ID_Norm, int ID_Enf, int ID_Over)
{
	BmpNorm.LoadBitmap(ID_Norm);
	BmpEnf.LoadBitmap(ID_Enf);
	BmpOver.LoadBitmap(ID_Over);
}

void CPersButton::DessinerImage(CBitmap *pBmp)
{
	BITMAP bm; pBmp->GetBitmap(&bm);
	CClientDC dc(this);
	CDC memDC; memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(pBmp);
	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);
}

void CPersButton::DessinerFocus()
{
	CRect rc; GetClientRect(&rc); rc.InflateRect(-10, -10);
	CClientDC dc(this); dc.DrawFocusRect(&rc);
}

void CPersButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	CRect rc; GetClientRect(&rc);

	if (!Capturing)
	{
		Over = Capturing = TRUE;
		SetCapture();
		
		// Invalidate(FALSE);
		DessinerImage(&BmpOver);
	}
	else
	{
		if (!rc.PtInRect(point))
		{
			ReleaseCapture();
			Over = Capturing = FALSE;
			// Invalidate(FALSE);
			DessinerImage(&BmpNorm);
		}
	}
	
	CButton::OnMouseMove(nFlags, point);
}



void CPersButton::OnCaptureChanged(CWnd *pWnd) 
{
	Over = Capturing = FALSE;	

	CButton::OnCaptureChanged(pWnd);
}

void CPersButton::SetImages(CString Normal, CString Enfoncee, CString Over)
{
	hBmp[0] = (HBITMAP)LoadImage(NULL, Normal, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BmpNorm.Attach(hBmp[0]);

	hBmp[1] = (HBITMAP)LoadImage(NULL, Enfoncee, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BmpEnf.Attach(hBmp[1]);

	hBmp[2] = (HBITMAP)LoadImage(NULL, Over, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BmpOver.Attach(hBmp[2]);
}
