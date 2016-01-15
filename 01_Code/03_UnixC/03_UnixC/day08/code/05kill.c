//使用kill函数发送指定的信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		//设置对信号40进行自定义处理
		signal(40,fa);
		printf("子进程%d开始运行\n",getpid());
		while(1);
	}
	//判断子进程是否存在
	if(0 == kill(pid,0))
	{
		sleep(5);
		//给子进程发信号40
		kill(pid,40);
	}
	return 0;
}
