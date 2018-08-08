// CD LabelDoc.cpp : implementation of the CCDLabelDoc class
//

#include "stdafx.h"
#include "CD Label.h"

#include "CD LabelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDLabelDoc

IMPLEMENT_DYNCREATE(CCDLabelDoc, CDocument)

BEGIN_MESSAGE_MAP(CCDLabelDoc, CDocument)
	//{{AFX_MSG_MAP(CCDLabelDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDLabelDoc construction/destruction

CCDLabelDoc::CCDLabelDoc()
{
	// TODO: add one-time construction code here

}

CCDLabelDoc::~CCDLabelDoc()
{
}

BOOL CCDLabelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCDLabelDoc serialization

void CCDLabelDoc::Serialize(CArchive& ar)
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
// CCDLabelDoc diagnostics

#ifdef _DEBUG
void CCDLabelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCDLabelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCDLabelDoc commands
