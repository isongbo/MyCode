// IPCServer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPCServer.h"


// CIPCServer

IMPLEMENT_DYNAMIC(CIPCServer, CWnd)


/*
*���캯��
*/
CIPCServer::CIPCServer()
{
  m_SessionHandle = 0;
  m_Active = false;
  //ע����Ϣ����
  m_ServerDisConnectHwnd = RegisterWindowMessage(IPCServerDisconnecting);
  m_ConnectRequestHwnd = RegisterWindowMessage(IPCConnectRequest);
  m_ConnectResposeHwnd = RegisterWindowMessage(IPCConnectRespose);
  m_ClientDisConnectHwnd = RegisterWindowMessage(IPCClientDisconnecting);
}



CIPCServer::~CIPCServer()
{
}


BEGIN_MESSAGE_MAP(CIPCServer, CWnd)

END_MESSAGE_MAP()



// CIPCServer ��Ϣ�������

/*
*�������ܣ��򿪷����������ڼ���״̬
*��ڲ�����parentWndָ����������Ĵ���ָ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPCServer::Open(CWnd* parentWnd)
{
  if (!m_Active)
  {
    //ע�����ӻỰ����Ϣ��ʶ��
    m_SessionHandle = RegisterWindowMessage(m_SessionName);
	m_ParentWnd = parentWnd;
	m_Active = true;
  }
}

/*
*�������ܣ��رշ�����
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPCServer::Close()
{
	if (m_Active)
	{
      //�㲥�������Ͽ�����Ϣ
	  ::SendMessage(HWND_BROADCAST, m_ServerDisConnectHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
      m_Active = false;
	}
}

/*
*�������ܣ���ͻ��˽��̷�������
*��ڲ�����MsgPointer������ָ��
           AWinHwnd : �ͻ��˴��ھ��
		   ASize : ���ݴ�С
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPCServer::SendMsg(LPVOID MsgPointer, HWND AWinHwnd, DWORD ASize)
{

  COPYDATASTRUCT copyDataStruct;
  
  copyDataStruct.dwData = 0;
  copyDataStruct.cbData = ASize;
  copyDataStruct.lpData = MsgPointer;
  //��ͻ��˴��ڷ���WM_COPYDATA��Ϣ
  ::SendMessage(AWinHwnd, WM_COPYDATA, m_SessionHandle, LPARAM(&copyDataStruct));
}

LRESULT CIPCServer::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  LPVOID MsgPointer;
  HWND ClientHwnd;
  DWORD bufLen;

  //������Ϣ���࣬�ֱ���
  if ((message == WM_COPYDATA) && (wParam = m_SessionHandle))
  {
    //�����WM_CopyData��Ϣ
    MsgPointer = ((PCOPYDATASTRUCT)lParam)->lpData;
    ClientHwnd = HWND(((PCOPYDATASTRUCT)lParam)->dwData);
    bufLen = ((PCOPYDATASTRUCT)lParam)->cbData;
    //��ʱ����������¼�
	m_ServerDataArrive(m_ParentWnd,MsgPointer,bufLen,ClientHwnd);
  }
  else if ((message == m_ConnectRequestHwnd) && (lParam = m_SessionHandle)) 
  {
  //����ǿͻ�������������Ϣʱ
    if (m_Active)
    {
      //�õ��ͻ��˴��ھ��
      ClientHwnd = (HWND)wParam;
      if (ClientHwnd != 0) 
      {
	    ::SendMessage(ClientHwnd, m_ConnectResposeHwnd, WPARAM(m_hWnd), 0);
        
		//���������¼� 
		m_ServerConnected(m_ParentWnd,ClientHwnd);
      }
    }
  }
  else if ((message == m_ClientDisConnectHwnd) && (lParam = m_SessionHandle)) 
  {
    //����ǿͻ��˶Ͽ�����ʱ
    ClientHwnd = (HWND)wParam;
    ::SendMessage(ClientHwnd, m_ServerDisConnectHwnd, WPARAM(m_hWnd), 0);
    
	//�����Ͽ��¼�
    m_ServerDisConnected(m_ParentWnd,ClientHwnd);
  }

	
	return CWnd::WindowProc(message, wParam, lParam);
}

