#if !defined(AFX_PARAMETRES_H__A380E721_EBBC_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_PARAMETRES_H__A380E721_EBBC_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Parametres.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParametres dialog

class CParametres : public CDialog
{
// Construction
public:
	CParametres(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParametres)
	enum { IDD = IDD_PARAMETRES };
	CString	m_path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParametres)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParametres)
	afx_msg void OnParcourir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETRES_H__A380E721_EBBC_11D4_86C8_0000E8EA8C1A__INCLUDED_)
