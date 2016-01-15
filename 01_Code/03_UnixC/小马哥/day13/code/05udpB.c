//基于UDP通信的客户端
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
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//3.进行通信
	//write(sockfd,"hello",5);
	sendto(sockfd,"hello",5,0,(struct sockaddr*)&addr,sizeof(addr));
	char buf[100] = {0};
	read(sockfd,buf,sizeof(buf));
	printf("服务器发来的消息是：%s\n",buf);
	//4.关闭socket
	close(sockfd);
	return 0;
}
