#if !defined(AFX_PROPRIETETEXTE_H__052381C7_9E6B_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_PROPRIETETEXTE_H__052381C7_9E6B_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProprieteTexte.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProprieteTexte dialog

class CProprieteTexte : public CDialog
{
// Construction
public:
	int m_textColor;
	BOOL m_bFontChanged;
	LOGFONT m_logFont;
	CProprieteTexte(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProprieteTexte)
	enum { IDD = IDD_TEXT_PROPERTY };
	CString	m_szText;
	int		m_align;
	int		m_rotation;
	int		m_rotationVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProprieteTexte)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProprieteTexte)
	afx_msg void OnPolice();
	virtual BOOL OnInitDialog();
	afx_msg void OnReleasedcaptureRotation(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPRIETETEXTE_H__052381C7_9E6B_11D5_925D_0000E8EA8C1A__INCLUDED_)
