#pragma once

// MyCEActiveXPropPage.h : CMyCEActiveXPropPage 属性页类的声明。


// CMyCEActiveXPropPage : 有关实现的信息，请参阅 MyCEActiveXPropPage.cpp。

class CMyCEActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyCEActiveXPropPage)
	DECLARE_OLECREATE_EX(CMyCEActiveXPropPage)

// 构造函数
public:
	CMyCEActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MYCEACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_Msg;
};

