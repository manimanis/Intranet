#if !defined(AFX_FAKECOLORSDIALOG_H__14335624_7A4E_11D4_B308_00400550E7C9__INCLUDED_)
#define AFX_FAKECOLORSDIALOG_H__14335624_7A4E_11D4_B308_00400550E7C9__INCLUDED_

#include "RmtSensingDoc.h"
#include "ColorListBox.h"
#include "ColorBox.h"
#include "Common.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FakeColorsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFakeColorsDialog dialog

class CFakeColorsDialog : public CDialog
{
// Construction
public:
	COLORREF color;
	void InitColorTree(int count, COLORREF* colors);
	void SetDocument(CRmtSensingDoc *pDoc);
	CFakeColorsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFakeColorsDialog)
	enum { IDD = IDD_FAKECOLORS };
	CColorBox	m_selectedColor;
	CColorListBox	m_colorList;
	CButton	m_choisirUneCouleur;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFakeColorsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_colorCount;
	COLORREF *ColorArray;
	CRmtSensingDoc *m_pDoc;

	// Generated message map functions
	//{{AFX_MSG(CFakeColorsDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnChoisirunecouleur();
	virtual void OnOK();
	//}}AFX_MSG
public:
	afx_msg void OnSelectionCritere();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAKECOLORSDIALOG_H__14335624_7A4E_11D4_B308_00400550E7C9__INCLUDED_)
