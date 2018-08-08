// ImgViewerView.cpp : implementation of the CImgViewerView class
//

#include "stdafx.h"
#include "ImgViewer.h"

#include "ImgViewerDoc.h"
#include "ImgViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView

IMPLEMENT_DYNCREATE(CImgViewerView, CScrollView)

BEGIN_MESSAGE_MAP(CImgViewerView, CScrollView)
	//{{AFX_MSG_MAP(CImgViewerView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView construction/destruction

CImgViewerView::CImgViewerView()
{
}

CImgViewerView::~CImgViewerView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView drawing

void CImgViewerView::OnDraw(CDC *pDC)
{
	CImgViewerDoc *pDoc = this->GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_pPicture != NULL)
	{
		// get palette
		HPALETTE hPal;
		pDoc->m_pPicture->get_hPal(reinterpret_cast<OLE_HANDLE *>(&hPal));

		CPalette *pPalOld = NULL;
		if (hPal != NULL)
		{
			TRACE(_T("CImgViewerView::OnDraw - RealizePalette\n"));
			pPalOld = pDC->SelectPalette(CPalette::FromHandle(hPal), FALSE);
			pDC->RealizePalette();
		}

		// transparent?
		DWORD dwAttr;
		if (FAILED(pDoc->m_pPicture->get_Attributes(&dwAttr)) ||
			(dwAttr & PICTURE_TRANSPARENT))
		{
			TRACE(_T("CImgViewerView::OnDraw - Transparent\n"));

			// use an off-screen DC to prevent flickering
			CDC MemDC;
			MemDC.CreateCompatibleDC(pDC);
			CBitmap Bmp;
			Bmp.CreateCompatibleBitmap(pDC,
									   pDoc->m_sizeInPix.cx,
									   pDoc->m_sizeInPix.cy);

			CBitmap *pBmpOld = MemDC.SelectObject(&Bmp);
			CPalette *pPalMemOld = NULL;
			if (hPal != NULL)
			{
				pPalMemOld = MemDC.SelectPalette(CPalette::FromHandle(hPal), FALSE);
				MemDC.RealizePalette();
			}

			RECT rc = { 0, 0, pDoc->m_sizeInPix.cx, pDoc->m_sizeInPix.cy };

			MemDC.FillSolidRect(&rc, ::GetSysColor(COLOR_WINDOW));

			// display picture using IPicture::Render
			pDoc->m_pPicture->Render(MemDC.GetSafeHdc(),
									 0,
									 0,
									 pDoc->m_sizeInPix.cx,
									 pDoc->m_sizeInPix.cy,
									 0,
									 pDoc->m_sizeInHiMetric.cy,
									 pDoc->m_sizeInHiMetric.cx,
									 -pDoc->m_sizeInHiMetric.cy,
									 &rc);

			pDC->BitBlt(0, 0, pDoc->m_sizeInPix.cx, pDoc->m_sizeInPix.cy,
						&MemDC, 0, 0, SRCCOPY);

			MemDC.SelectObject(pBmpOld);

			if (pPalMemOld != NULL)
			{
				ASSERT(hPal != NULL);
				MemDC.SelectPalette(pPalMemOld, FALSE);
			}
		}
		else
		{
			RECT rc;
			this->GetClientRect(&rc);

			// display picture using IPicture::Render
			pDoc->m_pPicture->Render(pDC->GetSafeHdc(),
									 0,
									 0,
									 pDoc->m_sizeInPix.cx,
									 pDoc->m_sizeInPix.cy,
									 0,
									 pDoc->m_sizeInHiMetric.cy,
									 pDoc->m_sizeInHiMetric.cx,
									 -pDoc->m_sizeInHiMetric.cy,
									 &rc);
		}

		if (pPalOld != NULL)
		{
			ASSERT(hPal != NULL);
			pDC->SelectPalette(pPalOld, FALSE);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView printing

BOOL CImgViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImgViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImgViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView diagnostics

#ifdef _DEBUG
void CImgViewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImgViewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImgViewerDoc* CImgViewerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImgViewerDoc)));
	return (CImgViewerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImgViewerView message handlers

BOOL CImgViewerView::OnEraseBkgnd(CDC *pDC)
{
	CBrush br(::GetSysColor(COLOR_WINDOW));
    this->FillOutsideRect(pDC, &br);

	return TRUE;
}

void CImgViewerView::OnUpdate(CView *pSender, LPARAM lHint, CObject *pHint) 
{
	CScrollView::OnUpdate(pSender, lHint, pHint);

	CImgViewerDoc *pDoc = this->GetDocument();
	ASSERT_VALID(pDoc);

	this->SetScrollSizes(MM_TEXT,
						 pDoc->m_pPicture != NULL
						 ? CSize(pDoc->m_sizeInPix.cx, pDoc->m_sizeInPix.cy)
						 : CSize(0, 0));

#ifdef _DEBUG
	pDoc->Dump(afxDump);
#endif //_DEBUG
}

void CImgViewerView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CScrollView::OnPrepareDC(pDC, pInfo);

	if (pDC->IsPrinting())
	{
		// Set the mapping mode so that the image is printed at the same
		// size as on the screen. Note that images may be too large to be
		// printed completely.
		CDC ScreenDC;
		ScreenDC.CreateIC(_T("DISPLAY"), NULL, NULL, NULL);
		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetWindowExt(ScreenDC.GetDeviceCaps(LOGPIXELSX),
						  ScreenDC.GetDeviceCaps(LOGPIXELSY));
		pDC->SetViewportExt(pDC->GetDeviceCaps(LOGPIXELSX),
							pDC->GetDeviceCaps(LOGPIXELSY));
		pDC->SetWindowOrg(0, 0);
		pDC->SetViewportOrg(0, 0);
	}
}
