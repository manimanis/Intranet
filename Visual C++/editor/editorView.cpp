// editorView.cpp : implementation of the CEditorView class
//

#include "stdafx.h"
#include "mainfrm.h"
#include "editor.h"

#include "editorDoc.h"
#include "editorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define LIGNES	60

/////////////////////////////////////////////////////////////////////////////
// CEditorView

IMPLEMENT_DYNCREATE(CEditorView, CView)

BEGIN_MESSAGE_MAP(CEditorView, CView)
	//{{AFX_MSG_MAP(CEditorView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorView construction/destruction

CEditorView::CEditorView()
{
	hCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
}

CEditorView::~CEditorView()
{
}

BOOL CEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEditorView drawing

void CEditorView::OnDraw(CDC* pDC)
{
	CEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rc;
	CPoint sel;
	CString strVide;

	for (int i = 0 ; i < 128 ; i++) strVide += "    ";

	if (!pDC->IsPrinting())
	{
		GetClientRect(&rc);
		m_WindowMax = rc.Height() / m_charSize.cy;

		for (int i = 0 ; i < m_WindowMax ; i++)
		{
			if ((i + m_ptTextPos.y) < m_pArrayText->GetSize())
			{
				sel = GetSelectedPart(i + m_ptTextPos.y);
				DrawString(pDC, CPoint(2, i), m_ptTextPos.y + i, sel.x, sel.y, m_ptTextPos.x); 
						//GetString(m_ptTextPos.y + i, m_ptTextPos.x));
			}
			else
				DrawString(pDC, CPoint(2, i), strVide);
		}

		SetScrollRange(SB_VERT, 0, m_pArrayText->GetSize() - m_WindowMax);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEditorView printing

BOOL CEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	pInfo->SetMinPage(1);
	pInfo->SetMaxPage((m_arrayText.GetSize() / LIGNES) + 1);

	return DoPreparePrinting(pInfo);
}

void CEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEditorView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (pDC->IsPrinting())
	{
		CSize size;

		size.cx = pDC->GetDeviceCaps(HORZRES);
		size.cy = pDC->GetDeviceCaps(VERTRES);

		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetViewportExt(size.cx, size.cy);
		pDC->SetWindowExt(750, 750 * 30 / 21);
	}
	
	CView::OnPrepareDC(pDC, pInfo);
}

