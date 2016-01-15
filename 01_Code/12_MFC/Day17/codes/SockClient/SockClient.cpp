// SockClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
void TCPClient()
{
   //1 创建socket
	 SOCKET hSockClient=socket(AF_INET,SOCK_STREAM,0);
	 //2 连接服务器
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5678);
	 addrSvr.sin_addr.S_un.S_addr=
		 inet_addr("127.0.0.1");
	 connect(hSockClient,(SOCKADDR*)&addrSvr,
		 sizeof(addrSvr));
	 //3 收据收发
	 //3.1 发送数据
	 char szSend[]="Hello,Data From client!";
	 send(hSockClient,szSend,strlen(szSend),0);
	 //3.2 接收数据

	 //4 关闭socket
	 closesocket(hSockClient);

}
void UDPClient()
{
	//1 创建socket
	 SOCKET hSockClient=socket(AF_INET,
		 SOCK_DGRAM,IPPROTO_UDP);
  //2 收据收发
	//2.1 发送数据
	 char szSend[]="Hello,Data From UDPClient!";
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5679);
	 addrSvr.sin_addr.S_un.S_addr=
		 inet_addr("127.0.0.1");
	 sendto(hSockClient,szSend,strlen(szSend),0,
	 (SOCKADDR*)&addrSvr,sizeof(addrSvr));
	 //3 关闭socket
	 closesocket(hSockClient);
}
int main(int argc, char* argv[])
{
	//1 初始化socket库
	WSAData wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	//2 TCP客户端
	//TCPClient();
	UDPClient();
	//3 卸载socket库
	WSACleanup();
	return 0;
}

