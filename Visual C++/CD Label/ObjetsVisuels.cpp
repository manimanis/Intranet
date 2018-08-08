// ObjetsVisuels.cpp: implementation of the CObjetsVisuels class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CD Label.h"
#include "ObjetsVisuels.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//--------------------------------------
CRect GetRect(CRect m_rcPos)
{
	CRect rc;

	rc.left = (m_rcPos.left < m_rcPos.right) ? m_rcPos.left : m_rcPos.right;
	rc.right = (m_rcPos.right < m_rcPos.left) ? m_rcPos.left : m_rcPos.right;

	rc.top = (m_rcPos.top < m_rcPos.bottom) ? m_rcPos.top : m_rcPos.bottom;
	rc.bottom = (m_rcPos.bottom < m_rcPos.top) ? m_rcPos.top : m_rcPos.bottom;

	return rc;
}

BOOL PtInRect(CRect rcPos, CPoint point)
{
	return GetRect(rcPos).PtInRect(point);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CObjetsVisuels::CObjetsVisuels()
{
	m_nState = OBJECT_STATE_NONE;

	m_rcPos = CRect(1000, -1000, 5000, -2000);	
	m_typeObject = 0;
}

void CObjetsVisuels::Copie(CObjetsVisuels *pCopie)
{
	m_nState = pCopie->m_nState;
	m_rcPos = pCopie->m_rcPos;
	m_typeObject = pCopie->m_typeObject;
}

CObjetsVisuels::~CObjetsVisuels()
{
	
}

void CObjetsVisuels::SetPos(CRect newPos)
{
	m_rcPos = newPos;
}

CRect CObjetsVisuels::GetPos()
{
	return m_rcPos;
}

void CObjetsVisuels::SelectObject(BOOL bState)
{
	if (bState) 
		m_nState = OBJECT_STATE_SELECTED;
	else
		m_nState = OBJECT_STATE_NONE;
}

int CObjetsVisuels::GetState()
{
	return m_nState;
}

BOOL CObjetsVisuels::PtInObject(CPoint point)
{
	// GetRect(m_rcPos);
	return PtInRect(m_rcPos, point);
}

// 7*     6*     *5
//
// 8*            *4
//  
// 1*     2*     *3
int CObjetsVisuels::IsOverResizeCorners(CPoint point)
{
	GetRect(m_rcPos);

	if (PtInRect(CRect(m_rcPos.left, m_rcPos.bottom, m_rcPos.left + 200, m_rcPos.bottom + 200), point))
		return 1;
	
	if (PtInRect(CRect(m_rcPos.CenterPoint().x - 100, m_rcPos.bottom, m_rcPos.CenterPoint().x + 100, m_rcPos.bottom + 200), point))
		return 2;

	if (PtInRect(CRect(m_rcPos.right, m_rcPos.bottom, m_rcPos.right - 200, m_rcPos.bottom + 200), point))
		return 3;

	if (PtInRect(CRect(m_rcPos.right, m_rcPos.CenterPoint().y + 100, m_rcPos.right - 200, m_rcPos.CenterPoint().y - 100), point))
		return 4;

	if (PtInRect(CRect(m_rcPos.right, m_rcPos.top, m_rcPos.right - 200, m_rcPos.top - 200), point))
		return 5;

	if (PtInRect(CRect(m_rcPos.CenterPoint().x - 100, m_rcPos.top, m_rcPos.CenterPoint().x + 100, m_rcPos.top - 200), point))
		return 6;

	if (PtInRect(CRect(m_rcPos.left, m_rcPos.top, m_rcPos.left + 200, m_rcPos.top - 200), point))
		return 7;

	if (PtInRect(CRect(m_rcPos.left, m_rcPos.CenterPoint().y + 100, m_rcPos.left + 200, m_rcPos.CenterPoint().y - 100), point))
		return 8;
	
	return 0;
}


int CObjetsVisuels::GetType()
{
	return m_typeObject;
}

void CObjetsVisuels::RecalcRect()
{
	int i;

	if (m_rcPos.top > m_rcPos.bottom) { i = m_rcPos.top; m_rcPos.top = m_rcPos.bottom ; m_rcPos.bottom = i;}
	if (m_rcPos.left > m_rcPos.right) { i = m_rcPos.left; m_rcPos.left = m_rcPos.right ; m_rcPos.right = i;}
}