//sigqueue函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo,siginfo_t* infor,void* p)
{
	printf("进程%d发送了信号%d,附加数据是：%d\n",infor->si_pid,signo,infor->si_value);
}

int main(void)
{
	//1.准备结构体
	struct sigaction action;
	//使用结构体中的第二个函数指针处理信号
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = fa;
	//2.使用sigaction设置
	sigaction(40,&action,NULL);
	//3.使用fork创建子进程负责给父进程发信号
	pid_t pid = fork();
	if(0 == pid) //子进程
	{
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			union sigval v;
			v.sival_int = i;
			//4.使用sigqueue发信号和附加数据
			sigqueue(getppid(),40,v);
		}
		sleep(1);
		exit(0);
	}
	while(1);
	return 0;
}
