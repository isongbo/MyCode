// IPC_MapFileDlg.h : ͷ�ļ�
//
#include "MemFileMap.h"
#pragma once

// CIPC_MapFileDlg �Ի���
class CIPC_MapFileDlg : public CDialog
{
// ����
public:
	CIPC_MapFileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IPC_MAPFILE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Exist;
	BOOL m_Syn;
	BOOL m_Open;
	CString m_MemData;
public:
	//�����ڴ�ӳ���ļ�ͨѶ�����
	CMemFileMap m_memFileMap;
private:
	//�ڴ�ӳ���ļ����ݱ仯�¼�����
	static void CALLBACK OnMemDataChange(CWnd *pWnd);

public:
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnread();
	afx_msg void OnBnClickedBtnwrite();
	afx_msg void OnBnClickedCksyn();
};
