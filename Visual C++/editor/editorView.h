// editorView.h : interface of the CEditorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITORVIEW_H__B50096AE_2D3C_11D5_9911_A496D723677B__INCLUDED_)
#define AFX_EDITORVIEW_H__B50096AE_2D3C_11D5_9911_A496D723677B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SELECT_NONE		0
#define SELECT_BEGIN	1
#define SELECTING		2
#define SELECT_END		3

class CEditorView : public CView
{
protected: // create from serialization only
	CEditorView();
	DECLARE_DYNCREATE(CEditorView)

// Attributes
public:
	CEditorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnSelection(CDC *pDC, int sel = TRUE);
	CString GetString(int nLine, int startSel, int endSel);
	void GetSelection(CRect rc, CString &str);
	CPoint m_ptSelPos;
	void SetModified();
	void OnDeleteKey();
	void OnHomeEndKey(int nChar);
	void OnUpDownKey(int nChar);
	void OnRightLeftKey(int nChar);
	void OnBackspaceKey();
	void OnOtherChar(int nChar);
	void OnTabulationKey();
	void OnEnterKey(BOOL bIndent = TRUE);
	CPoint GetSelectedPart(int nLine);
	CString DrawTabs(CString str);
	void DrawString(CDC* pDC, CPoint point, int nLine, int startSel, int endSel, int from = 0);
	void EditPosValidityVerif(CDC *pDC);
	int IndentLine(int nLine, int fromLine, int curPos);
	int GetCharRange(int editPos, int nLine);
	int GetHomePos(int firstPos, int nLine);
	CString GetString(int nLine, int from);
	void SetCaretAt(CPoint point);
	int GetCharPos(int point, int nChar, int nLine);
	void DrawString(CDC *pDC, CPoint point, CString& str);
	virtual ~CEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int m_selState;
	CRect m_rcSelection;
	HCURSOR hCursor;
	int m_WindowMax;
	CPoint m_ptEditPos;
	CPoint m_ptTextPos;
	CPoint m_ptCurPos;
	CSize m_charSize;
	CFont m_ftFont;
	CArray<CString, CString> *m_pArrayText;
	//{{AFX_MSG(CEditorView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in editorView.cpp
inline CEditorDoc* CEditorView::GetDocument()
   { return (CEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORVIEW_H__B50096AE_2D3C_11D5_9911_A496D723677B__INCLUDED_)
