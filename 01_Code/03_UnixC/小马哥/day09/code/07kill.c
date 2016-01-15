//使用kill函数进行信号的发送
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
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		//设置子进程对信号50进行自定义处理
		signal(50,fa);
		while(1);
	}
	sleep(1);
	printf("父进程准备发送信号...\n");
	//检查子进程是否存在
	int res = kill(pid,0);
	if(0 == res)
	{
		printf("父进程向子进程发送信号50\n");
		kill(pid,50);
	}
	return 0;
}