void CEditorView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	int curPage = (pInfo->m_nCurPage - 1) * LIGNES;
	int nextPage = pInfo->m_nCurPage * LIGNES;

	for (int i = curPage ; i < nextPage ; i++)
	{
		if (i < m_arrayText.GetSize())
			DrawString(pDC, CPoint(2, i - curPage), GetString(i, 0));
	}

	CString str;
	str.Format("-- Edited and Printed With : MANI Mohamed Anis Editor -- Page %d sur %d --", 
		pInfo->m_nCurPage, pInfo->GetMaxPage());
	DrawString(pDC, CPoint(10, (i + 1) - curPage), str);
	
	CView::OnPrint(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CEditorView diagnostics

#ifdef _DEBUG
void CEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditorDoc* CEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditorDoc)));
	return (CEditorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditorView message handlers

void CEditorView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();

	m_pArrayText = &(GetDocument()->m_arrayText);
	
	// Initialisation de la fonte
	m_ftFont.CreateFont(-14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Courier New");	

	// Détermination de la largeur et la hauteur d'une lgne
	CClientDC dc(this);
	CFont *pOldFont;

	pOldFont = (CFont *)dc.SelectObject(&m_ftFont);
	m_charSize = dc.GetTextExtent("M", 1);
	dc.SelectObject(pOldFont);

	// Initialisation de la position du curseur dans le texte
	m_ptCurPos.x = 0;
	m_ptCurPos.y = 0;

	// Initialisation de la position du curseur clignotant
	m_ptEditPos.x = 0;
	m_ptEditPos.y = 0;

	// Initialisation de la position du texte
	m_ptTextPos.x = 0;
	m_ptTextPos.y = 0;

	// Ajout des barres de défilement Horizontale et Verticale
	ModifyStyle(0, WS_HSCROLL | WS_VSCROLL, SWP_DRAWFRAME);

	SetScrollRange(SB_VERT, 0, m_pArrayText->GetSize() - 1);
	SetScrollPos(SB_VERT, 0);

	SetScrollRange(SB_HORZ, 0, 512);
	SetScrollPos(SB_HORZ, 0);

	// Initialisation Sélection à zéro
	m_rcSelection = CRect(0, 0, 0, 0);
	m_selState = SELECT_NONE;
}

void CEditorView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CClientDC dc(this);
	
	EditPosValidityVerif(&dc);	

	switch(nChar)
	{
	case VK_RIGHT:
	case VK_LEFT:
		OnRightLeftKey(nChar);
		break;
	case VK_DOWN:
	case VK_UP:
		OnUpDownKey(nChar);
		break;
	case VK_HOME:
	case VK_END:
		OnHomeEndKey(nChar);
		break;
	case VK_DELETE:
		OnDeleteKey();
		break;
	}

	OnSelection(&dc, FALSE);

	EditPosValidityVerif(&dc);
	SetScrollPos(SB_VERT, m_ptEditPos.y - m_WindowMax);
	SetCaretAt((m_ptEditPos - m_ptTextPos));

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CClientDC dc(this);

	EditPosValidityVerif(&dc);

	m_ptCurPos.x = GetCharRange(m_ptEditPos.x, m_ptEditPos.y);
	m_ptCurPos.y = m_ptEditPos.y;

	switch(nChar)
	{
	case 0x08: // BackSpace
		OnBackspaceKey();
		break;
	case 0x0d: // entrée
	case 0x0a:
		OnEnterKey();
		break;
	case 0x09: // Tabulation
		OnTabulationKey();
		break;
	default:
		OnOtherChar(nChar);
	}

	EditPosValidityVerif(&dc);
	SetScrollPos(SB_VERT, m_ptEditPos.y - m_WindowMax);
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnDraw(&dc);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


// Les barres de défilements
void CEditorView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CClientDC dc(this);

	switch(nSBCode)
	{
	case SB_THUMBPOSITION :
	case SB_THUMBTRACK:
		SetScrollPos(SB_VERT, nPos);
		break;

	case SB_BOTTOM:
	case SB_LINEDOWN:
		SetScrollPos(SB_VERT, GetScrollPos(SB_VERT) + 1);
		break;

	case SB_TOP:
	case SB_LINEUP:
		SetScrollPos(SB_VERT, GetScrollPos(SB_VERT) - 1);
		break;

	case SB_PAGEUP:
		SetScrollPos(SB_VERT, GetScrollPos(SB_VERT) - 10);
		break;

	case SB_PAGEDOWN:
		SetScrollPos(SB_VERT, GetScrollPos(SB_VERT) + 10);
		break;
	}

	m_ptTextPos.y = GetScrollPos(SB_VERT);
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnDraw(&dc);

	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CEditorView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CClientDC dc(this);

	switch(nSBCode)
	{
	case SB_THUMBPOSITION :
	case SB_THUMBTRACK:
		SetScrollPos(SB_HORZ, nPos);
		break;

	case SB_LEFT:
	case SB_LINELEFT:
		SetScrollPos(SB_HORZ, GetScrollPos(SB_HORZ) - 10);
		break;

	case SB_RIGHT:
	case SB_LINERIGHT:
		SetScrollPos(SB_HORZ, GetScrollPos(SB_HORZ) + 10);
		break;

	case SB_PAGELEFT:
		SetScrollPos(SB_HORZ, GetScrollPos(SB_HORZ) - 100);
		break;

	case SB_PAGERIGHT:
		SetScrollPos(SB_HORZ, GetScrollPos(SB_HORZ) + 100);
		break;
	}

	m_ptTextPos.x = GetScrollPos(SB_HORZ);
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnDraw(&dc);
	
	CView::OnHScroll(nSBCode, nPos, pScrollBar);
}

