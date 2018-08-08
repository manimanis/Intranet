// CD LabelDoc.h : interface of the CCDLabelDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CDLABELDOC_H__044C05E2_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
#define AFX_CDLABELDOC_H__044C05E2_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCDLabelDoc : public CDocument
{
protected: // create from serialization only
	CCDLabelDoc();
	DECLARE_DYNCREATE(CCDLabelDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDLabelDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCDLabelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCDLabelDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLABELDOC_H__044C05E2_9E24_11D5_925D_0000E8EA8C1A__INCLUDED_)
