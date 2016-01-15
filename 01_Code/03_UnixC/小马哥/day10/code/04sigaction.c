//sigaction函数的第二种处理方法
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo,siginfo_t* infor,void* p)
{
	printf("进程%d发送了信号%d\n",infor->si_pid,signo);
}

int main(void)
{
	//1.准备结构体
	struct sigaction action;
	//表示使用结构体中第二个函数指针处理信号
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = fa;
	//2.使用sigaction进行设置
	sigaction(2,&action,NULL);
	printf("pid = %d\n",getpid());
	while(1);
	return 0;
}
