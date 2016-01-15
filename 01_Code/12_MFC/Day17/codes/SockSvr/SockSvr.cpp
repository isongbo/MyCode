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
void UDPServer()
{
   //1 ����socket
	 SOCKET hSockSvr=socket(AF_INET,
		 SOCK_DGRAM,IPPROTO_UDP);
	 //2 ��
	 SOCKADDR_IN sockSvr={0};
	 sockSvr.sin_family=AF_INET;
	 sockSvr.sin_port=htons(5679);
	 sockSvr.sin_addr.S_un.S_addr=INADDR_ANY;
	 bind(hSockSvr,(SOCKADDR*)&sockSvr,
		 sizeof(sockSvr));
	 //3 �����շ�
	 //3.1 ���Ƚ�������
	 char szRecv[256]={0};
	 SOCKADDR_IN sockClient={0};
	 int nLen=sizeof(sockClient);
	 int nRecv=recvfrom(hSockSvr,szRecv,256,0,
		 (SOCKADDR*)&sockClient,&nLen);
	 char* IP=inet_ntoa(sockClient.sin_addr);
	 printf("%s:%s\n",IP,szRecv);
	 printf("����:%d\n",nRecv);
	 //4 �ر�socket
	 closesocket(hSockSvr);

}
int main(int argc, char* argv[])
{
  // 1 ��ʼ��Socket��
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
  // 2 ʹ��(�����ͨ��)
  //TCPServer(); 
	UDPServer();
  // 3 ж��Socket��
	WSACleanup();
	return 0;
}