// Affiche ou cache le curseur selon la vue en cours
void CEditorView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if (bActivate)			// Si c'est la vue principale
	{
		CreateSolidCaret(2, m_charSize.cy);
		ShowCaret();
		SetCaretAt(m_ptEditPos);
	}

	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

//--------------------------------------------------------------------//
// 
//  Mes Fonctions
//
//--------------------------------------------------------------------//

// Détermine la chaine à afficher
CString CEditorView::GetString(int nLine, int from)
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	if (nLine < m_arrayText.GetSize())
		if (from < m_arrayText[nLine].GetLength()) return m_arrayText[nLine].Mid(from);

	return CString("");
}

// Détermine la position initiale du curseur
int CEditorView::GetHomePos(int firstPos, int nLine)
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	int length = m_arrayText[nLine].GetLength();
	int i = 0;

	while (i < length && m_arrayText[nLine][i] == 011) i++;

	return ((firstPos <= i) ?0 : i);
}

// Repositionne le caret
void CEditorView::SetCaretAt(CPoint point) // Position du caret
{
	CString strPos;
	strPos.Format("(x : %d, y: %d)", point.x + m_ptTextPos.x + 1, point.y + m_ptTextPos.y + 1);

	point.x = (point.x + 2) * m_charSize.cx;
	point.y = point.y * m_charSize.cy;

	SetCaretPos(point);

	((CMainFrame *)AfxGetMainWnd())->m_wndStatusBar.SetPaneText(1, strPos);
}

// détermine la position d'un caractère dans une chaine
int CEditorView::GetCharPos(int point, int nChar, int nLine) // Position du caractère
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	int length = m_arrayText[nLine].GetLength();
	int x = point;

	if (nChar > length) nChar = length;

	for (int i = 0 ; i < nChar ; i++)
	{
		switch(m_arrayText[nLine][i])
		{
		case 0x09:
			x += 4;
			break;
		default:
			x++;
		}
	}	

	return x;
}

// Dessine une chaine de carctères
void CEditorView::DrawString(CDC *pDC, CPoint point, CString &str)
{
	HideCaret();

	CFont *pOldFont;
	CString str1 = "";

	pOldFont = (CFont *)pDC->SelectObject(&m_ftFont);

	int length = str.GetLength();
	int x = point.x * m_charSize.cx, y = point.y * m_charSize.cy;

	for (int i = 0 ; i < length ; i++)
	{
		switch(str[i])
		{
		case 0x09:
			str1 += "    ";
			break;
		default:
			str1 += str[i];
		}
	}

	pDC->TextOut(x, y, str1);
	pDC->SelectObject(pOldFont);

	ShowCaret();
}

int CEditorView::GetCharRange(int editPos, int nLine)
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	int length = m_arrayText[nLine].GetLength();
	int x, i;

	x = i = 0;

	while (x < editPos && i < length)
	{
		switch(m_arrayText[nLine][i])
		{
		case 0x09:
			x += 4;
			break;
		default:
			x++;
		}

		if (x < editPos) 
			i++;
		else
			if (x == editPos)
				return (i + 1);
			else
				return i;
	}

	return i;
}

int CEditorView::IndentLine(int nLine, int fromLine, int curPos)
{
	CArray<CString, CString> &m_arrayText = *m_pArrayText;

	int i = 0;

	while (i < curPos && m_arrayText[fromLine][i] == 0x09) i++;
	
	for (int j = 0 ; j < i ; j++)
		m_arrayText[nLine] = "\011" + m_arrayText[nLine];

	return i;
}

void CEditorView::EditPosValidityVerif(CDC *pDC)
{
	if (m_ptEditPos.y >= (m_ptTextPos.y + m_WindowMax))
	{
		m_ptTextPos.y = (m_ptEditPos.y - m_WindowMax + 1);
		OnDraw(pDC);
	}

	if ((m_ptTextPos.y - m_ptEditPos.y - 1) >= 0)
	{
		m_ptTextPos.y = m_ptEditPos.y;
		OnDraw(pDC);
	}
}

