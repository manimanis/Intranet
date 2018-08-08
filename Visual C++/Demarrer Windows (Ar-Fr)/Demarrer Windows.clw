; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CParametresArAn
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demarrer Windows.h"

ClassCount=5
Class1=CDemarrerWindowsApp
Class2=CDemarrerWindowsDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DEMARRERWINDOWS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CParametres
Resource4=IDD_PARAMETRES
Class5=CParametresArAn
Resource5=IDD_PARAMETRES_ARABE_FRANCAIS

[CLS:CDemarrerWindowsApp]
Type=0
HeaderFile=Demarrer Windows.h
ImplementationFile=Demarrer Windows.cpp
Filter=N

[CLS:CDemarrerWindowsDlg]
Type=0
HeaderFile=Demarrer WindowsDlg.h
ImplementationFile=Demarrer WindowsDlg.cpp
Filter=D
LastObject=CDemarrerWindowsDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Demarrer WindowsDlg.h
ImplementationFile=Demarrer WindowsDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308481
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_DEMARRERWINDOWS_DIALOG]
Type=1
Class=CDemarrerWindowsDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_REBOOT,button,1342242816
Control3=IDC_STATIC,button,1342178055
Control4=IDC_PARAMETRES,button,1342242816
Control5=IDC_ARABE,button,1342308361
Control6=IDC_FRANCAIS,button,1342177289
Control7=IDC_STATIC,static,1342308353

[DLG:IDD_PARAMETRES]
Type=1
Class=CParametres
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PATH,edit,1350633600
Control4=IDC_PARCOURIR,button,1342242816

[CLS:CParametres]
Type=0
HeaderFile=Parametres.h
ImplementationFile=Parametres.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CParametres

[DLG:IDD_PARAMETRES_ARABE_FRANCAIS]
Type=1
Class=CParametresArAn
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PARAM_ARABE,button,1342242816
Control4=IDC_PARAM_FRANCAIS,button,1342242816

[CLS:CParametresArAn]
Type=0
HeaderFile=ParametresArAn.h
ImplementationFile=ParametresArAn.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

