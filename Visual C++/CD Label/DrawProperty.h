#if !defined(AFX_DRAWPROPERTY_H__ABDA2C26_A12D_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_DRAWPROPERTY_H__ABDA2C26_A12D_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawProperty.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawProperty dialog

class CDrawProperty : public CDialog
{
// Construction
public:
	void ModifyCtlColor(CStatic *pStatic, int nColor);
	int m_nColTrace;
	int m_nColFond;
	CDrawProperty(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawProperty)
	enum { IDD = IDD_DRAW_PROPERTIES };
	CStatic	m_ctlTrace;
	CStatic	m_ctlFond;
	CString	m_type;
	BOOL	m_bColFond;
	BOOL	m_bColTrace;
	int		m_nLineWidth;
	int		m_nArrHeight;
	int		m_nArrWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawProperty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDrawProperty)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckFond();
	afx_msg void OnCheckTrace();
	afx_msg void OnBtnFond();
	afx_msg void OnBtnTrace();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPROPERTY_H__ABDA2C26_A12D_11D5_925D_0000E8EA8C1A__INCLUDED_)
