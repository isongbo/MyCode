#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#define SOCK_FILE "/tmp/sock"
int main (void) {
	printf ("服务器：创建本地套接字\n");
	int sockfd = socket (AF_LOCAL,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("服务器：准备地址并绑定\n");
	struct sockaddr_un addr;
	addr.sun_family = AF_LOCAL;
	strcpy (addr.sun_path, SOCK_FILE);
	if (bind (sockfd, (struct sockaddr*)&addr,
		sizeof (addr)) == -1) {
		perror ("bind");
		return -1;
	}
	for (;;) {
		char buf[1024];
		printf ("服务器：接收数据\n");
		ssize_t rb = read (sockfd, buf,
			sizeof (buf));
		if (rb == -1) {
			perror ("read");
			return -1;
		}
		printf ("服务器：处理数据\n");
		if (! strcmp (buf, "!!"))
			break;
		printf ("< %s\n", buf);
	}
	printf ("服务器：关闭套接字\n");
	close (sockfd);
	printf ("服务器：删除套接字文件\n");
	unlink (SOCK_FILE);
	printf ("服务器：终止！\n");
	return 0;
}
