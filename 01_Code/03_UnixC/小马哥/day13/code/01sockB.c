//基于本地通信的客户端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main(void)
{
	//1.创建socket
	int sockfd = socket(AF_UNIX,SOCK_DGRAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	//2.准备通信地址
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	//3.进行连接
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("connect"),exit(-1);
	}
	//4.进行通信
	char buf[20] = "hello";
	res = write(sockfd,buf,strlen(buf));
	printf("写入的数据是：%s,写入的数据大小是：%d\n",buf,res);
	//5.关闭socket
	close(sockfd);
	return 0;
}



