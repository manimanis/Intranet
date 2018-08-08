// UserZoomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "UserZoomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserZoomDlg dialog


CUserZoomDlg::CUserZoomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserZoomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserZoomDlg)
	m_editZoom = 0;
	//}}AFX_DATA_INIT
}


void CUserZoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserZoomDlg)
	DDX_Text(pDX, IDC_EDIT_ZOOM, m_editZoom);
	DDV_MinMaxInt(pDX, m_editZoom, 10, 1600);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserZoomDlg, CDialog)
	//{{AFX_MSG_MAP(CUserZoomDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserZoomDlg message handlers
