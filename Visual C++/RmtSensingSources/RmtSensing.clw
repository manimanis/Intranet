; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorSelectionCriteres
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "rmtsensing.h"
LastPage=0

ClassCount=21
Class1=CChildFrame
Class2=CColorBox
Class3=CColorListBox
Class4=CColorSelectionCriteres
Class5=CEdgeDetectionDlg
Class6=CFakeColorsDialog
Class7=CMainFrame
Class8=CMyListCtrl
Class9=COptimisationsDlg
Class10=CPictureHistogrammeSettingsDlg
Class11=CPictureHistogrammeView
Class12=CRmtListData
Class13=CRmtListForm
Class14=CRmtSensingApp
Class15=CAboutDlg
Class16=CRmtSensingDoc
Class17=CRmtSensingFrame
Class18=CRmtSensingView
Class19=CSplashScreen
Class20=CUserZoomDlg
Class21=CWaitDialog

ResourceCount=13
Resource1=IDD_EDGEDETECT_PERCENT
Resource2=IDD_RMTLISTFORM_FORM
Resource3=IDD_USER_ZOOM
Resource4=IDD_ABOUTBOX
Resource5=IDD_CRITEREDESELECTION
Resource6=IDR_MAINFRAME
Resource7=IDD_SPLASHSCREEN (French (Belgium))
Resource8=IDD_FAKECOLORS
Resource9=IDD_WAITDIALOG
Resource10=IDR_ZOOM
Resource11=IDD_PICTUREHISTOGRAME_DLG
Resource12=IDR_RMTSENTYPE
Resource13=IDD_OPTIMISATIONS_DLG (French (Belgium))

[CLS:CChildFrame]
Type=0
BaseClass=CMDIChildWnd
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp

[CLS:CColorBox]
Type=0
BaseClass=CStatic
HeaderFile=ColorBox.h
ImplementationFile=ColorBox.cpp

[CLS:CColorListBox]
Type=0
BaseClass=CListBox
HeaderFile=ColorListBox.h
ImplementationFile=ColorListBox.cpp
Filter=W
VirtualFilter=bWC

[CLS:CColorSelectionCriteres]
Type=0
BaseClass=CDialog
HeaderFile=ColorSelectionCriteres.h
ImplementationFile=ColorSelectionCriteres.cpp
LastObject=CColorSelectionCriteres

[CLS:CEdgeDetectionDlg]
Type=0
BaseClass=CDialog
HeaderFile=EdgeDetectionDlg.h
ImplementationFile=EdgeDetectionDlg.cpp

[CLS:CFakeColorsDialog]
Type=0
BaseClass=CDialog
HeaderFile=FakeColorsDialog.h
ImplementationFile=FakeColorsDialog.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CMDIFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CMyListCtrl]
Type=0
BaseClass=CListCtrl
HeaderFile=mlistctl.h
ImplementationFile=mlistctl.cpp

[CLS:COptimisationsDlg]
Type=0
BaseClass=CDialog
HeaderFile=OptimisationsDlg.h
ImplementationFile=OptimisationsDlg.cpp

[CLS:CPictureHistogrammeSettingsDlg]
Type=0
BaseClass=CDialog
HeaderFile=PictureHistogrammeSettingsDlg.h
ImplementationFile=PictureHistogrammeSettingsDlg.cpp

[CLS:CPictureHistogrammeView]
Type=0
BaseClass=CView
HeaderFile=PictureHistogrammeView.h
ImplementationFile=PictureHistogrammeView.cpp

[CLS:CRmtListData]
Type=0
BaseClass=CDialog
HeaderFile=RmtListData.h
ImplementationFile=RmtListData.cpp

[CLS:CRmtListForm]
Type=0
BaseClass=CFormView
HeaderFile=RmtListForm.h
ImplementationFile=RmtListForm.cpp

[CLS:CRmtSensingApp]
Type=0
BaseClass=CWinApp
HeaderFile=RmtSensing.h
ImplementationFile=RmtSensing.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=RmtSensing.cpp
ImplementationFile=RmtSensing.cpp
LastObject=CAboutDlg

[CLS:CRmtSensingDoc]
Type=0
BaseClass=CDocument
HeaderFile=RmtSensingDoc.h
ImplementationFile=RmtSensingDoc.cpp
Filter=N
VirtualFilter=DC

[CLS:CRmtSensingFrame]
Type=0
BaseClass=CMDIChildWnd
HeaderFile=RmtSensingFrame.h
ImplementationFile=RmtSensingFrame.cpp

