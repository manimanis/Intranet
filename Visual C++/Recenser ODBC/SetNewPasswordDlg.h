#if !defined(AFX_SETNEWPASSWORDDLG_H__8E5FCB24_DB56_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SETNEWPASSWORDDLG_H__8E5FCB24_DB56_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetNewPasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetNewPasswordDlg dialog

class CSetNewPasswordDlg : public CDialog
{
// Construction
public:
	CSetNewPasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetNewPasswordDlg)
	enum { IDD = IDD_PASSWORD_SETDIALOG };
	CString	m_password1;
	CString	m_password2;
	CString	m_login;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetNewPasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetNewPasswordDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETNEWPASSWORDDLG_H__8E5FCB24_DB56_11D4_86C8_0000E8EA8C1A__INCLUDED_)
