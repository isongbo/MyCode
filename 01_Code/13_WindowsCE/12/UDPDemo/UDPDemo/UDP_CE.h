/*-----------------------------------------
* Copyright (c) 2008 Eric Wong
* 本版紧供读者参考，不得用于任何商业行为
*
* 文件名称： UDP_CE.h
* 文件标识： 
* 摘要：用于封装WINCE UDP通讯
*
* 当前版本： 1.0
* 作者： 汪兵 Eric Wong
* 完成日期： 2008年1月18日
*
* 取代版本：
* 原作者： 
* 完成日期： 
----------------------------------------*/
#pragma once

#include "winsock.h"

//UDP客户端发送错误回调函数
typedef void (CALLBACK* ONUDPERROR)(void*,int nErrorCode);
//UDP客户端接收数据回调函数
typedef void (CALLBACK* ONUDPRECV)(void*,char* buf,DWORD dwBufLen,sockaddr* saRecvAddress);


class CUDP_CE
{
public:
	CUDP_CE(void);
	~CUDP_CE(void);
public:
	//打开UDP通讯
    DWORD Open(void* pOwner,int localPort, LPCTSTR remoteHost ,int remotePort);
	//关闭UDP通讯
	DWORD Close(void);
	//发送数据
	DWORD SendData(const char *buf, int len);
private:
	//通讯线程函数
	static UINT RecvThread(LPVOID lparam);
private:
	SOCKET m_UDPSocket;                   		//UDP Socket通讯套接字
	struct sockaddr_in m_RemoteAddr;     	//存储远程通讯地址
	HANDLE m_ExitThreadEvent;            	//线程退出事件
	void * m_pOwner;                  		//存储父对象句柄
	char m_recvBuf[4096] ;					//接收数据缓冲区
public:
	//UDP发生错误事件
	ONUDPERROR m_OnUdpError;
	//UDP接收数据事件
	ONUDPRECV  m_OnUdpRecv;
};
