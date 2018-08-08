// Tri_Bulles.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "Tri_Bulles.h"

#include "Démonstration TriView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTri_Bulles

IMPLEMENT_DYNCREATE(CTri_Bulles, CSortSearch)

CTri_Bulles::CTri_Bulles()
{
	m_szName = "Algorithme de tri à Bulles";
}

CTri_Bulles::~CTri_Bulles()
{
}

BEGIN_MESSAGE_MAP(CTri_Bulles, CSortSearch)
	//{{AFX_MSG_MAP(CTri_Bulles)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTri_Bulles message handlers

void CTri_Bulles::Init(CDmonstrationTriView *pView, BOOL bOrdreCroissant)
{
	m_pView = pView;
	m_bEnd = FALSE;
	m_bOrdreCroissant = bOrdreCroissant;
}

int CTri_Bulles::Run() 
{
	Tri_Bulles();
	
	m_bEnd = TRUE;

	return CWinThread::Run();
}

void CTri_Bulles::Tri_Bulles()
{
	CClientDC dc(m_pView);

	int j, inter, nTest;

	if (m_bOrdreCroissant) 
		nTest = CMP_LESS;
	else
		nTest = CMP_GREAT;

	for (int i = 0 ; i < DEMO_TAB_SIZE - 1 ; i++)
	{
		m_pView->m_pTabCls->Compare(&dc, i + 1, i, nTest);
		SuspendThread();
		m_pView->m_pTabCls->Decision(&dc, i + 1, i, nTest);
		SuspendThread();
		m_pView->RedrawWindow();

		if (m_bOrdreCroissant)
		{
			if (m_pView->Tab[i + 1] < m_pView->Tab[i])
			{
				j = i;
				do
				{
					m_pView->m_pTabCls->Exchange(&dc, j + 1, j);
					SuspendThread();
					m_pView->RedrawWindow();

					inter = m_pView->Tab[j + 1];
					m_pView->Tab[j + 1] = m_pView->Tab[j];
					m_pView->Tab[j] = inter;

					m_pView->m_pTabCls->Draw(&dc);

					j--;

					m_pView->m_pTabCls->Compare(&dc, j + 1, j, nTest);
					SuspendThread();
					m_pView->m_pTabCls->Decision(&dc, j + 1, j, nTest);
					SuspendThread();
					m_pView->RedrawWindow();

				} while ((j + 1) > 0 && (m_pView->Tab[j + 1] < m_pView->Tab[j]));
			}
		}
		else
		{
			if (m_pView->Tab[i + 1] > m_pView->Tab[i])
			{
				j = i;
				do
				{
					m_pView->m_pTabCls->Exchange(&dc, j + 1, j);
					SuspendThread();
					m_pView->RedrawWindow();

					inter = m_pView->Tab[j + 1];
					m_pView->Tab[j + 1] = m_pView->Tab[j];
					m_pView->Tab[j] = inter;

					m_pView->m_pTabCls->Draw(&dc);

					j--;

					m_pView->m_pTabCls->Compare(&dc, j + 1, j, nTest);
					SuspendThread();
					m_pView->m_pTabCls->Decision(&dc, j + 1, j, nTest);
					SuspendThread();
					m_pView->RedrawWindow();

				} while ((j + 1) > 0 && (m_pView->Tab[j + 1] > m_pView->Tab[j]));
			}
		}
	}
}
