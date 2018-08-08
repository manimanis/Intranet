// FileJoinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileJoin.h"
#include "FileJoinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

typedef struct {
	int jfSize;
	int jfReste;
	int jfTailleBloc;
	int jfNbreBlocs;
} JoinFileHeader;

/////////////////////////////////////////////////////////////////////////////
// CFileJoinDlg dialog

CFileJoinDlg::CFileJoinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileJoinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileJoinDlg)
	m_resultat = _T("");
	m_fichier = _T("");
	m_taille = 0;
	m_taux = 0;
	m_sTaille = 0;
	m_sTaux = 0;
	m_jointonormal = 1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileJoinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileJoinDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Text(pDX, IDC_RESULTAT, m_resultat);
	DDX_Text(pDX, IDC_FICHIER, m_fichier);
	DDX_Text(pDX, IDC_EDIT_TAILLE, m_taille);
	DDX_Text(pDX, IDC_EDIT_TAUX, m_taux);
	DDX_Slider(pDX, IDC_TAILLEFRAGMENTS, m_sTaille);
	DDX_Slider(pDX, IDC_TAUXFRAGMENTATION, m_sTaux);
	DDX_Radio(pDX, IDC_JOINTONORMAL, m_jointonormal);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileJoinDlg, CDialog)
	//{{AFX_MSG_MAP(CFileJoinDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PARFICHIER, OnParfichier)
	ON_BN_CLICKED(IDC_PARRESULTAT, OnParresultat)
	ON_BN_CLICKED(IDC_CONVERTIR, OnConvertir)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TAILLEFRAGMENTS, OnCustomdrawTaillefragments)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TAUXFRAGMENTATION, OnCustomdrawTauxfragmentation)
	ON_EN_CHANGE(IDC_FICHIER, OnChangeFichier)
	ON_EN_CHANGE(IDC_RESULTAT, OnChangeResultat)
	ON_BN_CLICKED(IDC_JOINTONORMAL, OnJointonormal)
	ON_BN_CLICKED(IDC_NORMALTOJOIN, OnNormaltojoin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileJoinDlg message handlers

BOOL CFileJoinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	((CSliderCtrl *)GetDlgItem(IDC_TAUXFRAGMENTATION))->SetRange(3, 20, TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_TAILLEFRAGMENTS))->SetRange(8, 150, TRUE);

	GetDlgItem(IDC_CONVERTIR)->EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileJoinDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileJoinDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileJoinDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileJoinDlg::OnParres() 
{
	CFileDialog opFile(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						"Tous les fichier (*.*)|*.*|");	

	if (opFile.DoModal() == IDCANCEL) return;

	m_resultat = opFile.GetPathName();

	UpdateData(FALSE);
}

void CFileJoinDlg::OnParfichier() 
{
	CFileDialog opFile(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						"Tous les fichier (*.*)|*.*|");	

	if (opFile.DoModal() == IDCANCEL) return;

	m_fichier = opFile.GetPathName();

	UpdateData(FALSE);
	
	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier != "" && m_resultat != "")
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(FALSE);
}

void CFileJoinDlg::OnParresultat() 
{
	CFileDialog opFile(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
						"Tous les fichier (*.*)|*.*|");	

	if (opFile.DoModal() == IDCANCEL) return;

	m_resultat = opFile.GetPathName();

	UpdateData(FALSE);

	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier != "" && m_resultat != "")
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(FALSE);
}

void CFileJoinDlg::OnConvertir() 
{
	UpdateData();

	if (m_jointonormal == 1) 
		ConvertNormalToJoin();
	else
		ConvertJoinToNormal();

}

void CFileJoinDlg::OnCustomdrawTaillefragments(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData();

	m_taille = m_sTaille;	
	m_taux = m_sTaux;

	UpdateData(FALSE);
	*pResult = 0;
}

void CFileJoinDlg::OnCustomdrawTauxfragmentation(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData();

	m_taille = m_sTaille;	
	m_taux = m_sTaux;

	UpdateData(FALSE);
	*pResult = 0;
}

void CFileJoinDlg::OnChangeFichier() 
{
	UpdateData();
	
	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier != "" && m_resultat != "")
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(FALSE);
}

