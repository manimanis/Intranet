// Tri_Selection.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "Recherche.h"

#include "Démonstration TriView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecherche

IMPLEMENT_DYNCREATE(CRecherche, CSortSearch)

CRecherche::CRecherche()
{
	m_szName = "Algorithme de recherche";
}

CRecherche::~CRecherche()
{
}



BEGIN_MESSAGE_MAP(CRecherche, CSortSearch)
	//{{AFX_MSG_MAP(CRecherche)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecherche message handlers

void CRecherche::Init(CDmonstrationTriView *pView, int nValue, BOOL bOrdreCroissant)
{
	m_pView = pView;
	m_nValue = nValue;
	m_bEnd = FALSE;
	m_bOrdreCroissant = bOrdreCroissant;
}

int CRecherche::Run() 
{
	if (Recherche())
		AfxMessageBox("Valeur Trouvée");
	else
		AfxMessageBox("Impossible de Trouver cette Valeur");
	
	m_bEnd = TRUE;

	return CSortSearch::Run();
}

BOOL CRecherche::Recherche()
{
	CClientDC dc(m_pView);

	for (int i = 0 ; i < DEMO_TAB_SIZE ; i++)
	{
		m_pView->m_pTabCls->ValueCompare(&dc, i, m_nValue, CMP_EQUAL);
		SuspendThread();

		m_pView->m_pTabCls->ValueDecision(&dc, i, m_nValue, CMP_EQUAL);
		SuspendThread();
		m_pView->RedrawWindow();


		if (m_pView->Tab[i] == m_nValue) return TRUE;
	}

	return FALSE;
}
