//基于TCP通信模型的服务器端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	//3.进行绑定
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
	//5.响应客户端的请求
	struct sockaddr_in rcvAddr;
	socklen_t len = sizeof(rcvAddr);
	//将客户端的地址信息存储到rcvAddr里面
	int fd = accept(sockfd,(struct sockaddr*)&rcvAddr,&len);
	if(-1 == fd)
	{
		perror("accept"),exit(-1);
	}
	//将客户端的ip地址转换为字符串类型
	char* ip = inet_ntoa(rcvAddr.sin_addr);
	printf("客户端的ip地址是：%s\n",ip);

	//6.进行通信
	char buf[100] = {0};
	res = read(fd,buf,sizeof(buf));
	printf("读取到的数据内容是：%s,数据大小是：%d\n",buf,res);
	write(fd,"I received!",11);
	//7.关闭socket
	close(fd);
	close(sockfd);
	return 0;
}
