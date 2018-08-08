// Démonstration TriDoc.cpp : implementation of the CDmonstrationTriDoc class
//

#include "stdafx.h"
#include "Démonstration Tri.h"

#include "Démonstration TriDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriDoc

IMPLEMENT_DYNCREATE(CDmonstrationTriDoc, CDocument)

BEGIN_MESSAGE_MAP(CDmonstrationTriDoc, CDocument)
	//{{AFX_MSG_MAP(CDmonstrationTriDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriDoc construction/destruction

CDmonstrationTriDoc::CDmonstrationTriDoc()
{
	// TODO: add one-time construction code here

}

CDmonstrationTriDoc::~CDmonstrationTriDoc()
{
}

BOOL CDmonstrationTriDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriDoc serialization

void CDmonstrationTriDoc::Serialize(CArchive& ar)
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
// CDmonstrationTriDoc diagnostics

#ifdef _DEBUG
void CDmonstrationTriDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDmonstrationTriDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriDoc commands
