#pragma once


// CIPCServer
//定义消息常量
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//当服务器断开连接时
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//当客户端断开连接时
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//当客户端连接请求时
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//当客户端连接响应时

//服务器连接事件
typedef void (CALLBACK* ONSERVERCONNECTED)(CWnd*,HWND);
//服务器断开事件
typedef void (CALLBACK* ONSERVERDISCONNECTED)(CWnd*,HWND);
//服务器接收数据事件
typedef void (CALLBACK* ONSERVERDATAARRIVE)(CWnd*,LPVOID,DWORD,HWND);


class CIPCServer : public CWnd
{
	DECLARE_DYNAMIC(CIPCServer)

public:
	CIPCServer();
	virtual ~CIPCServer();

protected:
	DECLARE_MESSAGE_MAP()

private:
	bool m_Active; //是否激活
    CWnd* m_ParentWnd; //指定创建此组件的类指针
    DWORD m_SessionHandle; //连接会话的消息标识符
    DWORD m_ServerDisConnectHwnd; //IPCServerDisconnecting消息标识符
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest消息标识符
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose消息标识符
    DWORD m_ClientDisConnectHwnd; //IPCClientDisconnecting消息标识符
public:
	LPCTSTR m_SessionName; //连接会话的名字
	ONSERVERCONNECTED  m_ServerConnected; //服务器连接事件
	ONSERVERDISCONNECTED m_ServerDisConnected; //服务器断开事件
	ONSERVERDATAARRIVE m_ServerDataArrive; //服务器接收数据事件
public:
    //打开服务器，进行监听
    void Open(CWnd* parentWnd);
    //关闭服务器
	void Close(void);
	//发送数据
    void SendMsg(LPVOID MsgPointer, HWND AWinHwnd, DWORD ASize);

protected:
	//消息消息处理函数
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);


};


