// RmtSensingView.h : interface of the CRmtSensingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_


#include "BitmapManipulations.h"	// Added by ClassView
#include "RmtSensingDoc.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRmtSensingView : public CScrollView
{
protected: // create from serialization only
	CRmtSensingView();
	DECLARE_DYNCREATE(CRmtSensingView)

// Attributes
public:
	CRmtSensingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetZoom(float newFactor);
	void Expansion(CLookUpTables *lkUpTables);
	virtual ~CRmtSensingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	float factor;
	CMDIChildWnd *wndR;
	CMDIChildWnd *wndG;
	CMDIChildWnd *wndB;
	BOOL copyMode;
	CRect PicRect;
public :
	void Actualiser(BOOL setModifiedFlag = FALSE);
	//{{AFX_MSG(CRmtSensingView)
	afx_msg void OnPictureInfo();
	afx_msg void OnEditCopy();
	afx_msg void OnOutilsExpansionlinaire();
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnOutilsExpansionlogarithmique();
	afx_msg void OnOutilsExpansionexponentielle();
	afx_msg void OnOutilsExpansionlinairesegmente();
	afx_msg void OnOutilsComposantesrgb();
	afx_msg void OnOutilsEgalisation();
	afx_msg void OnOutilsTransformerennoiretblanc();
	afx_msg void OnAffichageZoom10();
	afx_msg void OnAffichageZoom100();
	afx_msg void OnAffichageZoom150();
	afx_msg void OnAffichageZoom25();
	afx_msg void OnAffichageZoom200();
	afx_msg void OnAffichageZoom50();
	afx_msg void OnAffichageZoom400();
	afx_msg void OnAffichageZoom75();
	afx_msg void OnAffichageZoomUser();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnOutilsEstomper();
	afx_msg void OnOutilsContourvertical();
	afx_msg void OnOutilsContourhorizontal();
	afx_msg void OnOutilsRecherchertouslescontours();
	afx_msg void OnZoomFaussecouleur();
	afx_msg void OnOutilsDiminuerlenombredecouleurs();
	afx_msg void OnZoomActualiser();
	//}}AFX_MSG
protected:
	DECLARE_MESSAGE_MAP()
private:
	CRmtSensingDoc *pDoc;
};

#ifndef _DEBUG  // debug version in RmtSensingView.cpp
inline CRmtSensingDoc* CRmtSensingView::GetDocument()
   { return (CRmtSensingDoc*) m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
