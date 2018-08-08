// QCMFileClass.cpp: implementation of the CQCMFileClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QCMAide.h"
#include "QCMFileClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQCMFileClass::CQCMFileClass()
{
	m_szFileName = "";
	m_nQuestionCount = 0;
	m_nMaxPropositionCount = 0;
	m_pcPropositionArray = NULL;
	m_pcChoiceProp = NULL;
}

CQCMFileClass::~CQCMFileClass()
{
	if (m_pcPropositionArray) delete [] m_pcPropositionArray;
	if (m_pcChoiceProp) delete [] m_pcChoiceProp;
}

void CQCMFileClass::SetFileName(CString szFilename)
{
	m_szFileName = szFilename;
}

BOOL CQCMFileClass::LoadData()
{
	if (m_szFileName == "") return FALSE;

	CStdioFile file;
	CString szText;
	CDataStorage datStorage;

	if (!file.Open(m_szFileName, CFile::modeRead)) return FALSE;
	if (!file.ReadString(szText)) return FALSE;
	if (szText != "MANI Mohamed Anis QCM File") return FALSE;

	while(file.ReadString(szText))
	{
		if (szText != "")
		{
			if (szText[0] == '#') // Question
			{
				datStorage.iType = TYPE_QUESTION;
				m_nQuestionCount++;
			}
			else				// une proposition fausse
				datStorage.iType = TYPE_PROPOSITION;
		

			if (szText[0] == '>') // une Bonne proposition
				datStorage.iType |= TYPE_GOOD_ANSWER;

			if (szText[0] == '#' || szText[0] == '>')
				szText = szText.Mid(1);

			datStorage.szText = szText;

			m_dataStorage.Add(datStorage);
		}
	}

	file.Close();

	int i, j = 0;

	m_pcPropositionArray = new int [m_nQuestionCount];
	m_pcChoiceProp = new char[m_dataStorage.GetSize()];
	memset(m_pcChoiceProp, 0, m_dataStorage.GetSize());
	for (i = 0, j = 0 ; i < m_dataStorage.GetSize() ; i++)
		if (m_dataStorage[i].iType & TYPE_QUESTION)
		{
			m_pcPropositionArray[j++] = i;
		}

	m_nMaxPropositionCount = GetPropositionCount(0);
	for (i = 1 ; i < m_nQuestionCount ; i++)
		if ((j = GetPropositionCount(i)) > m_nMaxPropositionCount) 
			m_nMaxPropositionCount = j;

	return TRUE;
}

int CQCMFileClass::GetPropositionCount(int nQuestionIndex)
{
	if (nQuestionIndex >= m_nQuestionCount) return -1;

	int fin;

	if (nQuestionIndex == (m_nQuestionCount - 1))
		fin = m_dataStorage.GetSize();
	else
		fin = m_pcPropositionArray[nQuestionIndex + 1];

	return (fin - m_pcPropositionArray[nQuestionIndex] - 1);
}

CString CQCMFileClass::GetQuestion(int nIndex)
{
	if (nIndex >= m_nQuestionCount) return CString("");

	return m_dataStorage[m_pcPropositionArray[nIndex]].szText;
}

CString CQCMFileClass::GetPropostion(int nQuestionIndex, int nPropIndex)
{
	if (nQuestionIndex >= m_nQuestionCount) return CString("");
	if (nPropIndex >= GetPropositionCount(nQuestionIndex)) return CString("");

	return m_dataStorage[m_pcPropositionArray[nQuestionIndex] + nPropIndex + 1].szText;
}

int CQCMFileClass::GetQuestionCount()
{
	return m_nQuestionCount;
}

int CQCMFileClass::GetMaxPropositions()
{
	return m_nMaxPropositionCount;
}

char CQCMFileClass::IsPropChecked(int nQuestionIndex, int nPropIndex)
{
	if (nQuestionIndex >= m_nQuestionCount) return FALSE;
	if (nPropIndex >= GetPropositionCount(nQuestionIndex)) return FALSE;

	return m_pcChoiceProp[m_pcPropositionArray[nQuestionIndex] + nPropIndex + 1];
}

void CQCMFileClass::SetCheckProp(int nQuestionIndex, int nPropIndex, char value)
{
	if (nQuestionIndex >= m_nQuestionCount) return ;
	if (nPropIndex >= GetPropositionCount(nQuestionIndex)) return ;

	m_pcChoiceProp[m_pcPropositionArray[nQuestionIndex] + nPropIndex + 1] = value;
}

float CQCMFileClass::GetMark()
{
	float result = 0;

	for (int i = 0 ; i < m_nQuestionCount ; i++)
		result += GetQuestionMark(i);

	return (result / (float)m_nQuestionCount) * 20;
}

float CQCMFileClass::GetQuestionMark(int nQuestionIndex)
{
	int choix = GetPropositionCount(nQuestionIndex);
	int base = m_pcPropositionArray[nQuestionIndex] + 1;
	float mark = (float)choix;

	for (int i = 0 ; i < choix ; i++)
	{
		if ((m_pcChoiceProp[base + i] && !(m_dataStorage[base + i].iType & TYPE_GOOD_ANSWER)) ||
			(!m_pcChoiceProp[base + i] && (m_dataStorage[base + i].iType & TYPE_GOOD_ANSWER)))
		{
				if (mark > 1.0) mark -= 1.0; else mark = 0.0;
		}
	}

	return (mark / (float)choix);
}

void CQCMFileClass::ResetProp()
{
	for (int i = 0 ; i < m_dataStorage.GetSize() ; i++)
		m_pcChoiceProp[i] = 0;
}
