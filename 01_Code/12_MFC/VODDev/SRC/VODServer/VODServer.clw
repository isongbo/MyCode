; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vodserver.h"
LastPage=0

ClassCount=6
Class1=CDlgVideo
Class2=CMainFrame
Class3=CVODServerApp
Class4=CAboutDlg
Class5=CVODServerDoc
Class6=CVODServerView

ResourceCount=5
Resource1=IDR_POPUPMENU
Resource2=IDD_ABOUTBOX
Resource3=IDR_MAINFRAME
Resource4=IDD_VODSERVER_FORM
Resource5=IDD_DLG_VIDEO

[CLS:CDlgVideo]
Type=0
BaseClass=CDialog
HeaderFile=DlgVideo.h
ImplementationFile=DlgVideo.cpp
LastObject=ID_SVR_START
Filter=D
VirtualFilter=dWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=ID_SVR_STOP

[CLS:CVODServerApp]
Type=0
BaseClass=CWinApp
HeaderFile=VODServer.h
ImplementationFile=VODServer.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=VODServer.cpp
ImplementationFile=VODServer.cpp
LastObject=CAboutDlg
Filter=D
VirtualFilter=dWC

[CLS:CVODServerDoc]
Type=0
BaseClass=CDocument
HeaderFile=VODServerDoc.h
ImplementationFile=VODServerDoc.cpp

[CLS:CVODServerView]
Type=0
BaseClass=CFormView
HeaderFile=VODServerView.h
ImplementationFile=VODServerView.cpp
Filter=D
VirtualFilter=VWC
LastObject=CVODServerView

[DLG:IDD_DLG_VIDEO]
Type=1
Class=CDlgVideo
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_VIDEO_NAME,edit,1350631552
Control3=IDC_VIDEO_PATH,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_OPENFILE,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_VIDEO_DESP,edit,1350631552
Control8=IDC_OK,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_VIDEO_TYPE,combobox,1344339970
Control11=IDC_STATIC,static,1342308352
Control12=IDC_VIDEO_ID,edit,1350633600
Control13=IDC_NEW,button,1342242816
Control14=IDC_DEL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VODSERVER_FORM]
Type=1
Class=CVODServerView
ControlCount=1
Control1=IDC_DATAGRID,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_TOOLBAR_NAVIGATE
Command2=ID_TOOLBAR_EDIT
Command3=ID_SVR_START
Command4=ID_SVR_STOP
CommandCount=4

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_TYPE_ADD
Command2=ID_TYPE_EDIT
Command3=ID_TYPE_DEL
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_APP_ABOUT
CommandCount=6

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

[MNU:IDR_POPUPMENU]
Type=1
Command1=ID_VIDEO_DOWNLOAD
Command2=ID_VIDEO_PLAYER
CommandCount=2

