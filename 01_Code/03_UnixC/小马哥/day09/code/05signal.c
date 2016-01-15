//使用vfork函数创建子进程对信号的处理
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置对信号2进行自定义处理
	signal(SIGINT,fa);
	//对信号3进行忽略处理
	signal(SIGQUIT,SIG_IGN);
	//创建子进程
	pid_t pid = vfork();
	if(0 == pid) //子进程
	{
		printf("子进程%d开始执行\n",getpid());
		//使用execl函数进行跳转
		execl("./proc","proc",NULL);
	}
	printf("父进程结束\n");
	return 0;
}
