// IPCClient.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MSGCLIENT.h"
#include "IPCClient.h"


// CIPCClient

IMPLEMENT_DYNAMIC(CIPCClient, CWnd)

/*
*构造函数
*/
CIPCClient::CIPCClient()
{
  m_ServerWinHwnd = 0;
  m_SessionHandle = 0;
  m_Active = false;
  //注册消息常量
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



// CIPCClient 消息处理程序


/*
*函数介绍：建立同服务器的连接
*入口参数：parentWnd指定创建此类的窗口指针
*出口参数：(无)
*返回值：(无)
*/

void CIPCClient::Open(CWnd *parentWnd)
{
  if (!m_Active)
  {
	m_ParentWnd = parentWnd;
    //注册连接会话的消息标识符
    m_SessionHandle = RegisterWindowMessage(m_SessionName);
	::SendMessage(HWND_BROADCAST, m_ConnectRequestHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
  }
}

/*
*函数介绍：关闭同服务器的连接
*入口参数：parentWnd指定创建此类的窗口指针
*出口参数：(无)
*返回值：(无)
*/
void CIPCClient::Close()
{
  if (m_Active)
  {
      //广播消息，客户端断开
      ::SendMessage(HWND_BROADCAST, m_ClientDisconnectHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
      m_Active = false;
  }
}
/*
*函数介绍：发送数据到服务器
*入口参数：MsgPointer : 发送的数据指针
           ASize : 发送的数据大小
*出口参数：(无)
*返回值：(无)
*/
void CIPCClient::SendMsg(LPVOID MsgPointer, DWORD ASize)
{
  COPYDATASTRUCT copyDataStruct;
  if (m_ServerWinHwnd != 0) 
  {
     copyDataStruct.dwData = DWORD(m_hWnd);
     copyDataStruct.cbData = ASize;
     copyDataStruct.lpData = MsgPointer;
	 //向服务器端窗口发送WM_COPYDATA消息
     ::SendMessage(m_ServerWinHwnd, WM_COPYDATA, m_SessionHandle, LPARAM(&copyDataStruct));
  }
}

//重载WindowProc函数
LRESULT CIPCClient::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  
  LPVOID MsgPointer;
  DWORD bufLen;

  //根据消息种类，分别执行
  //WM_CopyData消息
  if (message == WM_COPYDATA) 
  {
bufLen = ((PCOPYDATASTRUCT)lParam)->cbData;
    MsgPointer = ((PCOPYDATASTRUCT)lParam)->lpData;
    m_ClientDataArrive(m_ParentWnd,MsgPointer,bufLen);
    //处理客户端接收数据事件
  }
  //连接响应消息
  else if (message == m_ConnectResposeHwnd) 
  {
    if (!m_Active)
	{
      m_ServerWinHwnd = HWND(wParam);

	  //连接响应事件
	  m_ClientConnected(m_ParentWnd,m_ServerWinHwnd);
      m_Active = true;
	}
  }
  //服务器端断开连接消息
  else if (message == m_ServerDisconnectHwnd) 
  {
    if (m_Active)
    {
      if (wParam = DWORD(m_ServerWinHwnd))
      {

	  //触发断开事件
	  m_ClientDisConnected(m_ParentWnd,m_ServerWinHwnd);
        m_ServerWinHwnd = 0;
        m_Active = false;
      }
    }
  }

  return CWnd::WindowProc(message, wParam, lParam);
}
