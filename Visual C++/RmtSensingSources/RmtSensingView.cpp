// RmtSensingView.cpp : implementation of the CRmtSensingView class
//

#include "stdafx.h"
#include "RmtSensing.h"

#include "RmtSensingView.h"
#include "RmtSensingFrame.h"
#include "ChildFrm.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "PictureHistogrammeSettingsDlg.h"
#include "LogarithmicExpansion.h"
#include "ExponentialExpansion.h"
#include "PieceWiseLinearExpansion.h"
#include "LinearExpansion.h"
#include "PictureHistogrammeView.h"
#include "ComposanteR.h"
#include "ComposanteG.h"
#include "ComposanteB.h"
#include "Equalization.h"
#include "UserZoomDlg.h"
#include "EdgeDetectionDlg.h"
#include "FakeColorsDialog.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView

IMPLEMENT_DYNCREATE(CRmtSensingView, CScrollView)

BEGIN_MESSAGE_MAP(CRmtSensingView, CScrollView)
	//{{AFX_MSG_MAP(CRmtSensingView)
	ON_COMMAND(ID_PICTURE_INFO, OnPictureInfo)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_OUTILS_EXPANSIONLINAIRE, OnOutilsExpansionlinaire)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_OUTILS_EXPANSIONLOGARITHMIQUE, OnOutilsExpansionlogarithmique)
	ON_COMMAND(ID_OUTILS_EXPANSIONEXPONENTIELLE, OnOutilsExpansionexponentielle)
	ON_COMMAND(ID_OUTILS_EXPANSIONLINAIRESEGMENTE, OnOutilsExpansionlinairesegmente)
	ON_COMMAND(ID_OUTILS_COMPOSANTESRGB, OnOutilsComposantesrgb)
	ON_COMMAND(ID_OUTILS_EGALISATION, OnOutilsEgalisation)
	ON_COMMAND(ID_OUTILS_TRANSFORMERENNOIRETBLANC, OnOutilsTransformerennoiretblanc)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_10, OnAffichageZoom10)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_100, OnAffichageZoom100)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_150, OnAffichageZoom150)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_25, OnAffichageZoom25)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_200, OnAffichageZoom200)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_50, OnAffichageZoom50)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_400, OnAffichageZoom400)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_75, OnAffichageZoom75)
	ON_COMMAND(ID_AFFICHAGE_ZOOM_USER, OnAffichageZoomUser)
	ON_WM_CONTEXTMENU()
	ON_WM_INITMENUPOPUP()
	ON_COMMAND(ID_OUTILS_ESTOMPER, OnOutilsEstomper)
	ON_COMMAND(ID_OUTILS_CONTOURVERTICAL, OnOutilsContourvertical)
	ON_COMMAND(ID_OUTILS_CONTOURHORIZONTAL, OnOutilsContourhorizontal)
	ON_COMMAND(ID_OUTILS_RECHERCHERTOUSLESCONTOURS, OnOutilsRecherchertouslescontours)
	ON_COMMAND(ID_ZOOM_FAUSSECOULEUR, OnZoomFaussecouleur)
	ON_COMMAND(ID_OUTILS_DIMINUERLENOMBREDECOULEURS, OnOutilsDiminuerlenombredecouleurs)
	ON_COMMAND(ID_ZOOM_ACTUALISER, OnZoomActualiser)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView construction/destruction

CRmtSensingView::CRmtSensingView()
{
	copyMode = FALSE;
	factor = 1;
}

CRmtSensingView::~CRmtSensingView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView drawing

