#if !defined(AFX_WAITDIALOG_H__14335623_7A4E_11D4_B308_00400550E7C9__INCLUDED_)
#define AFX_WAITDIALOG_H__14335623_7A4E_11D4_B308_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WaitDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWaitDialog dialog

class CWaitDialog : public CDialog
{
// Construction
public:
	BOOL Create(CWnd* pWnd);
	CWaitDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWaitDialog)
	enum { IDD = IDD_WAITDIALOG };
	CProgressCtrl	m_progression;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaitDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWaitDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAITDIALOG_H__14335623_7A4E_11D4_B308_00400550E7C9__INCLUDED_)
