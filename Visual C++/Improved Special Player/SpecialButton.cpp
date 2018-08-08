// SpecialButton.cpp : implementation file
//

#include "stdafx.h"
#include "Special Player.h"
#include "SpecialButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton

CSpecialButton::CSpecialButton()
{
}

CSpecialButton::~CSpecialButton()
{
}


BEGIN_MESSAGE_MAP(CSpecialButton, CStatic)
	//{{AFX_MSG_MAP(CSpecialButton)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton message handlers

void CSpecialButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	AfxMessageBox("Ouvrir cette animation");
	
	CStatic::OnLButtonUp(nFlags, point);
}
