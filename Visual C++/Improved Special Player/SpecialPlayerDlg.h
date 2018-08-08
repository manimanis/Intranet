//{{AFX_INCLUDES()
#include "mediaplayer2.h"
//}}AFX_INCLUDES
#if !defined(AFX_SPECIALPLAYERDLG_H__2F5E7FC3_DD88_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SPECIALPLAYERDLG_H__2F5E7FC3_DD88_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialPlayerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDlg dialog

class CSpecialPlayerDlg : public CDialog
{
// Construction
public:	
	HICON m_hIcon;
	CString m_fichier;
	void Lecture();
	int  ConvertJoinToNormal();
	void ShowAll();
	void HideAll();
	CSpecialPlayerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpecialPlayerDlg)
	enum { IDD = IDD_SPECIALPLAYER };
	CProgressCtrl	m_progress;
	CMediaPlayer2	m_mplayer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_resultat;
	char m_tempPath[256];
	char m_tempFilePath[256];
	// Generated message map functions
	//{{AFX_MSG(CSpecialPlayerDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnDisplayModeChangeMediaplayer1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALPLAYERDLG_H__2F5E7FC3_DD88_11D4_86C8_0000E8EA8C1A__INCLUDED_)