[CLS:CRmtSensingView]
Type=0
BaseClass=CScrollView
HeaderFile=RmtSensingView.h
ImplementationFile=RmtSensingView.cpp

[CLS:CSplashScreen]
Type=0
BaseClass=CDialog
HeaderFile=SplashScreen.h
ImplementationFile=SplashScreen.cpp

[CLS:CUserZoomDlg]
Type=0
BaseClass=CDialog
HeaderFile=UserZoomDlg.h
ImplementationFile=UserZoomDlg.cpp

[CLS:CWaitDialog]
Type=0
BaseClass=CDialog
HeaderFile=WaitDialog.h
ImplementationFile=WaitDialog.cpp

[DLG:IDD_CRITEREDESELECTION]
Type=1
Class=CColorSelectionCriteres
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ROUGE_MIN,edit,1350631552
Control4=IDC_ROUGE_MAX,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_VERT_MIN,edit,1350631552
Control8=IDC_VERT_MAX,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_BLEU_MIN,edit,1350631552
Control12=IDC_BLEU_MAX,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_TOUT_SELECTIONNER,button,1342242819
Control16=IDC_STATIC,button,1342177287

[DLG:IDD_EDGEDETECT_PERCENT]
Type=1
Class=CEdgeDetectionDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_POURCENTAGE_DETECTION,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_FAKECOLORS]
Type=1
Class=CFakeColorsDialog
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COLORLIST,listbox,1352728601
Control4=IDC_SELECTEDCOLOR,static,1350565894
Control5=IDC_CHOISIRUNECOULEUR,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342178055
Control8=IDC_STATIC,button,1342177287
Control9=IDC_SELECTION_CRITERE,button,1342242816

[DLG:IDD_OPTIMISATIONS_DLG]
Type=1
Class=COptimisationsDlg

[DLG:IDD_PICTUREHISTOGRAME_DLG]
Type=1
Class=CPictureHistogrammeSettingsDlg
ControlCount=51
Control1=ID_PICHIST_SETTINGS_RED,button,1342242819
Control2=ID_PICHIST_SETTINGS_BLUE,button,1342242819
Control3=ID_PICHIST_SETTINGS_GREEN,button,1342242819
Control4=ID_PICHIST_SETTINGS_GRAPH_TTL_STATE,button,1342242819
Control5=ID_PICHIST_SETTINGS_GRAPH_TTL,edit,1350633600
Control6=ID_PICHIST_SETTINGS_GRAPH_XTTL_STATE,button,1342242819
Control7=ID_PICHIST_SETTINGS_GRAPH_XTTL,edit,1350633600
Control8=ID_PICHIST_SETTINGS_GRAPH_YTTL_STATE,button,1342242819
Control9=ID_PICHIST_SETTINGS_GRAPH_YTTL,edit,1350633600
Control10=ID_PICHIST_SETTINGS_PERCENTAGE_SCLY,button,1342242819
Control11=ID_PICHIST_SETTINGS_SCLY,button,1342242819
Control12=ID_PICHIST_SETTINGS_SCLX,button,1342242819
Control13=ID_PICHIST_SETTINGS_MAXY_RGB,button,1342308361
Control14=ID_PICHIST_SETTINGS_MAXY_USER_PERCENT_RADIO,button,1342177289
Control15=ID_PICHIST_SETTINGS_MAXY_USER_PERCENT,edit,1350633600
Control16=ID_PICHIST_SETTINGS_MAXY_USER_PIXEL_RADIO,button,1342177289
Control17=ID_PICHIST_SETTINGS_MAXY_USER_PIXELS,edit,1350633600
Control18=ID_PICHIST_SETTINGS_GRAPH_TYPE_COURBE,button,1342308361
Control19=ID_PICHIST_SETTINGS_GRAPH_TYPE_DISCRET,button,1342177289
Control20=ID_PICHIST_SETTINGS_GRAPH_TYPE_POINTS,button,1342177289
Control21=ID_PICHIST_SETTINGS_XQUADRILLAGE,button,1342242819
Control22=ID_PICHIST_SETTINGS_YQUADRILLAGE,button,1342242819
Control23=IDC_RADIO_MAXY_DIVN,button,1342308361
Control24=IDC_RADIO_MAXY_PERCENT_USER,button,1342177289
Control25=IDC_RADIO_MAXY_PIXELS_USER,button,1342177289
Control26=IDC_MAXY_DIV_N,edit,1350633600
Control27=IDC_MAXY_PERCENT_USER,edit,1350633600
Control28=IDC_MAXY_PIXELS_USER,edit,1350633600
Control29=IDC_RADIO_MAXX_DIVN,button,1342308361
Control30=IDC_RADIO_MAXX_PERCENT_USER,button,1342177289
Control31=IDC_RADIO_MAXX_PIXELS_USER,button,1342177289
Control32=IDC_MAXX_DIV_N,edit,1350633600
Control33=IDC_MAXX_PERCENT_USER,edit,1350633600
Control34=IDC_MAXX_PIXELS_USER,edit,1350633600
Control35=IDOK,button,1342242817
Control36=IDCANCEL,button,1342242816
Control37=IDC_STATIC,button,1342177287
Control38=IDC_STATIC,button,1342177287
Control39=IDC_STATIC,button,1342177287
Control40=IDC_STATIC,button,1342177287
Control41=IDC_STATIC,static,1342308352
Control42=IDC_STATIC,static,1342308352
Control43=IDC_STATIC,button,1342177287
Control44=IDC_STATIC,button,1342177287
Control45=IDC_STATIC,button,1342177287
Control46=IDC_STATIC,static,1342308352
Control47=IDC_STATIC,static,1342308352
Control48=IDC_STATIC,button,1342177287
Control49=IDC_STATIC,static,1342308352
Control50=IDC_STATIC,static,1342308352
Control51=IDC_STATIC,static,1342177294

