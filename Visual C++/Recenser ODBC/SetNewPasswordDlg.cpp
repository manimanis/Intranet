// SetNewPasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Recenser ODBC.h"
#include "SetNewPasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetNewPasswordDlg dialog


CSetNewPasswordDlg::CSetNewPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetNewPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetNewPasswordDlg)
	m_password1 = _T("");
	m_password2 = _T("");
	m_login = _T("");
	//}}AFX_DATA_INIT
}


void CSetNewPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetNewPasswordDlg)
	DDX_Text(pDX, IDC_PASSWORD, m_password1);
	DDX_Text(pDX, IDC_PASSWORD2, m_password2);
	DDX_Text(pDX, IDC_LOGIN, m_login);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetNewPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CSetNewPasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetNewPasswordDlg message handlers

void CSetNewPasswordDlg::OnOK() 
{
	UpdateData();

	if (m_login == "")
	{
		AfxMessageBox("Indiquer le nom d'utilisateur");

		return;
	}

	if (m_password1 == "" || m_password2 == "" || m_password1 != m_password2)
	{
		AfxMessageBox("Mots de passes différents");
		m_password1 = m_password2 = "";
		UpdateData(FALSE);

		return;
	}

	CDialog::OnOK();
}
