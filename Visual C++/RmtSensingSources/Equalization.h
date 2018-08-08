// Equalization.h: interface for the CEqualization class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EQUALIZATION_H__B7C62E6A_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
#define AFX_EQUALIZATION_H__B7C62E6A_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LookUpTables.h"

class CEqualization : public CLookUpTables  
{
public:
	CEqualization();
	virtual ~CEqualization();
	unsigned char GetLookUpTable(int x);
};

#endif // !defined(AFX_EQUALIZATION_H__B7C62E6A_6947_11D4_BEAA_0000E8EA8C1A__INCLUDED_)