BOOL CEditorView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (nHitTest == HTCLIENT && hCursor)
	{
		SetCursor(hCursor);return TRUE;
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CEditorView::DrawString(CDC *pDC, CPoint point, int nLine, int startSel, int endSel, int from)
{
	HideCaret();

	CString str[3] = {"", "", ""};
	
	char ch[256];
	memset(ch, ' ', sizeof(ch));
	ch[255] = 0;
	
	int length = m_pArrayText->GetAt(nLine).GetLength();
	CString s = GetString(nLine, from);
	int x = point.x * m_charSize.cx, y = point.y * m_charSize.cy;;

	startSel -= from;
	endSel -= from;

	if (startSel > length) startSel = length;
	if (endSel > length) endSel = length;

	if (startSel != endSel && endSel != 0 && startSel < endSel)
	{
		str[0] = DrawTabs(s.Left(startSel + 1 - 1));
		str[1] = DrawTabs(s.Mid(startSel, endSel - startSel));
		str[2] = DrawTabs(s.Right(length - endSel));
	}
	else
		str[0] = DrawTabs(s);

	CFont *pOldFont;
	pOldFont = (CFont *)pDC->SelectObject(&m_ftFont);

	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->TextOut(x + str[0].GetLength() * m_charSize.cx, y, str[1]);

	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->SetBkColor(RGB(255, 255, 255));
	pDC->TextOut(x, y, str[0]);
	pDC->TextOut(x + (str[0].GetLength() + str[1].GetLength()) * m_charSize.cx, y, str[2]);
	pDC->TextOut(x + (str[0].GetLength() + str[1].GetLength() + str[2].GetLength())
				   * m_charSize.cx, y, ch);

	pDC->SelectObject(pOldFont);

	ShowCaret();
}

CString CEditorView::DrawTabs(CString str)
{
	CString str1 = "";
	int length = str.GetLength();

	for (int i = 0 ; i < length ; i++)
	{
		switch(str[i])
		{
		case 0x09:
			str1 += "    ";
			break;
		default:
			str1 += str[i];
		}
	}

	return str1;
}

CPoint CEditorView::GetSelectedPart(int nLine)
{
	if (nLine < m_rcSelection.top || nLine > m_rcSelection.bottom) 
		return CPoint(-1, -1);
	
	int debut, fin;

	if (nLine == m_rcSelection.top) 
		debut = m_rcSelection.left;
	else
		debut = 0;

	if (nLine == m_rcSelection.bottom) 
		fin = m_rcSelection.right;
	else 
		fin = m_pArrayText->GetAt(nLine).GetLength();

	return CPoint(debut, fin);
}

void CEditorView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_rcSelection.Width() || m_rcSelection.Height());
}

void CEditorView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_rcSelection.Width() || m_rcSelection.Height());
}

void CEditorView::OnEditCopy() 
{
	CString str;
	LPTSTR lptstr;
	HGLOBAL hgl;
	
	if (OpenClipboard())
	{
		GetSelection(m_rcSelection, str);

		hgl = GlobalAlloc(GMEM_DDESHARE, str.GetLength() + 1);
		lptstr = (LPTSTR)GlobalLock(hgl);
		memcpy(lptstr, LPCTSTR(str), str.GetLength() + 1);
		GlobalUnlock(hgl); 

		SetClipboardData(CF_OEMTEXT, hgl);

		CloseClipboard();
	}
}

void CEditorView::OnEditCut() 
{
	
}

void CEditorView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(IsClipboardFormatAvailable(CF_OEMTEXT));
}

