// Special PlayerView.cpp : implementation of the CSpecialPlayerView class
//

#include "stdafx.h"
#include "Special Player.h"

#include "Special PlayerDoc.h"
#include "Special PlayerView.h"

#include "direct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerView

IMPLEMENT_DYNCREATE(CSpecialPlayerView, CFormView)

BEGIN_MESSAGE_MAP(CSpecialPlayerView, CFormView)
	//{{AFX_MSG_MAP(CSpecialPlayerView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_DESTROY()
	ON_WM_DROPFILES()
	ON_COMMAND(ID_AFFICHAGE_TOUJOURSVISIBLE, OnAffichageToujoursvisible)
	ON_UPDATE_COMMAND_UI(ID_AFFICHAGE_TOUJOURSVISIBLE, OnUpdateAffichageToujoursvisible)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerView construction/destruction

typedef struct {
	int jfSize;
	int jfReste;
	int jfTailleBloc;
	int jfNbreBlocs;
} JoinFileHeader;

CSpecialPlayerView::CSpecialPlayerView()
	: CFormView(CSpecialPlayerView::IDD)
{
	//{{AFX_DATA_INIT(CSpecialPlayerView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_wndTop = m_convResult = FALSE;

}

CSpecialPlayerView::~CSpecialPlayerView()
{
}

void CSpecialPlayerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpecialPlayerView)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_MEDIAPLAYER1, m_mplayer);
	//}}AFX_DATA_MAP
}

BOOL CSpecialPlayerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSpecialPlayerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_wndTop = AfxGetApp()->GetProfileInt("Affichage", "Visible", FALSE);
	CRect rect;
	AfxGetMainWnd()->GetWindowRect(&rect);
	AfxGetApp()->WriteProfileInt("Affichage", "Visible", m_wndTop);


	if (m_wndTop)
	{	
		AfxGetMainWnd()->SetWindowPos(&wndTopMost, rect.left, rect.top, 
												  rect.Width(), rect.Height(), SWP_DRAWFRAME);
	}
	else
	{
		AfxGetMainWnd()->SetWindowPos(&wndNoTopMost, rect.left, rect.top, 
												  rect.Width(), rect.Height(), SWP_DRAWFRAME);
	}
	
	GetTempPath(sizeof(m_tempPath), m_tempPath);
	strcat(m_tempPath, "\\Panneau de configuration.{21EC2020-3AEA-1069-A2DD-08002B30309D}");
	CreateDirectory(m_tempPath, NULL);
	HideAll();
}

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerView printing

BOOL CSpecialPlayerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSpecialPlayerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpecialPlayerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSpecialPlayerView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerView diagnostics

#ifdef _DEBUG
void CSpecialPlayerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSpecialPlayerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSpecialPlayerDoc* CSpecialPlayerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpecialPlayerDoc)));
	return (CSpecialPlayerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerView message handlers

void CSpecialPlayerView::OnFileOpen() 
{
	CFileDialog fDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						"Fichiers Join (*.join)|*.join|");

	if (fDlg.DoModal() == IDCANCEL) return;

	if (fDlg.GetPathName() != m_fichier)
	{
		m_mplayer.SetFileName("");
		m_fichier = fDlg.GetPathName();
		UpdateWindow();
		DeleteFile(m_resultat);
		m_convResult = ConvertJoinToNormal();
	}
	if (m_convResult) Lecture();
}

