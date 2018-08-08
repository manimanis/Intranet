// ImgViewerView.h : interface of the CImgViewerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGVIEWERVIEW_H__198FDAED_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
#define AFX_IMGVIEWERVIEW_H__198FDAED_4508_11D4_98A6_E5B5D3962525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImgViewerView : public CScrollView
{
protected: // create from serialization only
	CImgViewerView();
	DECLARE_DYNCREATE(CImgViewerView)

// Attributes
public:
	CImgViewerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgViewerView)
	public:
	virtual void OnDraw(CDC *pDC);  // overridden to draw this view
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView *pSender, LPARAM lHint, CObject *pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImgViewerView)
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImgViewerView.cpp
inline CImgViewerDoc* CImgViewerView::GetDocument()
   { return (CImgViewerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGVIEWERVIEW_H__198FDAED_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
