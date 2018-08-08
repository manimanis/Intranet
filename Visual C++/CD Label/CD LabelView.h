// CD LabelView.h : interface of the CCDLabelView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CDLABELVIEW_H__044C05E4_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_CDLABELVIEW_H__044C05E4_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ObjetsVisuels.h"

class CCDLabelView : public CScrollView
{
protected: // create from serialization only
	CCDLabelView();
	DECLARE_DYNCREATE(CCDLabelView)

// Attributes
public:
	CCDLabelDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDLabelView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_nSelectedObject;
	int m_rCorner;
	CPoint m_cpSelPoint;
	virtual ~CCDLabelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CArray<CObjetsVisuels*, CObjetsVisuels*> Objets;
	CObjetsVisuels *pClipboardObject;
// Generated message map functions
protected:
	//{{AFX_MSG(CCDLabelView)
	afx_msg void OnTexte();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateTexte(CCmdUI* pCmdUI);
	afx_msg void OnProperties();
	afx_msg void OnUpdateProperties(CCmdUI* pCmdUI);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDessin();
	afx_msg void OnAvance();
	afx_msg void OnBack();
	afx_msg void OnBringtoback();
	afx_msg void OnBringtofront();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CD LabelView.cpp
inline CCDLabelDoc* CCDLabelView::GetDocument()
   { return (CCDLabelDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLABELVIEW_H__044C05E4_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
