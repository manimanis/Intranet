// ResponseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CorrectionQCM.h"
#include "ResponseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResponseDlg dialog


CResponseDlg::CResponseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResponseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResponseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_pBtnArray = NULL;
	m_nBtnCount = 10;

	m_pArray = NULL;
	m_nArraySize = 0;

	m_nMaxBtnCount = 1;
	m_nCurrentPos = 0;

	m_pBtnState = NULL;
	m_nBtnStateSize = 0;
}


void CResponseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResponseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResponseDlg, CDialog)
	//{{AFX_MSG_MAP(CResponseDlg)
	ON_BN_CLICKED(IDC_PRECEDENT, OnPrecedent)
	ON_BN_CLICKED(IDC_SUIVANT, OnSuivant)
	ON_BN_CLICKED(IDC_FERMER, OnFermer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResponseDlg message handlers

BOOL CResponseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitResponseArray();

	InitButtons(m_nMaxBtnCount);

	InitWindow(m_nCurrentPos);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CResponseDlg::~CResponseDlg()
{
	if (m_pBtnArray) delete [] m_pBtnArray;
	if (m_pArray) delete [] m_pArray;
	if (m_pBtnState) delete [] m_pBtnState;
}

void CResponseDlg::InitWindow(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nArraySize) return;

	CRect clrc, rc;
	CSize size;
	CString szText;

	szText.Format("Question N° %d sur %d", nIndex + 1, m_nArraySize);
	SetWindowText(szText);

	int btnCount = m_pArray[nIndex];

	GetWindowRect(clrc);
	MoveWindow(clrc.left, clrc.top, clrc.Width(), 20 * (btnCount / 3 + 1) + 78);

	GetDlgItem(IDOK)->GetClientRect(rc);

	GetDlgItem(IDOK)->MoveWindow(clrc.Width() / 6 - rc.Width() / 2, 
					20 * (btnCount/ 3 + 1) + 20, rc.Width(), rc.Height());

	GetDlgItem(IDCANCEL)->MoveWindow(clrc.Width() * 2 / 6 - rc.Width() / 2, 
					20 * (btnCount / 3 + 1) + 20, rc.Width(), rc.Height());

	GetDlgItem(IDC_PRECEDENT)->MoveWindow(clrc.Width() * 3 / 6 - rc.Width() / 2, 
					20 * (btnCount / 3 + 1) + 20, rc.Width(), rc.Height());

	GetDlgItem(IDC_SUIVANT)->MoveWindow(clrc.Width() * 4 / 6 - rc.Width() / 2, 
					20 * (btnCount / 3 + 1) + 20, rc.Width(), rc.Height());


	GetDlgItem(IDC_FERMER)->MoveWindow(clrc.Width() * 5 / 6 - rc.Width() / 2, 
					20 * (btnCount / 3 + 1) + 20, rc.Width(), rc.Height());

	if (nIndex)
		GetDlgItem(IDC_PRECEDENT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_PRECEDENT)->EnableWindow(FALSE);

	if (nIndex != m_nArraySize - 1)
		GetDlgItem(IDC_SUIVANT)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_SUIVANT)->EnableWindow(FALSE);


	int base = GetIndexBase(nIndex);

	for (int i = 0 ; i < m_nMaxBtnCount ; i++)
		if (i >= btnCount)
			m_pBtnArray[i].ShowWindow(SW_HIDE);
		else
		{
			m_pBtnArray[i].ShowWindow(SW_SHOW);
			m_pBtnArray[i].SetCheck(m_pBtnState[i + base]);
		}
}

void CResponseDlg::InitButtons(int nCount)
{
	if (m_pBtnArray) return;

	CRect clrc, rc, rc1;
	CSize size;
	int i;
	CString szReponse;

	GetClientRect(clrc);
	size = CSize(clrc.Width() - 20, clrc.Height() - 20);
	m_pBtnArray = new CButton[nCount];

	for (i = 0 ; i < nCount ; i++)
	{
		rc1.left = (i % 3) * size.cx / 3 + 10;
		rc1.top = (i / 3) * 20 + 10;
		rc1.right = rc1.left + size.cx / 3;
		rc1.bottom = rc1.top + 20;

		szReponse.Format("Réponse %d", i + 1);
		m_pBtnArray[i].Create(szReponse, WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
															rc1, this, 100 + i);
		m_pBtnArray[i].SetFont(GetFont());
	}

	m_nBtnCount = nCount;
}

void CResponseDlg::InitResponseArray()
{
	CStdioFile stdFile;
	CString szText;
	int i;

	stdFile.Open("qcm.eva", CFile::modeRead);
	
	stdFile.ReadString(szText);

	m_nArraySize = atoi(szText.Right(2));
	m_pArray = new int [m_nArraySize];

	i = m_nArraySize - 1;

	m_nBtnStateSize = 0;

	while (stdFile.ReadString(szText))
	{
		m_pArray[i] = atoi(szText);
		m_nBtnStateSize += m_pArray[i];
		if (m_pArray[i] > m_nMaxBtnCount) m_nMaxBtnCount = m_pArray[i];
		stdFile.ReadString(szText);
		i--;
	}

	stdFile.Close();

	m_pBtnState = new char [m_nBtnStateSize];
	OnOuvrir();
}


void CResponseDlg::OnPrecedent() 
{
	InvalidateButtons(m_nCurrentPos);

	if (m_nCurrentPos)
		InitWindow(--m_nCurrentPos);	
}

void CResponseDlg::OnSuivant() 
{
	InvalidateButtons(m_nCurrentPos);

	if (m_nCurrentPos != m_nArraySize - 1)
		InitWindow(++m_nCurrentPos);
}

int CResponseDlg::GetIndexBase(int nIndex)
{
	int result = 0;

	for (int i = 0 ; i < nIndex ; i++)
		result += m_pArray[i];

	return result;
}

void CResponseDlg::OnFermer() 
{
	InvalidateButtons(m_nCurrentPos);

	CStdioFile stdFile;
	CString szText;
	
	stdFile.Open("Reponses.bl", CFile::modeCreate | CFile::modeWrite);

	szText.Format("%d\n", m_nBtnStateSize);
	stdFile.WriteString(szText);

	for (int i = 0 ; i < m_nBtnStateSize ; i++)
	{
		szText.Format("%d\n", m_pBtnState[i]);
		stdFile.WriteString(szText);
	}

	stdFile.Close();

	CDialog::OnOK();
}


void CResponseDlg::OnOuvrir()
{
	CStdioFile stdFile;
	CString szText;
	
	if (!stdFile.Open("Reponses.bl", CFile::modeRead)) return;

	
	stdFile.ReadString(szText);
	// m_nBtnStateSize = atoi(szText);
	
	for (int i = 0 ; i < m_nBtnStateSize ; i++)
	{
		stdFile.ReadString(szText);
		m_pBtnState[i] = atoi(szText);
	}

	stdFile.Close();
}

void CResponseDlg::InvalidateButtons(int nIndex)
{
	int base = GetIndexBase(nIndex);

	for (int i = 0 ; i < m_nMaxBtnCount ; i++)
		if (i < m_pArray[nIndex])
			m_pBtnState[i + base] = m_pBtnArray[i].GetCheck();

}
