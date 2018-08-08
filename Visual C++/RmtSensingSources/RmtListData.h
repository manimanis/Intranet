#if !defined(AFX_RMTLISTDATA_H__F8D9BDD6_6E8A_11D4_B2F7_00400550E7C9__INCLUDED_)
#define AFX_RMTLISTDATA_H__F8D9BDD6_6E8A_11D4_B2F7_00400550E7C9__INCLUDED_

#include "RmtSensingDoc.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RmtListData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRmtListData dialog

class CRmtListData : public CDialog
{
// Construction
public:
	CRmtSensingDoc* pDocument;
	void SetDocument(CRmtSensingDoc* pDoc);
	CRmtListData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRmtListData)
	enum { IDD = IDD_RMTLIST_DLG };
	CListCtrl	m_lstData;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtListData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRmtListData)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTLISTDATA_H__F8D9BDD6_6E8A_11D4_B2F7_00400550E7C9__INCLUDED_)
