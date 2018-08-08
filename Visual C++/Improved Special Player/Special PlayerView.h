// Special PlayerView.h : interface of the CSpecialPlayerView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "mediaplayer2.h"
//}}AFX_INCLUDES

#if !defined(AFX_SPECIALPLAYERVIEW_H__40968DFC_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SPECIALPLAYERVIEW_H__40968DFC_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSpecialPlayerView : public CFormView
{
protected: // create from serialization only
	CSpecialPlayerView();
	DECLARE_DYNCREATE(CSpecialPlayerView)

public:
	//{{AFX_DATA(CSpecialPlayerView)
	enum { IDD = IDD_SPECIALPLAYER_FORM };
	CProgressCtrl	m_progress;
	CMediaPlayer2	m_mplayer;
	//}}AFX_DATA

// Attributes
public:
	CSpecialPlayerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialPlayerView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_wndTop;
	void ShowAll();
	void HideAll();
	int m_convResult;
	void Lecture();
	CString m_resultat;
	CString m_fichier;
	int ConvertJoinToNormal();
	virtual ~CSpecialPlayerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	char m_tempPath[256];
	char m_tempFilePath[256];
	//{{AFX_MSG(CSpecialPlayerView)
	afx_msg void OnFileOpen();
	afx_msg void OnReadyStateChangeMediaplayer1(long ReadyState);
	afx_msg void OnDestroy();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnAffichageToujoursvisible();
	afx_msg void OnUpdateAffichageToujoursvisible(CCmdUI* pCmdUI);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Special PlayerView.cpp
inline CSpecialPlayerDoc* CSpecialPlayerView::GetDocument()
   { return (CSpecialPlayerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALPLAYERVIEW_H__40968DFC_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
