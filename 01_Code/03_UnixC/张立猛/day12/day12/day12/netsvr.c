#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main (void) {
	printf ("服务器：创建网络数据报文"
		"套接字...\n");
	int sockfd = socket (AF_INET,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("服务器：准备地址"
		"并绑定...\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (8888);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind (sockfd,
		(struct sockaddr*)&addr,
		sizeof (addr)) == -1) {
		perror ("bind");
		return -1;
	}
	printf ("服务器：接收数据...\n");
	for (;;) {
		char buf[1024];
		ssize_t rb = read (sockfd, buf,
			sizeof (buf));
		if (rb == -1) {
			perror ("read");
			return -1;
		}
		if (! strcmp (buf, "!!"))
			break;
		printf ("< %s\n", buf);
	}
	printf ("服务器：关闭套接字...\n");
	if (close (sockfd) == -1) {
		perror ("close");
		return -1;
	}
	printf ("服务器：完成！\n");
	return 0;
}