void CRmtSensingView::OnDraw(CDC* pDC)
{
	CRect OutsideRect, WindowRect;

	// Est-ce qu'on effctue une opération Copier ?
	if (copyMode)	
	{
		pDoc->bmpManip.Draw(pDC, 
			CRect(0, 0, pDoc->bmpManip.GetWidth(), pDoc->bmpManip.GetHeight()));

		return;
	}

	// Est-ce qu'on effectue une impression, ou un aperçu avant impression
	if (pDC->IsPrinting())		// Si oui
	{
		pDC->SetMapMode(MM_HIMETRIC);
		OutsideRect.top = OutsideRect.left = 0;
		OutsideRect.right = 20000;
		OutsideRect.bottom = -15000;

		pDoc->bmpManip.Draw(pDC, OutsideRect);	// On Dessine l'aperçu

		return;
	}
		
	CBrush brush(HS_DIAGCROSS, RGB(220, 220, 220)), *oldBrush;
	CPen pen(PS_NULL, 1, RGB(0, 0, 0)), *oldPen;

	oldBrush = (CBrush*) pDC->SelectObject(&brush);
	oldPen = (CPen*) pDC->SelectObject(&pen);

	GetClientRect(&OutsideRect);
	
	PicRect = CRect(0, 0, 
					int(factor * pDoc->bmpManip.GetWidth()), 
					int(factor * pDoc->bmpManip.GetHeight()));

	
	if (OutsideRect.Width() > PicRect.Width()) 
	{
		PicRect.left = (OutsideRect.Width() - int(factor * pDoc->bmpManip.GetWidth()))/ 2;
		PicRect.right = PicRect.left + int(factor * pDoc->bmpManip.GetWidth());

		WindowRect.left = 0;
		WindowRect.right = OutsideRect.Width();
	}
	else
	{
		WindowRect.left = 0;
		WindowRect.right = PicRect.Width();
	}

	if (OutsideRect.Height() > PicRect.Height()) 
	{
		PicRect.top = (OutsideRect.Height() - int(factor * pDoc->bmpManip.GetHeight())) / 2 ;
		PicRect.bottom = PicRect.top + int(factor * pDoc->bmpManip.GetHeight());

		WindowRect.top = 0;
		WindowRect.bottom = OutsideRect.Height();
	}
	else
	{
		WindowRect.top = 0;
		WindowRect.bottom = PicRect.Height();
	}

	pDC->Rectangle(&WindowRect);
	pDoc->bmpManip.Draw(pDC, PicRect);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);

	brush.DeleteObject();
	pen.DeleteObject();
}

void CRmtSensingView::OnInitialUpdate()
{
	pDoc = (CRmtSensingDoc *)GetDocument();
	CRect rect;
	
	SetScrollSizes(MM_TEXT, CSize(	int(factor * pDoc->bmpManip.GetWidth()), 
									int(factor * pDoc->bmpManip.GetHeight())));
	ResizeParentToFit(FALSE);

	pDoc->bmpManip.GetHistogrammeInfo();
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView printing

BOOL CRmtSensingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView diagnostics

#ifdef _DEBUG
void CRmtSensingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRmtSensingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CRmtSensingDoc* CRmtSensingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRmtSensingDoc)));
	return (CRmtSensingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView message handlers

void CRmtSensingView::OnPictureInfo() 
{
	pDoc->Informations();
}


void CRmtSensingView::OnEditCopy() 
{
	if (OpenClipboard())
	{
		CClientDC dc(this);

		CRect rect;
		GetClientRect(&rect);

		CDC memDC; memDC.CreateCompatibleDC(&dc);
		CBitmap bmp; 
		bmp.CreateCompatibleBitmap(&dc, pDoc->bmpManip.GetWidth(), pDoc->bmpManip.GetHeight());
		memDC.SelectObject(&bmp);

		memDC.Rectangle(rect);
		
		copyMode = TRUE;
		OnDraw(&memDC);
		copyMode = FALSE;

		BeginWaitCursor();
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, HBITMAP(bmp));
		CloseClipboard();
		EndWaitCursor();

		bmp.DeleteObject();
		memDC.DeleteDC();
	}	
}

void CRmtSensingView::OnOutilsExpansionlinaire() 
{

	CLinearExpansion linExp;	

	Expansion(&linExp);
}

