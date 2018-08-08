#if !defined(AFX_RMTLISTFORM_H__A16AF573_6EA5_11D4_B2F7_00400550E7C9__INCLUDED_)
#define AFX_RMTLISTFORM_H__A16AF573_6EA5_11D4_B2F7_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RmtListForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRmtListForm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CRmtListForm : public CFormView
{
protected:
	CRmtListForm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRmtListForm)

// Form Data
public:
	//{{AFX_DATA(CRmtListForm)
	enum { IDD = IDD_RMTLISTFORM_FORM };
	CListCtrl	m_lstData2;
	CListCtrl	m_lstData;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtListForm)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRmtListForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRmtListForm)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTLISTFORM_H__A16AF573_6EA5_11D4_B2F7_00400550E7C9__INCLUDED_)
