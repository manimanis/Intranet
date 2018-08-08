// Recenser ODBCDlg.h : header file
//

#if !defined(AFX_RECENSERODBCDLG_H__0CED5746_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_RECENSERODBCDLG_H__0CED5746_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRecenserODBCDlg dialog

class CRecenserODBCDlg : public CDialog
{
// Construction
public:
	CString m_dataDesc;
	CString m_dataPath;
	CString m_dataSource;
	int RegisterIt();
	long FillListControl();
	CRecenserODBCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRecenserODBCDlg)
	enum { IDD = IDD_RECENSERODBC_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecenserODBCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRecenserODBCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNouveau();
	afx_msg void OnSupprimer();
	afx_msg void OnPassword();
	afx_msg void OnModifier();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECENSERODBCDLG_H__0CED5746_DB4E_11D4_86C8_0000E8EA8C1A__INCLUDED_)
