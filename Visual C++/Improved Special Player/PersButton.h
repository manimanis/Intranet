#if !defined(AFX_PERSBUTTON_H__4A9C2DE4_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_PERSBUTTON_H__4A9C2DE4_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersButton window

class CPersButton : public CButton
{
// Construction
public:
	CPersButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL
private:
	HBITMAP hBmp[3];
	BOOL Capturing;
	BOOL Over;
	CBitmap BmpOver;
	CBitmap BmpEnf;
	CBitmap BmpNorm;

// Implementation
public:
	void SetImages(CString Normal, CString Enfoncee, CString Over);
	void DessinerFocus();
	void DessinerImage(CBitmap *pBmp);
	void SetImages(int ID_Norm, int ID_Enf, int ID_Over);
	virtual ~CPersButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPersButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSBUTTON_H__4A9C2DE4_DCF3_11D4_86C8_0000E8EA8C1A__INCLUDED_)
