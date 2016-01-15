//ATM的服务器端
#include "bank.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//创建两个消息队列的id
static int msgid1;
static int msgid2;

//创建两个消息队列msgget
void init()
{
	 //第一个参数是键值，IPC_CREAT表示没有此消息队列则创建，IPC_EXCL表示如果队列存在，则报错
    msgid1 = msgget(key1,0666|IPC_CREAT|IPC_EXCL);
	 if(msgid1 == -1)
	 {
	     perror("消息队列一创建失败");
		  exit(-1);
	 }
	 printf("消息队列一创建成功\n");
	 msgid2 = msgget(key2,0666|IPC_CREAT|IPC_EXCL);
	 if(msgid2 == -1)
	 {
	    perror("消息队列二创建失败");
		 exit(-1);
	 }
	 printf("消息队列二创建成功\n");
}
//启动服务
void start()
{
	printf("服务器正在启动...\n");
	sleep(2);
   //创建子进程
	pid_t open_pid = vfork();
	if(open_pid == -1)
	{
		perror("vfork failed");
		exit(-1);
	}
	else if(open_pid == 0)
	{
      //printf("in child process\n");
		//使用excl函数调用其他可执行程序
      execl("./open","open",NULL);
		//execl("save","save",0);
	}
	else
	{
		printf("正在等待客户端选择:\n");
		//printf("in parent process\n");
		//等待子进程中的函数
      waitpid(open_pid,0,0);
	}
	printf("服务器启动成功\n");
}
//关闭服务器
void destroy()
{
	printf("服务器正在关闭...\n");
	sleep(2);
   if(msgctl(msgid1,IPC_RMID,NULL) == -1)
	{
		perror("消息队列一删除失败");
		exit(-1);
	}
	else
	{
		printf("消息队列一删除成功\n");
	}
	if(msgctl(msgid2,IPC_RMID,NULL) == -1)
	{
		perror("消息队列二删除失败");
		exit(-1);
	}
	else
	{
		printf("消息队列二删除成功\n");
	}
	printf("服务器成功关闭\n");
}

void sig_exit()
{
	exit(0);
}

int main()
{
	//函数指针指向destroy函数，main函数结束后调用此函数
   atexit(destroy);

	printf("退出服务器请按CTRL+C\n");
	signal(SIGINT,sig_exit);

	//创建消息队列
	init();

	//启动服务
	start();
	return 0;
}
