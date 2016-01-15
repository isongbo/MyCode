#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#define SOCK_FILE "/tmp/sock"
int main (void) {
	printf ("客户机：创建本地数据报"
		"套接字...\n");
	int sockfd = socket (AF_LOCAL,
		SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("客户机：准备地址并"
		"连接...\n");
	struct sockaddr_un addr;
	addr.sun_family = AF_LOCAL;
	strcpy (addr.sun_path, SOCK_FILE);
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
