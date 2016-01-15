; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "VODClient.h"
LastPage=0

ClassCount=6
Class1=CVODClientApp
Class2=CVODClientDoc
Class3=CVODClientView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_POPUPMENU
Class5=CAboutDlg
Resource3=IDD_VODCLIENT_FORM
Class6=CDlgLogin
Resource4=IDR_MAINFRAME
Resource5=IDD_DLG_LOGIN

[CLS:CVODClientApp]
Type=0
HeaderFile=VODClient.h
ImplementationFile=VODClient.cpp
Filter=N

[CLS:CVODClientDoc]
Type=0
HeaderFile=VODClientDoc.h
ImplementationFile=VODClientDoc.cpp
Filter=N

[CLS:CVODClientView]
Type=0
HeaderFile=VODClientView.h
ImplementationFile=VODClientView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=ID_FILE_OPEN


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
HeaderFile=VODClient.cpp
ImplementationFile=VODClient.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_PLAY
CommandCount=17

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

[DLG:IDD_VODCLIENT_FORM]
Type=1
Class=CVODClientView
ControlCount=1
Control1=IDC_MEDIA_PLAYER,{6BF52A52-394A-11D3-B153-00C04F79FAA6},1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DLG_LOGIN]
Type=1
Class=CDlgLogin
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_USERNAME,edit,1350631552
Control6=IDC_PASSWORD,edit,1350631552

[CLS:CDlgLogin]
Type=0
HeaderFile=DlgLogin.h
ImplementationFile=DlgLogin.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PASSWORD
VirtualFilter=dWC

[MNU:IDR_POPUPMENU]
Type=1
Class=?
Command1=ID_VIDEO_DOWNLOAD
Command2=ID_VIDEO_PLAYER
CommandCount=2

