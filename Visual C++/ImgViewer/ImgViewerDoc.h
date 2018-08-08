// ImgViewerDoc.h : interface of the CImgViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGVIEWERDOC_H__198FDAEB_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
#define AFX_IMGVIEWERDOC_H__198FDAEB_4508_11D4_98A6_E5B5D3962525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImgViewerDoc : public CDocument
{
protected: // create from serialization only
	CImgViewerDoc();
	DECLARE_DYNCREATE(CImgViewerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgViewerDoc)
	public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	SIZE m_sizeInPix;
	SIZE m_sizeInHiMetric;
	LPPICTURE m_pPicture;
	virtual ~CImgViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImgViewerDoc)
	afx_msg void OnFileProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGVIEWERDOC_H__198FDAEB_4508_11D4_98A6_E5B5D3962525__INCLUDED_)
