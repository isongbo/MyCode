//比较vfork创建的子进程对信号的处理方式
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
	signal(SIGINT,fa);
	signal(SIGQUIT,SIG_IGN);
	pid_t pid = vfork();
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		//跳转出去执行
		execl("./proc","proc",NULL);
	}
	printf("父进程结束\n");
	return 0;
}
