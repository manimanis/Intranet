// CorrectionQCMDoc.cpp : implementation of the CCorrectionQCMDoc class
//

#include "stdafx.h"
#include "CorrectionQCM.h"

#include "CorrectionQCMDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMDoc

IMPLEMENT_DYNCREATE(CCorrectionQCMDoc, CDocument)

BEGIN_MESSAGE_MAP(CCorrectionQCMDoc, CDocument)
	//{{AFX_MSG_MAP(CCorrectionQCMDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMDoc construction/destruction

CCorrectionQCMDoc::CCorrectionQCMDoc()
{
	// TODO: add one-time construction code here

}

CCorrectionQCMDoc::~CCorrectionQCMDoc()
{
}

BOOL CCorrectionQCMDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMDoc serialization

void CCorrectionQCMDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMDoc diagnostics

#ifdef _DEBUG
void CCorrectionQCMDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCorrectionQCMDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMDoc commands
