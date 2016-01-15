// SerialSampleDlg.h : 头文件
//

#pragma once

#include "CESeries.h"

// CSerialSampleDlg 对话框
class CSerialSampleDlg : public CDialog
{
// 构造
public:
	CSerialSampleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERIALSAMPLE_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	// 串口接收数据处理函数
	afx_msg LONG OnRecvSerialData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()


public:
	CCESeries *m_pSerial;  //串口对象指针
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnSend();

private:
	//定义串口接收数据函数类型
	static void CALLBACK OnSerialRead(void * pOwner,BYTE* buf,DWORD bufLen);
};
