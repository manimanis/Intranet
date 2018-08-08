; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CApacheStarterDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Apache Starter.h"

ClassCount=3
Class1=CApacheStarterApp
Class2=CApacheStarterDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_APACHESTARTER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_POPUP

[CLS:CApacheStarterApp]
Type=0
HeaderFile=Apache Starter.h
ImplementationFile=Apache Starter.cpp
Filter=N

[CLS:CApacheStarterDlg]
Type=0
HeaderFile=Apache StarterDlg.h
ImplementationFile=Apache StarterDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CACHEDIALOG

[CLS:CAboutDlg]
Type=0
HeaderFile=Apache StarterDlg.h
ImplementationFile=Apache StarterDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_APACHESTARTER_DIALOG]
Type=1
Class=CApacheStarterDlg
ControlCount=5
Control1=IDC_EXIT,button,1342242816
Control2=IDC_STATE,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_PARAMS,button,1342242816
Control5=IDC_CACHEDIALOG,button,1342242816

[MNU:IDR_POPUP]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_QUITTER
CommandCount=2

