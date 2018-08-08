// DessinVectoriel.h: interface for the CDessinVectoriel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESSINVECTORIEL_H__4942D020_9FDA_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_DESSINVECTORIEL_H__4942D020_9FDA_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ObjetsVisuels.h"

class CDessinVectoriel : public CObjetsVisuels  
{
public:
	void Copie(CObjetsVisuels* pCopie);
	void Properties();
	void DrawObject(CDC *pDC);
	CDessinVectoriel();
	virtual ~CDessinVectoriel();

protected:
	int m_nLineWidth;
	int m_typeDessin;
	int m_nColFond;
	int m_nColTrace;
	BOOL m_bColFond;
	BOOL m_bColTrace;
	int		m_nArrHeight;
	int		m_nArrWidth;
};

#endif // !defined(AFX_DESSINVECTORIEL_H__4942D020_9FDA_11D5_925D_0000E8EA8C1A__INCLUDED_)
