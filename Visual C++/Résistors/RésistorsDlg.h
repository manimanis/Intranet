// RésistorsDlg.h : header file
//

#if !defined(AFX_RSISTORSDLG_H__B100C1C6_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
#define AFX_RSISTORSDLG_H__B100C1C6_2453_11D5_9911_A8DCADD2F70E__INCLUDED_

#include "Resistor.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRsistorsDlg dialog

class CRsistorsDlg : public CDialog
{
// Construction
public:
	void DisplayColors();
	CString m_bandColor[12];
	Resistor r;
	void DisplayBandSliders();
	CRsistorsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRsistorsDlg)
	enum { IDD = IDD_RSISTORS_DIALOG };
	CSliderCtrl	m_bande4Ctrl;
	CSliderCtrl	m_bande3Ctrl;
	CSliderCtrl	m_bande2Ctrl;
	CSliderCtrl	m_bande1Ctrl;
	CSliderCtrl	m_bande0Ctrl;
	CSliderCtrl	m_nbBandesCtrl;
	CString	m_couleur;
	CString	m_resistance;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRsistorsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRsistorsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReleasedcaptureNbBandes(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureBande0(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureBande1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureBande2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureBande3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReleasedcaptureBande4(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSISTORSDLG_H__B100C1C6_2453_11D5_9911_A8DCADD2F70E__INCLUDED_)
