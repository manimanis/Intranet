// RmtListForm.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtListForm.h"
#include "RmtSensingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtListForm

IMPLEMENT_DYNCREATE(CRmtListForm, CFormView)

CRmtListForm::CRmtListForm()
	: CFormView(CRmtListForm::IDD)
{
	//{{AFX_DATA_INIT(CRmtListForm)
	//}}AFX_DATA_INIT
}

CRmtListForm::~CRmtListForm()
{
}

void CRmtListForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRmtListForm)
	DDX_Control(pDX, IDC_RMTDATA_LIST2, m_lstData2);
	DDX_Control(pDX, IDC_RMTDATA_LIST, m_lstData);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRmtListForm, CFormView)
	//{{AFX_MSG_MAP(CRmtListForm)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtListForm diagnostics

#ifdef _DEBUG
void CRmtListForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CRmtListForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRmtListForm message handlers

void CRmtListForm::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CRmtSensingDoc *pDocument = (CRmtSensingDoc *)GetDocument();
	
	CString str;
	LVITEM lvItem;
	
	m_lstData.InsertColumn(0, "Luminosité"		, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(1, "Bleu (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(2, "Vert (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData.InsertColumn(3, "Rouge (pixels)"	, LVCFMT_LEFT, 100);

	int iActualItem;
	int iItem, iSubItem;

	for (iItem = 0; iItem < 256; iItem++)  // insert the items and subitems into the list view.
		for (iSubItem = 0; iSubItem < 4; iSubItem++)
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

	m_lstData2.InsertColumn(0, "Luminosité"		, LVCFMT_LEFT, 100);
	m_lstData2.InsertColumn(1, "Bleu (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData2.InsertColumn(2, "Vert (pixels)"	, LVCFMT_LEFT, 100);
	m_lstData2.InsertColumn(3, "Rouge (pixels)"	, LVCFMT_LEFT, 100);

	for (iItem = 0; iItem < 256; iItem++)  // insert the items and subitems into the list view.
		for (iSubItem = 0; iSubItem < 4; iSubItem++)
		{
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = (iSubItem == 0)? iItem : iActualItem;;
			lvItem.iSubItem = iSubItem;

			str.Format("%d", ((iSubItem == 0) ? iItem : pDocument->cumData[(iSubItem - 1) * 256 + iItem]));
			lvItem.pszText = (char *)LPCSTR(str);

			if (iSubItem == 0)
				iActualItem = m_lstData2.InsertItem(&lvItem); // insert new item
			else
				m_lstData2.SetItem(&lvItem); // modify existing item (the sub-item text)
		}
}

void CRmtListForm::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRmtSensingDoc *pDocument = (CRmtSensingDoc *)GetDocument();

	if (pDocument->DataChanged)
	{
		CString str;
		LVITEM lvItem;

		m_lstData.DeleteAllItems();
		m_lstData2.DeleteAllItems();

		int iActualItem;
		int iItem, iSubItem;

		for (iItem = 0; iItem < 256; iItem++)  // insert the items and subitems into the list view.
			for (iSubItem = 0; iSubItem < 4; iSubItem++)
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

		for (iItem = 0; iItem < 256; iItem++)  // insert the items and subitems into the list view.
			for (iSubItem = 0; iSubItem < 4; iSubItem++)
			{
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = (iSubItem == 0)? iItem : iActualItem;;
				lvItem.iSubItem = iSubItem;

				str.Format("%d", ((iSubItem == 0) ? iItem : pDocument->cumData[(iSubItem - 1) * 256 + iItem]));
				lvItem.pszText = (char *)LPCSTR(str);

				if (iSubItem == 0)
					iActualItem = m_lstData2.InsertItem(&lvItem); // insert new item
				else
					m_lstData2.SetItem(&lvItem); // modify existing item (the sub-item text)
			}
	}

	
	pDocument->DataChanged = FALSE;
}
