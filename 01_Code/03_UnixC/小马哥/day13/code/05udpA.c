//基于UDP通信模型的服务器端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
	//1.创建socket
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	// 127.0.0.1 本地回环地址
	// ifconfig 查看ip地址等信息
	// ipconfig/all windows系统中察看ip等信息
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//3.绑定
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.通信
	char buf[100] = {0};
	//read(sockfd,buf,sizeof(buf));
	struct sockaddr_in rcvAddr;
	socklen_t len = sizeof(rcvAddr);
	//接受客户端发来的数据，并且保存客户端地址
	recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&rcvAddr,&len);
	printf("客户端发来的消息是：%s\n",buf);
	//向客户端返回一个消息
	sendto(sockfd,"I received!",11,0,(struct sockaddr*)&rcvAddr,sizeof(rcvAddr));
	//5.关闭socket
	close(sockfd);
	return 0;
}
