#if !defined(AFX_RECHERCHE_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_RECHERCH_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CRecherche.h : header file
//

#include "SortSearch.h"

//#include "Démonstration TriView.h"

class CDmonstrationTriView;

/////////////////////////////////////////////////////////////////////////////
// CRecherche thread

class CRecherche : public CSortSearch
{
	DECLARE_DYNCREATE(CRecherche)
protected:
	CRecherche();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	BOOL Recherche();
	void Init(CDmonstrationTriView *pView, int nValue, BOOL bOrdreCroissant);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecherche)
	public:
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_nValue;
	CDmonstrationTriView* m_pView;
	virtual ~CRecherche();

	// Generated message map functions
	//{{AFX_MSG(CRecherche)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRecherche_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
