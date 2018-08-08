// ColorBox.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "ColorBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorBox

CColorBox::CColorBox()
{
	selection = RGB(255, 255, 255);
}

CColorBox::~CColorBox()
{
}


BEGIN_MESSAGE_MAP(CColorBox, CStatic)
	//{{AFX_MSG_MAP(CColorBox)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorBox message handlers

void CColorBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	CBrush br(selection);

	GetClientRect(&rect);
	
	dc.FillRect(&rect, &br);
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CColorBox::SetSelection(COLORREF color)
{
	selection = color;
}
