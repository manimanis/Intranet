// Démonstration TriDoc.h : interface of the CDmonstrationTriDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DMONSTRATIONTRIDOC_H__89F281AA_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
#define AFX_DMONSTRATIONTRIDOC_H__89F281AA_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDmonstrationTriDoc : public CDocument
{
protected: // create from serialization only
	CDmonstrationTriDoc();
	DECLARE_DYNCREATE(CDmonstrationTriDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDmonstrationTriDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDmonstrationTriDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDmonstrationTriDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DMONSTRATIONTRIDOC_H__89F281AA_A517_11D5_A8C8_0000E8EA8C1A__INCLUDED_)
