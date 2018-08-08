// DichotomicSearch.cpp: implementation of the CDichotomicSearch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "DichotomicSearch.h"

#include "Démonstration TriView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CDichotomicSearch, CSortSearch)

CDichotomicSearch::CDichotomicSearch()
{
	m_szName = "Algorithme de recherche Dichotomique";
}

CDichotomicSearch::~CDichotomicSearch()
{

}

int CDichotomicSearch::Run()
{
	if (Recherche())
		AfxMessageBox("Valeur Trouvée");
	else
		AfxMessageBox("Impossible de Trouver cette Valeur");

	m_bEnd = TRUE;	

	return CSortSearch::Run();
}

void CDichotomicSearch::Init(CDmonstrationTriView *pView, int nValue, BOOL bOrdreCroissant)
{
	m_pView = pView;
	m_nValue = nValue;
	m_bEnd = FALSE;
	m_bOrdreCroissant = bOrdreCroissant;
}

BOOL CDichotomicSearch::Recherche()
{
	CClientDC dc(m_pView);
	int left = 0, right = DEMO_TAB_SIZE - 1, mid;
	BOOL bTrouve = FALSE;

	do
	{
		mid = (left + right) / 2;

		m_pView->m_pTabCls->ValueCompare(&dc, mid, m_nValue, CMP_EQUAL);
		SuspendThread();

		m_pView->m_pTabCls->ValueDecision(&dc, mid, m_nValue, CMP_EQUAL);
		SuspendThread();
		m_pView->RedrawWindow();

		if (m_nValue == m_pView->Tab[mid]) return TRUE;

		if (m_bOrdreCroissant)
		{
			if (m_nValue > m_pView->Tab[mid]) 
				left = mid + 1;
			else
				right = mid - 1;	
		}
		else
		{
			if (m_nValue < m_pView->Tab[mid]) 
				left = mid + 1;
			else
				right = mid - 1;	
		}

	} while (((left + right) / 2) != mid);

	return FALSE;
}
