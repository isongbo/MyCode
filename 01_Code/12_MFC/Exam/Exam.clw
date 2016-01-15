; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyFormView
LastTemplate=CListView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Exam.h"
LastPage=0

ClassCount=6
Class1=CExamApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class2=CChildView
Class5=CMyFormView
Class6=CMyListView
Resource3=IDD_FORMVIEW

[CLS:CExamApp]
Type=0
HeaderFile=Exam.h
ImplementationFile=Exam.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Exam.cpp
ImplementationFile=Exam.cpp
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
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
CommandCount=5

[DLG:IDD_FORMVIEW]
Type=1
Class=CMyFormView
ControlCount=7
Control1=IDC_NAME,edit,1350631552
Control2=IDC_AGE,edit,1350631552
Control3=IDC_ADDRESS,edit,1350631552
Control4=IDC_ADD,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[CLS:CMyFormView]
Type=0
HeaderFile=MyFormView.h
ImplementationFile=MyFormView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC

[CLS:CMyListView]
Type=0
HeaderFile=MyListView.h
ImplementationFile=MyListView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC

