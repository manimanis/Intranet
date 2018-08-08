// CD LabelView.cpp : implementation of the CCDLabelView class
//

#include "stdafx.h"
#include "CD Label.h"

#include "CD LabelDoc.h"
#include "CD LabelView.h"

#include "TextObject.h"
#include "DessinVectoriel.h"

#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView

IMPLEMENT_DYNCREATE(CCDLabelView, CScrollView)

BEGIN_MESSAGE_MAP(CCDLabelView, CScrollView)
	//{{AFX_MSG_MAP(CCDLabelView)
	ON_COMMAND(ID_TEXTE, OnTexte)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_TEXTE, OnUpdateTexte)
	ON_COMMAND(ID_PROPERTIES, OnProperties)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES, OnUpdateProperties)
	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_DESSIN, OnDessin)
	ON_COMMAND(ID_AVANCE, OnAvance)
	ON_COMMAND(ID_BACK, OnBack)
	ON_COMMAND(ID_BRINGTOBACK, OnBringtoback)
	ON_COMMAND(ID_BRINGTOFRONT, OnBringtofront)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView construction/destruction

CCDLabelView::CCDLabelView()
{
	m_nSelectedObject = 0;
	pClipboardObject = NULL;
}

CCDLabelView::~CCDLabelView()
{
	Objets.RemoveAll();
	if (pClipboardObject) delete pClipboardObject;
}

BOOL CCDLabelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView drawing

void CCDLabelView::OnDraw(CDC* pDC)
{
	CCDLabelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->SetMapMode(MM_HIMETRIC);
	pDC->Rectangle(1000, -1000, 13000, -13000); 
	pDC->Rectangle(1000, -13500, 16000, -(13500 + 11800));
	pDC->Rectangle(1650, -13500, 16000 - 650, -(13500 + 11800));

	for (int i = 0 ; i < Objets.GetSize() ; i++)
	{
		Objets.ElementAt(i)->DrawObject(pDC);
	}
}

void CCDLabelView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;

	sizeTotal.cx = sizeTotal.cy = 13500 + 12500;
	SetScrollSizes(MM_HIMETRIC, sizeTotal);
	GetParentFrame()->RecalcLayout(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView printing

BOOL CCDLabelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCDLabelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCDLabelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView diagnostics

#ifdef _DEBUG
void CCDLabelView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCDLabelView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCDLabelDoc* CCDLabelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCDLabelDoc)));
	return (CCDLabelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCDLabelView message handlers

void CCDLabelView::OnTexte() 
{
	CClientDC dc(this);
	CTextObject *tObject;
	
	tObject = new CTextObject;

	Objets.Add(tObject);

	Invalidate();
}

void CCDLabelView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect rc;

	m_rCorner = 0;

	if (GetCapture() == this) 
	{
		ReleaseCapture(); 
		Invalidate(); 
		return;
	}

	Invalidate();
}

void CCDLabelView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect rc;
	CObjetsVisuels *pObVis;

	OnPrepareDC(&dc);
	dc.SetMapMode(MM_HIMETRIC);
	dc.DPtoLP(&point);

	m_rCorner = 0;
	m_nSelectedObject = 0;

	for (int i = 0 ; i < Objets.GetSize() ; i++)
	{
		pObVis = Objets.GetAt(i);
		if (pObVis->PtInObject(point))
		{
			if (GetCapture() != this) 
			{
				SetCapture();
				m_cpSelPoint = point - pObVis->GetPos().TopLeft();
			}

			if (!m_nSelectedObject) 
			{
				pObVis->SelectObject();
				m_nSelectedObject = i + 1;
				m_rCorner = pObVis->IsOverResizeCorners(point);
			}

			CString str;
			str.Format("%d", m_rCorner);

			((CMainFrame *)AfxGetMainWnd())->m_wndStatusBar.SetPaneText(0, str);
		}
		else
		{
			pObVis->SelectObject(FALSE);
		}
	}

	CScrollView::OnLButtonDown(nFlags, point);
}

