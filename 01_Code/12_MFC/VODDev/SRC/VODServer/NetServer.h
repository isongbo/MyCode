// NetServer.h: interface for the CNetServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETSERVER_H__35FC16EE_CED5_4240_B71E_E234B76AC2FE__INCLUDED_)
#define AFX_NETSERVER_H__35FC16EE_CED5_4240_B71E_E234B76AC2FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NetClient.h"
class CNetServer  
{
public:
	CNetServer();
	virtual ~CNetServer();
	//启动一个线程，线程函数ServerThread
	void InitServer( );
    static DWORD WINAPI ServerThread(LPVOID pParam);
    SOCKET m_hSockServer;
};

#endif // !defined(AFX_NETSERVER_H__35FC16EE_CED5_4240_B71E_E234B76AC2FE__INCLUDED_)
