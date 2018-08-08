// SaisieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CorrectionQCM.h"
#include "SaisieDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaisieDlg dialog


CSaisieDlg::CSaisieDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSaisieDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSaisieDlg)
	m_questionCount = 1;
	//}}AFX_DATA_INIT
}


void CSaisieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaisieDlg)
	DDX_Control(pDX, IDC_QUESTIONS, m_questionTree);
	DDX_Text(pDX, IDC_QUESTIONS_COUNT, m_questionCount);
	DDV_MinMaxInt(pDX, m_questionCount, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSaisieDlg, CDialog)
	//{{AFX_MSG_MAP(CSaisieDlg)
	ON_BN_CLICKED(IDC_CHANGE_QUESTION_COUNT_BTN, OnChangeQuestionCountBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaisieDlg message handlers

BOOL CSaisieDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// On initialise la liste des images pour les questions réponses
	m_imgList.Create(IDB_QUESTIONS_IMG, 16, 10, RGB(255, 255, 255));
	m_imgList.SetImageCount(2);
	// On associe les images avec le controle CTreeCtrl
	m_questionTree.SetImageList(&m_imgList, TVSIL_NORMAL);

	HTREEITEM hItem;
	// On initlialise les questions 
	m_questionTree.InsertItem("Question 1");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CSaisieDlg::OnChangeQuestionCountBtn() 
{
	UpdateData();

	FixQuestionsNumber(m_questionCount);
}

void CSaisieDlg::FixQuestionsNumber(int iNumber)
{
	HTREEITEM hItem = m_questionTree.GetRootItem();
	HTREEITEM hNextItem;
	CString szText;
	int currentPos = 0, i;

	do{
		currentPos++;
		if (currentPos > iNumber) 
		{
			hNextItem = m_questionTree.GetNextItem(hItem, TVGN_NEXT);
			m_questionTree.DeleteItem(hItem);
			hItem = hNextItem;
		}
		else
			hItem = m_questionTree.GetNextItem(hItem, TVGN_NEXT);
	} while(hItem);

	if (currentPos < iNumber)
		for (i = currentPos + 1 ; i <= iNumber ; i++)
		{
			szText.Format("Question %d", i);
			m_questionTree.InsertItem(szText);
		}
}




