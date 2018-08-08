// QCMAideView.h : interface of the CQCMAideView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QCMAIDEVIEW_H__6670AF2D_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QCMAIDEVIEW_H__6670AF2D_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#include "QCMFileClass.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQCMAideView : public CFormView
{
protected: // create from serialization only
	CQCMAideView();
	DECLARE_DYNCREATE(CQCMAideView)

public:
	//{{AFX_DATA(CQCMAideView)
	enum { IDD = IDD_QCMAIDE_FORM };
	CString	m_question;
	CString	m_moyenne;
	//}}AFX_DATA

// Attributes
public:
	CQCMAideDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQCMAideView)
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
	void OnButtonClicked(int nID);
	void InvalidateButtons();
	void InitWindow(int nQuestion);
	int m_nBtnCount;
	CButton *m_pBtnArray;
	void InitButtons();
	virtual ~CQCMAideView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int m_nCurrentPos;
	CQCMFileClass m_qcmClass;
	//{{AFX_MSG(CQCMAideView)
	afx_msg void OnSuivant();
	afx_msg void OnPrecedent();
	afx_msg void OnReset();
	afx_msg void OnFichierAfficherlanote();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in QCMAideView.cpp
inline CQCMAideDoc* CQCMAideView::GetDocument()
   { return (CQCMAideDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QCMAIDEVIEW_H__6670AF2D_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
