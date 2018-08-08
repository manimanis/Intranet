#if !defined(AFX_BACKSIDE_H__044C05EC_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_BACKSIDE_H__044C05EC_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackSide.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackSide view

class CBackSide : public CScrollView
{
protected:
	CBackSide();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBackSide)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackSide)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBackSide();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CBackSide)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKSIDE_H__044C05EC_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
