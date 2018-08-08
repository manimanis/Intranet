// Démonstration TriView.h : interface of the CDmonstrationTriView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DMONSTRATIONTRIVIEW_H__89F281AC_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DMONSTRATIONTRIVIEW_H__89F281AC_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#include "TableauClass.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TableauClass.h"

class CDmonstrationTriDoc;

#define DEMO_TAB_SIZE	11

class CDmonstrationTriView : public CView
{
protected: // create from serialization only
	CDmonstrationTriView();
	DECLARE_DYNCREATE(CDmonstrationTriView)

// Attributes
public:
	CDmonstrationTriDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDmonstrationTriView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bOrdreCroissant;
	BOOL IsSorted();
	void Scramble();
	void WndMessages();
	CTableauClass *m_pTabCls;
	int Tab[DEMO_TAB_SIZE];
	virtual ~CDmonstrationTriView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int m_timeBase;
	CWinThread *m_pThread;
	//{{AFX_MSG(CDmonstrationTriView)
	afx_msg void OnBubbleSort();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPlay();
	afx_msg void OnUpdatePlay(CCmdUI* pCmdUI);
	afx_msg void OnStop();
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnNext();
	afx_msg void OnUpdateNext(CCmdUI* pCmdUI);
	afx_msg void OnScramble();
	afx_msg void OnUpdateScramble(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBubbleSort(CCmdUI* pCmdUI);
	afx_msg void OnEject();
	afx_msg void OnUpdateEject(CCmdUI* pCmdUI);
	afx_msg void OnSelectionSort();
	afx_msg void OnUpdateSelectionSort(CCmdUI* pCmdUI);
	afx_msg void OnDemoSpeed();
	afx_msg void OnSearchValue();
	afx_msg void OnUpdateSearchValue(CCmdUI* pCmdUI);
	afx_msg void OnDicoSearch();
	afx_msg void OnUpdateDicoSearch(CCmdUI* pCmdUI);
	afx_msg void OnOrdreCroissant();
	afx_msg void OnUpdateOrdreCroissant(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Démonstration TriView.cpp
inline CDmonstrationTriDoc* CDmonstrationTriView::GetDocument()
   { return (CDmonstrationTriDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DMONSTRATIONTRIVIEW_H__89F281AC_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
