//真实计时器的设置和使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置SIGALRM信号的自定义处理
	signal(SIGALRM,fa);

	//准备结构体信息
	struct itimerval timer;
	//设置间隔时间 2.3秒
	timer.it_interval.tv_sec = 2;
	timer.it_interval.tv_usec = 300000;
	//设置启动时间 5秒后启动
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 0;
	//设置计时器的参数
	int res = setitimer(ITIMER_REAL,&timer,NULL);
	if(-1 == res)
	{
		perror("setitimer"),exit(-1);
	}
	printf("设置计时器成功\n");
	while(1);
	return 0;
}
