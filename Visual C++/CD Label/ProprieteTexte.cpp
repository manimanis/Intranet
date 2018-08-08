// ProprieteTexte.cpp : implementation file
//

#include "stdafx.h"
#include "CD Label.h"
#include "ProprieteTexte.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProprieteTexte dialog


CProprieteTexte::CProprieteTexte(CWnd* pParent /*=NULL*/)
	: CDialog(CProprieteTexte::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProprieteTexte)
	m_szText = _T("");
	m_align = -1;
	m_rotation = 0;
	m_rotationVal = 0;
	//}}AFX_DATA_INIT

	m_bFontChanged = FALSE;
}


void CProprieteTexte::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProprieteTexte)
	DDX_Text(pDX, IDC_TEXTE, m_szText);
	DDX_Radio(pDX, IDC_ALIGNLEFT, m_align);
	DDX_Slider(pDX, IDC_ROTATION, m_rotation);
	DDX_Text(pDX, IDC_ROTATIONVALUE, m_rotationVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProprieteTexte, CDialog)
	//{{AFX_MSG_MAP(CProprieteTexte)
	ON_BN_CLICKED(IDC_POLICE, OnPolice)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_ROTATION, OnReleasedcaptureRotation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProprieteTexte message handlers

void CProprieteTexte::OnPolice() 
{
	CFontDialog cfDlg(&m_logFont);

	if (cfDlg.DoModal() == IDCANCEL) return;

	m_textColor = cfDlg.GetColor();

	cfDlg.GetCurrentFont(&m_logFont);

	m_bFontChanged = TRUE;
}

BOOL CProprieteTexte::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CSliderCtrl *pSlider;

	pSlider = (CSliderCtrl *)GetDlgItem(IDC_ROTATION);
	pSlider->SetRange(0, 359);
	pSlider->SetPos(m_rotation);
	pSlider->SetPageSize(15);
	pSlider->SetTicFreq(15);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProprieteTexte::OnReleasedcaptureRotation(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData();

	m_rotationVal = m_rotation;
		m_bFontChanged = TRUE;

	UpdateData(FALSE);

	*pResult = 0;
}
