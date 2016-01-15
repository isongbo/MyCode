//定时器的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置SIGALRM信号的自定义处理
	signal(SIGALRM,fa);
	//准备定时器
	struct itimerval timer;
	//设置间隔时间
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 230000;
	//设置启动时间
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 0;
	//设置并且启动定时器
	setitimer(ITIMER_REAL,&timer,NULL);
	while(1);
	return 0;
}


