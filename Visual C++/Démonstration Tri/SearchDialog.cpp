// SearchDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Démonstration Tri.h"
#include "SearchDialog.h"

#include "Démonstration TriView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog dialog


CSearchDialog::CSearchDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDialog)
	m_nVal = 0;
	//}}AFX_DATA_INIT

	m_pView = (CDmonstrationTriView *)pParent;
}


void CSearchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDialog)
	DDX_Control(pDX, IDC_TAB_LIST, m_ctlList);
	DDX_Text(pDX, IDC_EDIT_VAL, m_nVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDialog, CDialog)
	//{{AFX_MSG_MAP(CSearchDialog)
	ON_LBN_DBLCLK(IDC_TAB_LIST, OnDblclkTabList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog message handlers

BOOL CSearchDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString str;

	for (int i = 0 ; i < DEMO_TAB_SIZE ; i++)
	{
		str.Format("%d", m_pView->Tab[i]);
		m_ctlList.InsertString(i, str);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSearchDialog::OnDblclkTabList() 
{
	UpdateData();

	m_nVal = m_pView->Tab[m_ctlList.GetCurSel()];
	
	UpdateData(FALSE);
}
