========================================================================
ACTIVEX 控件 DLL：MyCEActiveX 项目概述
========================================================================

控件向导已为您的 MyCEActiveX ActiveX 控件 DLL 创建了
此项目，其中包含一个控件。

此主干项目不仅演示编写 ActiveX 控件的
基本方法，还可作为您编写控件的特定功能的
起点。

此文件概述了组成 MyCEActiveX ActiveX 控件 DLL 的
每个文件的内容。

MyCEActiveX.vcproj
这是使用应用程序向导生成的 VC++ 项目的主项目
文件。它包含生成该文件的 Visual C++ 的版本
信息，以及有关使用应用程序向导选择的平台、
配置和项目功能的信息。

MyCEActiveX.h
这是 ActiveX 控件 DLL 的主包含文件。它
包括其他项目特定的包含文件。

MyCEActiveX.cpp
这是包含 DLL 初始化、终止和其他簿记的代码的
主源文件。


MyCEActiveXppc.rc
这是项目使用的所有 Microsoft Windows 资源的清单
（当针对 Pocket PC 平台或
支持相同的用户界面模型的平台进行编译时）。如果 .rc 文件保持不变，
数据节中的定义将保持为它们所定义为的数值的十六进制版本，
而不是定义的友好名称。



MyCEActiveX.rc2
此文件包含不由 Microsoft 
Visual C++ 编辑的资源。您应将所有无法由资源编辑器编辑的资源
放置到此文件中。

MyCEActiveX.def
此文件包含关于在 Microsoft Windows 上运行所必需的
的 ActiveX 控件 DLL 的信息。

MyCEActiveX.idl
此文件包含控件类型库的
对象描述语言源代码。

MyCEActiveX.ico
此文件包含将出现在“关于”框中的图标。此图标
包含在主资源 (.rc) 文件中

/////////////////////////////////////////////////////////////////////////////
CMyCEActiveXCtrl 控件：

MyCEActiveXCtrl.h
此文件包含 CMyCEActiveXCtrl C++ 类的声明。

MyCEActiveXCtrl.cpp
此文件包含 CMyCEActiveXCtrl C++ 类的实现。

MyCEActiveXPropPage.h
此文件包含 CMyCEActiveXPropPage C++ 类的声明。

MyCEActiveXPropPage.cpp
此文件包含 CMyCEActiveXPropPage C++ 类的实现。

CMyCEActiveXCtrl.bmp
此文件包含一个位图，当 CMyCEActiveXCtrl 控件出现在工具调板中时，
容器将使用该位图来表示此控件。此位图
包含在主资源 (.rc) 文件中

/////////////////////////////////////////////////////////////////////////////
其他标准文件：

stdAfx.h，stdAfx.cpp
这些文件用于生成名为 MyCEActiveX.pch 的预编译头 (PCH) 文件
和名为 stdafx.obj 的预编译类型 (PCT) 文件。


resourceppc.h
这是标准头文件，它定义新的资源 ID。
Visual C++ 资源编辑器读取并更新此文件。



/////////////////////////////////////////////////////////////////////////////
其他注释：

控件向导使用“TODO:”指示应添加或自定义的源代码部分。
应添加或自定义的源代码部分。

/////////////////////////////////////////////////////////////////////////////