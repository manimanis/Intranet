// MulExtDocTmp.h : interface of the CMultiExtSDTemplate class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULEXTDOCTMP_H__620B8302_450D_11D4_98A6_E5B5D3962525__INCLUDED_)
#define AFX_MULEXTDOCTMP_H__620B8302_450D_11D4_98A6_E5B5D3962525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiExtSDTemplate : public CSingleDocTemplate
{
public:
	CMultiExtSDTemplate(UINT nIDResource, CRuntimeClass *pDocClass,
		CRuntimeClass *pFrameClass, CRuntimeClass *pViewClass) :
	CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
	{ };

	virtual BOOL GetDocString(CString &rString, enum DocStringIndex index) const;
	virtual Confidence MatchDocType(LPCTSTR lpszPathName, CDocument *&rpDocMatch);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULEXTDOCTMP_H__620B8302_450D_11D4_98A6_E5B5D3962525__INCLUDED_)
