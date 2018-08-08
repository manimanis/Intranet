// Recenser ODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Recenser ODBC.h"
#include "Recenser ODBCDlg.h"
#include "RegisterDlg.h"
#include "PasswordDlg.h"
#include "SetNewPasswordDlg.h"

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
// CRecenserODBCDlg dialog

CRecenserODBCDlg::CRecenserODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecenserODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecenserODBCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRecenserODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecenserODBCDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRecenserODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CRecenserODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_NOUVEAU, OnNouveau)
	ON_BN_CLICKED(ID_SUPPRIMER, OnSupprimer)
	ON_BN_CLICKED(ID_PASSWORD, OnPassword)
	ON_BN_CLICKED(ID_MODIFIER, OnModifier)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecenserODBCDlg message handlers

BOOL CRecenserODBCDlg::OnInitDialog()
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
	
	CPasswordDlg passDlg;

	if (passDlg.DoModal() == IDCANCEL)
	{
		EndDialog(0);
		exit(0);
	}

	m_list.InsertColumn(0, "DSN Système", LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, "Driver", LVCFMT_LEFT, 200);

	FillListControl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRecenserODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRecenserODBCDlg::OnPaint() 
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
HCURSOR CRecenserODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

long CRecenserODBCDlg::FillListControl()
{
	HKEY hKey;
	unsigned long result, dwType;
	char buffer[256], buffer1[256];
	unsigned long bfSize, bfSize2;
	int i = 0;

	m_list.DeleteAllItems();

	result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\ODBC\\ODBC.INI\\ODBC Data Sources"
				, 0, KEY_ALL_ACCESS, &hKey);
	
	if (result)
	{
		AfxMessageBox("Echec d'ouverture");
	}

	bfSize = bfSize2 = sizeof(buffer);

	result = RegEnumValue(hKey, i, buffer, &bfSize, NULL, &dwType, (LPBYTE)buffer1, &bfSize2);
	while (result == ERROR_SUCCESS)
	{
		if (result)
		{
			AfxMessageBox("Echec d'énumération");
		}
		else
		{
			m_list.InsertItem(0, buffer);
			m_list.SetItemText(0, 1, buffer1);
		}

		i++;
		bfSize = bfSize2 = sizeof(buffer);
		result = RegEnumValue(hKey, i, buffer, &bfSize, NULL, &dwType, (LPBYTE)buffer1, &bfSize2);
	}
	RegCloseKey(hKey);

	return TRUE;
}



void CRecenserODBCDlg::OnNouveau() 
{
	CRegisterDlg regDlg;

	if (regDlg.DoModal() == IDCANCEL) return;

	if (regDlg.m_DBName == "" || regDlg.m_path == "")
	{
		MessageBox("Le nom de la base de donnée et son chemin ne doivent pas être null",
					"Attention", MB_OK);
		return;
	}

	for (int i = 0 ; i < m_list.GetItemCount() - 1 ; i++)
	{
		if (m_list.GetItemText(i, 0) == regDlg.m_DBName)
		{
			MessageBox("Ce Nom de base de donnée existe déja choisir un autre Nom",
						"Attention", MB_OK);
		return;	
		}
	}

	m_dataSource = regDlg.m_DBName;
	m_dataPath = regDlg.m_path;
	m_dataDesc = regDlg.m_Description;

	RegisterIt();
}

int CRecenserODBCDlg::RegisterIt()
{
	HKEY hKey;
	CString Str = "Microsoft Access Driver (*.mdb)";
	char SystemPath[256];
	long i;

	RegCreateKey(HKEY_LOCAL_MACHINE, "Software\\ODBC\\ODBC.INI\\ODBC Data Sources", &hKey);
	RegSetValueEx(hKey, LPCSTR(m_dataSource), NULL, REG_SZ, (unsigned char *)LPCSTR(Str), Str.GetLength());
	RegCloseKey(hKey);

	memset(SystemPath,0, sizeof(SystemPath));
	GetSystemDirectory(SystemPath, sizeof(SystemPath));

	Str = "Software\\ODBC\\ODBC.INI\\" + m_dataSource;
	RegCreateKey(HKEY_LOCAL_MACHINE, Str, &hKey);
	// [HKEY_LOCAL_MACHINE\Software\ODBC\ODBC.INI\MaBase]
	// "Driver"="C:\\WINFR\\SYSTEM\\odbcjt32.dll"
    // "DBQ"="C:\\MSDASDK\\bin\\oledb\\Nwind.mdb"
	// "Description"="OLE DB SDK sample data"
	// "DriverId"=dword:00000019
	// "SafeTransactions"=dword:00000000
	// "UID"=""
	Str = CString(SystemPath) + "\\odbcjt32.dll";
	RegSetValueEx(hKey, "Driver", NULL, REG_SZ, (unsigned char *)LPCSTR(Str), Str.GetLength());
	RegSetValueEx(hKey, "DBQ", NULL, REG_SZ, (unsigned char *)LPCSTR(m_dataPath), m_dataPath.GetLength());
	RegSetValueEx(hKey, "Description", NULL, REG_SZ, (unsigned char *)LPCSTR(m_dataDesc), m_dataDesc.GetLength());
	i = 25;
	RegSetValueEx(hKey, "DriverID", NULL, REG_DWORD, (unsigned char *)&i, 4);
	i = 0;
	RegSetValueEx(hKey, "SafeTransactions", NULL, REG_DWORD, (unsigned char *)&i, 4);
	Str = "";
	RegSetValueEx(hKey, "UID", NULL, REG_SZ, (unsigned char *)LPCSTR(Str), Str.GetLength());
	RegCloseKey(hKey);

	//[HKEY_LOCAL_MACHINE\Software\ODBC\ODBC.INI\MaBase\Engines\Jet]
	// "ImplicitCommitSync"=""
	// "Threads"=dword:00000003
	// "UserCommitSync"="Yes"
	
	Str = CString("Software\\ODBC\\ODBC.INI\\" + m_dataSource) + "\\Engines\\Jet";
	RegCreateKey(HKEY_LOCAL_MACHINE, Str, &hKey);
	Str = "";
	RegSetValueEx(hKey, "ImplicitCommitSync", NULL, REG_SZ, (unsigned char *)LPCSTR(Str), Str.GetLength());
	i = 5;
	RegSetValueEx(hKey, "Threads", NULL, REG_DWORD, (unsigned char *)&i, 4);
	Str = "Yes";
	RegSetValueEx(hKey, "UserCommitSync", NULL, REG_SZ, (unsigned char *)LPCSTR(Str), Str.GetLength());
	RegCloseKey(hKey);

	FillListControl();
	return TRUE;
}

