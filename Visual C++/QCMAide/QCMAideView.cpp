// QCMAideView.cpp : implementation of the CQCMAideView class
//

#include "stdafx.h"
#include "QCMAide.h"

#include "QCMAideDoc.h"
#include "QCMAideView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQCMAideView

IMPLEMENT_DYNCREATE(CQCMAideView, CFormView)

BEGIN_MESSAGE_MAP(CQCMAideView, CFormView)
	//{{AFX_MSG_MAP(CQCMAideView)
	ON_BN_CLICKED(IDC_SUIVANT, OnSuivant)
	ON_BN_CLICKED(IDC_PRECEDENT, OnPrecedent)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_COMMAND(ID_FICHIER_AFFICHERLANOTE, OnFichierAfficherlanote)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
	ON_COMMAND_RANGE(100, 200, OnButtonClicked)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQCMAideView construction/destruction

CQCMAideView::CQCMAideView()
	: CFormView(CQCMAideView::IDD)
{
	//{{AFX_DATA_INIT(CQCMAideView)
	m_question = _T("");
	m_moyenne = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pBtnArray = NULL;
	m_nBtnCount = 0;
	m_nCurrentPos = 0;
}

CQCMAideView::~CQCMAideView()
{
	if (m_pBtnArray) delete [] m_pBtnArray;
}

void CQCMAideView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQCMAideView)
	DDX_Text(pDX, IDC_QUESTION, m_question);
	DDX_Text(pDX, IDC_MOYENNE, m_moyenne);
	//}}AFX_DATA_MAP
}

BOOL CQCMAideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CQCMAideView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// Chargement du QCM
	BOOL succeed = FALSE;
	CString szText;

	szText = AfxGetApp()->GetProfileString("QCMLocation", "Path", "");

	while (szText == "")
		szText = GetDocument()->GetQCMFileName();
	
	m_qcmClass.SetFileName(szText);
	succeed = m_qcmClass.LoadData();

	// On charge le qcm
	while (!succeed)
	{
		if (MessageBox("Voulez vous indiquer l'emplacement du fichier QCM ?", 
					   "Recherche du QCM", MB_YESNO | MB_ICONQUESTION) != IDYES) exit(-1);

		szText = GetDocument()->GetQCMFileName();
		m_qcmClass.SetFileName(szText);
		succeed = m_qcmClass.LoadData();			
	} 

	AfxGetApp()->WriteProfileString("QCMLocation", "Path", szText);

	// On initialise les cases à cocher
	InitButtons();

	InitWindow(0);

	m_moyenne.Format("%.2f", m_qcmClass.GetMark());
	UpdateData(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CQCMAideView printing

BOOL CQCMAideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CQCMAideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CQCMAideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CQCMAideView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CQCMAideView diagnostics

#ifdef _DEBUG
void CQCMAideView::AssertValid() const
{
	CFormView::AssertValid();
}

void CQCMAideView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CQCMAideDoc* CQCMAideView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQCMAideDoc)));
	return (CQCMAideDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQCMAideView message handlers

void CQCMAideView::InitButtons()
{
	m_nBtnCount = m_qcmClass.GetMaxPropositions();
	m_pBtnArray = new CButton [m_nBtnCount];

	CRect rc, rc1;
	GetWindowRect(&rc);

	rc -= rc.TopLeft();

	for (int i = 0 ; i < m_nBtnCount ; i++)
	{
		rc1.top = rc.top + 25 * i + 120;
		rc1.bottom = rc1.top + 25;
		rc1.left = rc.left + 25;
		rc1.right = rc.right - 15;

		m_pBtnArray[i].Create("Réponse 1", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX , rc1, this, 100 + i);
		m_pBtnArray[i].SetRedraw();
		m_pBtnArray[i].SetFont(GetFont());
	}
}

void CQCMAideView::InitWindow(int nQuestion)
{
	int choix = m_qcmClass.GetPropositionCount(nQuestion);
	CRect rc, rc1;

	m_question = m_qcmClass.GetQuestion(nQuestion);
	for (int i = 0 ; i < m_nBtnCount ; i++)
		if (i < choix)
		{
			m_pBtnArray[i].SetWindowText(m_qcmClass.GetPropostion(nQuestion, i));
			m_pBtnArray[i].SetCheck(m_qcmClass.IsPropChecked(nQuestion, i));
			m_pBtnArray[i].ShowWindow(SW_SHOW);
		}
		else
			m_pBtnArray[i].ShowWindow(SW_HIDE);


	if (!nQuestion)
		GetDlgItem(IDC_PRECEDENT)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_PRECEDENT)->EnableWindow(TRUE);

	if (nQuestion == m_qcmClass.GetQuestionCount() - 1)
		GetDlgItem(IDC_SUIVANT)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_SUIVANT)->EnableWindow(TRUE);

	UpdateData(FALSE);
}

void CQCMAideView::OnSuivant() 
{
	InvalidateButtons();
	// m_moyenne.Format("%.2f", m_qcmClass.GetMark());

	InitWindow(++m_nCurrentPos);	
}

void CQCMAideView::OnPrecedent() 
{
	InvalidateButtons();
	// m_moyenne.Format("%.2f", m_qcmClass.GetMark());

	InitWindow(--m_nCurrentPos);
}

void CQCMAideView::InvalidateButtons()
{
	int choix = m_qcmClass.GetPropositionCount(m_nCurrentPos);
	
	for (int i = 0 ; i < m_nBtnCount ; i++)
		if (i < choix)
		{
			m_qcmClass.SetCheckProp(m_nCurrentPos, i, m_pBtnArray[i].GetCheck());
		}
}

void CQCMAideView::OnButtonClicked(int nID)
{
	InvalidateButtons();
	// m_moyenne.Format("%.2f", m_qcmClass.GetMark());

	UpdateData(FALSE);
}

void CQCMAideView::OnReset() 
{
	m_qcmClass.ResetProp();
	m_moyenne.Format("%.2f", m_qcmClass.GetMark());

	InitWindow(m_nCurrentPos = 0);
	UpdateData(FALSE);
}

void CQCMAideView::OnFichierAfficherlanote() 
{
	m_moyenne.Format("%.2f", m_qcmClass.GetMark());
	UpdateData(FALSE);	
}
