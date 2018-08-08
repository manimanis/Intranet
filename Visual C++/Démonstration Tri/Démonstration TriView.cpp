// Démonstration TriView.cpp : implementation of the CDmonstrationTriView class
//

#include "stdafx.h"
#include "Démonstration Tri.h"

#include "Démonstration TriDoc.h"
#include "Démonstration TriView.h"

#include "PlaySpeed.h"
#include "Tri_Bulles.h"
#include "Tri_Selection.h"
#include "Recherche.h"
#include "DichotomicSearch.h"

#include "SearchDialog.h"
#include "SortSearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView

IMPLEMENT_DYNCREATE(CDmonstrationTriView, CView)

BEGIN_MESSAGE_MAP(CDmonstrationTriView, CView)
	//{{AFX_MSG_MAP(CDmonstrationTriView)
	ON_COMMAND(ID_BUBBLE_SORT, OnBubbleSort)
	ON_WM_TIMER()
	ON_COMMAND(ID_PLAY, OnPlay)
	ON_UPDATE_COMMAND_UI(ID_PLAY, OnUpdatePlay)
	ON_COMMAND(ID_STOP, OnStop)
	ON_UPDATE_COMMAND_UI(ID_STOP, OnUpdateStop)
	ON_COMMAND(ID_NEXT, OnNext)
	ON_UPDATE_COMMAND_UI(ID_NEXT, OnUpdateNext)
	ON_COMMAND(ID_SCRAMBLE, OnScramble)
	ON_UPDATE_COMMAND_UI(ID_SCRAMBLE, OnUpdateScramble)
	ON_UPDATE_COMMAND_UI(ID_BUBBLE_SORT, OnUpdateBubbleSort)
	ON_COMMAND(ID_EJECT, OnEject)
	ON_UPDATE_COMMAND_UI(ID_EJECT, OnUpdateEject)
	ON_COMMAND(ID_SELECTION_SORT, OnSelectionSort)
	ON_UPDATE_COMMAND_UI(ID_SELECTION_SORT, OnUpdateSelectionSort)
	ON_COMMAND(ID_DEMO_SPEED, OnDemoSpeed)
	ON_COMMAND(ID_SEARCH_VALUE, OnSearchValue)
	ON_UPDATE_COMMAND_UI(ID_SEARCH_VALUE, OnUpdateSearchValue)
	ON_COMMAND(ID_DICO_SEARCH, OnDicoSearch)
	ON_UPDATE_COMMAND_UI(ID_DICO_SEARCH, OnUpdateDicoSearch)
	ON_COMMAND(ID_ORDRE_CROISSANT, OnOrdreCroissant)
	ON_UPDATE_COMMAND_UI(ID_ORDRE_CROISSANT, OnUpdateOrdreCroissant)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView construction/destruction

CDmonstrationTriView::CDmonstrationTriView()
{
	m_pThread = NULL;

	Scramble();

	m_pTabCls = new CTableauClass(Tab, DEMO_TAB_SIZE);

	m_timeBase = 250;

	m_bOrdreCroissant = TRUE;
}

CDmonstrationTriView::~CDmonstrationTriView()
{
	if (m_pThread)
	{
		m_pThread->ExitInstance();
		delete m_pThread;
	}
}

BOOL CDmonstrationTriView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView drawing

void CDmonstrationTriView::OnDraw(CDC* pDC)
{
	CDmonstrationTriDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	m_pTabCls->Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView printing

BOOL CDmonstrationTriView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDmonstrationTriView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDmonstrationTriView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView diagnostics

#ifdef _DEBUG
void CDmonstrationTriView::AssertValid() const
{
	CView::AssertValid();
}

void CDmonstrationTriView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDmonstrationTriDoc* CDmonstrationTriView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDmonstrationTriDoc)));
	return (CDmonstrationTriDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDmonstrationTriView message handlers

void CDmonstrationTriView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
}

void CDmonstrationTriView::OnBubbleSort() 
{
	m_pThread = AfxBeginThread(RUNTIME_CLASS(CTri_Bulles));
	((CTri_Bulles *)m_pThread)->Init(this, m_bOrdreCroissant);
}

