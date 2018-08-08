// Parametres.cpp : implementation file
//

#include "stdafx.h"
#include "Demarrer Windows.h"
#include "Parametres.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParametres dialog


CParametres::CParametres(CWnd* pParent /*=NULL*/)
	: CDialog(CParametres::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParametres)
	m_path = _T("");
	//}}AFX_DATA_INIT
}


void CParametres::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParametres)
	DDX_Text(pDX, IDC_PATH, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CParametres, CDialog)
	//{{AFX_MSG_MAP(CParametres)
	ON_BN_CLICKED(IDC_PARCOURIR, OnParcourir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParametres message handlers

void CParametres::OnParcourir() 
{
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | 
		OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST, "Explorer Windows|Explorer.exe|");
	CString tempFile;

	if (fileDlg.DoModal() == IDCANCEL) return;

	tempFile = fileDlg.GetPathName();
	tempFile.MakeLower();

	if (tempFile.Find("explorer.exe") > 0)
	{
		m_path = tempFile.Left(tempFile.GetLength() - 13);
		UpdateData(FALSE);
	}
}
