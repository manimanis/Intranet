// Resistor.h: interface for the Resistor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESISTOR_H__B100C1CE_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
#define AFX_RESISTOR_H__B100C1CE_2453_11D5_9911_A8DCADD2F70E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Resistor  
{
public:
	int nbBandes;
	char bandes[5];
	int m_bandsColors[12];
	void Draw(CDC *pDC, CRect rc);
	Resistor();
	virtual ~Resistor();

};

#endif // !defined(AFX_RESISTOR_H__B100C1CE_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