void CEditorView::OnEditPaste() 
{
	CClientDC dc(this);

	if (OpenClipboard())
	{
		HANDLE h = GetClipboardData(CF_OEMTEXT);

		char *ch = (char *)GlobalLock(h);

		do
		{
			switch(*ch)
			{
			case 0x09:
				OnTabulationKey();
				break;
			case 0x0a:
				OnEnterKey(FALSE);
				break;
			case 0x0d:
				if (*(ch + 1) == 0x0a) ch += 1;
				OnEnterKey(FALSE);
				break;
			default:
				OnOtherChar(*ch);
			}
		}
		while(*(++ch));

		GlobalUnlock(h);

		EditPosValidityVerif(&dc);
		OnDraw(&dc);

		SetCaretAt(m_ptEditPos - m_ptTextPos);
	}

	CloseClipboard();
}

// Interception des touches du clavier
void CEditorView::OnEnterKey(BOOL bIndent)
{
	CString str, str1;

	str = GetString(m_ptCurPos.y, m_ptCurPos.x);
	m_pArrayText->InsertAt(m_ptCurPos.y + 1, str);

	str1 = m_pArrayText->GetAt(m_ptCurPos.y);
	str1.Delete(m_ptCurPos.x, str.GetLength());
	m_pArrayText->SetAt(m_ptCurPos.y, str1);

	m_ptCurPos.x = (bIndent) ? IndentLine(m_ptCurPos.y + 1, m_ptCurPos.y, m_ptCurPos.x) : 0;
	m_ptCurPos.y++;

	m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
	m_ptEditPos.y++;	

	SetModified();
}

void CEditorView::OnTabulationKey()
{
	CString str;
	
	str = m_pArrayText->GetAt(m_ptCurPos.y);
	str.Insert(m_ptCurPos.x, 0x09);
	m_pArrayText->SetAt(m_ptCurPos.y, str);

	m_ptCurPos.x++;
	m_ptEditPos.x += 4;

	SetModified();
}

void CEditorView::OnOtherChar(int nChar)
{
	CString str;

	str = m_pArrayText->GetAt(m_ptCurPos.y);
	str.Insert(m_ptCurPos.x, nChar);
	m_pArrayText->SetAt(m_ptCurPos.y, str);

	m_ptCurPos.x++;
	m_ptEditPos.x++;

	SetModified();
}

void CEditorView::OnBackspaceKey()
{
	CString str;

	if (m_ptCurPos.x)
	{
		switch (m_pArrayText->GetAt(m_ptCurPos.y).GetAt(m_ptCurPos.x - 1))
		{
		case 0x09:
			m_ptEditPos.x -= 4;
			break;
		default:
			m_ptEditPos.x--;
		}

		str = m_pArrayText->GetAt(m_ptCurPos.y);
		str.Delete(m_ptCurPos.x - 1);
		m_pArrayText->SetAt(m_ptCurPos.y, str);
		m_ptCurPos.x--;
	}
	else
		if (m_ptCurPos.y)
		{
			m_ptCurPos.y--;
			m_ptCurPos.x = m_pArrayText->GetAt(m_ptCurPos.y).GetLength();

			m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
			m_ptEditPos.y--;

			str = m_pArrayText->GetAt(m_ptCurPos.y);
			str.Insert(m_ptCurPos.x, GetString(m_ptCurPos.y + 1, 0));
			m_pArrayText->SetAt(m_ptCurPos.y, str);
			m_pArrayText->RemoveAt(m_ptCurPos.y + 1);
		}

	SetModified();
}

