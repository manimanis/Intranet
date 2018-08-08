// QCMAideDoc.cpp : implementation of the CQCMAideDoc class
//

#include "stdafx.h"
#include "QCMAide.h"

#include "QCMAideDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQCMAideDoc

IMPLEMENT_DYNCREATE(CQCMAideDoc, CDocument)

BEGIN_MESSAGE_MAP(CQCMAideDoc, CDocument)
	//{{AFX_MSG_MAP(CQCMAideDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQCMAideDoc construction/destruction

CQCMAideDoc::CQCMAideDoc()
{
	// TODO: add one-time construction code here

}

CQCMAideDoc::~CQCMAideDoc()
{
}

BOOL CQCMAideDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CQCMAideDoc serialization

void CQCMAideDoc::Serialize(CArchive& ar)
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
// CQCMAideDoc diagnostics

#ifdef _DEBUG
void CQCMAideDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CQCMAideDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQCMAideDoc commands

CString CQCMAideDoc::GetQCMFileName()
{
	CFileDialog cfDlg(TRUE);

	cfDlg.DoModal();

	return cfDlg.GetPathName();
}
