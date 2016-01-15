#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#define SOCK_FILE "/tmp/sock"
int main (void) {
	printf ("服务器：创建本地数据报文"
		"套接字...\n");
	int sockfd = socket (AF_LOCAL,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("服务器：准备地址"
		"并绑定...\n");
	struct sockaddr_un addr;
	addr.sun_family = AF_LOCAL;
	strcpy (addr.sun_path, SOCK_FILE);
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
	if (unlink (SOCK_FILE) == -1) {
		perror ("unlink");
		return -1;
	}
	printf ("服务器：完成！\n");
	return 0;
}