[DLG:IDD_RMTLIST_DLG]
Type=1
Class=CRmtListData

[DLG:IDD_RMTLISTFORM_FORM]
Type=1
Class=CRmtListForm
ControlCount=4
Control1=IDC_RMTDATA_LIST,SysListView32,1350633473
Control2=IDC_RMTDATA_LIST2,SysListView32,1350633473
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,button,1342210823
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_SPLASHSCREEN]
Type=1
Class=CSplashScreen

[DLG:IDD_USER_ZOOM]
Type=1
Class=CUserZoomDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ZOOM,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_WAITDIALOG]
Type=1
Class=CWaitDialog
ControlCount=2
Control1=IDC_PROGRESSION,msctls_progress32,1350565889
Control2=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_FINDER
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_RMTSENTYPE]
Type=1
Class=?
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
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_AFFICHAGE_ZOOM_10
Command18=ID_AFFICHAGE_ZOOM_25
Command19=ID_AFFICHAGE_ZOOM_50
Command20=ID_AFFICHAGE_ZOOM_75
Command21=ID_AFFICHAGE_ZOOM_100
Command22=ID_AFFICHAGE_ZOOM_150
Command23=ID_AFFICHAGE_ZOOM_200
Command24=ID_AFFICHAGE_ZOOM_400
Command25=ID_AFFICHAGE_ZOOM_USER
Command26=ID_OUTILS_EXPANSIONLINAIRE
Command27=ID_OUTILS_EXPANSIONLINAIREAVECSATURATION
Command28=ID_OUTILS_EXPANSIONLOGARITHMIQUE
Command29=ID_OUTILS_EXPANSIONEXPONENTIELLE
Command30=ID_OUTILS_EXPANSIONLINAIRESEGMENTE
Command31=ID_OUTILS_EGALISATION
Command32=ID_OUTILS_TRANSFORMERENNOIRETBLANC
Command33=ID_OUTILS_ESTOMPER
Command34=ID_OUTILS_COMPOSANTESRGB
Command35=ID_OUTILS_CONTOURVERTICAL
Command36=ID_OUTILS_CONTOURHORIZONTAL
Command37=ID_OUTILS_RECHERCHERTOUSLESCONTOURS
Command38=ID_OUTILS_DIMINUERLENOMBREDECOULEURS
Command39=ID_PICTURE_INFO
Command40=ID_WINDOW_NEW
Command41=ID_WINDOW_CASCADE
Command42=ID_WINDOW_TILE_HORZ
Command43=ID_WINDOW_ARRANGE
Command44=ID_WINDOW_SPLIT
Command45=ID_APP_ABOUT
Command46=ID_HELP_FINDER
CommandCount=46

[DLG:IDD_SPLASHSCREEN (French (Belgium))]
Type=1
Class=?
ControlCount=0

