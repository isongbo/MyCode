// IPC_MapFileDlg.h : 头文件
//
#include "MemFileMap.h"
#pragma once

// CIPC_MapFileDlg 对话框
class CIPC_MapFileDlg : public CDialog
{
// 构造
public:
	CIPC_MapFileDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IPC_MAPFILE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Exist;
	BOOL m_Syn;
	BOOL m_Open;
	CString m_MemData;
public:
	//定义内存映射文件通讯类变量
	CMemFileMap m_memFileMap;
private:
	//内存映射文件内容变化事件函数
	static void CALLBACK OnMemDataChange(CWnd *pWnd);

public:
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnread();
	afx_msg void OnBnClickedBtnwrite();
	afx_msg void OnBnClickedCksyn();
};
