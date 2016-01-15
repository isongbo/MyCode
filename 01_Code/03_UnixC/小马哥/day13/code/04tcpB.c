//基于TCP的客户端
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
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.40.0.10");
	//3.连接
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("connect"),exit(-1);
	}
	char msg[200] = {0};
	printf("请输入您的昵称：\n");
	scanf("%s",msg);
	//4.不断的进行通信
	while(1)
	{
		char buf[100] = {0};
		printf("请输入要说的话：\n");
		scanf("%s",buf);
		strcat(msg,":");
		strcat(msg,buf);
		write(sockfd,msg,strlen(msg));
		if(!strcmp(buf,"bye"))
		{
			break;//结束对话
		}
		char rcvBuf[100] = {0};
		read(sockfd,rcvBuf,sizeof(rcvBuf));
		printf("服务器发来的消息是：%s\n",rcvBuf);
	}
	//5.关闭socket
	close(sockfd);
	return 0;
}
