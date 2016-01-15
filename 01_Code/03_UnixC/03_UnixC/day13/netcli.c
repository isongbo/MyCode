#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main (void) {
	printf ("客户机：创建网络套接字\n");
	int sockfd = socket (AF_INET,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("客户机：准备地址并连接\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (8888);
	addr.sin_addr.s_addr =
		inet_addr (/*"127.0.0.1"*/
			"172.40.0.10");
	if (connect (sockfd,
		(struct sockaddr*)&addr,
		sizeof (addr)) == -1) {
		perror ("connect");
		return -1;
	}
	for (;;) {
		printf ("客户机：产生数据\n");
		printf ("> ");
		char buf[1024];
		gets (buf);
		if (! strcmp (buf, "!"))
			break;
		printf ("客户机：发送数据\n");
		if (write (sockfd, buf,
			strlen (buf) + 1) == -1) {
			perror ("write");
			return -1;
		}
		if (! strcmp (buf, "!!"))
			break;
	}
	printf ("客户机：关闭套接字\n");
	close (sockfd);
	printf ("客户机：终止！\n");
	return 0;
}
