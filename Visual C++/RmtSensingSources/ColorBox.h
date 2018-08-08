#if !defined(AFX_COLORBOX_H__AEC15364_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_COLORBOX_H__AEC15364_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorBox window

class CColorBox : public CStatic
{
// Construction
public:
	CColorBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetSelection(COLORREF color);
	virtual ~CColorBox();

	// Generated message map functions
protected:
	COLORREF selection;
	//{{AFX_MSG(CColorBox)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORBOX_H__AEC15364_7ABD_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
