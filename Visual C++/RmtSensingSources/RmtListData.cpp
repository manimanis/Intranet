// RmtListData.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtListData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtListData dialog

CRmtListData::CRmtListData(CWnd* pParent /*=NULL*/)
	: CDialog(CRmtListData::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRmtListData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRmtListData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRmtListData)
	DDX_Control(pDX, IDC_LIST_RMTDATA, m_lstData);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRmtListData, CDialog)
	//{{AFX_MSG_MAP(CRmtListData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtListData message handlers

BOOL CRmtListData::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString str;
	LVITEM lvItem;
	
	m_lstData.InsertColumn(0, "Luminosité"		, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(1, "Rouge (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(2, "Vert (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(3, "Bleu (pixels)"	, LVCFMT_LEFT, 100);

	int iActualItem;

	for (int iItem = 0; iItem < 256; iItem++)  // insert the items and subitems into the list view.
		for (int iSubItem = 0; iSubItem < 4; iSubItem++)
		{
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = (iSubItem == 0)? iItem : iActualItem;;
			lvItem.iSubItem = iSubItem;

			str.Format("%d", ((iSubItem == 0) ? iItem : pDocument->picData[(iSubItem - 1) * 256 + iItem]));
			lvItem.pszText = (char *)LPCSTR(str);

			if (iSubItem == 0)
				iActualItem = m_lstData.InsertItem(&lvItem); // insert new item
			else
				m_lstData.SetItem(&lvItem); // modify existing item (the sub-item text)
		}

	return TRUE;  
}

void CRmtListData::SetDocument(CRmtSensingDoc *pDoc)
{
	pDocument = pDoc;
}
