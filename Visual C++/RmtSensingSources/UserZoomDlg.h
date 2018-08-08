#if !defined(AFX_USERZOOMDLG_H__B7C62E6E_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_USERZOOMDLG_H__B7C62E6E_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserZoomDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserZoomDlg dialog

class CUserZoomDlg : public CDialog
{
// Construction
public:
	CUserZoomDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserZoomDlg)
	enum { IDD = IDD_USER_ZOOM };
	int		m_editZoom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserZoomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserZoomDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERZOOMDLG_H__B7C62E6E_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