void CDmonstrationTriView::WndMessages()
{
	MSG msg;

	if (PeekMessage(&msg, m_hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void CDmonstrationTriView::OnTimer(UINT nIDEvent) 
{
	KillTimer(120);

	if (((CSortSearch *)m_pThread)->m_bEnd)
	{
		MessageBox("Fin de l'" + ((CSortSearch *)m_pThread)->m_szName, "Information", MB_ICONINFORMATION);
		OnEject();
		return;
	}

	m_pThread->ResumeThread();

	SetTimer(120, m_timeBase, NULL);

	CView::OnTimer(nIDEvent);
}

void CDmonstrationTriView::OnPlay() 
{
	SetTimer(120, m_timeBase, NULL);	
}

void CDmonstrationTriView::OnUpdatePlay(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread != NULL);
}

void CDmonstrationTriView::OnStop() 
{
	KillTimer(120);
}

void CDmonstrationTriView::OnUpdateStop(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread != NULL);
}

void CDmonstrationTriView::OnNext() 
{
	KillTimer(120);

	if (((CSortSearch *)m_pThread)->m_bEnd)
	{
		MessageBox("Fin de l'" + ((CSortSearch *)m_pThread)->m_szName, "Information", MB_ICONINFORMATION);
		OnEject();
		return;
	}

	m_pThread->ResumeThread();
}

void CDmonstrationTriView::OnUpdateNext(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread != NULL);
}

void CDmonstrationTriView::Scramble()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < DEMO_TAB_SIZE ; i++)
	{
		Tab[i] = rand() % 200;
	}
}

void CDmonstrationTriView::OnScramble() 
{
	Scramble();
	Invalidate();
}

void CDmonstrationTriView::OnUpdateScramble(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread == NULL);	
}

void CDmonstrationTriView::OnUpdateBubbleSort(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread == NULL);	
}

void CDmonstrationTriView::OnEject() 
{
	KillTimer(120);

	m_pThread->SuspendThread();
	TerminateThread(m_pThread->m_hThread, 0);
	delete m_pThread;

	m_pThread = NULL;

	Invalidate();
}

void CDmonstrationTriView::OnUpdateEject(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread != NULL);
}

void CDmonstrationTriView::OnSelectionSort() 
{
	m_pThread = AfxBeginThread(RUNTIME_CLASS(CTri_Selection));
	((CTri_Selection *)m_pThread)->Init(this, m_bOrdreCroissant);
}

void CDmonstrationTriView::OnUpdateSelectionSort(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread == NULL);
}

void CDmonstrationTriView::OnDemoSpeed() 
{
	CPlaySpeed psDlg;
	
	psDlg.m_nSpeed = m_timeBase;
	psDlg.m_vitesse.Format("%d", m_timeBase);

	if (psDlg.DoModal() == IDCANCEL) return;

	m_timeBase = psDlg.m_nSpeed;
}

void CDmonstrationTriView::OnSearchValue() 
{
	CSearchDialog sDlg(this);
	CString str;
	
	if (sDlg.DoModal() == IDCANCEL) return;

	m_pThread = AfxBeginThread(RUNTIME_CLASS(CRecherche));
	((CRecherche *)m_pThread)->Init(this, sDlg.m_nVal, m_bOrdreCroissant);
}

void CDmonstrationTriView::OnUpdateSearchValue(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread == NULL);
}

void CDmonstrationTriView::OnDicoSearch() 
{
	if (!IsSorted()) 
	{
		MessageBox("La recherche dichotomique se fait uniquement sur un tableau Trié.",
			       "Information", MB_ICONINFORMATION);
		return;
	}

	CSearchDialog sDlg(this);
	CString str;
	
	if (sDlg.DoModal() == IDCANCEL) return;

	m_pThread = AfxBeginThread(RUNTIME_CLASS(CDichotomicSearch));
	((CDichotomicSearch *)m_pThread)->Init(this, sDlg.m_nVal, m_bOrdreCroissant);
}

void CDmonstrationTriView::OnUpdateDicoSearch(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pThread == NULL);
}

BOOL CDmonstrationTriView::IsSorted()
{
	if (m_bOrdreCroissant)
	{
		for (int i = 0 ; i < DEMO_TAB_SIZE - 1 ; i++)
			if (Tab[i + 1] < Tab[i]) return FALSE;
	}
	else
	{
		for (int i = 0 ; i < DEMO_TAB_SIZE - 1 ; i++)
			if (Tab[i + 1] > Tab[i]) return FALSE;
	}

	return TRUE;
}

void CDmonstrationTriView::OnOrdreCroissant() 
{
	m_bOrdreCroissant = !m_bOrdreCroissant;
}

void CDmonstrationTriView::OnUpdateOrdreCroissant(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bOrdreCroissant);
	pCmdUI->Enable(m_pThread == NULL);
}
