// ParametresArAn.cpp : implementation file
//

#include "stdafx.h"
#include "Demarrer Windows.h"
#include "ParametresArAn.h"
#include "Parametres.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametresArAn dialog


CParametresArAn::CParametresArAn(CWnd* pParent /*=NULL*/)
	: CDialog(CParametresArAn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParametresArAn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CParametresArAn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParametresArAn)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParametresArAn, CDialog)
	//{{AFX_MSG_MAP(CParametresArAn)
	ON_BN_CLICKED(IDC_PARAM_ARABE, OnParamArabe)
	ON_BN_CLICKED(IDC_PARAM_FRANCAIS, OnParamFrancais)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParametresArAn message handlers

void CParametresArAn::OnParamArabe() 
{
	CParametres prmDlg;
	
	prmDlg.m_path = m_winArPath;

	if (prmDlg.DoModal() == IDCANCEL) return;
	
	m_winArPath = prmDlg.m_path;
	AfxGetApp()->WriteProfileString("OSPath", "Arabe", m_winArPath);
}

void CParametresArAn::OnParamFrancais() 
{
	CParametres prmDlg;

	prmDlg.m_path = m_winFrPath;
	
	if (prmDlg.DoModal() == IDCANCEL) return;
	
	m_winFrPath = prmDlg.m_path;
	AfxGetApp()->WriteProfileString("OSPath", "Francais", m_winFrPath);	
}

BOOL CParametresArAn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_winArPath = AfxGetApp()->GetProfileString("OSPath", "Arabe", "");
	m_winFrPath = AfxGetApp()->GetProfileString("OSPath", "Francais", "");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
