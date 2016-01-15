// SockSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

void TCPServer()
{
   //1 ����
	 SOCKET hSockSvr=
		 socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	 //2 ��
	 SOCKADDR_IN addrSvr={0};
	 addrSvr.sin_family=AF_INET;
	 addrSvr.sin_port=htons(5678);
	 addrSvr.sin_addr.S_un.S_addr=INADDR_ANY;
   bind(hSockSvr,(SOCKADDR*)&addrSvr,
		 sizeof(addrSvr));
	 //3 ����
	 listen(hSockSvr,5);
	 //4 �ȴ��ͻ�������
	 printf("�ȴ��ͻ�������...\n");
	 SOCKADDR_IN addrClient={0};
	 int nLen=sizeof(addrClient);
	 SOCKET hSockClient=
		 accept(hSockSvr,(SOCKADDR*)&addrClient,&nLen);
   printf("�����ӡ�\n");
	 //5 �����շ�
	 //5.1���Ƚ�������
	 char szRecv[256]={0};
	 int nRecv=recv(hSockClient,szRecv,256,0);
	 char* IP=inet_ntoa(addrClient.sin_addr);
   printf("%s:%s\n",IP,szRecv);
	 printf("����:%d\n",nRecv);
	 //6 �ر��׽���
	 closesocket(hSockClient);
	 closesocket(hSockSvr);

}
int main(int argc, char* argv[])
{
  // 1 ��ʼ��Socket��
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
  // 2 ʹ��(�����ͨ��)
  TCPServer(); 
  // 3 ж��Socket��
	WSACleanup();
	return 0;
}