void CRecenserODBCDlg::OnSupprimer() 
{
	
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	CString Str;
	HKEY hKey;

	int nIndex = m_list.GetNextSelectedItem(pos);
	if (nIndex < 0) return;
	if (m_list.GetItemText(nIndex, 1) != "Microsoft Access Driver (*.mdb)")
	{
		MessageBox("Vous n'avez pas le droit de supprimer les autres DSN.\n"
				   "Choisir une base de Donnée Access", " Attention");
		return;
	}

	if (MessageBox("Etes vous sûr de vouloir supprimer cette clé?\n" + 
					m_list.GetItemText(nIndex, 0), "Attention", 
					MB_ICONEXCLAMATION | MB_YESNO) == IDNO) return;
	
	Str = "Software\\ODBC\\ODBC.INI\\"  + m_list.GetItemText(nIndex, 0);
	RegDeleteKey(HKEY_LOCAL_MACHINE, Str);

	Str = m_list.GetItemText(nIndex, 0);
	RegCreateKey(HKEY_LOCAL_MACHINE, "Software\\ODBC\\ODBC.INI\\ODBC Data Sources", &hKey);
	RegDeleteValue(hKey, LPCSTR(Str));
	RegCloseKey(hKey);

	FillListControl();
}

void CRecenserODBCDlg::OnPassword() 
{
	CString m_HiddenLogin, m_HiddenPassword;

	m_HiddenLogin = AfxGetApp()->GetProfileString("Passwd", "Login", "");
	m_HiddenPassword = AfxGetApp()->GetProfileString("Passwd", "Password", "");
	
	if (m_HiddenLogin != "" && m_HiddenPassword != "")
	{
		CPasswordDlg passDlg;

		if (passDlg.DoModal() == IDCANCEL) return;
	}

	CSetNewPasswordDlg newPass;

	CPasswordDlg passDlg;

	if (newPass.DoModal() == IDOK)
	{
		AfxGetApp()->WriteProfileString("Passwd", "Login", newPass.m_login );
		AfxGetApp()->WriteProfileString("Passwd", "Password", newPass.m_password1);
	}		
}

void CRecenserODBCDlg::OnModifier() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	CString Str;
	HKEY hKey;
	char buffer[256], SystemPath[256];
	unsigned long size, dwType;

	int nIndex = m_list.GetNextSelectedItem(pos);
	if (nIndex < 0) return;
	if (m_list.GetItemText(nIndex, 1) != "Microsoft Access Driver (*.mdb)")
	{
		MessageBox("Ce n'est pas une base de donnée Microsoft Access."
				   "Choisir une base de Donnée Access", " Attention");
		return;
	}
	
	memset(SystemPath,0, sizeof(SystemPath));
	GetSystemDirectory(SystemPath, sizeof(SystemPath));

	m_dataSource = m_list.GetItemText(nIndex, 0);
	Str = "Software\\ODBC\\ODBC.INI\\" + m_dataSource;
	RegOpenKey(HKEY_LOCAL_MACHINE, Str, &hKey);
	size = sizeof(buffer);
	RegQueryValueEx(hKey, "DBQ", NULL, &dwType, (LPBYTE)buffer, &size);	
	m_dataPath = buffer;
	size = sizeof(buffer);
	RegQueryValueEx(hKey, "Description", NULL, &dwType, (LPBYTE)buffer, &size);	
	m_dataDesc = buffer;
	RegCloseKey(hKey);

	CRegisterDlg regDlg;

	regDlg.m_DBName = m_dataSource;
	regDlg.m_path = m_dataPath;
	regDlg.m_Description = m_dataDesc;

	if (regDlg.DoModal() == IDCANCEL) return;
	
	m_dataSource = regDlg.m_DBName;
	m_dataPath = regDlg.m_path;
	m_dataDesc = regDlg.m_Description;

	RegisterIt();
}
