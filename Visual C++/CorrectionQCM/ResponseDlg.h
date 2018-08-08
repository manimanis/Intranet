#if !defined(AFX_RESPONSEDLG_H__74DA7DB7_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_RESPONSEDLG_H__74DA7DB7_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResponseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResponseDlg dialog

class CResponseDlg : public CDialog
{
// Construction
public:
	void InvalidateButtons(int nIndex);
	void OnOuvrir();
	int GetIndexBase(int nIndex);
	int m_nCurrentPos;
	void InitResponseArray();
	void InitButtons(int nCount);
	void InitWindow(int nIndex);
	int m_nBtnCount;
	~CResponseDlg();
	CButton *m_pBtnArray;
	CResponseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResponseDlg)
	enum { IDD = IDD_SAISIE_REPONSES };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResponseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_nBtnStateSize;
	char *m_pBtnState;
	int m_nMaxBtnCount;
	int m_nArraySize;
	int *m_pArray;

	// Generated message map functions
	//{{AFX_MSG(CResponseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPrecedent();
	afx_msg void OnSuivant();
	afx_msg void OnFermer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESPONSEDLG_H__74DA7DB7_4DF5_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
