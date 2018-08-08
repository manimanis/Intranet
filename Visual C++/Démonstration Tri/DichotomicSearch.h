// DichotomicSearch.h: interface for the CDichotomicSearch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DICHOTOMICSEARCH_H__418E1A2B_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DICHOTOMICSEARCH_H__418E1A2B_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SortSearch.h"

class CDmonstrationTriView;

class CDichotomicSearch : public CSortSearch  
{
	DECLARE_DYNCREATE(CDichotomicSearch)
public:
	BOOL Recherche();
	int Run();
	CDichotomicSearch();
	virtual ~CDichotomicSearch();
	void Init(CDmonstrationTriView *pView, int nValue, BOOL bOrdreCroissant);
protected:
	int m_nValue;
	CDmonstrationTriView* m_pView;
};

#endif // !defined(AFX_DICHOTOMICSEARCH_H__418E1A2B_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
