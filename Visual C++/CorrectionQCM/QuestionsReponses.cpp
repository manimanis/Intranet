// QuestionsReponses.cpp : implementation file
//

#include "stdafx.h"
#include "CorrectionQCM.h"
#include "QuestionsReponses.h"

#include "QuestionCount.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestionsReponses dialog


CQuestionsReponses::CQuestionsReponses(CWnd* pParent /*=NULL*/)
	: CDialog(CQuestionsReponses::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuestionsReponses)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_nQuestionCount = 5;
}


void CQuestionsReponses::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuestionsReponses)
	DDX_Control(pDX, IDC_QUESTION_LIST, m_questionList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuestionsReponses, CDialog)
	//{{AFX_MSG_MAP(CQuestionsReponses)
	ON_NOTIFY(NM_DBLCLK, IDC_QUESTION_LIST, OnDblclkQuestionList)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_QUESTION_LIST, OnColumnclickQuestionList)
	ON_BN_CLICKED(IDC_FERMER, OnFermer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestionsReponses message handlers

BOOL CQuestionsReponses::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_questionList.ModifyStyle(0, LVS_REPORT);
	m_questionList.ModifyStyleEx(0, LVS_EX_FULLROWSELECT);

	UpdateWindow();

	m_questionList.InsertColumn(0, "Questions", LVCFMT_RIGHT, 120);
	m_questionList.InsertColumn(1, "Propositions", LVCFMT_RIGHT, 200);
	
	InitList();

	SetQuestionCount(m_nQuestionCount);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CQuestionsReponses::OnDblclkQuestionList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CString szText;


	if (!pNMListView->iSubItem && pNMListView->iItem != -1)
	{
		CQuestionCount cDlg;

		cDlg.SetQuestionText("Entrer le nombre de Choix");
		cDlg.m_nCount = atoi(m_questionList.GetItemText(pNMListView->iItem, 1));

		if (cDlg.DoModal() == IDCANCEL) return;
		
		szText.Format("%d", cDlg.m_nCount);
		m_questionList.SetItemText(pNMListView->iItem, 1, szText);
	}
	
	
	*pResult = 0;
}

void CQuestionsReponses::OnColumnclickQuestionList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if (pNMListView->iSubItem == 0)
	{
		CQuestionCount cDlg;

		cDlg.SetQuestionText("Entrer le nombre de Questions :");
		cDlg.m_nCount = m_questionList.GetItemCount();
		
		if (cDlg.DoModal() == IDCANCEL) return;

		SetQuestionCount(cDlg.m_nCount);
		m_nQuestionCount = cDlg.m_nCount;
	}

	*pResult = 0;
}

void CQuestionsReponses::SetQuestionCount(int nCount)
{
	CString szText;

	if (m_questionList.GetItemCount() < nCount)
	{
		for(int i = m_questionList.GetItemCount() ; i < nCount; i++)
		{
			szText.Format("Question %02d", i + 1);
			m_questionList.InsertItem(i, szText);
			m_questionList.SetItemText(i, 1, "0");
		}
	}
	else
		while (m_questionList.GetItemCount() > nCount)
			m_questionList.DeleteItem(m_questionList.GetItemCount() - 1);
}

void CQuestionsReponses::OnOK() 
{
	// 	CDialog::OnOK();
}

void CQuestionsReponses::OnFermer() 
{
	CStdioFile stdFile;
	CString szText;
	
	stdFile.Open("qcm.eva", CFile::modeWrite | CFile::modeCreate);

	for (int i = m_questionList.GetItemCount() - 1 ; i >= 0  ; i--)
	{
		szText =	m_questionList.GetItemText(i, 0) + "\n" + 
					m_questionList.GetItemText(i, 1) + "\n";
		
		stdFile.WriteString(szText);
	}

	stdFile.Close();

	CDialog::OnOK();
}

void CQuestionsReponses::InitList()
{
	CStdioFile stdFile;
	CString szText;
	int i;

	if (!stdFile.Open("qcm.eva", CFile::modeRead)) return;
	
	while (stdFile.ReadString(szText))
	{
		m_questionList.InsertItem(0, szText);
		stdFile.ReadString(szText);
		m_questionList.SetItemText(0, 1, szText);
	}

	stdFile.Close();

	m_nQuestionCount = m_questionList.GetItemCount();
}
