// MyCEActiveX_TestDlg.h : ͷ�ļ�
//

#pragma once

#include "CDMyCEActiveX.h"

// CMyCEActiveX_TestDlg �Ի���
class CMyCEActiveX_TestDlg : public CDialog
{
// ����
public:
	CMyCEActiveX_TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYCEACTIVEX_TEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	//MyCEActiveX�ؼ�OnMsgChange�¼�
	afx_msg void OnMsgChangeMyceactivexctrl();	
	//����OLE COM �¼�ӳ��
	DECLARE_EVENTSINK_MAP()
	DECLARE_MESSAGE_MAP()

private:
	//����MyCEActiveX�ؼ�����
	CDMyCEActiveX m_myCEActiveX;
public:
	afx_msg void OnBnClickedBtnTest();
};
