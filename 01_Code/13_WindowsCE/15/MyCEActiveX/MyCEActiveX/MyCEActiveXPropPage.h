#pragma once

// MyCEActiveXPropPage.h : CMyCEActiveXPropPage ����ҳ���������


// CMyCEActiveXPropPage : �й�ʵ�ֵ���Ϣ������� MyCEActiveXPropPage.cpp��

class CMyCEActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyCEActiveXPropPage)
	DECLARE_OLECREATE_EX(CMyCEActiveXPropPage)

// ���캯��
public:
	CMyCEActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MYCEACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_Msg;
};

