//父子进程对信号的处理方式的比较
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
	//1.对信号2进行自定义处理
	signal(2,fa);
	//2.对信号3进行忽略处理
	signal(3,SIG_IGN);
	//3.使用fork创建一个子进程
	pid_t pid = fork();
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		while(1);
	}
	//父进程
	printf("父进程结束\n");
	return 0;
}
