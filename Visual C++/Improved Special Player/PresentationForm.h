#if !defined(AFX_PRESENTATIONFORM_H__4A9C2DE0_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_PRESENTATIONFORM_H__4A9C2DE0_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PresentationForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPresentationForm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "SpecialPlayerDlg.h"
#include "PersButton.h"

class CPresentationForm : public CFormView
{
protected:
	CPresentationForm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPresentationForm)

// Form Data
public:
	//{{AFX_DATA(CPresentationForm)
	enum { IDD = IDD_PRESENTATIONFORM_FORM };
	CPersButton	m_presentation1;
	CPersButton	m_presentation2;
	CPersButton	m_presentation3;
	CPersButton	m_presentation4;
	CPersButton	m_presentation5;
	CPersButton	m_presentation6;
	CPersButton	m_presentation7;
	CPersButton	m_presentation8;
	CPersButton	m_presentation9;
	CPersButton	m_presentation10;
	//}}AFX_DATA
	CPersButton	*m_presentation[10];

// Attributes
public:

// Operations
public:
	void Ouvrir(CString path);
	void InitPresentationClips();
	void InitPresentationPictures();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPresentationForm)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_wndTop;
	CString m_clipPath[10];
	CSpecialPlayerDlg spDlg;
	virtual ~CPresentationForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPresentationForm)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL dlgCreated;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRESENTATIONFORM_H__4A9C2DE0_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
