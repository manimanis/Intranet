// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Recenser ODBC.h"
#include "RegisterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog


CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisterDlg)
	m_DBName = _T("");
	m_Description = _T("");
	m_path = _T("");
	//}}AFX_DATA_INIT
}


void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisterDlg)
	DDX_Text(pDX, IDC_DBNAME, m_DBName);
	DDX_Text(pDX, IDC_DESCRIPTION, m_Description);
	DDX_Text(pDX, IDC_PATH, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterDlg)
	ON_BN_CLICKED(IDC_PARCOURIR, OnParcourir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg message handlers

void CRegisterDlg::OnParcourir() 
{
	UpdateData();

	CFileDialog fDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
				"MS Access (*.mdb)|*.mdb");	

	if (m_path != "")
	{
		int titSize = GetFileTitle(m_path, NULL, NULL);
		fDlg.m_ofn.lpstrInitialDir = m_path.Left(m_path.GetLength() - titSize - 4);
	}

	if (fDlg.DoModal() == IDCANCEL) return;

	m_path = fDlg.GetPathName();
	m_DBName = fDlg.GetFileName().Left(fDlg.GetFileName().GetLength() - 4);
	m_Description = m_DBName + " (Added by MMA Program)";

	UpdateData(FALSE);
}


