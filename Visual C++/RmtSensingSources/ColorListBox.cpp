// ColorListBox.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "ColorListBox.h"
#include "FakeColorsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorListBox

CColorListBox::CColorListBox()
{	
	blackBrush.CreateSolidBrush(RGB(0, 0, 0));
	whiteBrush.CreateSolidBrush(RGB(255, 255, 255));
}

CColorListBox::~CColorListBox()
{
	blackBrush.DeleteObject();
	whiteBrush.DeleteObject();
}


BEGIN_MESSAGE_MAP(CColorListBox, CListBox)
	//{{AFX_MSG_MAP(CColorListBox)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_SLECTION_DSLECTIONNER, OnSlectionDslectionner)
	ON_COMMAND(ID_SLECTION_INVERSERLASLECTION, OnSlectionInverserlaslection)
	ON_COMMAND(ID_SLECTION_TOUTSLECTIONNER, OnSlectionToutslectionner)
	ON_COMMAND(ID_SELECTION_CRITERE, OnSelectionCritere)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#define COLOR_ITEM_HEIGHT   15
#define COLOR_ITEM_WIDTH	15

/////////////////////////////////////////////////////////////////////////////
// CColorListBox message handlers


void CColorListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS) 
{
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	COLORREF cr = (COLORREF)lpDIS->itemData; // RGB in item data

	CRect rect = lpDIS->rcItem;
	rect.right = rect.left + rect.Width() / 8;

	if (lpDIS->itemAction & ODA_DRAWENTIRE)
	{
		// Paint the color item in the color requested
		CBrush br(cr);

		CRect rect1 = rect; rect1.InflateRect(-2, -2, -2, -2);
		pDC->FillRect(&rect1, &br);

		CString str;
		str.Format("%d", lpDIS->itemID);

		pDC->TextOut(rect.right + 2, rect.top, str);

		str.Format("r = %d", cr & 0xff);
		pDC->TextOut(rect.right + 50, rect.top, str);

		str.Format("v = %d", (cr >> 8) & 0xff);
		pDC->TextOut(rect.right + 100, rect.top, str);

		str.Format("b = %d", cr >> 16);
		pDC->TextOut(rect.right + 150, rect.top, str);
	}

	if ((lpDIS->itemState & ODS_SELECTED) &&
		(lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE)))
	{
		// item has been selected - hilite frame
		pDC->FrameRect(&rect, &blackBrush);
	}

	if (!(lpDIS->itemState & ODS_SELECTED) &&
		(lpDIS->itemAction & ODA_SELECT))
	{
		// Item has been de-selected -- remove frame
		pDC->FrameRect(&rect, &whiteBrush);
	}	
}

void CColorListBox::AddColorItem(COLORREF color)
{
	AddString((LPCTSTR) color);		
}

void CColorListBox::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu menu;

	menu.LoadMenu(IDR_ZOOM);
	menu.GetSubMenu(1)->TrackPopupMenu(TPM_RIGHTALIGN, point.x, point.y, this);
	menu.Detach();		
}

void CColorListBox::OnSlectionDslectionner() 
{
	SelItemRange(FALSE, 0, GetCount() - 1);
	Invalidate();
}

void CColorListBox::OnSlectionInverserlaslection() 
{
	int uB, lB, selCount;
	int i;

	selCount = GetSelCount();

	int *sel = new int [GetSelCount()];
	GetSelItems(selCount, sel);

	SelItemRange(TRUE, 0, GetCount() - 1);

	lB = uB = sel[0];

	i = 1;
	do {
		while (sel[i++] == (uB + 1) && i < selCount) uB = sel[i];

		if (uB > lB)
		{
			SelItemRange(FALSE, lB, uB);
		} else SetSel(lB, FALSE);

		lB = uB = sel[i];
	} while (i < selCount);

	delete [] sel;
	Invalidate();
}

void CColorListBox::OnSlectionToutslectionner() 
{
	SelItemRange(TRUE, 0, GetCount() - 1);
}


void CColorListBox::OnSelectionCritere() 
{
	((CFakeColorsDialog *)GetParent())->OnSelectionCritere();
}
