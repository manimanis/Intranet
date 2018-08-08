// DessinVectoriel.cpp: implementation of the CDessinVectoriel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CD Label.h"
#include "DessinVectoriel.h"

#include "DrawProperty.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDessinVectoriel::CDessinVectoriel()
{
	m_typeObject = OBJECT_TYPE_DESSIN;
	m_typeDessin = 0;
	m_bColFond = TRUE;
	m_bColTrace = FALSE;
	m_nColFond = RGB(255, 255, 255);
	m_nColTrace = RGB (0, 0, 0);
	m_nLineWidth = 1;
	m_nArrWidth = 15;
	m_nArrHeight = 15;
}

CDessinVectoriel::~CDessinVectoriel()
{

}

void CDessinVectoriel::DrawObject(CDC *pDC)
{
	CBrush *pOldBrush, brush;
	CPen *pOldPen, pen;

	brush.CreateSolidBrush(m_nColFond);
	pen.CreatePen(PS_SOLID, m_nLineWidth * 10, m_nColTrace);
	
	if (m_bColFond) // Est NULL
		pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	else
		pOldBrush = (CBrush *)pDC->SelectObject(&brush);

	if (m_bColTrace)
		pOldPen = (CPen *)pDC->SelectStockObject(NULL_PEN);
	else
		pOldPen = (CPen *)pDC->SelectObject(&pen);

	switch(m_typeDessin)
	{
	case 0 : pDC->Rectangle(m_rcPos); break;
	case 1 : pDC->Ellipse(m_rcPos) ;  break;
	case 2 : pDC->MoveTo(m_rcPos.TopLeft()); pDC->LineTo(m_rcPos.BottomRight());break;
	case 3 : pDC->RoundRect(m_rcPos, CPoint(m_nArrWidth * 100, m_nArrHeight * 100));
	}

	if (!pDC->IsPrinting() && m_nState == OBJECT_STATE_SELECTED) 
	{

		m_blackBrush.CreateSolidBrush(RGB(0, 0, 0));

		pDC->SelectObject(&m_blackBrush);
		
		pDC->Rectangle(m_rcPos.left, m_rcPos.top, m_rcPos.left + 200, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.CenterPoint().x - 100, m_rcPos.top, m_rcPos.CenterPoint().x + 100, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.right, m_rcPos.top, m_rcPos.right - 200, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.right, m_rcPos.CenterPoint().y + 100, m_rcPos.right - 200, m_rcPos.CenterPoint().y - 100);
		pDC->Rectangle(m_rcPos.right, m_rcPos.bottom, m_rcPos.right - 200, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.CenterPoint().x - 100, m_rcPos.bottom, m_rcPos.CenterPoint().x + 100, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.left, m_rcPos.bottom, m_rcPos.left + 200, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.left, m_rcPos.CenterPoint().y + 100, m_rcPos.left + 200, m_rcPos.CenterPoint().y - 100);

		m_blackBrush.DeleteObject();
	}

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	brush.DeleteObject();
	pen.DeleteObject();
}

void CDessinVectoriel::Properties()
{
	CDrawProperty dPr;

	switch (m_typeDessin)
	{
	case 0 : dPr.m_type = "Rectangle"; break;
	case 1 : dPr.m_type = "Ellipse"  ; break;
	case 2 : dPr.m_type = "Lignes"    ; break;
	case 3 : dPr.m_type = "Rectangle Arrondi"; break;
	}

	dPr.m_nColFond = m_nColFond;
	dPr.m_nColTrace = m_nColTrace;
	dPr.m_bColFond = m_bColFond;
	dPr.m_bColTrace = m_bColTrace;
	dPr.m_nLineWidth = m_nLineWidth;
	dPr.m_nArrHeight = m_nArrHeight;
	dPr.m_nArrWidth = m_nArrWidth;

	if (dPr.DoModal() == IDCANCEL) return;

	m_nColFond = dPr.m_nColFond;
	m_nColTrace = dPr.m_nColTrace;
	m_bColFond = dPr.m_bColFond;
	m_bColTrace = dPr.m_bColTrace;

	if (dPr.m_type == "Rectangle") m_typeDessin = 0;
	else if (dPr.m_type == "Ellipse") m_typeDessin = 1;
	else if (dPr.m_type == "Lignes") m_typeDessin = 2;
	else if (dPr.m_type == "Rectangle Arrondi") m_typeDessin = 3;

	m_nLineWidth = dPr.m_nLineWidth;
	m_nArrHeight = dPr.m_nArrHeight;
	m_nArrWidth = dPr.m_nArrWidth;
}

void CDessinVectoriel::Copie(CObjetsVisuels *pCopie)
{
	m_bColFond = ((CDessinVectoriel *)pCopie)->m_bColFond;
	m_nColFond = ((CDessinVectoriel *)pCopie)->m_nColFond;

	m_bColTrace = ((CDessinVectoriel *)pCopie)->m_bColTrace;
	m_nColTrace = ((CDessinVectoriel *)pCopie)->m_nColTrace;

	m_typeDessin = ((CDessinVectoriel *)pCopie)->m_typeDessin;

	m_nLineWidth = ((CDessinVectoriel *)pCopie)->m_nLineWidth;

	m_nArrWidth = ((CDessinVectoriel *)pCopie)->m_nArrWidth;
	m_nArrHeight = ((CDessinVectoriel *)pCopie)->m_nArrHeight;

	CObjetsVisuels::Copie(pCopie);
}
