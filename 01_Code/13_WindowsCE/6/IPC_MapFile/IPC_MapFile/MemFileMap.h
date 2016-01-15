#pragma once

//�����ڴ��ļ����ݱ仯��Ϣ�ַ���
const LPCTSTR  MEMFILECHANG = _T("MEMFILECHANGE");
//�����ڴ�ӳ�����ݸı��¼�
typedef void (CALLBACK* ONMEMDATACHANGE)(CWnd*);

// CMemFileMap

class CMemFileMap : public CWnd
{
	DECLARE_DYNAMIC(CMemFileMap)

public:
	CMemFileMap();
	virtual ~CMemFileMap();

protected:
	DECLARE_MESSAGE_MAP()
public:
	//��������ڴ�ӳ���ļ�
	DWORD OpenFileMap(CWnd * pWnd);
	//�ر�ӳ���ļ�
	void CloseFileMap();
	//��ȡ�ڴ��ļ���Ϣ
	LPCTSTR ReadBuffer();
	//д���ڴ��ļ���Ϣ
	DWORD WriteBuffer(LPCTSTR buf);
public:
	//windows ��Ϣ������
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) ;


private:
	HANDLE m_hMapFile; //�ڴ�ӳ���ļ����
	LPTSTR m_pMapPointer ; //�ڴ��ļ�ӳ�����ݾ��
	HANDLE m_hSynEvent ; //д�ڴ��ļ�ʱ��ͬ���¼����
	DWORD m_SynMessageID ;//ͬ����Ϣ
	CWnd  * m_pParentWnd ; //ָ����������Ĵ���ָ��
public:
	DWORD m_MaxSize ; //�ڴ��ļ���С
	CString m_MapName; //�ڴ�ӳ���ļ�����
	bool m_Syn; //�Ƿ�ͬ��
	ONMEMDATACHANGE m_OnMemDataChange; //�ڴ�ӳ�������ݸı��¼�

};


