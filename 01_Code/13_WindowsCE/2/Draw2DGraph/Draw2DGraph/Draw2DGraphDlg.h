// Draw2DGraphDlg.h : ͷ�ļ�
//

#pragma once

#include "2DGraph.h"
// CDraw2DGraphDlg �Ի���
class CDraw2DGraphDlg : public CDialog
{
// ����
public:
	CDraw2DGraphDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DRAW2DGRAPH_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()

private:
	C2DGraph m_2DGraph;  //��ά���߶���
	int m_pointCount; //���ߵ����

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
