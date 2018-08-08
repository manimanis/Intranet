// RebooterDlg.h : header file
//

#if !defined(AFX_REBOOTERDLG_H__07882F06_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_REBOOTERDLG_H__07882F06_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRebooterDlg dialog

class CRebooterDlg : public CDialog
{
// Construction
public:
	CRebooterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRebooterDlg)
	enum { IDD = IDD_REBOOTER_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRebooterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRebooterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REBOOTERDLG_H__07882F06_5367_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
