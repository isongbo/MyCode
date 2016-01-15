//sigaction函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	sleep(5);
	printf("信号处理结束\n");
}

int main(void)
{
	//1.准备结构体
	struct sigaction action;
	action.sa_handler = fa;
	//2.设置在信号处理期间需要屏蔽的信号
	//清空信号集
	sigemptyset(&action.sa_mask);
	//把信号3放入信号集中
	sigaddset(&action.sa_mask,3);
	//3.信号的处理选项
	//第一次自定义处理，再来默认处理
	//action.sa_flags = SA_RESETHAND;
	//解除对相同信号的屏蔽
	action.sa_flags = SA_NODEFER;
	//4.使用sigaction函数进行设置
	sigaction(2,&action,NULL);
	while(1);
	return 0;
}
