// ImgViewerDoc.cpp : implementation of the CImgViewerDoc class
//

#include "stdafx.h"
#include <afxpriv.h>
#include "ImgViewer.h"
#include "ImgViewerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgViewerDoc

IMPLEMENT_DYNCREATE(CImgViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CImgViewerDoc, CDocument)
	//{{AFX_MSG_MAP(CImgViewerDoc)
	ON_COMMAND(ID_FILE_PROPERTIES, OnFileProperties)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgViewerDoc construction/destruction

CImgViewerDoc::CImgViewerDoc()
{
	m_pPicture = NULL;
}

CImgViewerDoc::~CImgViewerDoc()
{
	if (m_pPicture != NULL)
	{
		m_pPicture->Release();
		m_pPicture = NULL;

		TRACE(_T("CImgViewerDoc::~CImgViewerDoc - m_pPicture->Release()\n"));
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImgViewerDoc diagnostics

#ifdef _DEBUG
void CImgViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImgViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);

	dc << _T("m_pPicture = ") << m_pPicture << _T("\n");
	dc << _T("m_sizeInHiMetric = ") << m_sizeInHiMetric << _T("\n");
	dc << _T("m_sizeInPix = ") << m_sizeInPix << _T("\n");
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImgViewerDoc commands

BOOL CImgViewerDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	this->DeleteContents();

	// The previous image should be unloaded.
	ASSERT(m_pPicture == NULL);

	USES_CONVERSION;
	HRESULT hr = ::OleLoadPicturePath(const_cast<LPOLESTR>(T2COLE(lpszPathName)),
									  NULL,
									  0,
									  0,
									  IID_IPicture,
									  reinterpret_cast<LPVOID *>(&m_pPicture));
	
	TRACE(_T("CImgViewerDoc::OnOpenDocument - OleLoadPicturePath(\"%s\"): ")
		  _T("hr = 0x%08X, m_pPicture = 0x%08X\n"), lpszPathName, hr, m_pPicture);
	
	if (SUCCEEDED(hr) && m_pPicture != NULL)
	{
		// get width and height of picture
		m_pPicture->get_Width(&m_sizeInHiMetric.cx);
		m_pPicture->get_Height(&m_sizeInHiMetric.cy);

		const int HIMETRIC_PER_INCH = 2540;

		HDC hDCScreen = ::GetDC(NULL);
		ASSERT(hDCScreen != NULL);
		// Pixels per logical inch along width
		const int nPixelsPerInchX = ::GetDeviceCaps(hDCScreen, LOGPIXELSX);
		// Pixels per logical inch along height
		const int nPixelsPerInchY = ::GetDeviceCaps(hDCScreen, LOGPIXELSY);
		::ReleaseDC(NULL, hDCScreen);

		// convert himetric to pixels
		m_sizeInPix.cx = (nPixelsPerInchX * m_sizeInHiMetric.cx +
						  HIMETRIC_PER_INCH / 2) / HIMETRIC_PER_INCH;
		m_sizeInPix.cy = (nPixelsPerInchY * m_sizeInHiMetric.cy +
						  HIMETRIC_PER_INCH / 2) / HIMETRIC_PER_INCH;

		return TRUE;
	}
	else
	{
		// OleLoadPicturePath failed.
		CString strErrMsg;
		strErrMsg.Format(IDS_ERRLOADPIC, lpszPathName);
		::AfxMessageBox(strErrMsg, MB_OK | MB_ICONEXCLAMATION);

		// Back to initial state
		this->OnNewDocument();
		this->GetDocTemplate()->SetDefaultTitle(this);
		this->UpdateAllViews(NULL);

		ASSERT(m_pPicture == NULL);
		ASSERT(this->GetPathName().IsEmpty());

		return FALSE;
	}
}

void CImgViewerDoc::DeleteContents() 
{
	if (m_pPicture != NULL)
	{
		m_pPicture->Release();
		m_pPicture = NULL;

		TRACE(_T("CImgViewerDoc::DeleteContents - m_pPicture->Release()\n"));
	}
	
	CDocument::DeleteContents();
}

void CImgViewerDoc::OnFileProperties() 
{
	if (m_pPicture != NULL)
	{
		// Picture type
		short shType;
		m_pPicture->get_Type(&shType);

		CString strType;
		strType.LoadString(shType >= PICTYPE_UNINITIALIZED &&
						   shType <= PICTYPE_ENHMETAFILE
						   ? IDS_PT_UNINITIALIZED + shType + 1
						   : IDS_PT_UNKNOWN);

		// Picture attributes
		DWORD dwAttr;
		m_pPicture->get_Attributes(&dwAttr);

		CString strAttr;
		if (dwAttr & PICTURE_SCALABLE)
			strAttr.LoadString(IDS_PA_SCALABLE);

		if (dwAttr & PICTURE_TRANSPARENT)
		{
			CString strTemp(reinterpret_cast<LPCTSTR>(IDS_PA_TRANSPARENT));
			if (!strAttr.IsEmpty())
				strAttr += _T(" | ");
			strAttr += strTemp;
		}

		if (strAttr.IsEmpty())
			strAttr.LoadString(IDS_PA_NONE);

		// Properties
		CString strProp;
		strProp.Format(IDS_PROP,
					   this->GetPathName(),
					   m_sizeInPix.cx, m_sizeInPix.cy,
					   shType,
					   strType,
					   dwAttr,
					   strAttr);

		::AfxMessageBox(strProp, MB_OK | MB_ICONINFORMATION);
	}
}