void CCDLabelView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect rc;

	OnPrepareDC(&dc);
	dc.SetMapMode(MM_HIMETRIC);
	dc.DPtoLP(&point);

	if (GetCapture() == this)
	{
		if (m_rCorner)
		{
			rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
			if (m_rCorner == 3 || m_rCorner == 4 || m_rCorner == 5) 
				if (point.x > rc.left) rc.right = point.x;
				else rc.left = point.x;

			if (m_rCorner == 5 || m_rCorner == 6 || m_rCorner == 7) 
				if (rc.bottom < point.y) rc.top = point.y;
				else rc.bottom = point.y;

			if (m_rCorner == 7 || m_rCorner == 8 || m_rCorner == 1) 
				if (rc.right > point.x) rc.left = point.x;
				else rc.right = point.y;

			if (m_rCorner == 1 || m_rCorner == 2 || m_rCorner == 3) 
				if (rc.top > point.y) rc.bottom = point.y;
				else rc.top = point.y;

			Objets.GetAt(m_nSelectedObject - 1)->SetPos(rc);
			Objets.GetAt(m_nSelectedObject - 1)->DrawObject(&dc);
		}
		else 
		if (Objets.GetAt(m_nSelectedObject - 1)->GetState() == OBJECT_STATE_SELECTED)
		{
			rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
			Objets.GetAt(m_nSelectedObject - 1)->SetPos(CRect(point.x - m_cpSelPoint.x, 
										point.y - m_cpSelPoint.y, 
										rc.Width() + point.x - m_cpSelPoint.x, 
										rc.Height() + point.y - m_cpSelPoint.y));
			Objets.GetAt(m_nSelectedObject - 1)->DrawObject(&dc);
		}

		Invalidate();
	}
	
}

void CCDLabelView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect rc;
	CObjetsVisuels *pObVis;
	CPoint pt = point;

	OnPrepareDC(&dc);
	dc.SetMapMode(MM_HIMETRIC);
	dc.DPtoLP(&point);

	m_nSelectedObject = 0;

	for (int i = 0 ; i < Objets.GetSize() ; i++)
	{
		pObVis = Objets.GetAt(i);
		if (pObVis->PtInObject(point))
		{
			if (!m_nSelectedObject) 
			{
				pObVis->SelectObject();
				m_nSelectedObject = i + 1;
				m_rCorner = pObVis->IsOverResizeCorners(point);
			}

			CString str;
			str.Format("%d", m_rCorner);

			((CMainFrame *)AfxGetMainWnd())->m_wndStatusBar.SetPaneText(0, str);
		}
		else
		{
			pObVis->SelectObject(FALSE);
		}
	}

	if (m_nSelectedObject)
	{
		CMenu  menu;

		menu.LoadMenu(IDR_POPUP_MENU);

		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);

		// Objets.GetAt(m_nSelectedObject - 1)->Properties();

		menu.DestroyMenu();
		Invalidate();
	}
	
	CScrollView::OnRButtonUp(nFlags, point);
}

void CCDLabelView::OnUpdateTexte(CCmdUI* pCmdUI) 
{

}

void CCDLabelView::OnProperties() 
{
	if (m_nSelectedObject)
	{
		Objets.GetAt(m_nSelectedObject - 1)->Properties();
		Invalidate();	
	}
}

void CCDLabelView::OnUpdateProperties(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nSelectedObject);
}

void CCDLabelView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar)	
	{
	case VK_DELETE :
			if (m_nSelectedObject)
			{
				Objets.RemoveAt(m_nSelectedObject - 1);
				m_nSelectedObject = 0;
				Invalidate();
			}
	}
	CScrollView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CCDLabelView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch (nChar)	
	{
	case VK_UP :
			if (m_nSelectedObject)
			{
				CRect rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
				rc.top += 100;
				rc.bottom += 100;
				Objets.GetAt(m_nSelectedObject - 1)->SetPos(rc);
				Invalidate();
			}
			break;
	case VK_DOWN :
			if (m_nSelectedObject)
			{
				CRect rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
				rc.top -= 100;
				rc.bottom -= 100;
				Objets.GetAt(m_nSelectedObject - 1)->SetPos(rc);
				Invalidate();
			}
			break;
	case VK_LEFT :
			if (m_nSelectedObject)
			{
				CRect rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
				rc.left -= 100;
				rc.right -= 100;
				Objets.GetAt(m_nSelectedObject - 1)->SetPos(rc);
				Invalidate();
			}
			break;
	case VK_RIGHT :
			if (m_nSelectedObject)
			{
				CRect rc = Objets.GetAt(m_nSelectedObject - 1)->GetPos();
				rc.left += 100;
				rc.right += 100;
				Objets.GetAt(m_nSelectedObject - 1)->SetPos(rc);
				Invalidate();
			}
			break;
	}
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCDLabelView::OnDessin() 
{
	CClientDC dc(this);
	CDessinVectoriel *dObject;
	
	dObject = new CDessinVectoriel;

	Objets.Add(dObject);

	Invalidate();
}