void CRmtSensingView::OnEditUndo() 
{
	pDoc->bmpManip.RestoreFromTempCopy(pDoc->oFile);

	Actualiser(TRUE);
}

void CRmtSensingView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TRUE);
}

void CRmtSensingView::OnOutilsExpansionlogarithmique() 
{
	CLogarithmicExpansion logExp;
	
	Expansion(&logExp);
}

void CRmtSensingView::OnOutilsExpansionexponentielle() 
{
	CExponentialExpansion expExp;
	
	Expansion(&expExp);
}

void CRmtSensingView::OnOutilsExpansionlinairesegmente() 
{
	CPieceWiseLinearExpansion wiseExp;
	
	Expansion(&wiseExp);
}

void CRmtSensingView::Expansion(CLookUpTables *lkUpTables)
{
	pDoc->SetModifiedFlag();

	pDoc->bmpManip.GetHistogrammeInfo();

	pDoc->bmpManip.MakeModification(lkUpTables);
	
	Actualiser(TRUE);
}


void CRmtSensingView::OnOutilsComposantesrgb() 
{
	if (pDoc->bmpManip.GetBitCount() < 24) 
	{
		AfxMessageBox("Ce format n'est pas encore pris en charge par le programme");
		return;
	}

	CCreateContext context;
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_RGB);

	if (!pDoc->RComponent)
	{
		pDoc->RComponent = TRUE;

		wndR = new CChildFrame;
		
		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteR);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndR;

		wndR->Create(NULL, "Rouge", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);

		wndR->InitialUpdateFrame(pDoc, TRUE);
		wndR->SetIcon(hIcon, TRUE);

		wndR->ShowWindow(SW_SHOW);		
	}

	if (!pDoc->GComponent)
	{
		pDoc->GComponent = TRUE;

		wndG = new CChildFrame;

		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteG);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndG;

		wndG->Create(NULL, "Vert", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);
	
		wndG->InitialUpdateFrame(pDoc, TRUE);
		wndG->SetIcon(hIcon, TRUE);

		wndG->ShowWindow(SW_SHOW);	
	}
	
	if (!pDoc->BComponent)
	{
		pDoc->BComponent = TRUE;

		wndB = new CChildFrame;
	
		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteB);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndB;

		wndB->Create(NULL, "Bleu", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);

		wndB->InitialUpdateFrame(pDoc, TRUE);
		wndB->SetIcon(hIcon, TRUE);

		wndB->ShowWindow(SW_SHOW);		
	}
}

void CRmtSensingView::OnOutilsEgalisation() 
{
	CEqualization equ;
	
	Expansion(&equ);
}

void CRmtSensingView::OnOutilsTransformerennoiretblanc() 
{
	pDoc->bmpManip.BWTransform();
	pDoc->SetModifiedFlag();
	Actualiser(TRUE);
}

void CRmtSensingView::OnAffichageZoom10() 
{
 	SetZoom(float(0.1));
}

void CRmtSensingView::OnAffichageZoom100() 
{
	SetZoom(float(1.0));
}

void CRmtSensingView::OnAffichageZoom150() 
{
	SetZoom(float(1.5));
}

void CRmtSensingView::OnAffichageZoom25() 
{
	SetZoom(float(0.25));
}

void CRmtSensingView::OnAffichageZoom200() 
{
	SetZoom(float(2.0));
}

void CRmtSensingView::OnAffichageZoom50() 
{
	SetZoom(float(0.5));
}

void CRmtSensingView::OnAffichageZoom400() 
{
	SetZoom(float(4.0));
}

void CRmtSensingView::OnAffichageZoom75() 
{
	SetZoom(float(0.75));
}

