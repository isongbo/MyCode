//信号处理函数signal的使用
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//自定义信号的处理函数
void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	//设置对信号signo的处理方式为默认
	signal(signo,SIG_DFL);
}

int main(void)
{
	//设置对信号2进行忽略处理
	signal(2/*SIGINT*/,SIG_IGN);
	//设置对信号3进行自定义处理
	signal(3/*SIGQUIT*/,fa);
	//设置对信号9进行自定义处理
	//信号9只能默认处理，也就是杀死进程
	signal(9/*SIGKILL*/,SIG_IGN);

	printf("pid = %d\n",getpid());
	while(1);
	return 0;
}