void CFileJoinDlg::OnChangeResultat() 
{
	UpdateData();
	
	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier != "" && m_resultat != "")
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_CONVERTIR)->EnableWindow(FALSE);
}

void CFileJoinDlg::OnJointonormal() 
{
	GetDlgItem(IDC_TAUXFRAGMENTATION)->EnableWindow(FALSE);	
	GetDlgItem(IDC_TAILLEFRAGMENTS)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TAUX)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_TAILLE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATICTAUX)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATICTAILLE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATICPARAM)->EnableWindow(FALSE);
}

void CFileJoinDlg::OnNormaltojoin() 
{
	GetDlgItem(IDC_TAUXFRAGMENTATION)->EnableWindow(TRUE);
	GetDlgItem(IDC_TAILLEFRAGMENTS)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_TAUX)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_TAILLE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICTAUX)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICTAILLE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICPARAM)->EnableWindow(TRUE);
}

void CFileJoinDlg::ConvertNormalToJoin()
{
	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier == "" && m_resultat == "") return;

	CFile f1, f2;
	unsigned char buffer[150 * 1024];
	JoinFileHeader jfHeader;
	
	f1.Open(m_fichier, CFile::modeRead);
	f2.Open(m_resultat, CFile::modeCreate | CFile::modeWrite);

	jfHeader.jfSize = sizeof(JoinFileHeader);
	jfHeader.jfReste = f1.GetLength() % (m_taille * 1024);
	jfHeader.jfNbreBlocs = f1.GetLength() / (m_taille * 1024);
	jfHeader.jfTailleBloc = m_taille * 1024;

	int *BlocPos = new int [jfHeader.jfNbreBlocs];
	int debutBlocs = jfHeader.jfSize + jfHeader.jfNbreBlocs * sizeof(int) + jfHeader.jfReste;

	m_progress.SetRange32(0, jfHeader.jfNbreBlocs);
	m_progress.SetPos(0);
	int l = 0, m = 0, n = 0;
	for (int i = 0 ; i < jfHeader.jfNbreBlocs ; i++)
	{
		BlocPos[i] = debutBlocs + jfHeader.jfTailleBloc * (jfHeader.jfNbreBlocs - l - 1);
		
		l = m + m_taux * ++n;
		if (l >= jfHeader.jfNbreBlocs)
		{
			m++;
			l = m;
			n = 0;
		}
	}

	f2.Write(&jfHeader, sizeof(JoinFileHeader));
	f2.Write(BlocPos, sizeof(int) * jfHeader.jfNbreBlocs);

	f1.Read(buffer, jfHeader.jfReste);
	f2.Write(buffer, jfHeader.jfReste);

	for (i = 0 ; i < jfHeader.jfNbreBlocs ; i++)
	{
		f1.Seek(BlocPos[i], CFile::begin);
		f1.Read(buffer, jfHeader.jfTailleBloc);
		f2.Write(buffer,jfHeader.jfTailleBloc);

		m_progress.SetPos(i);
	}

	delete [] BlocPos;

	f1.Close();
	f2.Close();

	AfxMessageBox("Opération terminée avec succes");
	m_progress.SetPos(0);
}

void CFileJoinDlg::ConvertJoinToNormal()
{
	m_fichier.TrimLeft();
	m_fichier.TrimRight();
	m_resultat.TrimLeft();
	m_resultat.TrimRight();

	if (m_fichier == "" && m_resultat == "") return;

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
		return;
	}

	int *BlocPos = new int [jfHeader.jfNbreBlocs];
	int dist = jfHeader.jfSize + sizeof(int) * jfHeader.jfNbreBlocs;
	f1.Read(BlocPos, sizeof(int) * jfHeader.jfNbreBlocs);
	
	f2.Open(m_resultat, CFile::modeWrite | CFile::modeCreate);

	f1.Read(buffer, jfHeader.jfReste);
	f2.Write(buffer, jfHeader.jfReste);

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

	AfxMessageBox("Opération terminée avec succes");
	m_progress.SetPos(0);
}

void CAboutDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CDialog::OnOK();
}
