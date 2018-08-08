#if !defined(AFX_PARAMETRESARAN_H__18F83BA0_EC05_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_PARAMETRESARAN_H__18F83BA0_EC05_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ParametresArAn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParametresArAn dialog

class CParametresArAn : public CDialog
{
// Construction
public:
	CString m_winFrPath;
	CString m_winArPath;
	CParametresArAn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParametresArAn)
	enum { IDD = IDD_PARAMETRES_ARABE_FRANCAIS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParametresArAn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParametresArAn)
	afx_msg void OnParamArabe();
	afx_msg void OnParamFrancais();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETRESARAN_H__18F83BA0_EC05_11D4_86C8_0000E8EA8C1A__INCLUDED_)
