//信号的处理对父子进程的影响
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

//自定义处理函数
void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置对信号2进行自定义处理
	signal(2,fa);
	//设置对信号3进行忽略处理
	signal(SIGQUIT/*3*/,SIG_IGN);
	//创建子进程，子进程进入无限循环
	pid_t pid = fork();
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	return 0;
}