void CEditorView::OnRightLeftKey(int nChar)
{
	m_ptCurPos.x = GetCharRange(m_ptEditPos.x, m_ptEditPos.y);
	m_ptCurPos.y = m_ptEditPos.y;

	char car;
	int length = m_pArrayText->GetAt(m_ptCurPos.y).GetLength();

	switch(nChar)
	{
	case VK_RIGHT:	
		if (m_ptCurPos.x < length)
		{
			car = m_pArrayText->GetAt(m_ptCurPos.y).GetAt(m_ptCurPos.x);
			switch (car)
			{
			case 0x09:
				m_ptEditPos.x += 4;
				break;
			default:
				m_ptEditPos.x++;
			}
			m_ptCurPos.x++;
		}
		else
			if ((m_ptCurPos.y + 1) < m_pArrayText->GetSize())
			{
				m_ptCurPos.x = 0;
				m_ptCurPos.y++;

				m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
				m_ptEditPos.y++;
			}
		break;
	case VK_LEFT:
		if (m_ptCurPos.x)
		{
			car = m_pArrayText->GetAt(m_ptCurPos.y).GetAt(m_ptCurPos.x - 1);
			switch (car)
			{
			case 0x09:
				m_ptEditPos.x -= 4;
				break;
			default:
				m_ptEditPos.x--;
			}
			m_ptCurPos.x--;
		}
		else
			if (m_ptCurPos.y)
			{
				m_ptCurPos.y--;
				m_ptCurPos.x = length;

				m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
				m_ptEditPos.y--;
			}
		break;
	}
}

void CEditorView::OnUpDownKey(int nChar)
{
	switch(nChar)
	{
	case VK_DOWN:
		if ((m_ptEditPos.y + 1) < m_pArrayText->GetSize())
		{
			m_ptEditPos.y++;

			int curPos = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);

			m_ptEditPos.x = GetCharPos(0, GetCharRange(curPos, m_ptEditPos.y), m_ptEditPos.y); 
		}
		break;
	case VK_UP:
		if (m_ptEditPos.y)
		{
			m_ptEditPos.y--;

			int curPos = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);

			m_ptEditPos.x = GetCharPos(0, GetCharRange(curPos, m_ptEditPos.y), m_ptEditPos.y); 
		}
		break;
	}
}

void CEditorView::OnHomeEndKey(int nChar)
{
	switch(nChar)
	{
	case VK_HOME:
		m_ptCurPos.x = GetHomePos(m_ptCurPos.x, m_ptEditPos.y);
		m_ptCurPos.y = m_ptEditPos.y;
		m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptEditPos.y);
		break;
	case VK_END:
		m_ptCurPos.y = m_ptEditPos.y;
		m_ptCurPos.x = m_pArrayText->GetAt(m_ptCurPos.y).GetLength();
		m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptEditPos.y);
		break;
	}
}

void CEditorView::OnDeleteKey()
{
	CString str;

	m_ptCurPos.x = GetCharRange(m_ptEditPos.x, m_ptEditPos.y);
	m_ptCurPos.y = m_ptEditPos.y;

	str = m_pArrayText->GetAt(m_ptCurPos.y);
	str.Delete(m_ptCurPos.x);
	m_pArrayText->SetAt(m_ptCurPos.y , str);

	SetModified();

	Invalidate();
}

void CEditorView::SetModified()
{
	if (!GetDocument()->m_bModified)
	{
		GetDocument()->SetModifiedFlag();
		GetDocument()->m_bModified = TRUE;

		GetDocument()->SetTitle(GetDocument()->GetTitle() + "*");
	}
}

void CEditorView::GetSelection(CRect rc, CString &str)
{
	int i;
	CPoint sel;

	if (rc.bottom < rc.top)
	{
		i = rc.bottom;
		rc.bottom = rc.top;
		rc.top = i;

		i = rc.right;
		rc.right = rc.left;
		rc.left = i;
	}
	else
	if (rc.bottom == rc.top)
	{
		i = rc.right;
		rc.right = rc.left;
		rc.left = i;
	}

	str = "";
	for (i = rc.top ; i <= rc.bottom ; i++)
	{
		if ((i + m_ptTextPos.y) < m_pArrayText->GetSize())
		{
			sel = GetSelectedPart(i);
			str += GetString(i, sel.x, sel.y); 
		}
		str += (i != rc.bottom) ? "\n" : "";
	}
}

CString CEditorView::GetString(int nLine, int startSel, int endSel)
{
	if (nLine < m_pArrayText->GetSize())
		return m_pArrayText->GetAt(nLine).Mid(startSel, endSel - startSel);

	return CString("");
}

