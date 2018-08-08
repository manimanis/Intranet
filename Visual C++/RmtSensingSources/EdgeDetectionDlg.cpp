// EdgeDetectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "EdgeDetectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEdgeDetectionDlg dialog


CEdgeDetectionDlg::CEdgeDetectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEdgeDetectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEdgeDetectionDlg)
	m_percentage = 1.0f;
	//}}AFX_DATA_INIT
}


void CEdgeDetectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEdgeDetectionDlg)
	DDX_Text(pDX, IDC_POURCENTAGE_DETECTION, m_percentage);
	DDV_MinMaxFloat(pDX, m_percentage, 1.f, 255.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEdgeDetectionDlg, CDialog)
	//{{AFX_MSG_MAP(CEdgeDetectionDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEdgeDetectionDlg message handlers
