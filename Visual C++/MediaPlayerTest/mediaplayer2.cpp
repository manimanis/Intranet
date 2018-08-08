// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "mediaplayer2.h"

// Dispatch interfaces referenced by this interface
#include "MediaPlayerDvd.h"

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer2

IMPLEMENT_DYNCREATE(CMediaPlayer2, CWnd)
BEGIN_MESSAGE_MAP(CMediaPlayer2, CWnd)
	//{{AFX_MSG_MAP(CWnd)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer2 properties

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer2 operations

double CMediaPlayer2::GetCurrentPosition()
{
	double result;
	InvokeHelper(0x403, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetCurrentPosition(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x403, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

double CMediaPlayer2::GetDuration()
{
	double result;
	InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetImageSourceWidth()
{
	long result;
	InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetImageSourceHeight()
{
	long result;
	InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetMarkerCount()
{
	long result;
	InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetCanScan()
{
	BOOL result;
	InvokeHelper(0x3f3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetCanSeek()
{
	BOOL result;
	InvokeHelper(0x3f4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetCanSeekToMarkers()
{
	BOOL result;
	InvokeHelper(0x417, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetCurrentMarker()
{
	long result;
	InvokeHelper(0x405, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetCurrentMarker(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x405, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CMediaPlayer2::GetFileName()
{
	CString result;
	InvokeHelper(0x402, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetFileName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x402, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CMediaPlayer2::GetSourceLink()
{
	CString result;
	InvokeHelper(0x3f1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

DATE CMediaPlayer2::GetCreationDate()
{
	DATE result;
	InvokeHelper(0x40c, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetErrorCorrection()
{
	CString result;
	InvokeHelper(0x40e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetBandwidth()
{
	long result;
	InvokeHelper(0x40d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetSourceProtocol()
{
	long result;
	InvokeHelper(0x424, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetReceivedPackets()
{
	long result;
	InvokeHelper(0x40f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetRecoveredPackets()
{
	long result;
	InvokeHelper(0x410, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetLostPackets()
{
	long result;
	InvokeHelper(0x411, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetReceptionQuality()
{
	long result;
	InvokeHelper(0x412, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetBufferingCount()
{
	long result;
	InvokeHelper(0x413, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetIsBroadcast()
{
	BOOL result;
	InvokeHelper(0x422, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetBufferingProgress()
{
	long result;
	InvokeHelper(0x438, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetChannelName()
{
	CString result;
	InvokeHelper(0x41a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetChannelDescription()
{
	CString result;
	InvokeHelper(0x41b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetChannelURL()
{
	CString result;
	InvokeHelper(0x41c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetContactAddress()
{
	CString result;
	InvokeHelper(0x41d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetContactPhone()
{
	CString result;
	InvokeHelper(0x41e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetContactEmail()
{
	CString result;
	InvokeHelper(0x41f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

double CMediaPlayer2::GetBufferingTime()
{
	double result;
	InvokeHelper(0x42e, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetBufferingTime(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x42e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CMediaPlayer2::GetAutoStart()
{
	BOOL result;
	InvokeHelper(0x3f9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAutoStart(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetAutoRewind()
{
	BOOL result;
	InvokeHelper(0x3fa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAutoRewind(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3fa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

double CMediaPlayer2::GetRate()
{
	double result;
	InvokeHelper(0x404, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetRate(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x404, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CMediaPlayer2::GetSendKeyboardEvents()
{
	BOOL result;
	InvokeHelper(0x3f5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendKeyboardEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetSendMouseClickEvents()
{
	BOOL result;
	InvokeHelper(0x3f6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendMouseClickEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetSendMouseMoveEvents()
{
	BOOL result;
	InvokeHelper(0x3f7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendMouseMoveEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3f7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetPlayCount()
{
	long result;
	InvokeHelper(0x406, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetPlayCount(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x406, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CMediaPlayer2::GetClickToPlay()
{
	BOOL result;
	InvokeHelper(0x401, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetClickToPlay(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x401, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetAllowScan()
{
	BOOL result;
	InvokeHelper(0x40b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAllowScan(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x40b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetEnableContextMenu()
{
	BOOL result;
	InvokeHelper(0x3fd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetEnableContextMenu(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3fd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetCursorType()
{
	long result;
	InvokeHelper(0x414, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetCursorType(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x414, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CMediaPlayer2::GetCodecCount()
{
	long result;
	InvokeHelper(0x421, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetAllowChangeDisplaySize()
{
	BOOL result;
	InvokeHelper(0x420, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAllowChangeDisplaySize(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x420, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetIsDurationValid()
{
	BOOL result;
	InvokeHelper(0x423, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetOpenState()
{
	long result;
	InvokeHelper(0x425, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetSendOpenStateChangeEvents()
{
	BOOL result;
	InvokeHelper(0x426, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendOpenStateChangeEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x426, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetSendWarningEvents()
{
	BOOL result;
	InvokeHelper(0x427, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendWarningEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x427, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetSendErrorEvents()
{
	BOOL result;
	InvokeHelper(0x428, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendErrorEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x428, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetPlayState()
{
	long result;
	InvokeHelper(0x42c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetSendPlayStateChangeEvents()
{
	BOOL result;
	InvokeHelper(0x42d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSendPlayStateChangeEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x42d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetDisplaySize()
{
	long result;
	InvokeHelper(0x408, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetDisplaySize(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x408, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CMediaPlayer2::GetInvokeURLs()
{
	BOOL result;
	InvokeHelper(0x3fc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetInvokeURLs(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3fc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CMediaPlayer2::GetBaseURL()
{
	CString result;
	InvokeHelper(0x43a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetBaseURL(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x43a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CMediaPlayer2::GetDefaultFrame()
{
	CString result;
	InvokeHelper(0x43b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetDefaultFrame(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x43b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CMediaPlayer2::GetHasError()
{
	BOOL result;
	InvokeHelper(0x429, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetErrorDescription()
{
	CString result;
	InvokeHelper(0x42a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetErrorCode()
{
	long result;
	InvokeHelper(0x42b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetAnimationAtStart()
{
	BOOL result;
	InvokeHelper(0x415, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAnimationAtStart(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x415, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetTransparentAtStart()
{
	BOOL result;
	InvokeHelper(0x3fe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetTransparentAtStart(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3fe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetVolume()
{
	long result;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetVolume(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CMediaPlayer2::GetBalance()
{
	long result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetBalance(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CMediaPlayer2::GetReadyState()
{
	long result;
	InvokeHelper(DISPID_READYSTATE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

double CMediaPlayer2::GetSelectionStart()
{
	double result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSelectionStart(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

double CMediaPlayer2::GetSelectionEnd()
{
	double result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSelectionEnd(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CMediaPlayer2::GetShowDisplay()
{
	BOOL result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowDisplay(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowControls()
{
	BOOL result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowControls(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowPositionControls()
{
	BOOL result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowPositionControls(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowTracker()
{
	BOOL result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowTracker(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetEnablePositionControls()
{
	BOOL result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetEnablePositionControls(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetEnableTracker()
{
	BOOL result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetEnableTracker(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetEnabled()
{
	BOOL result;
	InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetEnabled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

unsigned long CMediaPlayer2::GetDisplayForeColor()
{
	unsigned long result;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetDisplayForeColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CMediaPlayer2::GetDisplayBackColor()
{
	unsigned long result;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetDisplayBackColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CMediaPlayer2::GetDisplayMode()
{
	long result;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetDisplayMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x20, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CMediaPlayer2::GetVideoBorder3D()
{
	BOOL result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetVideoBorder3D(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CMediaPlayer2::GetVideoBorderWidth()
{
	long result;
	InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetVideoBorderWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

unsigned long CMediaPlayer2::GetVideoBorderColor()
{
	unsigned long result;
	InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetVideoBorderColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL CMediaPlayer2::GetShowGotoBar()
{
	BOOL result;
	InvokeHelper(0x440, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowGotoBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x440, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowStatusBar()
{
	BOOL result;
	InvokeHelper(0x43e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowStatusBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x43e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowCaptioning()
{
	BOOL result;
	InvokeHelper(0x43c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowCaptioning(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x43c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetShowAudioControls()
{
	BOOL result;
	InvokeHelper(0x453, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetShowAudioControls(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x453, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString CMediaPlayer2::GetCaptioningID()
{
	CString result;
	InvokeHelper(0x43d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetCaptioningID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x43d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL CMediaPlayer2::GetMute()
{
	BOOL result;
	InvokeHelper(0x441, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetMute(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x441, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetCanPreview()
{
	BOOL result;
	InvokeHelper(0x445, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetPreviewMode()
{
	BOOL result;
	InvokeHelper(0x443, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetPreviewMode(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x443, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetHasMultipleItems()
{
	BOOL result;
	InvokeHelper(0x446, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetLanguage()
{
	long result;
	InvokeHelper(0x447, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetLanguage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x447, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CMediaPlayer2::GetAudioStream()
{
	long result;
	InvokeHelper(0x448, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAudioStream(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x448, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CMediaPlayer2::GetSAMIStyle()
{
	CString result;
	InvokeHelper(0x449, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSAMIStyle(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x449, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CMediaPlayer2::GetSAMILang()
{
	CString result;
	InvokeHelper(0x44a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSAMILang(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x44a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CMediaPlayer2::GetSAMIFileName()
{
	CString result;
	InvokeHelper(0x44b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetSAMIFileName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x44b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long CMediaPlayer2::GetStreamCount()
{
	long result;
	InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString CMediaPlayer2::GetClientId()
{
	CString result;
	InvokeHelper(0x452, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetConnectionSpeed()
{
	long result;
	InvokeHelper(0x459, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetAutoSize()
{
	BOOL result;
	InvokeHelper(0xfffffe0c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetAutoSize(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xfffffe0c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CMediaPlayer2::GetEnableFullScreenControls()
{
	BOOL result;
	InvokeHelper(0x454, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetEnableFullScreenControls(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x454, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH CMediaPlayer2::GetActiveMovie()
{
	LPDISPATCH result;
	InvokeHelper(0x455, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH CMediaPlayer2::GetNSPlay()
{
	LPDISPATCH result;
	InvokeHelper(0x456, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL CMediaPlayer2::GetWindowlessVideo()
{
	BOOL result;
	InvokeHelper(0x458, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetWindowlessVideo(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x458, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void CMediaPlayer2::Play()
{
	InvokeHelper(0x7d1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::Stop()
{
	InvokeHelper(0x7d3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::Pause()
{
	InvokeHelper(0x7d2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

double CMediaPlayer2::GetMarkerTime(long MarkerNum)
{
	double result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d4, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		MarkerNum);
	return result;
}

CString CMediaPlayer2::GetMarkerName(long MarkerNum)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		MarkerNum);
	return result;
}

void CMediaPlayer2::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CMediaPlayer2::GetCodecInstalled(long CodecNum)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		CodecNum);
	return result;
}

CString CMediaPlayer2::GetCodecDescription(long CodecNum)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d8, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		CodecNum);
	return result;
}

CString CMediaPlayer2::GetCodecURL(long CodecNum)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7d9, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		CodecNum);
	return result;
}

CString CMediaPlayer2::GetMoreInfoURL(long MoreInfoType)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7db, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		MoreInfoType);
	return result;
}

CString CMediaPlayer2::GetMediaInfoString(long MediaInfoType)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7e0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		MediaInfoType);
	return result;
}

void CMediaPlayer2::Cancel()
{
	InvokeHelper(0x7d6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::Open(LPCTSTR bstrFileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7da, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 bstrFileName);
}

BOOL CMediaPlayer2::IsSoundCardEnabled()
{
	BOOL result;
	InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::Next()
{
	InvokeHelper(0x7e7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::Previous()
{
	InvokeHelper(0x7e6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::StreamSelect(long StreamNum)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7df, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 StreamNum);
}

void CMediaPlayer2::FastForward()
{
	InvokeHelper(0x7e8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMediaPlayer2::FastReverse()
{
	InvokeHelper(0x7e9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString CMediaPlayer2::GetStreamName(long StreamNum)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7e3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		StreamNum);
	return result;
}

long CMediaPlayer2::GetStreamGroup(long StreamNum)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7e4, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		StreamNum);
	return result;
}

BOOL CMediaPlayer2::GetStreamSelected(long StreamNum)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7e5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		StreamNum);
	return result;
}

CMediaPlayerDvd CMediaPlayer2::GetDvd()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x5dc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CMediaPlayerDvd(pDispatch);
}

CString CMediaPlayer2::GetMediaParameter(long EntryNum, LPCTSTR bstrParameterName)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x7ec, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		EntryNum, bstrParameterName);
	return result;
}

CString CMediaPlayer2::GetMediaParameterName(long EntryNum, long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x7ed, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		EntryNum, Index);
	return result;
}

long CMediaPlayer2::GetEntryCount()
{
	long result;
	InvokeHelper(0x7ee, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long CMediaPlayer2::GetCurrentEntry()
{
	long result;
	InvokeHelper(0x7ef, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void CMediaPlayer2::SetCurrentEntry(long EntryNumber)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7f0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 EntryNumber);
}

void CMediaPlayer2::ShowDialog(long mpDialogIndex)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7f1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 mpDialogIndex);
}
