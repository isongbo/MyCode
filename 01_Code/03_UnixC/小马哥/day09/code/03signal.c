//signal函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	//恢复对信号进行默认处理
	signal(signo,SIG_DFL);
}

int main(void)
{
	//设置对信号2进行忽略处理
	signal(2,SIG_IGN);
	//设置对信号3进行自定义处理
	signal(SIGQUIT/*3*/,fa);
	//设置对信号9也进行自定义处理
	signal(9,fa);
	printf("pid = %d\n",getpid());
	while(1);
	return 0;
}
