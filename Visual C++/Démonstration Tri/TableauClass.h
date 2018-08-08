// TableauClass.h: interface for the CTableauClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEAUCLASS_H__89F281B4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_TABLEAUCLASS_H__89F281B4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CMP_GREAT		1
#define CMP_LESS		2
#define CMP_EQUAL		4

class CTableauClass  
{
public:
	void ValueDecision(CDC *pDC, int i, int value, int cmp);
	void ValueCompare(CDC *pDC, int i, int value, int cmp);
	void Exchange(CDC *pDC, int i, int j);
	void Decision(CDC *pDC, int i, int j, int cmp);
	void Compare(CDC *pDC, int i, int j, int cmp);
	void Draw(CDC *pDC);
	CTableauClass(int *pTab, int nCount);
	virtual ~CTableauClass();

protected:
	int m_nCount;
	int *m_pTab;
};

#endif // !defined(AFX_TABLEAUCLASS_H__89F281B4_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
