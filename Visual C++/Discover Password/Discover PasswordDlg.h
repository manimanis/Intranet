// Discover PasswordDlg.h : header file
//

#if !defined(AFX_DISCOVERPASSWORDDLG_H__5ED05A06_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DISCOVERPASSWORDDLG_H__5ED05A06_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiscoverPasswordDlg dialog

class CDiscoverPasswordDlg : public CDialog
{
// Construction
public:
	CDiscoverPasswordDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDiscoverPasswordDlg)
	enum { IDD = IDD_DISCOVERPASSWORD_DIALOG };
	CString	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiscoverPasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiscoverPasswordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISCOVERPASSWORDDLG_H__5ED05A06_EF97_11D4_86C8_0000E8EA8C1A__INCLUDED_)
