; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImgViewerView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImgViewer.h"
LastPage=0

ClassCount=5
Class1=CImgViewerApp
Class2=CImgViewerDoc
Class3=CImgViewerView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CImgViewerApp]
Type=0
HeaderFile=ImgViewer.h
ImplementationFile=ImgViewer.cpp
Filter=N

[CLS:CImgViewerDoc]
Type=0
HeaderFile=ImgViewerDoc.h
ImplementationFile=ImgViewerDoc.cpp
Filter=N
LastObject=CImgViewerDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CImgViewerView]
Type=0
HeaderFile=ImgViewerView.h
ImplementationFile=ImgViewerView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CImgViewerView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=ImgViewer.cpp
ImplementationFile=ImgViewer.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_FILE_PRINT_PREVIEW
Command4=ID_FILE_PRINT_SETUP
Command5=ID_FILE_SEND_MAIL
Command6=ID_FILE_PROPERTIES
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_VIEW_TOOLBAR
Command10=ID_VIEW_STATUS_BAR
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_NEXT_PANE
Command4=ID_PREV_PANE
CommandCount=4

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_FILE_PRINT_PREVIEW
Command4=ID_FILE_SEND_MAIL
Command5=ID_FILE_PROPERTIES
Command6=ID_APP_ABOUT
CommandCount=6

