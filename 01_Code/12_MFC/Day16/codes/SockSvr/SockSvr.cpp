// SockSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

void TCPServer()
{
   //1 创建
	 SOCKET hSockSvr=
		 socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	 //2 绑定
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5678);
	 addrSvr.sin_addr.S_un.S_addr=INADDR_ANY;
   bind(hSockSvr,(SOCKADDR*)&addrSvr,
		 sizeof(addrSvr));
	 //3 监听
	 listen(hSockSvr,5);
	 //4 等待客户端连接
	 printf("等待客户端连接...\n");
	 SOCKADDR_IN addrClient={0};
	 int nLen=sizeof(addrClient);
	 SOCKET hSockClient=
		 accept(hSockSvr,(SOCKADDR*)&addrClient,&nLen);
   printf("已连接。\n");
	 //5 数据收发
	 //5.1首先接收数据
	 char szRecv[256]={0};
	 int nRecv=recv(hSockClient,szRecv,256,0);
	 char* IP=inet_ntoa(addrClient.sin_addr);
   printf("%s:%s\n",IP,szRecv);
	 printf("长度:%d\n",nRecv);
	 //6 关闭套接字
	 closesocket(hSockClient);
	 closesocket(hSockSvr);

}
int main(int argc, char* argv[])
{
  // 1 初始化Socket库
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
  // 2 使用(具体的通信)
  TCPServer(); 
  // 3 卸载Socket库
	WSACleanup();
	return 0;
}

