#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include "../inc/bank.h"
static int g_reqid = -1; // 请求队列
static int g_resid = -1; // 响应队列
// 服务进程结构
typedef struct tag_Service {
	char  srv_path[PATH_MAX+1];//服务路径
	pid_t srv_pid;             //服务PID
}	SERVICE;
// 服务进程数组
static SERVICE g_srv[] = {
	{"./open",  -1},
	{"./query", -1}};
// 初始化
int init (void) {
	printf ("服务器初始化...\n");
	if ((g_reqid = msgget (KEY_REQUEST,
		0600 | IPC_CREAT |
		IPC_EXCL)) == -1) {
		perror ("msgget");
		return -1;
	}
	printf ("创建请求消息队列成功！\n");
	if ((g_resid = msgget (KEY_RESPOND,
		0600 | IPC_CREAT |
		IPC_EXCL)) == -1) {
		perror ("msgget");
		return -1;
	}
	printf ("创建响应消息队列成功！\n");
	return 0;
}
// 终结化
void deinit (void) {
	printf ("服务器终结化...\n");
	if (msgctl (g_reqid, IPC_RMID,
		NULL) == -1)
		perror ("msgctl");
	else
		printf ("销毁请求消息队列"
			"成功！\n");
	if (msgctl (g_resid, IPC_RMID,
		NULL) == -1)
		perror ("msgctl");
	else
		printf ("销毁响应消息队列"
			"成功！\n");
}
// 启动业务服务
void start (void) {
	printf ("启动业务服务...\n");
	size_t i;
	for (i = 0; i < sizeof (g_srv) /
		sizeof (g_srv[0]); ++i) {
		g_srv[i].srv_pid = vfork ();
		if (g_srv[i].srv_pid == -1) {
			perror ("vfork");
			continue;
		}
		if (g_srv[i].srv_pid == 0)
			if (execl (g_srv[i].srv_path,
				g_srv[i].srv_path,
				NULL) == -1) {
				perror ("execl");
				_exit (EXIT_FAILURE);
			}
	}
}
// 停止业务服务
void stop (void) {
	printf ("停止业务服务...\n");
	size_t i;
	for (i = 0; i < sizeof (g_srv) /
		sizeof (g_srv[0]); ++i) {
		if (g_srv[i].srv_pid == -1)
			continue;
		if (kill (g_srv[i].srv_pid,
			SIGINT) == -1)
			perror ("kill");
	}
	for (;;)
		if (wait (0) == -1) {
			if (errno == ECHILD)
				break;
			perror ("wait");
		}
}
int main (void) {
	atexit (deinit);
	if (init () == -1)
		return -1;
	start ();
	sleep (1);
	printf ("按<回车>退出...\n");
	getchar ();
	stop ();
	return 0;
}
