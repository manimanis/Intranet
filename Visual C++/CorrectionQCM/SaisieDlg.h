#if !defined(AFX_SAISIEDLG_H__74DA7DB3_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_SAISIEDLG_H__74DA7DB3_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaisieDlg.h : header file
//

#include "MyTreeCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CSaisieDlg dialog

class CSaisieDlg : public CDialog
{
// Construction
public:
	void FixQuestionsNumber(int iNumber);
	CImageList m_imgList;
	CSaisieDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSaisieDlg)
	enum { IDD = IDD_SAISIE_DLG };
	CMyTreeCtrl	m_questionTree;
	CSpinButtonCtrl	m_spinCtrl;
	int		m_questionCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaisieDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSaisieDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeQuestionCountBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAISIEDLG_H__74DA7DB3_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
