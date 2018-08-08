// Tri_Selection.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "Tri_Selection.h"

#include "Démonstration TriView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTri_Selection

IMPLEMENT_DYNCREATE(CTri_Selection, CSortSearch)

CTri_Selection::CTri_Selection()
{
	m_szName = "Algorithme de tri par Sélection";
}

CTri_Selection::~CTri_Selection()
{
}

BEGIN_MESSAGE_MAP(CTri_Selection, CSortSearch)
	//{{AFX_MSG_MAP(CTri_Selection)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTri_Selection message handlers

void CTri_Selection::Init(CDmonstrationTriView *pView, BOOL bOrdreCroissant)
{
	m_pView = pView;
	m_bEnd = FALSE;
	m_bOrdreCroissant = bOrdreCroissant;
}

int CTri_Selection::Run() 
{
	Tri_Selection();

	m_bEnd = TRUE;
	
	return CSortSearch::Run();
}

void CTri_Selection::Tri_Selection()
{
	CClientDC dc(m_pView);

	int j, inter, min;
	int nTest;

	if (m_bOrdreCroissant) 
		nTest = CMP_LESS;
	else
		nTest = CMP_GREAT;

	for (int i = 0 ; i < DEMO_TAB_SIZE - 1 ; i++)
	{
		min = i;

		for (j = i + 1 ; j < DEMO_TAB_SIZE ; j++)
		{
			m_pView->m_pTabCls->Compare(&dc, j, min, nTest);
			SuspendThread();

			m_pView->m_pTabCls->Decision(&dc, j, min, nTest);
			SuspendThread();

			m_pView->RedrawWindow();

			if (m_bOrdreCroissant)
			{
				if (m_pView->Tab[j] < m_pView->Tab[min]) min = j;
			}
			else
			{
				if (m_pView->Tab[j] > m_pView->Tab[min]) min = j;
			}
		}

		m_pView->m_pTabCls->Exchange(&dc, i, min);
		SuspendThread();
		m_pView->RedrawWindow();

		inter = m_pView->Tab[i];
		m_pView->Tab[i] = m_pView->Tab[min];
		m_pView->Tab[min] = inter;

		m_pView->m_pTabCls->Draw(&dc);
	}
}
