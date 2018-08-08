// Resistor.cpp: implementation of the Resistor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Résistors.h"
#include "Resistor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Resistor::Resistor()
{

	// Bandes multiplicateur
	m_bandsColors[11] = RGB(242, 242, 242);	// -2 Argent
	m_bandsColors[10] = RGB(230, 241, 3);	// -1 Or
	// Bandes de couleur
	m_bandsColors[0] = RGB(0, 0, 0);		// 0  Noir
	m_bandsColors[1] = RGB(204, 147, 83);	// 1  Marron
	m_bandsColors[2] = RGB(255, 0, 0);		// 2  Rouge
	m_bandsColors[3] = RGB(255, 186, 108);	// 3  Orange
	m_bandsColors[4] = RGB(255, 255, 0);	// 4  Jaune
	m_bandsColors[5] = RGB(0, 255, 0);		// 5  Vert
	m_bandsColors[6] = RGB(0, 0, 255);		// 6  Bleu
	m_bandsColors[7] = RGB(255, 128, 255);	// 7  Violet
	m_bandsColors[8] = RGB(191, 191, 191);	// 8  Gris
	m_bandsColors[9] = RGB(255, 255, 255);	// 9  Blanc


	memset(bandes, 0, sizeof(bandes));
}

Resistor::~Resistor()
{

}

void Resistor::Draw(CDC *pDC, CRect rc)
{
	CBrush newBr, *oldBr;
	CPoint middle;

	int increm = (rc.Height() - 40) / 8;

	middle.x = (rc.left + rc.right) / 2;
	middle.y = (rc.bottom + rc.top) / 2;
	
	
	newBr.CreateSolidBrush(RGB(254, 255, 225));
	oldBr = (CBrush *)pDC->SelectObject(&newBr);
	pDC->Rectangle(rc.left + 20, rc.top + 20, rc.right - 20, rc.bottom - 20);

	newBr.DeleteObject();
	newBr.CreateSolidBrush(RGB(0, 0, 0));
	pDC->SelectObject(&newBr);
	pDC->Rectangle(middle.x - 10, rc.top + 2, middle.x + 10, rc.top + 20);
	pDC->Rectangle(middle.x - 10, rc.bottom - 2, middle.x + 10, rc.bottom - 20);

	for (int i = 0 ; i < nbBandes ; i++)
	{
		newBr.DeleteObject();
		newBr.CreateSolidBrush(m_bandsColors[bandes[i]]);
		pDC->SelectObject(&newBr);
		pDC->Rectangle(rc.left + 20, rc.top + 30 + increm * i, rc.right - 20, 
							rc.top + 30 + increm * i + increm - 10);
	}

	int tolCol;

	switch(bandes[4])
	{
	case 1 : tolCol = 1; break;
	case 2 : tolCol = 2; break;
	case 3 : tolCol = 10; break;
	case 4 : tolCol = 11; break;
	}

	if (bandes[4] > 0)
	{
		newBr.DeleteObject();
		newBr.CreateSolidBrush(m_bandsColors[tolCol]);
		pDC->SelectObject(&newBr);
		pDC->Rectangle(rc.left + 20, rc.bottom - 30, rc.right - 20, 
							rc.bottom - 30 - increm + 10);
	}

	pDC->SelectObject(oldBr);
}
