// TextObject.cpp: implementation of the CTextObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CD Label.h"
#include "TextObject.h"

#include <math.h>

#include "ProprieteTexte.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define PI 3.141596

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTextObject::CTextObject()
{
	CClientDC dc(AfxGetMainWnd());

	dc.SetMapMode(MM_HIMETRIC);

	m_szStr = "Modifier ce texte";
	memset(&m_lfFont, 0, sizeof(m_lfFont));

	m_nHeight = 12;
	m_devCaps = dc.GetDeviceCaps(LOGPIXELSY);

	m_lfFont.lfHeight = -MulDiv(m_nHeight, m_devCaps, 2540);
	m_lfFont.lfWeight = 12;
	strcpy(m_lfFont.lfFaceName, "Times New Roman");

	m_ftFont.CreateFontIndirect(&m_lfFont); 

	CFont *pFont;

	pFont = (CFont *)dc.SelectObject(&m_ftFont);

	CSize size = dc.GetTextExtent(m_szStr);
	//dc.LPtoDP(&size);

	m_rcPos.right = size.cx + m_rcPos.left;
	m_rcPos.bottom = -size.cy + m_rcPos.top;

	dc.SelectObject(pFont);

	m_textColor = 0;
	m_typeObject = OBJECT_TYPE_TEXT;
	m_align = 0;
	m_rotation = 0;

	RecalcRect();
}

CTextObject::~CTextObject()
{
	m_ftFont.DeleteObject();
}

void CTextObject::DrawObject(CDC *pDC)
{
	CRect tempRc = m_rcPos;
	CFont *pFont;
	int align;

	pDC->SetTextColor(m_textColor);
	pFont = (CFont *)pDC->SelectObject(&m_ftFont);

	switch(m_align)
	{
	case 0 : align = TA_LEFT;  break;
	case 1 : align = TA_CENTER;break;
	case 2 : align = TA_RIGHT; break;
	}

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextAlign(align);

	CalculateBorderingRect(pDC, m_szStr);

	if (!pDC->IsPrinting() && m_nState == OBJECT_STATE_SELECTED) 
	{
		CBrush *pOldBrush;

		m_blackBrush.CreateSolidBrush(RGB(0, 0, 0));

		pOldBrush = (CBrush *)pDC->SelectObject(&m_blackBrush);
		
		pDC->Rectangle(m_rcPos.left, m_rcPos.top, m_rcPos.left + 200, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.CenterPoint().x - 100, m_rcPos.top, m_rcPos.CenterPoint().x + 100, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.right, m_rcPos.top, m_rcPos.right - 200, m_rcPos.top - 200);
		pDC->Rectangle(m_rcPos.right, m_rcPos.CenterPoint().y + 100, m_rcPos.right - 200, m_rcPos.CenterPoint().y - 100);
		pDC->Rectangle(m_rcPos.right, m_rcPos.bottom, m_rcPos.right - 200, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.CenterPoint().x - 100, m_rcPos.bottom, m_rcPos.CenterPoint().x + 100, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.left, m_rcPos.bottom, m_rcPos.left + 200, m_rcPos.bottom + 200);
		pDC->Rectangle(m_rcPos.left, m_rcPos.CenterPoint().y + 100, m_rcPos.left + 200, m_rcPos.CenterPoint().y - 100);

		pDC->SelectObject(pOldBrush);

		m_blackBrush.DeleteObject();
	}

	pDC->SelectObject(pFont);
}

void CTextObject::Properties()
{
	CProprieteTexte pDlg;

	pDlg.m_szText = m_szStr;
	m_lfFont.lfHeight = m_nHeight;
	memcpy(&pDlg.m_logFont, &m_lfFont, sizeof(LOGFONT));
	pDlg.m_textColor = m_textColor;
	pDlg.m_align = m_align;
	pDlg.m_rotationVal = pDlg.m_rotation = m_rotation;

	if (pDlg.DoModal() == IDCANCEL) return;

	m_textColor = pDlg.m_textColor;
	m_szStr = pDlg.m_szText;
	m_align = pDlg.m_align;
	m_rotation = pDlg.m_rotation;

	if (pDlg.m_bFontChanged)
	{
		m_nHeight = pDlg.m_logFont.lfHeight;
		pDlg.m_logFont.lfHeight = -MulDiv(m_nHeight, m_devCaps * 1000, 2540);

		memcpy(&m_lfFont, &pDlg.m_logFont, sizeof(LOGFONT));
		m_lfFont.lfEscapement = m_rotation * 10;
		m_ftFont.Detach();
		m_ftFont.CreateFontIndirect(&m_lfFont);
	}
}


