#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf ("用法：%s <服务器IP>\n",
			argv[0]);
		return -1;
	}
	printf ("客户机：创建网络数据报"
		"套接字...\n");
	int sockfd = socket (AF_INET,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("客户机：准备地址并"
		"连接...\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (8888);
	addr.sin_addr.s_addr = inet_addr (
		argv[1]);
	if (connect (sockfd,
		(struct sockaddr*)&addr,
		sizeof (addr)) == -1) {
		perror ("connect");
		return -1;
	}
	printf ("客户机：发送数据...\n");
	for (;;) {
		printf ("> ");
		char buf[1024];
		gets (buf);
		if (! strcmp (buf, "!"))
			break;
		if (write (sockfd, buf,
			strlen (buf) + 1) == -1) {
			perror ("write");
			return -1;
		}
		if (! strcmp (buf, "!!"))
			break;
	}
	printf ("客户机：关闭套接字...\n");
	if (close (sockfd) == -1) {
		perror ("close");
		return -1;
	}
	printf ("客户机：完成！\n");
	return 0;
}
