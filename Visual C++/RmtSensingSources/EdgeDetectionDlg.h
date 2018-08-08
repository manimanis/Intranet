#if !defined(AFX_EDGEDETECTIONDLG_H__7163FF33_7800_11D4_B306_00400550E7C9__INCLUDED_)
#define AFX_EDGEDETECTIONDLG_H__7163FF33_7800_11D4_B306_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EdgeDetectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEdgeDetectionDlg dialog

class CEdgeDetectionDlg : public CDialog
{
// Construction
public:
	CEdgeDetectionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEdgeDetectionDlg)
	enum { IDD = IDD_EDGEDETECT_PERCENT };
	float	m_percentage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEdgeDetectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEdgeDetectionDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDGEDETECTIONDLG_H__7163FF33_7800_11D4_B306_00400550E7C9__INCLUDED_)
