//简易的网络通信 服务器
#include <stdio.h>
#include <stdlib.h>
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
	addr.sin_addr.s_addr = inet_addr("172.40.0.10");
	//3.进行绑定
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.进行通信
	char buf[100] = {0};
	res = read(sockfd,buf,sizeof(buf));
	printf("读取到的数据内容是：%s,读取到的数据大小是：%d\n",buf,res);
	//5.关闭socket
	close(sockfd);
	//练习：vi 02sockNetB.c,编写客户端
	return 0;
}