void CTextObject::CalculateBorderingRect(CDC *pDC, CString str)
{
	int from = 0, pos;
	CSize sz, sz1= CSize(0, 0);
	int lineCount = 0, i;
	CString s;

	double cos_a, sin_a, cos_b, sin_b;
	double d;
	double cos_apb, sin_apb, cos_amb, sin_amb;
	CPoint pt[4];

	CRect oldPos;

	do
	{
		pos = str.Find("\015\012", from);
		if (pos >= 0) 
			sz = pDC->GetOutputTextExtent(m_szStr.Mid(from, pos - from));
		else
			sz = pDC->GetOutputTextExtent(m_szStr.Mid(from));

		if (sz.cx > sz1.cx) sz1.cx = sz.cx;
		sz1.cy += sz.cy;

		from = pos + 1;
		lineCount++;
	} while (pos >= 0);

	sz1.cx = abs(sz1.cx); sz1.cy = abs(sz1.cy);
	
	d = sqrt(sz1.cx * sz1.cx + sz1.cy * sz1.cy);
	
	cos_a = (double)sz1.cx / d;
	sin_a = (double)sz1.cy / d;

	cos_b = cos((double)m_rotation * PI / 180.0);
	sin_b = -sin((double)m_rotation * PI / 180.0);

	cos_apb = cos_a * cos_b - sin_a * sin_b;
	sin_apb = sin_a * cos_b + cos_a * sin_b;

	cos_amb = cos_a * cos_b + sin_a * sin_b;
	sin_amb = sin_a * cos_b - cos_a * sin_b;

	RecalcRect();

	CPoint midPoint = m_rcPos.CenterPoint();

	pt[0].x = (int)(-d * cos_amb / 2.0) + midPoint.x;
	pt[0].y = (int)(d * sin_amb / 2.0) + midPoint.y;

	pt[1].x = (int)(d * cos_apb / 2.0) + midPoint.x;
	pt[1].y = (int)(d * sin_apb / 2.0) + midPoint.y;

	pt[2].x = (int)(d * cos_amb / 2.0) + midPoint.x;
	pt[2].y = (int)(-d * sin_amb / 2.0) + midPoint.y;

	pt[3].x = (int)(-d * cos_apb / 2.0) + midPoint.x;
	pt[3].y = (int)(-d * sin_apb / 2.0) + midPoint.y;

	m_rcPos.left = pt[0].x;
	m_rcPos.right = pt[0].x;
	m_rcPos.top = pt[0].y;
	m_rcPos.bottom = pt[0].y;

	for (i = 0 ; i < 4 ; i++)
	{
		if (m_rcPos.left > pt[i].x) m_rcPos.left = pt[i].x;
		if (m_rcPos.right < pt[i].x) m_rcPos.right = pt[i].x;
		if (m_rcPos.top > pt[i].y) m_rcPos.top = pt[i].y;
		if (m_rcPos.bottom < pt[i].y) m_rcPos.bottom = pt[i].y;
	}

	int ofx = 0, ofy = 0;

	for (from = 0, i = 0 ; i < lineCount ; i++)
	{
		pos = str.Find("\015\012", from);

		if (pos >= 0) 
			s = m_szStr.Mid(from, pos - from);
		else
			s = m_szStr.Mid(from);
		
		if (m_align == 0) ofx = pt[0].x, ofy = pt[0].y;
		else if (m_align == 1) ofx = (pt[1].x - pt[0].x) / 2 + pt[0].x, ofy = (pt[1].y - pt[0].y) / 2 + pt[0].y;
		else if (m_align == 2) ofx = pt[1].x, ofy = pt[1].y;

		pDC->TextOut(i * (pt[3].x - pt[0].x) / lineCount + ofx, 
					 i * (pt[3].y - pt[0].y) / lineCount + ofy, s);

		from = pos + 2;
	}
}

void CTextObject::Copie(CObjetsVisuels *pCopie)
{
	m_align = ((CTextObject *)pCopie)->m_align;
	m_nHeight = ((CTextObject *)pCopie)->m_nHeight;
	m_rotation = ((CTextObject *)pCopie)->m_rotation;
	m_szStr = ((CTextObject *)pCopie)->m_szStr;
	m_textColor = ((CTextObject *)pCopie)->m_textColor;
	memcpy(&m_lfFont, &(((CTextObject *)pCopie)->m_lfFont), sizeof(LOGFONT));

	m_lfFont.lfHeight = -MulDiv(m_nHeight, m_devCaps * 1000, 2540);
	m_ftFont.Detach();
	m_ftFont.CreateFontIndirect(&m_lfFont);

	memcpy(&m_lfFont, &(((CTextObject *)pCopie)->m_lfFont), sizeof(LOGFONT));
	
	CObjetsVisuels::Copie(pCopie);
}
