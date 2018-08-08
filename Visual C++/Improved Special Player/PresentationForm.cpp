// PresentationForm.cpp : implementation file
//

#include "stdafx.h"
#include "Special Player.h"
#include "PresentationForm.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPresentationForm

IMPLEMENT_DYNCREATE(CPresentationForm, CFormView)

CPresentationForm::CPresentationForm()
	: CFormView(CPresentationForm::IDD)
{
	//{{AFX_DATA_INIT(CPresentationForm)
	//}}AFX_DATA_INIT
	m_presentation[0] = &m_presentation1;
	m_presentation[1] = &m_presentation2;
	m_presentation[2] = &m_presentation3;
	m_presentation[3] = &m_presentation4;
	m_presentation[4] = &m_presentation5;
	m_presentation[5] = &m_presentation6;
	m_presentation[6] = &m_presentation7;
	m_presentation[7] = &m_presentation8;
	m_presentation[8] = &m_presentation9;
	m_presentation[9] = &m_presentation10;

	dlgCreated = FALSE;
}

CPresentationForm::~CPresentationForm()
{
}

void CPresentationForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPresentationForm)
	DDX_Control(pDX, IDC_BUTTON10, m_presentation10);
	DDX_Control(pDX, IDC_BUTTON1, m_presentation1);
	DDX_Control(pDX, IDC_BUTTON2, m_presentation2);
	DDX_Control(pDX, IDC_BUTTON3, m_presentation3);
	DDX_Control(pDX, IDC_BUTTON4, m_presentation4);
	DDX_Control(pDX, IDC_BUTTON5, m_presentation5);
	DDX_Control(pDX, IDC_BUTTON6, m_presentation6);
	DDX_Control(pDX, IDC_BUTTON7, m_presentation7);
	DDX_Control(pDX, IDC_BUTTON8, m_presentation8);
	DDX_Control(pDX, IDC_BUTTON9, m_presentation9);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPresentationForm, CFormView)
	//{{AFX_MSG_MAP(CPresentationForm)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPresentationForm diagnostics

#ifdef _DEBUG
void CPresentationForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CPresentationForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPresentationForm message handlers

void CPresentationForm::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);

	m_wndTop = AfxGetApp()->GetProfileInt("Affichage", "Visible", FALSE);
	AfxGetApp()->WriteProfileInt("Affichage", "Visible", m_wndTop);

	InitPresentationPictures();
	InitPresentationClips();

	AfxGetMainWnd()->CenterWindow();

	UpdateWindow();
}


void CPresentationForm::InitPresentationPictures()
{
	CString Entree;
	CString Fichier[3];

	for(int i = 0; i < 10 ; i++)
	{
		// Image Normale
		Entree.Format("ImageNormale_%d", i + 1);
		Fichier[0] = AfxGetApp()->GetProfileString("Images", Entree, "");

		// Image Enfoncée
		Entree.Format("ImageEnfoncee_%d", i + 1);
		Fichier[1] = AfxGetApp()->GetProfileString("Images", Entree, "");

		// Image Over
		Entree.Format("ImageOver_%d", i + 1);
		Fichier[2] = AfxGetApp()->GetProfileString("Images", Entree, "");

		if (Fichier[0] == "" || Fichier[1] == "" || Fichier[2] == "")
		{
			m_presentation[i]->SetImages(IDB_NORMAL, IDB_CLICK, IDB_OVER);
		}
		else
			m_presentation[i]->SetImages(Fichier[0], Fichier[1], Fichier[2]);
	}
}

void CPresentationForm::InitPresentationClips()
{
	CString Entree;

	for(int i = 0; i < 10 ; i++)
	{
		Entree.Format("Clip_%d", i + 1);
		m_clipPath[i] = AfxGetApp()->GetProfileString("Clips", Entree, "");
	}
}

void CPresentationForm::OnButton1() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton2() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton3() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton4() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton5() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton6() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton7() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton8() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton9() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::OnButton10() 
{
	Ouvrir(m_clipPath[0]);
}

void CPresentationForm::Ouvrir(CString path)
{
	CWnd *pMainWnd;

	pMainWnd = AfxGetMainWnd();
	// AfxGetMainWnd()->ShowWindow(SW_HIDE);
	// AfxGetMainWnd()->UpdateWindow();

	if (!dlgCreated)
	{
		dlgCreated = TRUE;

		for (int i = 0 ; i < 10 ; i++)
		{
			m_presentation[i]->EnableWindow(FALSE);
		}

		//CSpecialPlayerDlg spDlg;

		//AfxGetApp()->m_pMainWnd = &spDlg;
		//spDlg.SetParent(NULL);
		//spDlg.m_fichier = path;
		//spDlg.DoModal();

		CMainFrame frm;
		frm.Create(NULL, "Ma fenêtre");
		frm.ShowWindow(SW_NORMAL);
		
		MessageBox("jkjk");
		frm.DestroyWindow();

		for (i = 0 ; i < 10 ; i++)
		{
			m_presentation[i]->EnableWindow(TRUE);
		}

		// AfxGetApp()->m_pMainWnd = pMainWnd;

		dlgCreated = FALSE;
	}

	// AfxGetMainWnd()->ShowWindow(SW_SHOW);
}


