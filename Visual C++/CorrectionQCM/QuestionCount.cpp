// QuestionCount.cpp : implementation file
//

#include "stdafx.h"
#include "CorrectionQCM.h"
#include "QuestionCount.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestionCount dialog


CQuestionCount::CQuestionCount(CWnd* pParent /*=NULL*/)
	: CDialog(CQuestionCount::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuestionCount)
	m_nCount = 0;
	//}}AFX_DATA_INIT
	m_szText = "";
}


void CQuestionCount::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuestionCount)
	DDX_Text(pDX, IDC_EDIT_COUNT, m_nCount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuestionCount, CDialog)
	//{{AFX_MSG_MAP(CQuestionCount)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestionCount message handlers

void CQuestionCount::OnOK() 
{
	UpdateData();
	
	CDialog::OnOK();
}

BOOL CQuestionCount::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	ShowWindow(SW_SHOW);

	SetQuestionText(m_szText);

	GetDlgItem(IDC_TEXT)->SetWindowText(m_szText);
	GetDlgItem(IDC_EDIT_COUNT)->SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CQuestionCount::SetQuestionText(CString szText)
{
	m_szText = szText;
}
