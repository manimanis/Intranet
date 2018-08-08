// PlaySpeed.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "PlaySpeed.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaySpeed dialog


CPlaySpeed::CPlaySpeed(CWnd* pParent /*=NULL*/)
	: CDialog(CPlaySpeed::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlaySpeed)
	m_nSpeed = 0;
	m_vitesse = _T("");
	//}}AFX_DATA_INIT
}


void CPlaySpeed::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlaySpeed)
	DDX_Slider(pDX, IDC_SPEED, m_nSpeed);
	DDX_Text(pDX, IDC_VITESSE, m_vitesse);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlaySpeed, CDialog)
	//{{AFX_MSG_MAP(CPlaySpeed)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SPEED, OnReleasedcaptureSpeed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaySpeed message handlers

void CPlaySpeed::OnReleasedcaptureSpeed(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData();
	
	m_vitesse.Format("%d", m_nSpeed);

	UpdateData(FALSE);

	*pResult = 0;
}

BOOL CPlaySpeed::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	((CSliderCtrl *)GetDlgItem(IDC_SPEED))->SetRange(0, 2000);
	((CSliderCtrl *)GetDlgItem(IDC_SPEED))->SetPos(m_nSpeed);
	((CSliderCtrl *)GetDlgItem(IDC_SPEED))->SetPageSize(250);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
