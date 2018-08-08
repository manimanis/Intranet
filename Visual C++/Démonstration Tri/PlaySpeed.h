#if !defined(AFX_PLAYSPEED_H__7BAFB3A3_A540_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_PLAYSPEED_H__7BAFB3A3_A540_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlaySpeed.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlaySpeed dialog

class CPlaySpeed : public CDialog
{
// Construction
public:
	CPlaySpeed(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlaySpeed)
	enum { IDD = IDD_PLAY_SPEED };
	int		m_nSpeed;
	CString	m_vitesse;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaySpeed)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlaySpeed)
	afx_msg void OnReleasedcaptureSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYSPEED_H__7BAFB3A3_A540_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
