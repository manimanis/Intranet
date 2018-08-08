// RmtSensingDoc.cpp : implementation of the CRmtSensingDoc class
//

#include "stdafx.h"
#include "RmtSensing.h"

#include "RmtSensingDoc.h"
// #include "PictureHistogrammeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc

IMPLEMENT_DYNCREATE(CRmtSensingDoc, CDocument)

BEGIN_MESSAGE_MAP(CRmtSensingDoc, CDocument)
	//{{AFX_MSG_MAP(CRmtSensingDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc construction/destruction

CRmtSensingDoc::CRmtSensingDoc()
{
	RComponent = GComponent = BComponent = FALSE;
}

CRmtSensingDoc::~CRmtSensingDoc()
{
}

BOOL CRmtSensingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	AfxMessageBox("Il est interdit de créer une nouvelle instance\n Ouvrir une image bitmap.");
	
	return FALSE;
}



/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc serialization
void CRmtSensingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		BITMAP bm; bmpManip.GetCBitmap()->GetBitmap(&bm);

		ar.Write(bmpManip.GetBitmapFileHeader(), sizeof(BITMAPFILEHEADER));
		ar.Write(bmpManip.GetBitmapInfoHeader(), sizeof(BITMAPINFOHEADER));
		ar.Write(bm.bmBits, bmpManip.GetHeight() * bmpManip.GetWidthBytes());
	}
	else
	{
		// TODO
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc diagnostics

#ifdef _DEBUG
void CRmtSensingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRmtSensingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc commands

BOOL CRmtSensingDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	iFile = lpszPathName;

	if (!CDocument::OnOpenDocument(iFile))
		return FALSE;

	if (!bmpManip.Open(iFile)) 
	{
		AfxMessageBox("Impossible d'ouvrir " + iFile + ".");

		return FALSE;
	}

	if (!bmpManip.IsValidBitmap())
	{
		AfxMessageBox("Ce n'est pas un bitmap valide.");
		bmpManip.Close();
		return FALSE;
	}

	if (bmpManip.GetBitCount() < 24)
	{
		bmpManip.Close();
		if (AfxMessageBox("Il est conseillé de convertir ce fichier en 24 bits.\n Procèder?",
				MB_YESNO) == IDNO) return FALSE;

		bmpManip.InitBitmap(iFile);
		CClientDC dc(AfxGetMainWnd());
		
		if (!bmpManip.ConvertToRGB(&dc, FALSE, iFile)) return FALSE;
		bmpManip.Open(iFile);
	}

	oFile = iFile;
	iFile = iFile + ".tmp";

	bmpManip.Close();

	bmpManip.InitBitmap(oFile);

	picData = bmpManip.GetPictureHistogrammeInfo();
	cumData = bmpManip.GetCumulatifHistogrammeInfo();

	DataChanged = TRUE;

	return TRUE;
}

void CRmtSensingDoc::Informations()
{
	CString str;

	str.Format(	"Fichier\t=\t%s\nLongueur\t=\t%d pixels\nLargeur\t=\t%d pixels"
				"\nBits/pix\t=\t%d\nOctets/lig\t=\t%d\nCouleurs\t=\t%d", 
				oFile, bmpManip.GetWidth(), bmpManip.GetHeight(), 
				bmpManip.GetBitCount(), bmpManip.GetWidthBytes(), bmpManip.GetColorCount());
	
	AfxMessageBox(str, MB_ICONINFORMATION | MB_OK);
}

void CRmtSensingDoc::FindRGBMax()
{
	bYmax = picData[0];
	gYmax = picData[256];
	rYmax = picData[512];
	
	for (int i = 1 ; i < 256 ; i++)
	{
		if (picData[i] > bYmax) bYmax = picData[i];
		if (picData[256 + i] > gYmax) gYmax = picData[256 + i];
		if (picData[512 + i] > rYmax) rYmax = picData[512 + i];
	}
}

void CRmtSensingDoc::SetDefaultMax()
{
	max = bYmax;
	if (gYmax > max) max = gYmax;
	if (rYmax > max) max = rYmax;
}
