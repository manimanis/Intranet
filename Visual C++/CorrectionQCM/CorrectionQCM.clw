; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CResponseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CorrectionQCM.h"
LastPage=0

ClassCount=10
Class1=CCorrectionQCMApp
Class2=CCorrectionQCMDoc
Class3=CCorrectionQCMView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_SAISIE_REPONSES
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDR_QUESTION_MENU
Class6=CSaisieDlg
Class7=CMyTreeCtrl
Resource4=IDD_CORRECTIONQCM_FORM
Class8=CResponseDlg
Resource5=IDD_ABOUTBOX
Class9=CQuestionsReponses
Resource6=IDD_QUESTREPONSES
Class10=CQuestionCount
Resource7=IDD_QUESTION_COUNT_DLG

[CLS:CCorrectionQCMApp]
Type=0
HeaderFile=CorrectionQCM.h
ImplementationFile=CorrectionQCM.cpp
Filter=N

[CLS:CCorrectionQCMDoc]
Type=0
HeaderFile=CorrectionQCMDoc.h
ImplementationFile=CorrectionQCMDoc.cpp
Filter=N

[CLS:CCorrectionQCMView]
Type=0
HeaderFile=CorrectionQCMView.h
ImplementationFile=CorrectionQCMView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CCorrectionQCMView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=CorrectionQCM.cpp
ImplementationFile=CorrectionQCM.cpp
Filter=D
LastObject=CAboutDlg

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
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_CORRECTIONQCM_FORM]
Type=1
Class=CCorrectionQCMView
ControlCount=9
Control1=IDC_ETAPE1,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ETAPE2,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ETAPE3,button,1342242816

[CLS:CSaisieDlg]
Type=0
HeaderFile=SaisieDlg.h
ImplementationFile=SaisieDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSaisieDlg
VirtualFilter=dWC

[CLS:CMyTreeCtrl]
Type=0
HeaderFile=MyTreeCtrl.h
ImplementationFile=MyTreeCtrl.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC

[MNU:IDR_QUESTION_MENU]
Type=1
Class=?
Command1=ID_NEW_RESPONSE
CommandCount=1

[CLS:CResponseDlg]
Type=0
HeaderFile=ResponseDlg.h
ImplementationFile=ResponseDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CResponseDlg
VirtualFilter=dWC

[DLG:IDD_SAISIE_REPONSES]
Type=1
Class=CResponseDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SUIVANT,button,1342242816
Control4=IDC_PRECEDENT,button,1342242816
Control5=IDC_FERMER,button,1342242816

[DLG:IDD_QUESTREPONSES]
Type=1
Class=CQuestionsReponses
ControlCount=2
Control1=IDC_QUESTION_LIST,SysListView32,1350566029
Control2=IDC_FERMER,button,1342177280

[CLS:CQuestionsReponses]
Type=0
HeaderFile=QuestionsReponses.h
ImplementationFile=QuestionsReponses.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQuestionsReponses

[DLG:IDD_QUESTION_COUNT_DLG]
Type=1
Class=CQuestionCount
ControlCount=4
Control1=IDC_EDIT_COUNT,edit,1350631554
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_TEXT,static,1342308352

[CLS:CQuestionCount]
Type=0
HeaderFile=QuestionCount.h
ImplementationFile=QuestionCount.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

