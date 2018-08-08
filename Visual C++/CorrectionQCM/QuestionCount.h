#if !defined(AFX_QUESTIONCOUNT_H__74DA7DB9_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QUESTIONCOUNT_H__74DA7DB9_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QuestionCount.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuestionCount dialog

class CQuestionCount : public CDialog
{
// Construction
public:
	void SetQuestionText(CString szText);
	CQuestionCount(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuestionCount)
	enum { IDD = IDD_QUESTION_COUNT_DLG };
	int		m_nCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestionCount)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_szText;

	// Generated message map functions
	//{{AFX_MSG(CQuestionCount)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTIONCOUNT_H__74DA7DB9_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
