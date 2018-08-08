// SpecialPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Special Player.h"
#include "SpecialPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDlg dialog


typedef struct {
	int jfSize;
	int jfReste;
	int jfTailleBloc;
	int jfNbreBlocs;
} JoinFileHeader;

CSpecialPlayerDlg::CSpecialPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpecialPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpecialPlayerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CSpecialPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpecialPlayerDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_MEDIAPLAYER1, m_mplayer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpecialPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CSpecialPlayerDlg)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialPlayerDlg message handlers

BOOL CSpecialPlayerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);

	GetTempPath(sizeof(m_tempPath), m_tempPath);
	strcat(m_tempPath, "\\Panneau de configuration.{21EC2020-3AEA-1069-A2DD-08002B30309D}");
	CreateDirectory(m_tempPath, NULL);

	HideAll();
	ShowWindow(SW_SHOW);
	CenterWindow();

	ConvertJoinToNormal();
	Lecture();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSpecialPlayerDlg::HideAll()
{
	GetDlgItem(IDC_MEDIAPLAYER1)->ModifyStyle(WS_VISIBLE, 0);
	GetDlgItem(IDC_BITMAP)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PROGRESS1)->ModifyStyle(WS_VISIBLE, 0);
	GetDlgItem(IDC_PATIENTEZ)->ModifyStyle(WS_VISIBLE, 0);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ModifyStyle(WS_VISIBLE, 0);
}

void CSpecialPlayerDlg::ShowAll()
{
	GetDlgItem(IDC_MEDIAPLAYER1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BITMAP)->ModifyStyle(WS_VISIBLE, 0);
	GetDlgItem(IDC_PROGRESS1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PATIENTEZ)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_IMPORTATION_MESSAGE)->ShowWindow(SW_SHOW);
}

void CSpecialPlayerDlg::OnOK()
{

}

void CSpecialPlayerDlg::OnCancel()
{

}

void CSpecialPlayerDlg::OnClose() 
{
	CDialog::OnCancel();
	CDialog::OnClose();
}

int CSpecialPlayerDlg::ConvertJoinToNormal()
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

void CSpecialPlayerDlg::Lecture()
{
	m_mplayer.SetFileName(m_resultat);
	m_mplayer.SetAutoStart(TRUE);
	m_mplayer.SetEnabled(TRUE);	
}

BEGIN_EVENTSINK_MAP(CSpecialPlayerDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CSpecialPlayerDlg)
	ON_EVENT(CSpecialPlayerDlg, IDC_MEDIAPLAYER1, 51 /* DisplayModeChange */, OnDisplayModeChangeMediaplayer1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CSpecialPlayerDlg::OnDisplayModeChangeMediaplayer1() 
{
	MessageBox("jkjk");
}
