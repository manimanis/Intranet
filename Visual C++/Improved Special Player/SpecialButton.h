#if !defined(AFX_SPECIALBUTTON_H__4A9C2DE3_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SPECIALBUTTON_H__4A9C2DE3_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialButton window

class CSpecialButton : public CStatic
{
// Construction
public:
	CSpecialButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpecialButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpecialButton)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALBUTTON_H__4A9C2DE3_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
