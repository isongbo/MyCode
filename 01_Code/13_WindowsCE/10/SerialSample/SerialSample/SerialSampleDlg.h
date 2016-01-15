// SerialSampleDlg.h : ͷ�ļ�
//

#pragma once

#include "CESeries.h"

// CSerialSampleDlg �Ի���
class CSerialSampleDlg : public CDialog
{
// ����
public:
	CSerialSampleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERIALSAMPLE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	// ���ڽ������ݴ�����
	afx_msg LONG OnRecvSerialData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()


public:
	CCESeries *m_pSerial;  //���ڶ���ָ��
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSend();

private:
	//���崮�ڽ������ݺ�������
	static void CALLBACK OnSerialRead(void * pOwner,BYTE* buf,DWORD bufLen);
};
