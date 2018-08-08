// Apache StarterDlg.h : header file
//

#if !defined(AFX_APACHESTARTERDLG_H__A2D8DBE8_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_APACHESTARTERDLG_H__A2D8DBE8_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CApacheStarterDlg dialog

#include <tlhelp32.h>

class CApacheStarterDlg : public CDialog
{
// Construction
public:
	void KillAllPHP();
	void OnStop();
	void OnStart();
	void OnShowDlg();
	void ModifyTrayIcon(int uID);
	void OnDemarrerArreter();
	void OnTrayNotification(WPARAM wParam, LPARAM lParam);
	void DeleteTrayIcon(int uID);
	void AddTrayIcon(int uID);
	CString m_szExec;
	BOOL m_state;
	BOOL IsStarted();
	void OnCancel();
	void OnOK();
	CApacheStarterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CApacheStarterDlg)
	enum { IDD = IDD_APACHESTARTER_DIALOG };
	CString	m_etat;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApacheStarterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CApacheStarterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnParams();
	afx_msg void OnQuitter();
	afx_msg void OnCachedialog();
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APACHESTARTERDLG_H__A2D8DBE8_5CFD_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