void CEditorView::OnSelection(CDC *pDC, int sel)
{
	if (GetAsyncKeyState(VK_SHIFT) || sel) 
	{
		CPoint curPos = CPoint(GetCharRange(m_ptEditPos.x, m_ptEditPos.y), m_ptEditPos.y);
		switch(m_selState)
		{
		case SELECT_NONE:
			m_selState = SELECTING;
			m_rcSelection.left = curPos.x;
			m_rcSelection.right = curPos.x;
			m_rcSelection.top = curPos.y;
			m_rcSelection.bottom = curPos.y;
			m_ptSelPos.x = curPos.x;
			m_ptSelPos.y = curPos.y;
			break;
		case SELECTING:
			if ((curPos.x >= m_ptSelPos.x && curPos.y == m_ptSelPos.y) || 
				curPos.y > m_ptSelPos.y)
			{
				m_rcSelection.left = m_ptSelPos.x; 
				m_rcSelection.top = m_ptSelPos.y;
				m_rcSelection.right = curPos.x;
				m_rcSelection.bottom = curPos.y;
			}
			else
			{
				m_rcSelection.left = curPos.x;
				m_rcSelection.top = curPos.y;
				m_rcSelection.right = m_ptSelPos.x; 
				m_rcSelection.bottom = m_ptSelPos.y;
			}
			break;
		}
		OnDraw(pDC);
	}
	else
	{
		m_rcSelection = CRect(0, 0, 0, 0);
		m_selState = SELECT_NONE;

		OnDraw(pDC);
	}
}

void CEditorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);

	m_ptCurPos.y = point.y / m_charSize.cy + m_ptTextPos.y;
	m_ptCurPos.y = ((m_ptCurPos.y + 1) < m_pArrayText->GetSize()) ? m_ptCurPos.y : (m_pArrayText->GetSize() - 1);
	m_ptCurPos.y = (m_ptCurPos.y >= 0) ? m_ptCurPos.y : 0;
	point.x -= m_charSize.cx * 2;
	m_ptCurPos.x = GetCharRange(point.x / m_charSize.cx, m_ptCurPos.y);
	
	m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
	m_ptEditPos.y = m_ptCurPos.y;
	
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnSelection(&dc, FALSE);
	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}

void CEditorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (GetCapture() != this) return;
	
	CClientDC dc(this);

	m_ptCurPos.y = point.y / m_charSize.cy + m_ptTextPos.y;
	m_ptCurPos.y = ((m_ptCurPos.y + 1) < m_pArrayText->GetSize()) ? m_ptCurPos.y : (m_pArrayText->GetSize() - 1);
	m_ptCurPos.y = (m_ptCurPos.y >= 0) ? m_ptCurPos.y : 0;
	point.x -= m_charSize.cx * 2;
	m_ptCurPos.x = GetCharRange(point.x / m_charSize.cx, m_ptCurPos.y);
	
	m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
	m_ptEditPos.y = m_ptCurPos.y;
	
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnSelection(&dc, TRUE);

	CView::OnMouseMove(nFlags, point);
}

void CEditorView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (GetCapture() != this) return;
	
	ReleaseCapture();

	CClientDC dc(this);

	m_ptCurPos.y = point.y / m_charSize.cy + m_ptTextPos.y;
	m_ptCurPos.y = ((m_ptCurPos.y + 1) < m_pArrayText->GetSize()) ? m_ptCurPos.y : (m_pArrayText->GetSize() - 1);
	m_ptCurPos.y = (m_ptCurPos.y > 0) ? m_ptCurPos.y : 0;
	point.x -= m_charSize.cx * 2;
	m_ptCurPos.x = GetCharRange(point.x / m_charSize.cx, m_ptCurPos.y);
	
	m_ptEditPos.x = GetCharPos(0, m_ptCurPos.x, m_ptCurPos.y);
	m_ptEditPos.y = m_ptCurPos.y;
	
	SetCaretAt(m_ptEditPos - m_ptTextPos);

	OnSelection(&dc, TRUE);

	CView::OnLButtonUp(nFlags, point);
}
