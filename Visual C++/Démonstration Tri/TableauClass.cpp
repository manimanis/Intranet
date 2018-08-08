// TableauClass.cpp: implementation of the CTableauClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "TableauClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTableauClass::CTableauClass(int *pTab, int nCount)
{
	m_pTab = pTab;
	m_nCount = nCount;
}

CTableauClass::~CTableauClass()
{

}

void CTableauClass::Draw(CDC *pDC)
{
	int i;
	CString str;

	for (i = 0; i < m_nCount ; i++)
	{
		pDC->Rectangle(40 + i * 40, 60, 80 + i * 40, 90);
		str.Format(" %d ", m_pTab[i]);
		pDC->TextOut(44 + i * 40, 64, str);
	}
}

void CTableauClass::Compare(CDC *pDC, int i, int j, int cmp)
{
	int Posi = 60 + i * 40, Posj = 60 + j * 40;
	int Posc = (Posi + Posj) / 2;
	CRect rc = CRect(Posc + 15, 110 - 15, Posc - 15, 110 + 15);

	pDC->MoveTo(Posi, 90);
	pDC->LineTo(Posi, 110);
	pDC->LineTo(Posj, 110);
	pDC->LineTo(Posj, 90);
	pDC->LineTo(Posj + 5, 95);
	
	pDC->MoveTo(Posj, 90);
	pDC->LineTo(Posj - 5, 95);

	CString str = "?";

	if (cmp & CMP_LESS)  str += "<";
	if (cmp & CMP_GREAT) str += ">";
	if (cmp & CMP_EQUAL) str += "=";

	pDC->Rectangle(rc);
	rc.DeflateRect(1, 1);
	pDC->DrawText(str, rc, DT_CENTER | DT_NOCLIP | DT_VCENTER);
}

void CTableauClass::Decision(CDC *pDC, int i, int j, int cmp)
{
	int Posi = 60 + i * 40, Posj = 60 + j * 40;
	int Posc = (Posi + Posj) / 2;
	CRect rc = CRect(Posc + 15, 110 - 15, Posc - 15, 110 + 15);

	BOOL eval = FALSE;

	if (cmp & CMP_LESS) 
		if (m_pTab[i] < m_pTab[j]) eval |= TRUE;
	
	if (cmp & CMP_EQUAL) 
		if (m_pTab[i] == m_pTab[j]) eval |= TRUE;

	if (cmp & CMP_GREAT)
		if (m_pTab[i] > m_pTab[j]) eval |= TRUE;

	CString str;

	if (eval)
		str = "Vrai";
	else
		str = "Faux";

	rc += CPoint(0, 70);
	rc.InflateRect(-20, -4);
	pDC->MoveTo(Posc, 110 + 15);
	pDC->LineTo(Posc, rc.top);
	pDC->LineTo(Posc + 5, rc.top - 5);
	pDC->MoveTo(Posc, rc.top);
	pDC->LineTo(Posc - 5, rc.top - 5);
	pDC->Rectangle(rc);
	rc.DeflateRect(1, 1);
	pDC->DrawText(str, rc, DT_CENTER | DT_NOCLIP);
}

void CTableauClass::Exchange(CDC *pDC, int i, int j)
{
	if (i == j) return;

	CString str;
	int Posi = 60 + i * 40, Posj = 60 + j * 40;
	int Posc = (Posi + Posj) / 2;
	int PosInt = m_nCount * 40 + 60;
		
	pDC->MoveTo(Posj, 90);
	pDC->LineTo(Posj, 110);
	pDC->LineTo(Posi, 110);
	pDC->LineTo(Posi, 90);
	pDC->LineTo(Posi - 5, 90 + 5);
	pDC->MoveTo(Posi, 90);
	pDC->LineTo(Posi + 5, 90 + 5);

	pDC->MoveTo(Posi, 60);
	pDC->LineTo(Posi, 40);
	pDC->LineTo(Posj, 40);
	pDC->LineTo(Posj, 60);
	pDC->LineTo(Posj - 5, 60 - 5);
	pDC->MoveTo(Posj, 60);
	pDC->LineTo(Posj + 5, 60 - 5);
}

void CTableauClass::ValueCompare(CDC *pDC, int i, int value, int cmp)
{
	int Posi = 60 + i * 40;

	pDC->MoveTo(Posi, 90);
	pDC->LineTo(Posi, 110);
	pDC->MoveTo(Posi + 5, 110 - 5);
	pDC->LineTo(Posi, 110);
	pDC->LineTo(Posi -5, 110 - 5);

	pDC->MoveTo(Posi, 130);
	pDC->LineTo(Posi, 150);
	pDC->MoveTo(Posi + 5, 150 - 5);
	pDC->LineTo(Posi, 150);
	pDC->LineTo(Posi -5, 150 - 5);

	pDC->Rectangle(Posi - 20, 110, Posi + 20, 130);
	pDC->Rectangle(Posi - 20, 150, Posi + 20, 170);

	CString str = "?";

	if (cmp & CMP_LESS)  str += "<";
	if (cmp & CMP_GREAT) str += ">";
	if (cmp & CMP_EQUAL) str += "=";
	pDC->TextOut(Posi - 16, 111, str);

	str.Format("%d", value);
	pDC->TextOut(Posi - 16, 151, str);
}

void CTableauClass::ValueDecision(CDC *pDC, int i, int value, int cmp)
{
	int Posi = 60 + i * 40;
	CRect rc = CRect(Posi + 60, 110, Posi + 160, 130);

	pDC->MoveTo(Posi + 20, 120);
	pDC->LineTo(Posi + 60, 120);
	pDC->LineTo(Posi + 60 - 5, 120 - 5);
	pDC->MoveTo(Posi + 60, 120);
	pDC->LineTo(Posi + 60 - 5, 120 + 5);

	BOOL eval = FALSE;

	if (cmp & CMP_LESS) 
		if (m_pTab[i] < value) eval |= TRUE;
	
	if (cmp & CMP_EQUAL) 
		if (m_pTab[i] == value) eval |= TRUE;

	if (cmp & CMP_GREAT)
		if (m_pTab[i] > value) eval |= TRUE;

	CString str;

	if (eval)
		str = "Vrai";
	else
		str = "Faux";

	pDC->Rectangle(rc);
	rc.DeflateRect(1, 1);
	pDC->DrawText(str, &rc, DT_NOCLIP | DT_CENTER);
}
