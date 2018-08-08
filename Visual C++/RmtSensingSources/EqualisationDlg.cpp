// EqualisationDlg.cpp: implementation of the CEqualisationDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "EqualisationDlg.h"
#include "common.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEqualisationDlg::CEqualisationDlg()
{
	m_maxPoints = 1;
}

CEqualisationDlg::~CEqualisationDlg()
{

}

void CEqualisationDlg::InitPoints(int *picInfo, int *cumInfo)
{
	for (int i = 0 ; i < 256 ; i++)
	{
		LookUpTable[2][i] = int(*(cumInfo + i) * 255.0 / *(cumInfo + 255));
		LookUpTable[1][i] = int(*(cumInfo + 256 + i) * 255.0 / *(cumInfo + 256 + 255));
		LookUpTable[0][i] = int(*(cumInfo + 512 + i) * 255.0 / *(cumInfo + 512 + 255));
	}
}

void CEqualisationDlg::Recalc()
{

}

void CEqualisationDlg::OnChangeMaxPoints()
{

}
