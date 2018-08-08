// FileJoinDlg.h : header file
//

#if !defined(AFX_FILEJOINDLG_H__40968DE6_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_FILEJOINDLG_H__40968DE6_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileJoinDlg dialog

class CFileJoinDlg : public CDialog
{
// Construction
public:
	void ConvertJoinToNormal();
	void ConvertNormalToJoin();
	CFileJoinDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileJoinDlg)
	enum { IDD = IDD_FILEJOIN_DIALOG };
	CProgressCtrl	m_progress;
	CString	m_resultat;
	CString	m_fichier;
	UINT	m_taille;
	UINT	m_taux;
	int		m_sTaille;
	int		m_sTaux;
	int		m_jointonormal;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileJoinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileJoinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnParres();
	afx_msg void OnParfichier();
	afx_msg void OnParresultat();
	afx_msg void OnConvertir();
	afx_msg void OnCustomdrawTaillefragments(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawTauxfragmentation(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeFichier();
	afx_msg void OnChangeResultat();
	afx_msg void OnJointonormal();
	afx_msg void OnNormaltojoin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEJOINDLG_H__40968DE6_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
