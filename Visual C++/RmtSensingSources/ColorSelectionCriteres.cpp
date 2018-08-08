// ColorSelectionCriteres.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "ColorSelectionCriteres.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorSelectionCriteres dialog


CColorSelectionCriteres::CColorSelectionCriteres(CWnd* pParent /*=NULL*/)
	: CDialog(CColorSelectionCriteres::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorSelectionCriteres)
	m_selectAll = FALSE;
	m_bleuMax = 255;
	m_bleuMin = 0;
	m_rougeMax = 255;
	m_rougeMin = 0;
	m_vertMax = 255;
	m_vertMin = 0;
	//}}AFX_DATA_INIT
}


void CColorSelectionCriteres::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorSelectionCriteres)
	DDX_Check(pDX, IDC_TOUT_SELECTIONNER, m_selectAll);
	DDX_Text(pDX, IDC_BLEU_MAX, m_bleuMax);
	DDV_MinMaxByte(pDX, m_bleuMax, 0, 255);
	DDX_Text(pDX, IDC_BLEU_MIN, m_bleuMin);
	DDV_MinMaxByte(pDX, m_bleuMin, 0, 255);
	DDX_Text(pDX, IDC_ROUGE_MAX, m_rougeMax);
	DDV_MinMaxByte(pDX, m_rougeMax, 0, 255);
	DDX_Text(pDX, IDC_ROUGE_MIN, m_rougeMin);
	DDV_MinMaxByte(pDX, m_rougeMin, 0, 255);
	DDX_Text(pDX, IDC_VERT_MAX, m_vertMax);
	DDV_MinMaxByte(pDX, m_vertMax, 0, 255);
	DDX_Text(pDX, IDC_VERT_MIN, m_vertMin);
	DDV_MinMaxByte(pDX, m_vertMin, 0, 255);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BLEU_MAX, m_bleuMaxCtrl);
	DDX_Control(pDX, IDC_BLEU_MIN, m_bleuMinCtrl);
	DDX_Control(pDX, IDC_ROUGE_MAX, m_rougeMaxCtrl);
	DDX_Control(pDX, IDC_ROUGE_MIN, m_rougeMinCtrl);
	DDX_Control(pDX, IDC_VERT_MAX, m_vertMaxCtrl);
	DDX_Control(pDX, IDC_VERT_MIN, m_vertMinCtrl);
}


BEGIN_MESSAGE_MAP(CColorSelectionCriteres, CDialog)
	//{{AFX_MSG_MAP(CColorSelectionCriteres)
	ON_BN_CLICKED(IDC_TOUT_SELECTIONNER, OnToutSelectionner)
	ON_EN_CHANGE(IDC_BLEU_MIN, OnChangeBleuMin)
	ON_EN_CHANGE(IDC_BLEU_MAX, OnChangeBleuMax)
	ON_EN_CHANGE(IDC_VERT_MIN, OnChangeVertMin)
	ON_EN_CHANGE(IDC_VERT_MAX, OnChangeVertMax)
	ON_EN_CHANGE(IDC_ROUGE_MIN, OnChangeRougeMin)
	ON_EN_CHANGE(IDC_ROUGE_MAX, OnChangeRougeMax)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorSelectionCriteres message handlers



void CColorSelectionCriteres::OnToutSelectionner() 
{
	m_bleuMaxCtrl.SetReadOnly(!m_selectAll);
	m_bleuMinCtrl.SetReadOnly(!m_selectAll);
	m_rougeMaxCtrl.SetReadOnly(!m_selectAll);
	m_rougeMinCtrl.SetReadOnly(!m_selectAll);
	m_vertMaxCtrl.SetReadOnly(!m_selectAll);
	m_vertMinCtrl.SetReadOnly(!m_selectAll);

	m_selectAll = (m_selectAll) ? FALSE : TRUE;

	UpdateData(FALSE);
}

void CColorSelectionCriteres::OnOK() 
{
	UpdateData();
	
	CDialog::OnOK();
}

void CColorSelectionCriteres::OnChangeBleuMin() 
{
	UpdateData();
}

void CColorSelectionCriteres::OnChangeBleuMax() 
{
	UpdateData();
}

void CColorSelectionCriteres::OnChangeVertMin() 
{
	UpdateData();
}

void CColorSelectionCriteres::OnChangeVertMax() 
{
	UpdateData();
}

void CColorSelectionCriteres::OnChangeRougeMin() 
{
	UpdateData();
}

void CColorSelectionCriteres::OnChangeRougeMax() 
{
	UpdateData();	
}
