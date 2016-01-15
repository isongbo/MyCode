//sigaction函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//准备结构体
	struct sigaction action = {};
	//采用第二个函数指针处理信号
	action.sa_sigaction = fa;
	//设置flag为SA_SIGINFO;
	action.sa_flags = SA_SIGINFO;
	//设置对信号2进行自定义处理
	int res = sigaction(2,&action,NULL);
	if(-1 == res)
	{
		perror("sigaction"),exit(-1);
	}
	printf("针对信号的处理方式设置成功\n");
	while(1);
	return 0;
}
