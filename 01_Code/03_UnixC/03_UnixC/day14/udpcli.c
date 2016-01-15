#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main (int argc, char* argv[]) {
	if (argc < 3) {
		printf("用法：%s <IP地址> <端口号>\n",
			argv[0]);
		return -1;
	}
	printf ("客户机：创建网络套接字\n");
	int sockfd = socket (AF_INET, SOCK_DGRAM,
		0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("客户机：准备地址\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (atoi (argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	for (;;) {
		printf ("> ");
		char buf[1024];
		gets (buf);
		if (! strcmp (buf, "!"))
			break;
		printf ("客户机：向%s:%u发送请求\n",
			inet_ntoa (addr.sin_addr),
			ntohs (addr.sin_port));
		if (sendto (sockfd, buf,
			strlen (buf) + 1, 0,
			(struct sockaddr*)&addr,
			sizeof (addr)) == -1) {
			perror ("sendto");
			return -1;
		}
		printf ("客户机：接收响应\n");
		struct sockaddr_in addrsvr = {};
		socklen_t addrlen = sizeof (addrsvr);
		if (recvfrom (sockfd, buf,
			sizeof (buf), 0,
			(struct sockaddr*)&addrsvr,
			&addrlen) == -1) {
			perror ("recvfrom");
			return -1;
		}
		// 验证addrsvr是否和合法的服务器
		printf ("< %s\n", buf);
	}
	printf ("客户机：关闭套接字\n");
	close (sockfd);
	printf ("客户机：终止\n");
	return 0;
}
