// Equalization.cpp: implementation of the CEqualization class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "Equalization.h"
#include "EqualisationDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEqualization::CEqualization()
{
	linExpDlg = new CEqualisationDlg;
}

CEqualization::~CEqualization()
{
	if (linExpDlg) delete linExpDlg;
}

unsigned char CEqualization::GetLookUpTable(int x)
{
	return LookUpTable[x];
}
