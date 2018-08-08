// QCMAideDoc.h : interface of the CQCMAideDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QCMAIDEDOC_H__6670AF2B_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QCMAIDEDOC_H__6670AF2B_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQCMAideDoc : public CDocument
{
protected: // create from serialization only
	CQCMAideDoc();
	DECLARE_DYNCREATE(CQCMAideDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQCMAideDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetQCMFileName();
	virtual ~CQCMAideDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQCMAideDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QCMAIDEDOC_H__6670AF2B_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
