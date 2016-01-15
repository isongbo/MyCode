#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
// 处理SIGCHLD(17)信号，为子进程收尸
void sigchld (int signum) {
	for (;;) {
		pid_t pid = waitpid (-1, 0, WNOHANG);
		if (pid == -1) {
			if (errno != ECHILD) {
				perror ("waitpid");
				exit (-1);
			}
			printf ("服务器：全部子进程都已"
				"终止\n");
			break;
		}
		if (pid)
			printf ("服务器：回收子进程%d\n",
				pid);
		else {
			printf ("服务器：没有终止的子进"
				"程\n");
			break;
		}
	}
}
// 处理客户机
int do_client (int connfd) {
	for (;;) {
		char buf[1024];
		printf ("服务器：接收请求\n");
		ssize_t rb = recv (connfd, buf,
			sizeof (buf), 0);
		if (rb == -1) {
			perror ("recv");
			return -1;
		}
		if (rb == 0) {
			printf ("服务器：客户机已关闭\n");
			break;
		}
		printf ("服务器：业务处理\n");
		// ...
		printf ("服务器：发送响应\n");
		if (send (connfd, buf, rb, 0) == -1) {
			perror ("send");
			return -1;
		}
	}
	return 0;
}
int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf ("用法：%s <端口号>\n",
			argv[0]);
		return -1;
	}
	if (signal (SIGCHLD, sigchld) == SIG_ERR){
		perror ("signal");
		return -1;
	}
	printf ("服务器：创建网络套接字\n");
	int sockfd = socket (AF_INET,
		SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror ("socket");
		return -1;
	}
	printf ("服务器：准备地址并绑定\n");
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (atoi (argv[1]));
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind (sockfd, (struct sockaddr*)&addr,
		sizeof (addr)) == -1) {
		perror ("bind");
		return -1;
	}
	printf ("服务器：启动侦听\n");
	if (listen (sockfd, 1024) == -1) {
		perror ("listen");
		return -1;
	}
	for (;;) {
		printf ("服务器：等待连接\n");
		struct sockaddr_in addrcli = {};
		socklen_t addrlen = sizeof (addrcli);
		int connfd = accept (sockfd,
			(struct sockaddr*)&addrcli,
			&addrlen);
		if (connfd == -1) {
			perror ("accept");
			return -1;
		}
		printf ("客户机：%s，%u\n",
			inet_ntoa (addrcli.sin_addr),
			ntohs (addrcli.sin_port));
		pid_t pid = fork ();
		if (pid == -1) {
			perror ("fork");
			return -1;
		}
		if (pid == 0) {
			close (sockfd);
			if (do_client (connfd) == -1)
				return -1;
			printf ("服务器：关闭套接字\n");
			close (connfd);
			return 0;
		}
		close (connfd);
	}
	close (sockfd);
	printf ("服务器：终止！\n");
	return 0;
}
