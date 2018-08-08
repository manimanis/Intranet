; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRecenserODBCDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Recenser ODBC.h"

ClassCount=6
Class1=CRecenserODBCApp
Class2=CRecenserODBCDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_PASSWOR_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CRegisterDlg
Resource4=IDD_RECENSERODBC_DIALOG
Class5=CPasswordDlg
Resource5=IDD_PARAMETERS
Class6=CSetNewPasswordDlg
Resource6=IDD_PASSWORD_SETDIALOG

[CLS:CRecenserODBCApp]
Type=0
HeaderFile=Recenser ODBC.h
ImplementationFile=Recenser ODBC.cpp
Filter=N

[CLS:CRecenserODBCDlg]
Type=0
HeaderFile=Recenser ODBCDlg.h
ImplementationFile=Recenser ODBCDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CRecenserODBCDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Recenser ODBCDlg.h
ImplementationFile=Recenser ODBCDlg.cpp
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

[DLG:IDD_RECENSERODBC_DIALOG]
Type=1
Class=CRecenserODBCDlg
ControlCount=7
Control1=IDC_LIST1,SysListView32,1350631937
Control2=IDCANCEL,button,1342242817
Control3=ID_SUPPRIMER,button,1342242816
Control4=ID_NOUVEAU,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=ID_MODIFIER,button,1342242816
Control7=ID_PASSWORD,button,1342242816

[DLG:IDD_PARAMETERS]
Type=1
Class=CRegisterDlg
ControlCount=10
Control1=IDC_STATIC,button,1342178055
Control2=IDC_PATH,edit,1350631552
Control3=IDC_DBNAME,edit,1350631552
Control4=IDC_DESCRIPTION,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDOK,button,1342242817
Control9=IDC_PARCOURIR,button,1342242816
Control10=IDCANCEL,button,1342242816

[CLS:CRegisterDlg]
Type=0
HeaderFile=RegisterDlg.h
ImplementationFile=RegisterDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_PASSWOR_DIALOG]
Type=1
Class=CPasswordDlg
ControlCount=7
Control1=IDC_LOGIN,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342177283

[CLS:CPasswordDlg]
Type=0
HeaderFile=PasswordDlg.h
ImplementationFile=PasswordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_PASSWORD_SETDIALOG]
Type=1
Class=CSetNewPasswordDlg
ControlCount=9
Control1=IDC_LOGIN,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDC_PASSWORD2,edit,1350631584
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342177283
Control9=IDC_STATIC,static,1342308352

[CLS:CSetNewPasswordDlg]
Type=0
HeaderFile=SetNewPasswordDlg.h
ImplementationFile=SetNewPasswordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

