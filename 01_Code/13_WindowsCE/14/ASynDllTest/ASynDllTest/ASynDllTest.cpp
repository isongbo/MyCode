// ASynDllTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ASynDllTest.h"
#include "ASynDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CASynDllTestApp

BEGIN_MESSAGE_MAP(CASynDllTestApp, CWinApp)
END_MESSAGE_MAP()


// CASynDllTestApp ����
CASynDllTestApp::CASynDllTestApp()
	: CWinApp()
{
	// TODO: �ڴ˴����ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CASynDllTestApp ����
CASynDllTestApp theApp;

// CASynDllTestApp ��ʼ��

BOOL CASynDllTestApp::InitInstance()
{
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
    // ��Ӧ�ó����ʼ���ڼ䣬Ӧ����һ�� SHInitExtraControls �Գ�ʼ��
    // ���� Windows Mobile �ض��ؼ����� CAPEDIT �� SIPPREF��
    SHInitExtraControls();
#endif // WIN32_PLATFORM_PSPC || WIN32_PLATFORM_WFSP

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CASynDllTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô�����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}