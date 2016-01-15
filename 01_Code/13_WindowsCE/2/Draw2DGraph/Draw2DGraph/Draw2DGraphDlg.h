// Draw2DGraphDlg.h : 头文件
//

#pragma once

#include "2DGraph.h"
// CDraw2DGraphDlg 对话框
class CDraw2DGraphDlg : public CDialog
{
// 构造
public:
	CDraw2DGraphDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DRAW2DGRAPH_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()

private:
	C2DGraph m_2DGraph;  //二维曲线对象
	int m_pointCount; //曲线点计数

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
