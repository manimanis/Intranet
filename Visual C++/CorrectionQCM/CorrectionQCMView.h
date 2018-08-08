// CorrectionQCMView.h : interface of the CCorrectionQCMView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CORRECTIONQCMVIEW_H__74DA7DAC_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_CORRECTIONQCMVIEW_H__74DA7DAC_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCorrectionQCMView : public CFormView
{
protected: // create from serialization only
	CCorrectionQCMView();
	DECLARE_DYNCREATE(CCorrectionQCMView)

public:
	//{{AFX_DATA(CCorrectionQCMView)
	enum{ IDD = IDD_CORRECTIONQCM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CCorrectionQCMDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCorrectionQCMView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCorrectionQCMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCorrectionQCMView)
	afx_msg void OnEtape1();
	afx_msg void OnEtape2();
	afx_msg void OnEtape3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CorrectionQCMView.cpp
inline CCorrectionQCMDoc* CCorrectionQCMView::GetDocument()
   { return (CCorrectionQCMDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CORRECTIONQCMVIEW_H__74DA7DAC_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
