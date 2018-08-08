; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMediaPlayer2
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Special Player.h"
LastPage=0

ClassCount=11
Class1=CSpecialPlayerApp
Class2=CSpecialPlayerDoc
Class3=CSpecialPlayerView
Class4=CMainFrame
Class5=CAboutDlg
Class6=CPresentationForm
Class8=CPersButton
Class9=CSpecialPlayerDlg
Class10=CTest
Class11=CMediaPlayer2

ResourceCount=6
Resource1=IDD_PRESENTATIONFORM_FORM
Resource2=IDD_ABOUTBOX
Resource3=IDR_PRESENTATIONFORM_TMPL
Resource4=IDR_MAINFRAME
Resource5=IDD_SPECIALPLAYER
Resource6=IDD_DIALOG1



[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342178055
Control6=IDC_STATIC,button,1342178055
Control7=IDC_STATIC,static,1342308353

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_APP_EXIT
Command3=ID_AFFICHAGE_TOUJOURSVISIBLE
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_PRESENTATIONFORM_FORM]
Type=1
Class=CPresentationForm
ControlCount=11
Control1=IDC_FOND,static,1342177294
Control2=IDC_BUTTON1,button,1342242827
Control3=IDC_BUTTON2,button,1342242827
Control4=IDC_BUTTON3,button,1342242827
Control5=IDC_BUTTON4,button,1342242827
Control6=IDC_BUTTON10,button,1342242827
Control7=IDC_BUTTON9,button,1342242827
Control8=IDC_BUTTON8,button,1342242827
Control9=IDC_BUTTON7,button,1342242827
Control10=IDC_BUTTON6,button,1342242827
Control11=IDC_BUTTON5,button,1342242827

[CLS:CSpecialPlayerApp]
Type=0
HeaderFile=Special Player.h
ImplementationFile=Special Player.cpp
Filter=N

[CLS:CSpecialPlayerDoc]
Type=0
HeaderFile=Special PlayerDoc.h
ImplementationFile=Special PlayerDoc.cpp
Filter=N

[CLS:CSpecialPlayerView]
Type=0
HeaderFile=Special PlayerView.h
ImplementationFile=Special PlayerView.cpp
Filter=W
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T

[CLS:CAboutDlg]
Type=0
HeaderFile=Special Player.cpp
ImplementationFile=Special Player.cpp
Filter=D

[CLS:CPresentationForm]
Type=0
HeaderFile=PresentationForm.h
ImplementationFile=PresentationForm.cpp
BaseClass=CFormView
Filter=D
LastObject=CPresentationForm
VirtualFilter=VWC

[MNU:IDR_PRESENTATIONFORM_TMPL]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_APP_EXIT
Command3=ID_AFFICHAGE_TOUJOURSVISIBLE
Command4=ID_APP_ABOUT
CommandCount=4

[CLS:CTest]
Type=0
HeaderFile=Test.h
ImplementationFile=Test.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_SPECIALPLAYER]
Type=1
Class=CSpecialPlayerDlg
ControlCount=5
Control1=IDC_PROGRESS1,msctls_progress32,1350565888
Control2=IDC_IMPORTATION_MESSAGE,static,1342308352
Control3=IDC_PATIENTEZ,static,1342308352
Control4=IDC_BITMAP,static,1342177294
Control5=IDC_MEDIAPLAYER1,{22D6F312-B0F6-11D0-94AB-0080C74C7E95},1342242816

[CLS:CSpecialPlayerDlg]
Type=0
HeaderFile=SpecialPlayerDlg.h
ImplementationFile=SpecialPlayerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=CTest
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CPersButton]
Type=0
HeaderFile=PersButton.h
ImplementationFile=PersButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[CLS:CMediaPlayer2]
Type=0
HeaderFile=mediaplayer2.h
ImplementationFile=mediaplayer2.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC

