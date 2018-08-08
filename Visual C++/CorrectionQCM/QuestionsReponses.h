#if !defined(AFX_QUESTIONSREPONSES_H__74DA7DB8_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QUESTIONSREPONSES_H__74DA7DB8_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QuestionsReponses.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuestionsReponses dialog

class CQuestionsReponses : public CDialog
{
// Construction
public:
	void InitList();
	void SetQuestionCount(int nCount);
	int m_nQuestionCount;
	CQuestionsReponses(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuestionsReponses)
	enum { IDD = IDD_QUESTREPONSES };
	CListCtrl	m_questionList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestionsReponses)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuestionsReponses)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkQuestionList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickQuestionList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnFermer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTIONSREPONSES_H__74DA7DB8_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
