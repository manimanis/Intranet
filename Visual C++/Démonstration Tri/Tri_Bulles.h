#if !defined(AFX_TRI_BULLES_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_TRI_BULLES_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tri_Bulles.h : header file
//

//#include "Démonstration TriView.h"

#include "SortSearch.h"

class CDmonstrationTriView;

/////////////////////////////////////////////////////////////////////////////
// CTri_Bulles thread

class CTri_Bulles : public CSortSearch
{
	DECLARE_DYNCREATE(CTri_Bulles)
protected:
	CTri_Bulles();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	void Tri_Bulles();
	void Init(CDmonstrationTriView *pView, BOOL bOrdreCroissant);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTri_Bulles)
	public:
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDmonstrationTriView* m_pView;
	virtual ~CTri_Bulles();

	// Generated message map functions
	//{{AFX_MSG(CTri_Bulles)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRI_BULLES_H__47F2D549_A524_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
