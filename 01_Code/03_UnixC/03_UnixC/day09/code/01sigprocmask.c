//sigprocmask函数设置信号的屏蔽
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	//printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	printf("pid = %d\n",getpid());
	//设置对信号2 3 50进行自定义处理
	signal(2,fa);
	signal(3,fa);
	signal(50,fa);

	int res = sleep(20);
	if(0 != res)
	{
		printf("没有设置信号的屏蔽，睡眠被打断,还有%d秒没有来得及睡\n",res);
	}
	else
	{
		printf("没有设置信号的屏蔽，但是没有人打断，所以美美地睡了一觉\n");
	}

	printf("-----------------------------\n");
	//准备信号集
	sigset_t set,old;
	//清空信号集
	sigemptyset(&set);
	sigemptyset(&old);
	//把信号2 3 50 加入到信号集中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	//设置信号的屏蔽
	res = sigprocmask(SIG_SETMASK,&set,&old);
	printf("old = %ld\n",old);
	if(-1 == res)
	{
		perror("sigprocmask"),exit(-1);
	}
	printf("设置信号屏蔽成功\n");
	res = sleep(20);
	if(0 == res)
	{
		printf("想打扰我休息没门，美美地睡了一觉，我睡醒了\n");
	}
	//获取信号屏蔽期间来过的信号
	sigset_t pend;
	res = sigpending(&pend);
	if(-1 == res)
	{
		perror("sigpending"),exit(-1);
	}
	printf("pend = %ld\n",pend);
	if(sigismember(&pend,2))
	{
		printf("信号2来过\n");
	}
	if(sigismember(&pend,3))
	{
		printf("信号3来过\n");
	}
	if(sigismember(&pend,50))
	{
		printf("信号50来过\n");
	}
	//恢复原来默认的屏蔽字
	sigprocmask(SIG_SETMASK,&old,NULL);
	return 0;
}
