// MulExtDocTmp.cpp
//
// Microsoft KB Articles:
// Q141921 - HOWTO: How to Support Two File Extensions per MFC Document Type
// Q198538 - DocMgrEx.exe Assoc Multiple File Extensions w/1 Doc Type


#include "stdafx.h"
#include <..\src\afximpl.h>		// AfxComparePath
#include "MulExtDocTmp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BOOL CMultiExtSDTemplate::GetDocString(CString &rString,
									   enum DocStringIndex i) const
{
	if (::AfxExtractSubString(rString, m_strDocStrings, static_cast<int>(i)))
	{
		if (i == CDocTemplate::filterExt)
			rString.Replace(_T(";"), _T(";*"));
		
		return TRUE;
	}
	else
		return FALSE;
}

CDocTemplate::Confidence CMultiExtSDTemplate::MatchDocType(LPCTSTR lpszPathName,
														   CDocument *&rpDocMatch)
{
	ASSERT(lpszPathName != NULL);

	rpDocMatch = NULL;

	// go through all documents
	POSITION pos = this->GetFirstDocPosition();
	while (pos != NULL)
	{
		CDocument *pDoc = this->GetNextDoc(pos);
		if (::AfxComparePath(pDoc->GetPathName(), lpszPathName))
		{
			// already open
			rpDocMatch = pDoc;
            return yesAlreadyOpen;
		}
	}

    // deal with multiple extensions in the template filter
	// see if it matches our default suffix
	CString strMultiFilterExt;
	if (this->GetDocString(strMultiFilterExt, CDocTemplate::filterExt) &&
	    !strMultiFilterExt.IsEmpty())
	{
		strMultiFilterExt.Replace(_T(";*"), _T(";"));

        CString strFilterExt;
        for (int i = 0;
			 ::AfxExtractSubString(strFilterExt, strMultiFilterExt, i, _T(';'));
			 i++)
        {
		    // see if extension matches
		    ASSERT(strFilterExt[0] == _T('.'));

			LPCTSTR lpszDot = ::_tcsrchr(lpszPathName, _T('.'));
			if (lpszDot != NULL && ::lstrcmpi(lpszDot, strFilterExt) == 0)
                return yesAttemptNative; // extension matches, looks like ours
        }
	}

	// otherwise we will guess it may work
	return yesAttemptForeign;
}
