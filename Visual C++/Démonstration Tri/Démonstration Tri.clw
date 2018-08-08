; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Démonstration Tri.h"
LastPage=0

ClassCount=9
Class1=CDmonstrationTriApp
Class2=CDmonstrationTriDoc
Class3=CDmonstrationTriView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CTri_Bulles
Resource2=IDD_ABOUTBOX
Class7=CPlaySpeed
Resource3=IDD_PLAY_SPEED
Class8=CSearchDialog
Class9=CSortSearch
Resource4=IDD_SEARCH_DIALOG

[CLS:CDmonstrationTriApp]
Type=0
HeaderFile=Démonstration Tri.h
ImplementationFile=Démonstration Tri.cpp
Filter=N

[CLS:CDmonstrationTriDoc]
Type=0
HeaderFile=Démonstration TriDoc.h
ImplementationFile=Démonstration TriDoc.cpp
Filter=N

[CLS:CDmonstrationTriView]
Type=0
HeaderFile=Démonstration TriView.h
ImplementationFile=Démonstration TriView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BUBBLE_SORT
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Démonstration Tri.cpp
ImplementationFile=Démonstration Tri.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308481
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,button,1342177287

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_DEMO_SPEED
Command3=ID_SCRAMBLE
Command4=ID_ORDRE_CROISSANT
Command5=ID_BUBBLE_SORT
Command6=ID_SELECTION_SORT
Command7=ID_SEARCH_VALUE
Command8=ID_DICO_SEARCH
Command9=ID_PLAY
Command10=ID_STOP
Command11=ID_NEXT
Command12=ID_EJECT
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_DEMO_SPEED
Command2=ID_SCRAMBLE
Command3=ID_SEARCH_VALUE
Command4=ID_DICO_SEARCH
Command5=ID_ORDRE_CROISSANT
Command6=ID_BUBBLE_SORT
Command7=ID_SELECTION_SORT
Command8=ID_PLAY
Command9=ID_STOP
Command10=ID_NEXT
Command11=ID_EJECT
Command12=ID_APP_ABOUT
CommandCount=12

[CLS:CTri_Bulles]
Type=0
HeaderFile=Tri_Bulles.h
ImplementationFile=Tri_Bulles.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC
LastObject=CTri_Bulles

[DLG:IDD_PLAY_SPEED]
Type=1
Class=CPlaySpeed
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_SPEED,msctls_trackbar32,1342242841
Control5=IDC_VITESSE,static,1342308353

[CLS:CPlaySpeed]
Type=0
HeaderFile=PlaySpeed.h
ImplementationFile=PlaySpeed.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPlaySpeed

[DLG:IDD_SEARCH_DIALOG]
Type=1
Class=CSearchDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB_LIST,listbox,1352728835
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT_VAL,edit,1350631552

[CLS:CSearchDialog]
Type=0
HeaderFile=SearchDialog.h
ImplementationFile=SearchDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSearchDialog

[CLS:CSortSearch]
Type=0
HeaderFile=SortSearch.h
ImplementationFile=SortSearch.cpp
BaseClass=CWinThread
Filter=N