[MNU:IDR_ZOOM]
Type=1
Class=?
Command1=ID_AFFICHAGE_ZOOM_10
Command2=ID_AFFICHAGE_ZOOM_25
Command3=ID_AFFICHAGE_ZOOM_50
Command4=ID_AFFICHAGE_ZOOM_75
Command5=ID_AFFICHAGE_ZOOM_100
Command6=ID_AFFICHAGE_ZOOM_150
Command7=ID_AFFICHAGE_ZOOM_200
Command8=ID_AFFICHAGE_ZOOM_400
Command9=ID_AFFICHAGE_ZOOM_USER
Command10=ID_ZOOM_FAUSSECOULEUR
Command11=ID_ZOOM_ACTUALISER
Command12=ID_SLECTION_DSLECTIONNER
Command13=ID_SLECTION_TOUTSLECTIONNER
Command14=ID_SLECTION_INVERSERLASLECTION
Command15=ID_SELECTION_CRITERE
Command16=ID_OUTILS_PARAMTRES
Command17=ID_OUTILS_COMPOSANTEROUGE
Command18=ID_OUTILS_COMPOSANTEVERTE
Command19=ID_OUTILS_COMPOSANTEBLEU
Command20=ID_OUTILS_QUADRILLAGEX
Command21=ID_OUTILS_QUADRILLAGEY
Command22=ID_OUTILS_COURBE
Command23=ID_OUTILS_DISCRET
Command24=ID_OUTILS_POINTS
Command25=ID_OUTILS_ECHELLEYENPOURCENT
Command26=ID_OUTILS_ECHELLEY
Command27=ID_OUTILS_ECHELLEX
Command28=ID_OUTILS_TITREAXEDESX
Command29=ID_OUTILS_TITREAXEDESY
Command30=ID_OUTILS_TITREDUGRAPHE
Command31=ID_OUTILS_HISTOGRAMMEUMULATIF
Command32=ID_OUTILS_HISTOGRAMMEDELIMAGE
CommandCount=32

[DLG:IDD_OPTIMISATIONS_DLG (French (Belgium))]
Type=1
Class=?
ControlCount=15
Control1=IDC_PROPERTY_SHEET,SysTabControl32,1342242816
Control2=IDC_CURRENT_POINT,edit,1350631553
Control3=IDC_X_COORDS,edit,1350631553
Control4=IDC_Y_COORDS,edit,1350631553
Control5=IDC_MAX_POINTS,edit,1350631553
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,button,1342177287
Control15=IDC_R_EQUAL_V_B,button,1342242819

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_OUTILS_PARAMTRES
Command7=ID_OUTILS_COMPOSANTEROUGE
Command8=ID_OUTILS_COMPOSANTEVERTE
Command9=ID_OUTILS_COMPOSANTEBLEU
Command10=ID_OUTILS_QUADRILLAGEX
Command11=ID_OUTILS_QUADRILLAGEY
Command12=ID_OUTILS_COURBE
Command13=ID_OUTILS_DISCRET
Command14=ID_OUTILS_POINTS
Command15=ID_OUTILS_ECHELLEY
Command16=ID_OUTILS_ECHELLEX
Command17=ID_OUTILS_ECHELLEYENPOURCENT
Command18=ID_OUTILS_TITREAXEDESY
Command19=ID_OUTILS_TITREAXEDESX
Command20=ID_OUTILS_TITREDUGRAPHE
Command21=ID_OUTILS_HISTOGRAMMEUMULATIF
Command22=ID_OUTILS_HISTOGRAMMEDELIMAGE
Command23=ID_EDIT_UNDO
Command24=ID_OUTILS_EXPANSIONLINAIRE
Command25=ID_OUTILS_EXPANSIONLOGARITHMIQUE
Command26=ID_OUTILS_EXPANSIONEXPONENTIELLE
Command27=ID_OUTILS_EXPANSIONLINAIRESEGMENTE
Command28=ID_OUTILS_EGALISATION
Command29=ID_OUTILS_TRANSFORMERENNOIRETBLANC
Command30=ID_OUTILS_ESTOMPER
Command31=ID_OUTILS_CONTOURVERTICAL
Command32=ID_OUTILS_CONTOURHORIZONTAL
Command33=ID_OUTILS_RECHERCHERTOUSLESCONTOURS
Command34=ID_OUTILS_DIMINUERLENOMBREDECOULEURS
Command35=ID_ZOOM_FAUSSECOULEUR
Command36=ID_OUTILS_COMPOSANTESRGB
Command37=ID_PICTURE_INFO
Command38=ID_APP_ABOUT
CommandCount=38

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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
