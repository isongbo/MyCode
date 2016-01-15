//sigaction函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("处理信号%d开始...\n",signo);
	sleep(5);
	printf("信号处理完毕\n");
}

int main(void)
{
	//准备结构体变量
	struct sigaction action = {};
	//初始化结构体中的成员
	//选择第一个函数指针来处理函数
	action.sa_handler = fa;
	//初始化信号屏蔽字
	sigemptyset(&action.sa_mask);
	//设置信号3为要屏蔽的信号
	sigaddset(&action.sa_mask,3);
	//设置信号第二次到来的处理方式为默认
	//action.sa_flags = SA_RESETHAND;
	//解除对相同信号的屏蔽,处理2的期间解除对信号2的屏蔽
	action.sa_flags = SA_NODEFER;
	//设置对信号2的处理方式
	int res = sigaction(SIGINT,&action,NULL);
	if(-1 == res)
	{
		perror("sigaction"),exit(-1);
	}
	printf("信号的处理方式设置成功\n");
	while(1);
	return 0;
}