void CCDLabelView::OnAvance() 
{
	if (m_nSelectedObject)	
	{
		CObjetsVisuels *pTempObj, *pObj = Objets.GetAt(m_nSelectedObject - 1), *pObj2;

		if (m_nSelectedObject > 1)
		{
			pObj2 = Objets.GetAt(m_nSelectedObject - 2);
			
			pTempObj = pObj2;
			Objets.SetAt(m_nSelectedObject - 2, pObj);
			Objets.SetAt(m_nSelectedObject - 1, pTempObj);

			Invalidate();
		}
	}
}

void CCDLabelView::OnBack() 
{
	if (m_nSelectedObject)	
	{
		CObjetsVisuels *pTempObj, *pObj = Objets.GetAt(m_nSelectedObject - 1), *pObj2;

		if (m_nSelectedObject < Objets.GetSize())
		{
			pObj2 = Objets.GetAt(m_nSelectedObject);
			
			pTempObj = pObj2;
			Objets.SetAt(m_nSelectedObject, pObj);
			Objets.SetAt(m_nSelectedObject - 1, pTempObj);

			Invalidate();
		}
	}
}

void CCDLabelView::OnBringtoback() 
{
	if (m_nSelectedObject)	
	{
		CObjetsVisuels *pObj = Objets.GetAt(m_nSelectedObject - 1);

		if (m_nSelectedObject < Objets.GetSize())
		{
			Objets.InsertAt(Objets.GetSize(), pObj);
			Objets.RemoveAt(m_nSelectedObject - 1);

			Invalidate();
		}
	}
}

void CCDLabelView::OnBringtofront() 
{
	if (m_nSelectedObject)	
	{
		CObjetsVisuels *pObj = Objets.GetAt(m_nSelectedObject - 1);

		if (m_nSelectedObject > 0)
		{			
			Objets.InsertAt(0, pObj);
			Objets.RemoveAt(m_nSelectedObject);

			Invalidate();
		}
	}
}

void CCDLabelView::OnEditCopy() 
{
	CObjetsVisuels *pObjet = Objets.GetAt(m_nSelectedObject - 1);
/*
	if (pClipboardObject) 
	{
		delete pClipboardObject;
		pClipboardObject = NULL;
	}
*/
	switch(pObjet->GetType())
	{
	case OBJECT_TYPE_TEXT: 
		{
			CTextObject *pObj; 
			pObj = new CTextObject; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	case OBJECT_TYPE_DESSIN : 
		{
			CDessinVectoriel *pObj; 
			pObj = new CDessinVectoriel; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	}
}

void CCDLabelView::OnEditCut() 
{
	CObjetsVisuels *pObjet = Objets.GetAt(m_nSelectedObject - 1);

	switch(pObjet->GetType())
	{
	case OBJECT_TYPE_TEXT: 
		{
			CTextObject *pObj; 
			pObj = new CTextObject; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	case OBJECT_TYPE_DESSIN : 
		{
			CDessinVectoriel *pObj; 
			pObj = new CDessinVectoriel; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	}
	
	Objets.RemoveAt(m_nSelectedObject - 1);
	Invalidate();
}

void CCDLabelView::OnEditPaste() 
{
	CObjetsVisuels *pObjet = pClipboardObject;

	Objets.Add(pClipboardObject);

	switch(pObjet->GetType())
	{
	case OBJECT_TYPE_TEXT: 
		{
			CTextObject *pObj; 
			pObj = new CTextObject; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	case OBJECT_TYPE_DESSIN : 
		{
			CDessinVectoriel *pObj; 
			pObj = new CDessinVectoriel; 
			pObj->Copie(pObjet);
			pClipboardObject = pObj;	
		}
		break;
	}

	Invalidate();
}

void CCDLabelView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nSelectedObject);
}

void CCDLabelView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nSelectedObject);
}

void CCDLabelView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(pClipboardObject != NULL);
}
