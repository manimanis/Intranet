; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpecialPlayerView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Special Player.h"
LastPage=0

ClassCount=5
Class1=CSpecialPlayerApp
Class2=CSpecialPlayerDoc
Class3=CSpecialPlayerView
Class4=CMainFrame

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource7=IDD_SPECIALPLAYER_FORM

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

[DLG:IDD_SPECIALPLAYER_FORM]
Type=1
Class=CSpecialPlayerView
ControlCount=5
Control1=IDC_MEDIAPLAYER1,{22D6F312-B0F6-11D0-94AB-0080C74C7E95},1073807360
Control2=IDC_PROGRESS1,msctls_progress32,1350565888
Control3=IDC_IMPORTATION_MESSAGE,static,1342308352
Control4=IDC_PATIENTEZ,static,1342308352
Control5=IDC_BITMAP,static,1342177294

