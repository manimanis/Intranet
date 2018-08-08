// DrawProperty.cpp : implementation file
//

#include "stdafx.h"
#include "CD Label.h"
#include "DrawProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawProperty dialog


CDrawProperty::CDrawProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawProperty::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrawProperty)
	m_type = _T("");
	m_bColFond = FALSE;
	m_bColTrace = FALSE;
	m_nArrHeight = 0;
	m_nArrWidth = 0;
	//}}AFX_DATA_INIT
}


void CDrawProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawProperty)
	DDX_Control(pDX, IDC_STATIC_TRACE, m_ctlTrace);
	DDX_Control(pDX, IDC_STATIC_FOND, m_ctlFond);
	DDX_CBString(pDX, IDC_DTYPE, m_type);
	DDX_Check(pDX, IDC_CHECK_FOND, m_bColFond);
	DDX_Check(pDX, IDC_CHECK_TRACE, m_bColTrace);
	DDX_Text(pDX, IDC_LINE_WIDTH, m_nLineWidth);
	DDX_Text(pDX, IDC_ARR_HEIGHT, m_nArrHeight);
	DDX_Text(pDX, IDC_ARR_WIDTH, m_nArrWidth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDrawProperty, CDialog)
	//{{AFX_MSG_MAP(CDrawProperty)
	ON_BN_CLICKED(IDC_CHECK_FOND, OnCheckFond)
	ON_BN_CLICKED(IDC_CHECK_TRACE, OnCheckTrace)
	ON_BN_CLICKED(IDC_BTN_FOND, OnBtnFond)
	ON_BN_CLICKED(IDC_BTN_TRACE, OnBtnTrace)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawProperty message handlers

BOOL CDrawProperty::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (m_bColFond)	GetDlgItem(IDC_BTN_FOND)->EnableWindow(FALSE);
	if (m_bColTrace) GetDlgItem(IDC_BTN_TRACE)->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDrawProperty::OnCheckFond() 
{
	UpdateData();
	GetDlgItem(IDC_BTN_FOND)->EnableWindow(!m_bColFond);
}

void CDrawProperty::OnCheckTrace() 
{
	UpdateData();
	GetDlgItem(IDC_BTN_TRACE)->EnableWindow(!m_bColTrace);
}

void CDrawProperty::OnBtnFond() 
{
	CColorDialog cDlg;

	if (cDlg.DoModal() == IDCANCEL) return;

	m_nColFond = cDlg.GetColor();
	
	ModifyCtlColor(&m_ctlFond, m_nColFond);
}

void CDrawProperty::OnBtnTrace() 
{
	CColorDialog cDlg;

	if (cDlg.DoModal() == IDCANCEL) return;

	m_nColTrace = cDlg.GetColor();

	ModifyCtlColor(&m_ctlTrace, m_nColTrace);
}

void CDrawProperty::ModifyCtlColor(CStatic *pStatic, int nColor)
{
	CClientDC dc(pStatic);
	CRect rc;
	CBrush brush, *pBrush;

	brush.CreateSolidBrush(nColor);

	pBrush = (CBrush *)dc.SelectObject(&brush);

	pStatic->GetClientRect(&rc);

	dc.Rectangle(rc);

	dc.SelectObject(&pBrush);

	brush.DeleteObject();	
}

void CDrawProperty::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	ModifyCtlColor(&m_ctlFond, m_nColFond);
	ModifyCtlColor(&m_ctlTrace, m_nColTrace);
}
