// Demarrer WindowsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demarrer Windows.h"
#include "Demarrer WindowsDlg.h"
#include "ParametresArAn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


char msdos_sys[] =
//		"[Paths]\n"
//		"WinDir=C:\\winfr                                      \n"
//		"WinBootDir=C:\\winfr                                  \n"
		"HostWinBootDrv=C\n"
		"\n"
		"[Options]\n"
		"BootMulti=1\n"
		"BootGUI=1\n"
		"DoubleBuffer=1\n"
		"AutoScan=1\n"
		"WinVer=4.10.1998\n"
		";\n"
		";The following lines are required for compatibility with other programs.\n"
		";Do not remove them (MSDOS.SYS needs to be >1024 bytes).\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxa\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxb\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxc\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxd\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxe\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxf\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxg\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxh\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxi\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxj\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxk\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxl\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxm\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxn\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxo\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxq\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxr\n"
		";xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxs\n"
		"\n\n\n\n";

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

/////////////////////////////////////////////////////////////////////////////
// CDemarrerWindowsDlg dialog

CDemarrerWindowsDlg::CDemarrerWindowsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemarrerWindowsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemarrerWindowsDlg)
	m_rebootSystem = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_winArPath = AfxGetApp()->GetProfileString("OSPath", "Arabe", "");
	m_winFrPath = AfxGetApp()->GetProfileString("OSPath", "Francais", "");
}

void CDemarrerWindowsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemarrerWindowsDlg)
	DDX_Radio(pDX, IDC_ARABE, m_rebootSystem);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemarrerWindowsDlg, CDialog)
	//{{AFX_MSG_MAP(CDemarrerWindowsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REBOOT, OnReboot)
	ON_BN_CLICKED(IDC_PARAMETRES, OnParametres)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemarrerWindowsDlg message handlers

BOOL CDemarrerWindowsDlg::OnInitDialog()
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
	
	m_rebootSystem = AfxGetApp()->GetProfileInt("CurrentSystem", "Language", 0);
	SetWindowText("Windows Switcher");

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemarrerWindowsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDemarrerWindowsDlg::OnPaint() 
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
HCURSOR CDemarrerWindowsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemarrerWindowsDlg::OnReboot() 
{
	if (MessageBox("Voulez vous vraiment redémarrer?", "Attention", 
		MB_YESNO | MB_ICONEXCLAMATION | MB_DEFBUTTON2) == IDNO) return;

	SetFileAttributes("C:\\Msdos.sys", FILE_ATTRIBUTE_NORMAL | FILE_ATTRIBUTE_SYSTEM);
	CString str, winPath;

	CFile file;

	UpdateData();
	winPath = (!m_rebootSystem) ? m_winArPath : m_winFrPath;
	
	file.Open("C:\\Msdos.sys", CFile::modeCreate | CFile::modeWrite);

	str = "[Paths]\n";
	file.Write(LPCTSTR(str), str.GetLength());

	str = "WinDir=" + winPath + "\n";
	file.Write(LPCTSTR(str), str.GetLength());

	str = "WinBootDir=" + winPath + "\n";
	file.Write(LPCTSTR(str), str.GetLength());

	file.Write(msdos_sys, sizeof(msdos_sys));

	file.Close();

	SetFileAttributes("C:\\Msdos.sys", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);

	AfxGetApp()->WriteProfileInt("CurrentSystem", "Language", 1 - m_rebootSystem);

	ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0);
}

void CDemarrerWindowsDlg::OnParametres() 
{
	CParametresArAn parDlg;

	if (parDlg.DoModal() == IDCANCEL) return;

	m_winArPath = parDlg.m_winArPath;
	m_winFrPath = parDlg.m_winFrPath;
}


void CAboutDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	OnOK();
	
	CDialog::OnLButtonUp(nFlags, point);
}
