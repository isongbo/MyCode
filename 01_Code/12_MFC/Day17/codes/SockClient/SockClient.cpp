// SockClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
void TCPClient()
{
   //1 ����socket
	 SOCKET hSockClient=socket(AF_INET,SOCK_STREAM,0);
	 //2 ���ӷ�����
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5678);
	 addrSvr.sin_addr.S_un.S_addr=
		 inet_addr("127.0.0.1");
	 connect(hSockClient,(SOCKADDR*)&addrSvr,
		 sizeof(addrSvr));
	 //3 �վ��շ�
	 //3.1 ��������
	 char szSend[]="Hello,Data From client!";
	 send(hSockClient,szSend,strlen(szSend),0);
	 //3.2 ��������

	 //4 �ر�socket
	 closesocket(hSockClient);

}
void UDPClient()
{
	//1 ����socket
	 SOCKET hSockClient=socket(AF_INET,
		 SOCK_DGRAM,IPPROTO_UDP);
  //2 �վ��շ�
	//2.1 ��������
	 char szSend[]="Hello,Data From UDPClient!";
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5679);
	 addrSvr.sin_addr.S_un.S_addr=
		 inet_addr("127.0.0.1");
	 sendto(hSockClient,szSend,strlen(szSend),0,
	 (SOCKADDR*)&addrSvr,sizeof(addrSvr));
	 //3 �ر�socket
	 closesocket(hSockClient);
}
int main(int argc, char* argv[])
{
	//1 ��ʼ��socket��
	WSAData wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	//2 TCP�ͻ���
	//TCPClient();
	UDPClient();
	//3 ж��socket��
	WSACleanup();
	return 0;
}

