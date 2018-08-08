// TextObject.h: interface for the CTextObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTOBJECT_H__044C05EE_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_TEXTOBJECT_H__044C05EE_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ObjetsVisuels.h"

class CTextObject : public CObjetsVisuels  
{
public:
	void Copie(CObjetsVisuels* pCopie);
	void Properties();
	void DrawObject(CDC *pDC);
	CTextObject();
	virtual ~CTextObject();

protected:
	int m_rotation;
	int m_nHeight;
	int m_align;
	int m_textColor;
	LOGFONT m_lfFont;
	CFont m_ftFont;
	CString m_szStr;
private:
	void CalculateBorderingRect(CDC *pDC, CString str);
	int m_devCaps;
};

#endif // !defined(AFX_TEXTOBJECT_H__044C05EE_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
