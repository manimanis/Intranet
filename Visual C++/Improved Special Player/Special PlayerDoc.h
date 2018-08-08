// Special PlayerDoc.h : interface of the CSpecialPlayerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPECIALPLAYERDOC_H__40968DFA_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_SPECIALPLAYERDOC_H__40968DFA_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSpecialPlayerDoc : public CDocument
{
protected: // create from serialization only
	CSpecialPlayerDoc();
	DECLARE_DYNCREATE(CSpecialPlayerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialPlayerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpecialPlayerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpecialPlayerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALPLAYERDOC_H__40968DFA_DC2B_11D4_86C8_0000E8EA8C1A__INCLUDED_)
