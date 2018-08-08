// Encodeur.h: interface for the CEncodeur class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENCODEUR_H__F3AE94C1_DB92_11D4_86C8_0000E8EA8C1A__INCLUDED_)
#define AFX_ENCODEUR_H__F3AE94C1_DB92_11D4_86C8_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEncodeur  
{
public:
	CString Encoder(CString str);
	CEncodeur();
	virtual ~CEncodeur();

};

#endif // !defined(AFX_ENCODEUR_H__F3AE94C1_DB92_11D4_86C8_0000E8EA8C1A__INCLUDED_)
