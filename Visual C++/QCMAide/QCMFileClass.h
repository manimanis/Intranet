// QCMFileClass.h: interface for the CQCMFileClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QCMFILECLASS_H__6670AF34_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
#define AFX_QCMFILECLASS_H__6670AF34_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CQCMFileClass  
{
public:
	void ResetProp();
	float GetQuestionMark(int nQuestionIndex);
	float GetMark();
	void SetCheckProp(int nQuestionIndex, int nPropIndex, char value);
	char IsPropChecked(int nQuestionIndex, int nPropIndex);
	int GetMaxPropositions();
	int GetQuestionCount();
	CString GetPropostion(int nQuestionIndex, int nPropIndex);
	CString GetQuestion(int nIndex);
	int GetPropositionCount(int nQuestionIndex);
	BOOL LoadData();
	void SetFileName(CString szFilename);
	CQCMFileClass();
	virtual ~CQCMFileClass();

protected:
	char *m_pcChoiceProp;
	int m_nMaxPropositionCount;
	CString m_szFileName;
	int m_nQuestionCount;
	CArray<CDataStorage, CDataStorage> m_dataStorage;
	int *m_pcPropositionArray;
};

#endif // !defined(AFX_QCMFILECLASS_H__6670AF34_4EAC_11D5_B9B0_0000E8EA8C1A__INCLUDED_)
