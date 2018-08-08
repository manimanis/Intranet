// Apache StarterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Apache Starter.h"
#include "Apache StarterDlg.h"

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
// CApacheStarterDlg dialog

CApacheStarterDlg::CApacheStarterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CApacheStarterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CApacheStarterDlg)
	m_etat = _T("Serveur Apache Arrêté");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CApacheStarterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CApacheStarterDlg)
	DDX_Text(pDX, IDC_STATE, m_etat);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CApacheStarterDlg, CDialog)
	//{{AFX_MSG_MAP(CApacheStarterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_PARAMS, OnParams)
	ON_COMMAND(ID_QUITTER, OnQuitter)
	ON_BN_CLICKED(IDC_CACHEDIALOG, OnCachedialog)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	ON_MESSAGE(MYWM_NOTIFYICON, OnTrayNotification)
	ON_COMMAND(MYWM_NOTIFYICON + 1, OnDemarrerArreter)
	ON_COMMAND(MYWM_NOTIFYICON + 2, OnShowDlg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CApacheStarterDlg message handlers

BOOL CApacheStarterDlg::OnInitDialog()
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

	m_szExec = AfxGetApp()->GetProfileString("Apache Path", "Path", "");
	if (m_szExec == "") OnParams();

	IsStarted();
	SetTimer(1200, 2000, NULL);
	KillAllPHP();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CApacheStarterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CApacheStarterDlg::OnPaint() 
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
HCURSOR CApacheStarterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CApacheStarterDlg::OnStart() 
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESIZE;
	si.wShowWindow = SW_HIDE;
	si.dwXSize = 50;
	si.dwYSize = 40;

	CString szPath = m_szExec.Mid(0, m_szExec.ReverseFind('\\'));
	CString szCmd = szPath + "\\Apache.exe -d \042" + szPath + "\042 -s";

	BOOL result =
	CreateProcess(NULL, (char*)LPCTSTR(szCmd),
				   NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, 
				   LPCTSTR(szPath),
				   &si,
				   &pi); 
}

void CApacheStarterDlg::OnStop() 
{
	KillAllPHP();

	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESIZE;
	si.wShowWindow = SW_HIDE;
	si.dwXSize = 50;
	si.dwYSize = 40;

	CString szPath = m_szExec.Mid(0, m_szExec.ReverseFind('\\'));
	CString szCmd = szPath + "\\Apache.exe -d \042" + szPath + "\042 -k shutdown";

	CreateProcess(NULL, (char*)LPCTSTR(szCmd),
				   NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, 
				   LPCTSTR(szPath),
				   &si,
				   &pi);	
}

void CApacheStarterDlg::OnOK()
{

}

void CApacheStarterDlg::OnCancel()
{	
	if (IsStarted()) 
		ShowWindow(SW_MINIMIZE);
	else {
		CDialog::OnCancel();
		DeleteTrayIcon(2300); 
	}
}

void CApacheStarterDlg::OnExit() 
{
	KillTimer(1200);
	DeleteTrayIcon(2300);

	CDialog::OnOK();
}

BOOL CApacheStarterDlg::IsStarted()
{
	HANDLE         hProcessSnap = NULL; 
	BOOL		   bTrouve   = FALSE;
    PROCESSENTRY32 pe32      = {0}; 
	CString szFile;
 
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

    if (hProcessSnap == (HANDLE)-1) 
        return (FALSE); 
 
    pe32.dwSize = sizeof(PROCESSENTRY32); 

    if (Process32First(hProcessSnap, &pe32)) 
    { 
        do 
        { 
			szFile = pe32.szExeFile;
			
			int pos = szFile.ReverseFind('\\');
			szFile = szFile.Mid(pos + 1);
			
			szFile.MakeLower();

			if (szFile == "apache.exe") bTrouve = TRUE;
        } 
        while (Process32Next(hProcessSnap, &pe32) && !bTrouve); 
    } 
 
    CloseHandle (hProcessSnap); 

	if (bTrouve) 
		m_etat = "Apache Démarré";
	else
		m_etat = "Apache Arrêté";

	m_state = bTrouve;

	UpdateData(FALSE);

	SetWindowText(m_etat);

    return bTrouve; 
}

void CApacheStarterDlg::OnTimer(UINT nIDEvent) 
{
	IsStarted();

	ModifyTrayIcon(2300);
	
	CDialog::OnTimer(nIDEvent);
}

