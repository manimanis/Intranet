// MediaPlayerTestDlg.h : header file
//

#if !defined(AFX_MEDIAPLAYERTESTDLG_H__E4655C46_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_MEDIAPLAYERTESTDLG_H__E4655C46_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerTestDlg dialog

class CMediaPlayerTestDlg : public CDialog
{
// Construction
public:
	CMediaPlayerTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMediaPlayerTestDlg)
	enum { IDD = IDD_MEDIAPLAYERTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayerTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMediaPlayerTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYERTESTDLG_H__E4655C46_DDC9_11D4_86C8_0000E8EA8C1A__INCLUDED_)
