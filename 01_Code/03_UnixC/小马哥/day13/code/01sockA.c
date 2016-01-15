//基于本地通信的服务器
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>

int main(void)
{
	//1.创建socket,使用socket函数
	int sockfd = socket(AF_UNIX,SOCK_DGRAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	//2.准备通信地址
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	//3.进行绑定
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.进行通信
	char buf[100] = {0};
	//sleep(20);
	//printf("开始read了\n");
	res = read(sockfd,buf,sizeof(buf));
	printf("读取到的数据内容是：%s,数据长度是：%d\n",buf,res);
	//5.关闭socket
	close(sockfd);
	return 0;
}