void CApacheStarterDlg::OnParams() 
{
	CFileDialog fDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST,
					"apache.exe|apache.exe|");	
	CString szFile;

	if (fDlg.DoModal() == IDCANCEL) return;

	szFile = fDlg.GetPathName();
	
	m_szExec = szFile;

	AfxGetApp()->WriteProfileString("Apache Path", "Path", szFile);
}


void CApacheStarterDlg::AddTrayIcon(int uID)
{
	NOTIFYICONDATA nid;

	nid.cbSize = sizeof(NOTIFYICONDATA);

	if (m_etat == "Apache Démarré")
	{
		strcpy(nid.szTip, m_etat);
		nid.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	}
	else
	{
		strcpy(nid.szTip, m_etat);
		nid.hIcon = AfxGetApp()->LoadIcon(IDR_STOPPED);
	}

	strcpy(nid.szTip, "Apache Starter");
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
	nid.uCallbackMessage = MYWM_NOTIFYICON; 
	nid.uID = uID;
	nid.hWnd = m_hWnd;

	Shell_NotifyIcon(NIM_ADD, &nid);
}

void CApacheStarterDlg::DeleteTrayIcon(int uID)
{
	NOTIFYICONDATA nid;

	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.uID = uID;
	nid.hWnd = this->m_hWnd;

	Shell_NotifyIcon(NIM_DELETE, &nid);
}


void CApacheStarterDlg::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	UINT uID; 
    UINT uMouseMsg; 
 
    uID = (UINT) wParam; 
    uMouseMsg = (UINT) lParam; 
	
	CMenu menu, *pMenu;
	CPoint p;

	menu.LoadMenu(IDR_POPUP);

	pMenu = menu.GetSubMenu(0);

	pMenu->AppendMenu(MF_STRING, MYWM_NOTIFYICON + 2, "Afficher");

	if (m_etat == "Apache Démarré") 
		pMenu->AppendMenu(MF_STRING, MYWM_NOTIFYICON + 1, "Arrêter");
	else
		pMenu->AppendMenu(MF_STRING, MYWM_NOTIFYICON + 1, "Démarrer");

    if (uMouseMsg == WM_RBUTTONDOWN) { 
        switch (uID) { 
            case 2300:
				GetCursorPos(&p);
                pMenu->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
                break; 
 
            default: 
                break; 
        } 
     } 
     return; 
}

void CApacheStarterDlg::OnQuitter() 
{
	OnExit();	
}

void CApacheStarterDlg::OnDemarrerArreter()
{
	if (m_etat == "Apache Démarré") 
		OnStop();
	else
		OnStart();
}

void CApacheStarterDlg::OnCachedialog() 
{
	AddTrayIcon(2300);
	ShowWindow(SW_HIDE);
}

void CApacheStarterDlg::ModifyTrayIcon(int uID)
{
	NOTIFYICONDATA nid;

	nid.cbSize = sizeof(NOTIFYICONDATA);

	if (m_etat == "Apache Démarré")
	{
		strcpy(nid.szTip, m_etat);
		nid.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	}
	else
	{
		strcpy(nid.szTip, m_etat);
		nid.hIcon = AfxGetApp()->LoadIcon(IDR_STOPPED);
	}

	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
	nid.uCallbackMessage = MYWM_NOTIFYICON; 
	nid.uID = uID;
	nid.hWnd = m_hWnd;


	Shell_NotifyIcon(NIM_MODIFY, &nid);
}


void CApacheStarterDlg::OnShowDlg()
{
	DeleteTrayIcon(2300);
	ShowWindow(SW_SHOW);
}

void CApacheStarterDlg::OnAppAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CApacheStarterDlg::KillAllPHP()
{
	HANDLE         hProcessSnap = NULL, Handle; 
	BOOL		   bTrouve   = FALSE;
    PROCESSENTRY32 pe32      = {0}; 
	CString szFile;
 
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

    if (hProcessSnap == (HANDLE)-1) 
        return ; 
 
    pe32.dwSize = sizeof(PROCESSENTRY32); 

    if (Process32First(hProcessSnap, &pe32)) 
    { 
        do 
        { 
			szFile = pe32.szExeFile;
			
			int pos = szFile.ReverseFind('\\');
			szFile = szFile.Mid(pos + 1);
			
			szFile.MakeLower();
			
			if (szFile == "php.exe") {
				Handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			
				if (Handle != (HANDLE)-1 && Handle)
				{
					TerminateProcess(Handle, 0);
				}

				CloseHandle(Handle);
			}
        } 
        while (Process32Next(hProcessSnap, &pe32) && !bTrouve); 
    } 
 
    CloseHandle (hProcessSnap);
}