void CRmtSensingView::SetZoom(float newFactor)
{
	int fctX = 32767 / pDoc->bmpManip.GetWidth();
	int	fctY = 32767 / pDoc->bmpManip.GetWidth();

	factor = (newFactor < fctX && newFactor < fctY) ? newFactor : ((fctX < fctY) ? fctX : fctY);

	SetScrollSizes(MM_TEXT, CSize(	int(newFactor * pDoc->bmpManip.GetWidth()),
									int(newFactor * pDoc->bmpManip.GetHeight())));

	Invalidate();
}

void CRmtSensingView::OnAffichageZoomUser() 
{
	CUserZoomDlg zDlg;

	zDlg.m_editZoom = int(factor * 100);

	if (zDlg.DoModal() == IDOK) SetZoom((float)(zDlg.m_editZoom / 100.0));
}

void CRmtSensingView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu menu;

	menu.LoadMenu(IDR_ZOOM);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN, point.x, point.y, this);
	menu.Detach();
}

void CRmtSensingView::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
{
	CScrollView::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_10, (factor > 0.099 && factor < 0.101) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_25, (factor == 0.25) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_50, (factor == 0.5) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_75, (factor == 0.75) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_100, (factor == 1.0) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_150, (factor == 1.5) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_200, (factor == 2.0) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_400, (factor == 4.0) ?
															MF_CHECKED : MF_UNCHECKED);
	pPopupMenu->CheckMenuItem(ID_AFFICHAGE_ZOOM_USER, (factor != 0.1 && factor != 0.25 &&
													factor != 0.5 && factor != 0.75 &&
													factor != 1.0 && factor != 1.5 &&
													factor != 2.0 && factor != 4.0) ?
															MF_CHECKED : MF_UNCHECKED);
}

void CRmtSensingView::OnOutilsEstomper() 
{
	pDoc->bmpManip.Flou();
	
	Actualiser(TRUE);
}

void CRmtSensingView::OnOutilsContourvertical() 
{
	pDoc->bmpManip.EdgeDetect(VERTICAL_DETECT);
	
	Actualiser(TRUE);
}

void CRmtSensingView::OnOutilsContourhorizontal() 
{
	pDoc->bmpManip.EdgeDetect(HORIZONTAL_DETECT);
	
	Actualiser(TRUE);
}

void CRmtSensingView::OnOutilsRecherchertouslescontours() 
{
	pDoc->bmpManip.EdgeDetect(ALL_DETECT);
	
	Actualiser(TRUE);
}

void CRmtSensingView::OnZoomFaussecouleur() 
{
	CFakeColorsDialog fcDialog;

	fcDialog.SetDocument(pDoc);
	fcDialog.InitColorTree(pDoc->bmpManip.GetColorCount(), pDoc->bmpManip.GetColorArrayPointer());

	if (fcDialog.DoModal() == IDCANCEL) return;

	Actualiser(TRUE);
	/*
	CColorDialog cDlg;

	if (cDlg.DoModal() == IDCANCEL) return;
	COLORREF newColor;
	CString str;

	newColor = cDlg.GetColor();

	pDoc->bmpManip.FakeColours(1, &currentPointColor, &newColor);
	pDoc->SetModifiedFlag();
	
	*/
}

void CRmtSensingView::OnOutilsDiminuerlenombredecouleurs() 
{
	CEdgeDetectionDlg eDlg;

	if (eDlg.DoModal() == IDCANCEL) return;
	pDoc->bmpManip.LimitRGBBright(eDlg.m_percentage);
	
	Actualiser(TRUE);
}

void CRmtSensingView::OnZoomActualiser() 
{
	Actualiser();
}

void CRmtSensingView::Actualiser(BOOL setModifiedFlag)
{
	if (setModifiedFlag) pDoc->SetModifiedFlag();

	pDoc->bmpManip.GetHistogrammeInfo();

	pDoc->FindRGBMax();
	pDoc->SetDefaultMax();

	pDoc->DataChanged = TRUE;
	pDoc->UpdateAllViews(NULL);	
}
