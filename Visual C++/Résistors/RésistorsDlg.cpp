// RésistorsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Résistors.h"
#include "RésistorsDlg.h"

#include "Resistor.h"

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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRsistorsDlg dialog

CRsistorsDlg::CRsistorsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRsistorsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRsistorsDlg)
	m_couleur = _T("");
	m_resistance = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bandColor[0] = "Noir";
	m_bandColor[1] = "Marron";
	m_bandColor[2] = "Rouge";
	m_bandColor[3] = "Orange";
	m_bandColor[4] = "Jaune";
	m_bandColor[5] = "Vert";
	m_bandColor[6] = "Bleu";
	m_bandColor[7] = "Violet";
	m_bandColor[8] = "Gris";
	m_bandColor[9] = "Blanc";
	m_bandColor[10] = "Or";
	m_bandColor[11] = "Argent";
}

void CRsistorsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRsistorsDlg)
	DDX_Control(pDX, IDC_BANDE4, m_bande4Ctrl);
	DDX_Control(pDX, IDC_BANDE3, m_bande3Ctrl);
	DDX_Control(pDX, IDC_BANDE2, m_bande2Ctrl);
	DDX_Control(pDX, IDC_BANDE1, m_bande1Ctrl);
	DDX_Control(pDX, IDC_BANDE0, m_bande0Ctrl);
	DDX_Control(pDX, IDC_NB_BANDES, m_nbBandesCtrl);
	DDX_Text(pDX, IDC_COULEUR, m_couleur);
	DDX_Text(pDX, IDC_RESISTANCE, m_resistance);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRsistorsDlg, CDialog)
	//{{AFX_MSG_MAP(CRsistorsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_NB_BANDES, OnReleasedcaptureNbBandes)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_BANDE0, OnReleasedcaptureBande0)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_BANDE1, OnReleasedcaptureBande1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_BANDE2, OnReleasedcaptureBande2)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_BANDE3, OnReleasedcaptureBande3)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_BANDE4, OnReleasedcaptureBande4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRsistorsDlg message handlers

BOOL CRsistorsDlg::OnInitDialog()
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
	
	m_nbBandesCtrl.SetRange(3, 4);
	m_nbBandesCtrl.SetPageSize(1);
	m_nbBandesCtrl.SetPos(3);

	m_bande0Ctrl.SetRange(0, 9);
	m_bande0Ctrl.SetPageSize(1);
	m_bande0Ctrl.SetPos(0);

	m_bande1Ctrl.SetRange(0, 9);
	m_bande1Ctrl.SetPageSize(1);
	m_bande1Ctrl.SetPos(0);

	m_bande4Ctrl.SetRange(0, 4);
	m_bande4Ctrl.SetPageSize(1);
	m_bande4Ctrl.SetPos(0);

	DisplayBandSliders();

	UpdateWindow();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRsistorsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRsistorsDlg::OnPaint() 
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
		CClientDC dc(this);
		CRect rc;
		
		GetClientRect(&rc);
		rc.left += 10;
		rc.right = rc.left + 170;
		rc.top += 10;
		rc.bottom -= 10;

		r.nbBandes = m_nbBandesCtrl.GetPos();
		r.Draw(&dc, rc);

		DisplayColors();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRsistorsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRsistorsDlg::DisplayBandSliders()
{
	m_nbBandesCtrl.UpdateData();
	int pos = m_nbBandesCtrl.GetPos();

	if (pos == 3)
		m_bande2Ctrl.SetRange(0, 8);	
	else
		m_bande2Ctrl.SetRange(0, 9);

	
	if (pos == 4)
	{
		m_bande3Ctrl.ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATICBAND4)->ShowWindow(SW_SHOW);
		m_bande3Ctrl.SetRange(0, 8);
	}
	else	
	{
		m_bande3Ctrl.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATICBAND4)->ShowWindow(SW_HIDE);
	}

	m_bande2Ctrl.VerifyPos();
	m_bande3Ctrl.VerifyPos();

	m_bande2Ctrl.SetPageSize(1);
	m_bande3Ctrl.SetPageSize(1);

	if (pos == 4)
		r.bandes[2] = (r.bandes[2] > 9) ? r.bandes[2] - 3 : r.bandes[2];
	else
		r.bandes[2] = (r.bandes[2] > 6) ? r.bandes[2] + 3 : r.bandes[2];

	m_bande2Ctrl.SetPos(r.bandes[2]);
	m_bande3Ctrl.SetPos(r.bandes[3]);

	Invalidate();
}


void CRsistorsDlg::OnReleasedcaptureNbBandes(NMHDR* pNMHDR, LRESULT* pResult) 
{
	DisplayBandSliders();

	*pResult = 0;
}

void CRsistorsDlg::OnReleasedcaptureBande0(NMHDR* pNMHDR, LRESULT* pResult) 
{
	r.bandes[0] = m_bande0Ctrl.GetPos();
	Invalidate();

	*pResult = 0;
}

void CRsistorsDlg::OnReleasedcaptureBande1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	r.bandes[1] = m_bande1Ctrl.GetPos();
	Invalidate();

	*pResult = 0;
}

void CRsistorsDlg::OnReleasedcaptureBande2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int pos = m_bande2Ctrl.GetPos();

	if (r.nbBandes != 3)
	{
		r.bandes[2] = pos;
	}
	else
		r.bandes[2] = (pos > 6) ? (pos + 3) : pos;

	Invalidate();

	*pResult = 0;
}

void CRsistorsDlg::OnReleasedcaptureBande3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int pos = m_bande3Ctrl.GetPos();

	if (r.nbBandes != 4)
	{
		r.bandes[3] = pos;
	}
	else
		r.bandes[3] = (pos > 6) ? (pos + 3) : pos;

	Invalidate();

	*pResult = 0;
}

void CRsistorsDlg::OnReleasedcaptureBande4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	r.bandes[4] = m_bande4Ctrl.GetPos();
	Invalidate();

	*pResult = 0;
}

void CRsistorsDlg::DisplayColors()
{
	m_couleur = "";
	m_resistance = "";

	for(int i = 0; i < r.nbBandes ; i++)
		m_couleur += m_bandColor[r.bandes[i]] + ", ";

	for(i = 0; i < r.nbBandes  - 1; i++)
		m_resistance += r.bandes[i] + 48;

	m_resistance += " x 10^";
	if (r.bandes[i] > 9) 
	{
		m_resistance += "-";
		m_resistance += r.bandes[i] - 9 + 48;
	}
	else
		m_resistance += 48 + r.bandes[i];

	switch(r.bandes[4])
	{
	case 0 : m_resistance += " ± 20%"; break;
	case 1 : m_couleur += "Marron"; 
			 m_resistance += " ± 1%"; break;
	case 2 : m_couleur += "Rouge";  
			 m_resistance += " ± 2%"; break;
	case 3 : m_couleur += "Or";  
			 m_resistance += " ± 5%"; break;
	case 4 : m_couleur += "Argent";  
			 m_resistance += " ± 10%"; break;
	}
	
	UpdateData(FALSE);
}
