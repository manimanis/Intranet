// Special PlayerDoc.cpp : implementation of the CSpecialPlayerDoc class
//

#include "stdafx.h"
#include "Special Player.h"

#include "Special PlayerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDoc

IMPLEMENT_DYNCREATE(CSpecialPlayerDoc, CDocument)

BEGIN_MESSAGE_MAP(CSpecialPlayerDoc, CDocument)
	//{{AFX_MSG_MAP(CSpecialPlayerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDoc construction/destruction

CSpecialPlayerDoc::CSpecialPlayerDoc()
{
	// TODO: add one-time construction code here

}

CSpecialPlayerDoc::~CSpecialPlayerDoc()
{
}

BOOL CSpecialPlayerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDoc serialization

void CSpecialPlayerDoc::Serialize(CArchive& ar)
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
// CSpecialPlayerDoc diagnostics

#ifdef _DEBUG
void CSpecialPlayerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSpecialPlayerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDoc commands
