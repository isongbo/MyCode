// IPCServer.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPCServer.h"


// CIPCServer

IMPLEMENT_DYNAMIC(CIPCServer, CWnd)


/*
*构造函数
*/
CIPCServer::CIPCServer()
{
  m_SessionHandle = 0;
  m_Active = false;
  //注册消息常量
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



// CIPCServer 消息处理程序

/*
*函数介绍：打开服务器，处于监听状态
*入口参数：parentWnd指定创建此类的窗口指针
*出口参数：(无)
*返回值：(无)
*/
void CIPCServer::Open(CWnd* parentWnd)
{
  if (!m_Active)
  {
    //注册连接会话的消息标识符
    m_SessionHandle = RegisterWindowMessage(m_SessionName);
	m_ParentWnd = parentWnd;
	m_Active = true;
  }
}

/*
*函数介绍：关闭服务器
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPCServer::Close()
{
	if (m_Active)
	{
      //广播服务器断开的消息
	  ::SendMessage(HWND_BROADCAST, m_ServerDisConnectHwnd, WPARAM(m_hWnd), LPARAM(m_SessionHandle));
      m_Active = false;
	}
}

/*
*函数介绍：向客户端进程发送数据
*入口参数：MsgPointer：数据指针
           AWinHwnd : 客户端窗口句柄
		   ASize : 数据大小
*出口参数：(无)
*返回值：(无)
*/
void CIPCServer::SendMsg(LPVOID MsgPointer, HWND AWinHwnd, DWORD ASize)
{

  COPYDATASTRUCT copyDataStruct;
  
  copyDataStruct.dwData = 0;
  copyDataStruct.cbData = ASize;
  copyDataStruct.lpData = MsgPointer;
  //向客户端窗口发送WM_COPYDATA消息
  ::SendMessage(AWinHwnd, WM_COPYDATA, m_SessionHandle, LPARAM(&copyDataStruct));
}

LRESULT CIPCServer::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
  LPVOID MsgPointer;
  HWND ClientHwnd;
  DWORD bufLen;

  //根据消息种类，分别处理
  if ((message == WM_COPYDATA) && (wParam = m_SessionHandle))
  {
    //如果是WM_CopyData消息
    MsgPointer = ((PCOPYDATASTRUCT)lParam)->lpData;
    ClientHwnd = HWND(((PCOPYDATASTRUCT)lParam)->dwData);
    bufLen = ((PCOPYDATASTRUCT)lParam)->cbData;
    //此时，处理接收事件
	m_ServerDataArrive(m_ParentWnd,MsgPointer,bufLen,ClientHwnd);
  }
  else if ((message == m_ConnectRequestHwnd) && (lParam = m_SessionHandle)) 
  {
  //如果是客户端连接请求消息时
    if (m_Active)
    {
      //得到客户端窗口句柄
      ClientHwnd = (HWND)wParam;
      if (ClientHwnd != 0) 
      {
	    ::SendMessage(ClientHwnd, m_ConnectResposeHwnd, WPARAM(m_hWnd), 0);
        
		//触发连接事件 
		m_ServerConnected(m_ParentWnd,ClientHwnd);
      }
    }
  }
  else if ((message == m_ClientDisConnectHwnd) && (lParam = m_SessionHandle)) 
  {
    //如果是客户端断开连接时
    ClientHwnd = (HWND)wParam;
    ::SendMessage(ClientHwnd, m_ServerDisConnectHwnd, WPARAM(m_hWnd), 0);
    
	//触发断开事件
    m_ServerDisConnected(m_ParentWnd,ClientHwnd);
  }

	
	return CWnd::WindowProc(message, wParam, lParam);
}

