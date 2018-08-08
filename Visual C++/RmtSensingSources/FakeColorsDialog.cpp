// FakeColorsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "ColorSelectionCriteres.h"
#include "FakeColorsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFakeColorsDialog dialog


CFakeColorsDialog::CFakeColorsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFakeColorsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFakeColorsDialog)
	//}}AFX_DATA_INIT
	color = 0xffffff;
}


void CFakeColorsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFakeColorsDialog)
	DDX_Control(pDX, IDC_SELECTEDCOLOR, m_selectedColor);
	DDX_Control(pDX, IDC_COLORLIST, m_colorList);
	DDX_Control(pDX, IDC_CHOISIRUNECOULEUR, m_choisirUneCouleur);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFakeColorsDialog, CDialog)
	//{{AFX_MSG_MAP(CFakeColorsDialog)
	ON_BN_CLICKED(IDC_CHOISIRUNECOULEUR, OnChoisirunecouleur)
	ON_BN_CLICKED(IDC_SELECTION_CRITERE, OnSelectionCritere)
	ON_COMMAND(ID_SELECTION_CRITERE, OnSelectionCritere)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFakeColorsDialog message handlers

void CFakeColorsDialog::SetDocument(CRmtSensingDoc *pDoc)
{
	m_pDoc = pDoc;
}

void CFakeColorsDialog::InitColorTree(int count, COLORREF *colors)
{
	ColorArray = colors;
	m_colorCount = (count > 32000) ? 32000 : count;
}

BOOL CFakeColorsDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	for (int i = 0 ; i < m_colorCount ; i++)
		m_colorList.AddColorItem(ColorArray[i]);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFakeColorsDialog::OnChoisirunecouleur() 
{
	CColorDialog cDlg(color, CC_FULLOPEN | CC_RGBINIT);
	
	if (cDlg.DoModal() == IDCANCEL) return;

	m_selectedColor.SetSelection(color = cDlg.GetColor());
	m_selectedColor.Invalidate();
}

void CFakeColorsDialog::OnOK() 
{
	int clrCount = m_colorList.GetSelCount();	
	int *sel = new int [clrCount];
	COLORREF *cpy = new COLORREF [m_colorCount];

	memcpy(cpy, ColorArray, sizeof(COLORREF) * m_colorCount);
	
	m_colorList.GetSelItems(clrCount, sel);

	for (int i = 0 ; i < clrCount ; i++)
		ColorArray[sel[i]] = color; 

	m_pDoc->bmpManip.FakeColours(m_colorCount, cpy, ColorArray);

	delete [] sel;
	delete [] cpy;

	CDialog::OnOK();
}

void CFakeColorsDialog::OnSelectionCritere() 
{
	CColorSelectionCriteres critDlg;
	BYTE r, v, b;
	int uB, lB;
	BOOL select;
	
	if (critDlg.DoModal() == IDCANCEL) return;

	if (critDlg.m_selectAll)
	{
		m_colorList.SelItemRange(TRUE,0 , m_colorCount - 1);
		return;
	}

	select = FALSE;
	for (int i = 0 ; i < m_colorCount ; i++)
	{
		b = GetBValue(ColorArray[i]);
		v = GetGValue(ColorArray[i]);
		r = GetRValue(ColorArray[i]);

		if ((b >= critDlg.m_bleuMin ) && (b <= critDlg.m_bleuMax ) &&
				(v >= critDlg.m_vertMin ) && (v <= critDlg.m_vertMax ) && 
					(r >= critDlg.m_rougeMin) && (r <= critDlg.m_rougeMax)) 
		{	
			if (!select)	
			{
				select = TRUE;
				lB = uB = i;
			}
			else uB = i;
		}
		else
			if (select)
			{
				if (uB > lB)
					m_colorList.SelItemRange(TRUE, lB, uB);
				else
					m_colorList.SetSel(uB, TRUE);
				select = FALSE;
			}
	}

	if (select) 
		if (uB > lB)
			m_colorList.SelItemRange(TRUE, lB, uB);
		else
			m_colorList.SetSel(uB, TRUE);
}
