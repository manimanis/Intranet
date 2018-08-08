#if !defined(AFX_COLORLISTBOX_H__AEC15360_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_COLORLISTBOX_H__AEC15360_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorListBox window

class CColorListBox : public CListBox
{
// Construction
public:
	CColorListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorListBox)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	void AddColorItem(COLORREF color);
	virtual ~CColorListBox();

	// Generated message map functions
protected:
	CBrush blackBrush;
	CBrush whiteBrush;
	//{{AFX_MSG(CColorListBox)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSlectionDslectionner();
	afx_msg void OnSlectionInverserlaslection();
	afx_msg void OnSlectionToutslectionner();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnSelectionCritere();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORLISTBOX_H__AEC15360_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
