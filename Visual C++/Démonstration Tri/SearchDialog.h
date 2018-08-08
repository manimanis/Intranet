#if !defined(AFX_SEARCHDIALOG_H__418E1A20_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SEARCHDIALOG_H__418E1A20_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDialog.h : header file
//

class CDmonstrationTriView;

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog dialog

class CSearchDialog : public CDialog
{
// Construction
public:
	CSearchDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDialog)
	enum { IDD = IDD_SEARCH_DIALOG };
	CListBox	m_ctlList;
	int		m_nVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDmonstrationTriView* m_pView;

	// Generated message map functions
	//{{AFX_MSG(CSearchDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTabList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDIALOG_H__418E1A20_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