int CSpecialPlayerView::ConvertJoinToNormal()
{
	m_resultat = CString(m_tempPath) + "\\Panneau de configuration.{21EC2020-3AEA-1069-A2DD-08002B30309D}";
	
	//*
	m_fichier.TrimLeft();
	m_fichier.TrimRight();

	if (m_fichier == "" && m_resultat == "") return FALSE;

	CFile f1, f2;
	JoinFileHeader jfHeader;
	unsigned char buffer[150 * 1024];

	f1.Open(m_fichier, CFile::modeRead);

	f1.Read(&jfHeader, sizeof(JoinFileHeader));
	if (jfHeader.jfSize != sizeof(JoinFileHeader))
	{
		MessageBox("Ce n'est pas un fichier au format Join ou format Join Invalide",
				   "Attention");
		f1.Close();
		return FALSE;
	}

	int *BlocPos = new int [jfHeader.jfNbreBlocs];
	int dist = jfHeader.jfSize + sizeof(int) * jfHeader.jfNbreBlocs;
	f1.Read(BlocPos, sizeof(int) * jfHeader.jfNbreBlocs);
	
	f2.Open(m_resultat, CFile::modeWrite | CFile::modeCreate);

	f1.Read(buffer, jfHeader.jfReste);
	f2.Write(buffer, jfHeader.jfReste);

	GetDlgItem(IDC_BITMAP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PATIENTEZ)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ShowWindow(SW_SHOW);
	UpdateWindow();
		
	m_progress.SetPos(0);
	m_progress.SetRange32(0, jfHeader.jfNbreBlocs);

	for (int i = 0 ; i < jfHeader.jfNbreBlocs ; i++)
	{
		f1.Read(buffer, jfHeader.jfTailleBloc);
		f2.Seek(BlocPos[i] - dist, CFile::begin);
		f2.Write(buffer,jfHeader.jfTailleBloc);

		m_progress.SetPos(i);
	}

	delete [] BlocPos;
	f1.Close();
	f2.Close();

	m_progress.SetPos(0);
	GetDlgItem(IDC_BITMAP)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PATIENTEZ)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ShowWindow(SW_HIDE);

	return TRUE;
	//  */
}

BEGIN_EVENTSINK_MAP(CSpecialPlayerView, CFormView)
    //{{AFX_EVENTSINK_MAP(CSpecialPlayerView)
	ON_EVENT(CSpecialPlayerView, IDC_MEDIAPLAYER1, -609 /* ReadyStateChange */, OnReadyStateChangeMediaplayer1, VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CSpecialPlayerView::OnReadyStateChangeMediaplayer1(long ReadyState) 
{
	if (ReadyState == 4) // amvComplete
	{
		m_mplayer.ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BITMAP)->ShowWindow(SW_HIDE);
	}
	else if (ReadyState == 0) // amvUninitialized
	{
		m_mplayer.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BITMAP)->ShowWindow(SW_SHOW);
	}
}

void CSpecialPlayerView::Lecture()
{
	m_mplayer.SetFileName(m_resultat);
	m_mplayer.SetAutoStart(TRUE);
	m_mplayer.SetEnabled(TRUE);	
}

void CSpecialPlayerView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	DeleteFile(m_resultat);
}

void CSpecialPlayerView::OnDropFiles(HDROP hDropInfo) 
{
	char buffer[4096];

	
	DragQueryFile(hDropInfo, 0, buffer, sizeof(buffer));
	
	if (CString(buffer) != m_fichier)
	{
		m_mplayer.SetFileName("");
		m_fichier = buffer;
		UpdateWindow();
		DeleteFile(m_resultat);
		m_convResult = ConvertJoinToNormal();
	}
	if (m_convResult) Lecture();

	CFormView::OnDropFiles(hDropInfo);
}

void CSpecialPlayerView::HideAll()
{
	GetDlgItem(IDC_MEDIAPLAYER1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BITMAP)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PATIENTEZ)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ShowWindow(SW_HIDE);
}

void CSpecialPlayerView::ShowAll()
{
	GetDlgItem(IDC_MEDIAPLAYER1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BITMAP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PATIENTEZ)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ShowWindow(SW_SHOW);
}

void CSpecialPlayerView::OnAffichageToujoursvisible() 
{
	m_wndTop = !m_wndTop;

	AfxGetApp()->WriteProfileInt("Affichage", "Visible", m_wndTop);

	CRect rect;
	AfxGetMainWnd()->GetWindowRect(&rect);

	if (m_wndTop)
	{	
		AfxGetMainWnd()->SetWindowPos(&wndTopMost, rect.left, rect.top, 
												  rect.Width(), rect.Height(), SWP_DRAWFRAME);
	}
	else
	{
		AfxGetMainWnd()->SetWindowPos(&wndNoTopMost, rect.left, rect.top, 
												  rect.Width(), rect.Height(), SWP_DRAWFRAME);
	}
}

void CSpecialPlayerView::OnUpdateAffichageToujoursvisible(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndTop);
}
