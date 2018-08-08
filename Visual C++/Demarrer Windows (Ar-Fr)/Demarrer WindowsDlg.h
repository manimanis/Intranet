// Demarrer WindowsDlg.h : header file
//

#if !defined(AFX_DEMARRERWINDOWSDLG_H__CD42BD86_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DEMARRERWINDOWSDLG_H__CD42BD86_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDemarrerWindowsDlg dialog

class CDemarrerWindowsDlg : public CDialog
{
// Construction
public:
	CDemarrerWindowsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDemarrerWindowsDlg)
	enum { IDD = IDD_DEMARRERWINDOWS_DIALOG };
	int		m_rebootSystem;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemarrerWindowsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_winFrPath;
	CString m_winArPath;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemarrerWindowsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReboot();
	afx_msg void OnParametres();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMARRERWINDOWSDLG_H__CD42BD86_EBB8_11D4_86C8_0000E8EA8C1A__INCLUDED_)
