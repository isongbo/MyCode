// MemFileMap.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "MemFileMap.h"


// CMemFileMap

IMPLEMENT_DYNAMIC(CMemFileMap, CWnd)

/*
*���캯������ʼ�����Ա����
*/
CMemFileMap::CMemFileMap()
{
  m_pMapPointer = NULL;
  m_hMapFile = NULL;
  m_hSynEvent = NULL ; 
  m_SynMessageID = -1;
  m_pParentWnd = NULL;
  m_Syn =false;
}


CMemFileMap::~CMemFileMap()
{
}


BEGIN_MESSAGE_MAP(CMemFileMap, CWnd)
END_MESSAGE_MAP()



// CMemFileMap ��Ϣ�������


/*
*�������ܣ���������ڴ�ӳ���ļ�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��<=0 ,����ʧ��
*        >0,����ɹ�
*       -1 : ������ʧ��
*       -2 : ����ӳ��ʧ��
*       -3 : ����ͬ���¼�ʧ��
*       -4 : ע����Ϣʧ��
*        1 : �������ɹ����������´���
*        2 : ����򿪳ɹ����ļ��Ѵ���
*/
DWORD CMemFileMap::OpenFileMap(CWnd * pWnd)
{
	DWORD returnValue = 1; //���巵�ر���

    m_pParentWnd = pWnd;
    //�����ڴ�ӳ���ļ�
	m_hMapFile =CreateFileMapping(HANDLE(0xFFFFFFFF), NULL, 
		PAGE_READWRITE, 0,m_MaxSize,m_MapName.GetBuffer(m_MapName.GetLength()));  
	
	if ((m_hMapFile == INVALID_HANDLE_VALUE) || (m_hMapFile == 0))
	{
		return -1; //������ʧ��
	}

	if ((m_hMapFile != 0) && (GetLastError() == ERROR_ALREADY_EXISTS))
	{
		//�ڴ��ļ����Ѵ���
		returnValue = 2; //�����ڴ��ļ��Ѵ�
	}

	m_pMapPointer = (LPTSTR)MapViewOfFile(m_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (m_pMapPointer == NULL)
	{
		CloseHandle(m_hMapFile);
	    m_hMapFile = NULL;
        return -2;//'ӳ���ļ�����ͼ�����̵ĵ�ַ�ռ�ʧ��')
	}

	m_hSynEvent = CreateEvent(NULL,FALSE,TRUE,_T("MEMFILE"));
	if (!m_hSynEvent)
	{
       UnmapViewOfFile(m_pMapPointer);
       m_pMapPointer = NULL;
	   CloseHandle(m_hMapFile);
	   m_hMapFile = NULL;
	   return -3;//����ͬ���¼�ʧ��
	}

	m_SynMessageID = RegisterWindowMessage(MEMFILECHANG);
	 if (!m_SynMessageID)
	 {
       UnmapViewOfFile(m_pMapPointer);
       m_pMapPointer = NULL;
	   CloseHandle(m_hMapFile);
	   m_hMapFile = NULL;
	   CloseHandle(m_hSynEvent);
	   m_hSynEvent = NULL;
	   return -4 ; //ע����Ϣʧ��
	 }
  return returnValue;
}

/*
*�������ܣ��ر��ڴ�ӳ���ļ�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CMemFileMap::CloseFileMap()
{
	if (m_pMapPointer)
	{
	  UnmapViewOfFile(m_pMapPointer);
      m_pMapPointer = NULL;
	}

	if (m_hMapFile)
	{
		CloseHandle(m_hMapFile);
		m_hMapFile = NULL;
	}

	if (m_hSynEvent)
	{
	   CloseHandle(m_hSynEvent);
	   m_hSynEvent = NULL;
	}
}


/*
*�������ܣ���ȡ�ڴ�ӳ���ļ�����
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ���ڴ��ļ�����ָ��
*/
LPCTSTR CMemFileMap::ReadBuffer()
{
  return m_pMapPointer;
}

/*
*�������ܣ�д���ڴ�ӳ���ļ�����
*��ڲ�����buf :Ҫд����ַ�������ָ��
*���ڲ�����(��)
*����ֵ��-1 ��ʧ�ܣ�1���ɹ�
*/
DWORD CMemFileMap::WriteBuffer(LPCTSTR buf)
{
  if ((lstrlen(buf)) > m_MaxSize)
  {
	  return -1; //д�뻺���������ڶ����С
  }
  //ͬ��д���̣��ȴ�ͬ���źţ��ҵȵ�ͬ���źţ��Զ��ر��ź�
  if (WaitForSingleObject(m_hSynEvent,INFINITE) == WAIT_OBJECT_0)
  {
    lstrcpy(m_pMapPointer,buf);
  }
 
  ::SendMessage(HWND_BROADCAST,m_SynMessageID,WPARAM(m_hWnd),0);
  //ʹͬ���¼����ź�
  SetEvent(m_hSynEvent);
  return 1;
}

//��Ϣ������
LRESULT CMemFileMap::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == m_SynMessageID)
	{
		//���ͬ���Ļ�,�ʹ���ͬ���¼�
		if (m_Syn)
		{
		  m_OnMemDataChange(m_pParentWnd);
		}
	}
	return CWnd::WindowProc(message, wParam, lParam);
}
