// CorrectionQCMView.cpp : implementation of the CCorrectionQCMView class
//

#include "stdafx.h"
#include "CorrectionQCM.h"

#include "CorrectionQCMDoc.h"
#include "CorrectionQCMView.h"

#include "QuestionsReponses.h"
#include "ResponseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMView

IMPLEMENT_DYNCREATE(CCorrectionQCMView, CFormView)

BEGIN_MESSAGE_MAP(CCorrectionQCMView, CFormView)
	//{{AFX_MSG_MAP(CCorrectionQCMView)
	ON_BN_CLICKED(IDC_ETAPE1, OnEtape1)
	ON_BN_CLICKED(IDC_ETAPE2, OnEtape2)
	ON_BN_CLICKED(IDC_ETAPE3, OnEtape3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMView construction/destruction

CCorrectionQCMView::CCorrectionQCMView()
	: CFormView(CCorrectionQCMView::IDD)
{
	//{{AFX_DATA_INIT(CCorrectionQCMView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CCorrectionQCMView::~CCorrectionQCMView()
{
}

void CCorrectionQCMView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCorrectionQCMView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CCorrectionQCMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CCorrectionQCMView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMView diagnostics

#ifdef _DEBUG
void CCorrectionQCMView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCorrectionQCMView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCorrectionQCMDoc* CCorrectionQCMView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCorrectionQCMDoc)));
	return (CCorrectionQCMDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCorrectionQCMView message handlers

void CCorrectionQCMView::OnEtape1() 
{
	CQuestionsReponses qrDlg;
	
	qrDlg.DoModal();
}

void CCorrectionQCMView::OnEtape2() 
{
	CResponseDlg rDlg;
	
	rDlg.DoModal();
}

void CCorrectionQCMView::OnEtape3() 
{
	CResponseDlg rDlg;
	
	rDlg.DoModal();	
}
