#if !defined(AFX_COLORSELECTIONCRITERES_H__DE9028E2_7B40_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_COLORSELECTIONCRITERES_H__DE9028E2_7B40_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorSelectionCriteres.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorSelectionCriteres dialog

class CColorSelectionCriteres : public CDialog
{
// Construction
public:
	CColorSelectionCriteres(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CColorSelectionCriteres)
	enum { IDD = IDD_CRITEREDESELECTION };
	BOOL	m_selectAll;
	UINT	m_bleuMax;
	UINT	m_bleuMin;
	UINT	m_rougeMax;
	UINT	m_rougeMin;
	UINT	m_vertMax;
	UINT	m_vertMin;
	//}}AFX_DATA
	CEdit	m_bleuMaxCtrl;
	CEdit	m_bleuMinCtrl;
	CEdit	m_rougeMaxCtrl;
	CEdit	m_rougeMinCtrl;
	CEdit	m_vertMaxCtrl;
	CEdit	m_vertMinCtrl;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorSelectionCriteres)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColorSelectionCriteres)
	afx_msg void OnToutSelectionner();
	virtual void OnOK();
	afx_msg void OnChangeBleuMin();
	afx_msg void OnChangeBleuMax();
	afx_msg void OnChangeVertMin();
	afx_msg void OnChangeVertMax();
	afx_msg void OnChangeRougeMin();
	afx_msg void OnChangeRougeMax();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSELECTIONCRITERES_H__DE9028E2_7B40_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
