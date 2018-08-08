#if !defined(AFX_SORTSEARCH_H__418E1A2A_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SORTSEARCH_H__418E1A2A_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SortSearch.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSortSearch thread

class CSortSearch : public CWinThread
{
	DECLARE_DYNCREATE(CSortSearch)
protected:
	CSortSearch();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	CString m_szName;
	BOOL m_bEnd;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortSearch)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bOrdreCroissant;
	virtual ~CSortSearch();

	// Generated message map functions
	//{{AFX_MSG(CSortSearch)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTSEARCH_H__418E1A2A_A556_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
