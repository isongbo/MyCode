// IPCClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IPC_MSGCLIENT.h"
#include "IPCClient.h"


// CIPCClient

IMPLEMENT_DYNAMIC(CIPCClient, CWnd)

/*
*���캯��
*/
CIPCClient::CIPCClient()
{
  m_ServerWinHwnd = 0;
  m_SessionHandle = 0;
  m_Active = false;
  //ע����Ϣ����
  m_ServerDisconnectHwnd = RegisterWindowMessage(IPCServerDisconnecting);
  m_ConnectRequestHwnd = RegisterWindowMessage(IPCConnectRequest);
  m_ConnectResposeHwnd = RegisterWindowMessage(IPCConnectRespose);
  m_ClientDisconnectHwnd = RegisterWindowMessage(IPCClientDisconnecting);
}


CIPCClient::~CIPCClient()
{
}


BEGIN_MESSAGE_MAP(CIPCClient, CWnd)
END_MESSAGE_MAP()



// CIPCClient ��Ϣ�������


/*
*�������ܣ�����ͬ������������
*��ڲ�����parentWndָ����������Ĵ���ָ��
*���ڲ�����(��)
*����ֵ��(��)
*/

void CIPCClient::Open(CWnd *parentWnd)
{
  if (!m_Active)
  {
	m_ParentWnd = parentWnd;
    //ע�����ӻỰ����Ϣ��ʶ��
    m_SessionHandle = RegisterWindowMessage(m_SessionName);
	::SendMessage(HWND_BROADCAST, m_ConnectRequestHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
  }
}

/*
*�������ܣ��ر�ͬ������������
*��ڲ�����parentWndָ����������Ĵ���ָ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPCClient::Close()
{
  if (m_Active)
  {
      //�㲥��Ϣ���ͻ��˶Ͽ�
      ::SendMessage(HWND_BROADCAST, m_ClientDisconnectHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
      m_Active = false;
  }
}
/*
*�������ܣ��������ݵ�������
*��ڲ�����MsgPointer : ���͵�����ָ��
           ASize : ���͵����ݴ�С
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPCClient::SendMsg(LPVOID MsgPointer, DWORD ASize)
{
  COPYDATASTRUCT copyDataStruct;
  if (m_ServerWinHwnd != 0) 
  {
     copyDataStruct.dwData = DWORD(m_hWnd);
     copyDataStruct.cbData = ASize;
     copyDataStruct.lpData = MsgPointer;
	 //��������˴��ڷ���WM_COPYDATA��Ϣ
     ::SendMessage(m_ServerWinHwnd, WM_COPYDATA, m_SessionHandle, LPARAM(&copyDataStruct));
  }
}

//����WindowProc����
LRESULT CIPCClient::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  
  LPVOID MsgPointer;
  DWORD bufLen;

  //������Ϣ���࣬�ֱ�ִ��
  //WM_CopyData��Ϣ
  if (message == WM_COPYDATA) 
  {
bufLen = ((PCOPYDATASTRUCT)lParam)->cbData;
    MsgPointer = ((PCOPYDATASTRUCT)lParam)->lpData;
    m_ClientDataArrive(m_ParentWnd,MsgPointer,bufLen);
    //����ͻ��˽��������¼�
  }
  //������Ӧ��Ϣ
  else if (message == m_ConnectResposeHwnd) 
  {
    if (!m_Active)
	{
      m_ServerWinHwnd = HWND(wParam);

	  //������Ӧ�¼�
	  m_ClientConnected(m_ParentWnd,m_ServerWinHwnd);
      m_Active = true;
	}
  }
  //�������˶Ͽ�������Ϣ
  else if (message == m_ServerDisconnectHwnd) 
  {
    if (m_Active)
    {
      if (wParam = DWORD(m_ServerWinHwnd))
      {

	  //�����Ͽ��¼�
	  m_ClientDisConnected(m_ParentWnd,m_ServerWinHwnd);
        m_ServerWinHwnd = 0;
        m_Active = false;
      }
    }
  }

  return CWnd::WindowProc(message, wParam, lParam);
}
