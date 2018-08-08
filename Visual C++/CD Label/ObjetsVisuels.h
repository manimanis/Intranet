// ObjetsVisuels.h: interface for the CObjetsVisuels class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJETSVISUELS_H__044C05ED_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_OBJETSVISUELS_H__044C05ED_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define OBJECT_STATE_NONE		0
#define OBJECT_STATE_SELECTED	1

#define OBJECT_TYPE_TEXT		1
#define OBJECT_TYPE_DESSIN		2

class CObjetsVisuels  
{
protected:
	void RecalcRect();
	int m_typeObject;
	CBrush m_blackBrush;
	CRect m_rcPos;
	int	m_nState;
public:
	virtual void Copie(CObjetsVisuels *pCopie);
	int GetType();
	virtual void Properties() = 0;
	virtual int IsOverResizeCorners(CPoint point);
	virtual BOOL PtInObject(CPoint);
	virtual int GetState();
	virtual void SelectObject(BOOL bState = TRUE);
	virtual CRect GetPos();
	void SetPos(CRect newPos);
	virtual void DrawObject(CDC *pDC) = 0;
	CObjetsVisuels();
	virtual ~CObjetsVisuels();
	
};

#endif // !defined(AFX_OBJETSVISUELS_H__044C05ED_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
