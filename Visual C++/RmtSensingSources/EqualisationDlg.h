// EqualisationDlg.h: interface for the CEqualisationDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EQUALISATIONDLG_H__B7C62E6B_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_EQUALISATIONDLG_H__B7C62E6B_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OptimisationsDlg.h"

class CEqualisationDlg : public COptimisationsDlg  
{
public:
	void OnChangeMaxPoints();
	void Recalc();
	void InitPoints(int *picInf, int *cumInf);
	CEqualisationDlg();
	virtual ~CEqualisationDlg();

};

#endif // !defined(AFX_EQUALISATIONDLG_H__B7C62E6B_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
