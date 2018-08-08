// PasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Recenser ODBC.h"
#include "PasswordDlg.h"
#include "SetNewPasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog


CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDlg)
	m_login = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDlg)
	DDX_Text(pDX, IDC_LOGIN, m_login);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CPasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg message handlers

BOOL CPasswordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_HiddenLogin = AfxGetApp()->GetProfileString("Passwd", "Login", "");
	m_HiddenPassword = AfxGetApp()->GetProfileString("Passwd", "Password", "");
	
	if (m_HiddenLogin == "" && m_HiddenPassword == "")
	{
		CSetNewPasswordDlg newPass;

		if (newPass.DoModal() == IDOK)
		{
			AfxGetApp()->WriteProfileString("Passwd", "Login", newPass.m_login );
			AfxGetApp()->WriteProfileString("Passwd", "Password", newPass.m_password1);
			EndDialog(0);
		}
		else
		{
			exit(0);
		}
	}

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPasswordDlg::OnOK() 
{
	UpdateData();

	if (m_login != m_HiddenLogin || m_password != m_HiddenPassword)
	{
		MessageBox("Mot de passe incorrect", "Erreur");
		m_login = m_password = "";

		UpdateData(FALSE);
		return;
	}

	CDialog::OnOK();
}
