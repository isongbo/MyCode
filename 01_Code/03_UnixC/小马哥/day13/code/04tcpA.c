//同时响应多个客户端的服务器
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

int sockfd;

//信号的自定义处理函数
void fa(int signo)
{
	//7.关闭socket
	close(sockfd);
	printf("服务器成功关闭\n");
	exit(0);
}

int main(void)
{
	signal(2,fa);
	//1.创建socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.40.0.10");
	//解决端口号被占用的情况
	int reuseaddr = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr));

	//3.绑定
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.监听
	res = listen(sockfd,100);
	if(-1 == res)
	{
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");
	//5.不断地响应客户端的请求
	while(1)
	{
		//准备结构体保存客户端的地址信息
		struct sockaddr_in rcvAddr;
		socklen_t len = sizeof(rcvAddr);
		int fd = accept(sockfd,(struct sockaddr*)&rcvAddr,&len);
		if(-1 == fd)
		{
			perror("accept"),exit(-1);
		}
		char* ip = inet_ntoa(rcvAddr.sin_addr);
		printf("客户端%s连接上来...\n",ip);
		//创建子进程响应客户端的数据
		pid_t pid = fork();
		if(-1 == pid)
		{
			perror("fork"),exit(-1);
		}
		if(0 == pid) //子进程
		{
			//6.不断地聊天
			while(1)
			{
				char buf[100] = {0};
				read(fd,buf,sizeof(buf));
				if(!strcmp(buf,"bye"))
				{
					break;//结束聊天
				}
				printf("客户端发来的数据：%s\n",buf);
				write(fd,"I received!",11);
			}
			printf("客户端%s下线了\n",ip);
			close(fd);
			exit(0);//结束子进程
		}
	}

	return 0;
}
