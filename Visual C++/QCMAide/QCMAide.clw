; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQCMAideView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QCMAide.h"
LastPage=0

ClassCount=5
Class1=CQCMAideApp
Class2=CQCMAideDoc
Class3=CQCMAideView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDD_QCMAIDE_FORM

[CLS:CQCMAideApp]
Type=0
HeaderFile=QCMAide.h
ImplementationFile=QCMAide.cpp
Filter=N

[CLS:CQCMAideDoc]
Type=0
HeaderFile=QCMAideDoc.h
ImplementationFile=QCMAideDoc.cpp
Filter=N

[CLS:CQCMAideView]
Type=0
HeaderFile=QCMAideView.h
ImplementationFile=QCMAideView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CQCMAideView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=QCMAide.cpp
ImplementationFile=QCMAide.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FICHIER_AFFICHERLANOTE
Command2=ID_APP_EXIT
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FICHIER_AFFICHERLANOTE
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[DLG:IDD_QCMAIDE_FORM]
Type=1
Class=CQCMAideView
ControlCount=8
Control1=IDC_PRECEDENT,button,1342242816
Control2=IDC_SUIVANT,button,1342242816
Control3=IDC_RESET,button,1342242816
Control4=IDC_QUESTION,static,1342308352
Control5=IDC_STATIC,button,1342242823
Control6=IDC_MOYENNE,static,1342308354
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287

