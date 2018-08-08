; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrawProperty
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CD Label.h"
LastPage=0

ClassCount=9
Class1=CCDLabelApp
Class2=CCDLabelDoc
Class3=CCDLabelView
Class4=CMainFrame
Class7=CBackSide

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_POPUP_MENU
Resource3=IDR_CDLABETYPE
Class5=CChildFrame
Class6=CAboutDlg
Class8=CProprieteTexte
Resource4=IDR_DESSIN
Resource5=IDR_MAINFRAME
Resource6=IDD_TEXT_PROPERTY
Class9=CDrawProperty
Resource7=IDD_DRAW_PROPERTIES

[CLS:CCDLabelApp]
Type=0
HeaderFile=CD Label.h
ImplementationFile=CD Label.cpp
Filter=N

[CLS:CCDLabelDoc]
Type=0
HeaderFile=CD LabelDoc.h
ImplementationFile=CD LabelDoc.cpp
Filter=N

[CLS:CCDLabelView]
Type=0
HeaderFile=CD LabelView.h
ImplementationFile=CD LabelView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=CD Label.cpp
ImplementationFile=CD Label.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_CDLABETYPE]
Type=1
Class=CCDLabelView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_TEXTE
Command16=ID_DESSIN
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
Command19=ID_WINDOW_NEW
Command20=ID_WINDOW_CASCADE
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_ARRANGE
Command23=ID_APP_ABOUT
CommandCount=23

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

[CLS:CBackSide]
Type=0
HeaderFile=BackSide.h
ImplementationFile=BackSide.cpp
BaseClass=CScrollView
Filter=C
LastObject=CBackSide

[DLG:IDD_TEXT_PROPERTY]
Type=1
Class=CProprieteTexte
ControlCount=13
Control1=IDC_TEXTE,edit,1352732804
Control2=IDC_ALIGNLEFT,button,1342308361
Control3=IDC_ALIGNCENTER,button,1342177289
Control4=IDC_ALIGNRIGHT,button,1342177289
Control5=IDC_POLICE,button,1342242816
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_ROTATION,msctls_trackbar32,1342242836
Control13=IDC_ROTATIONVALUE,edit,1342244993

[CLS:CProprieteTexte]
Type=0
HeaderFile=ProprieteTexte.h
ImplementationFile=ProprieteTexte.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProprieteTexte

[TB:IDR_DESSIN]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_TEXTE
Command10=ID_PROPERTIES
Command11=ID_DESSIN
CommandCount=11

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_BRINGTOBACK
Command2=ID_BRINGTOFRONT
Command3=ID_AVANCE
Command4=ID_BACK
Command5=ID_PROPERTIES
CommandCount=5

[DLG:IDD_DRAW_PROPERTIES]
Type=1
Class=CDrawProperty
ControlCount=21
Control1=IDC_DTYPE,combobox,1344340226
Control2=IDC_CHECK_FOND,button,1342242819
Control3=IDC_CHECK_TRACE,button,1342242819
Control4=IDC_BTN_FOND,button,1342242816
Control5=IDC_BTN_TRACE,button,1342242816
Control6=IDC_LINE_WIDTH,edit,1350633600
Control7=IDC_SPIN1,msctls_updown32,1342177334
Control8=IDC_ARR_WIDTH,edit,1350633600
Control9=IDC_SPIN2,msctls_updown32,1342177334
Control10=IDC_ARR_HEIGHT,edit,1350633600
Control11=IDC_SPIN3,msctls_updown32,1342177334
Control12=IDOK,button,1342242817
Control13=IDCANCEL,button,1342242816
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC_FOND,static,1342177294
Control17=IDC_STATIC_TRACE,static,1342177294
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352

[CLS:CDrawProperty]
Type=0
HeaderFile=DrawProperty.h
ImplementationFile=DrawProperty.cpp
BaseClass=CDialog
Filter=D
LastObject=CDrawProperty
VirtualFilter=dWC

