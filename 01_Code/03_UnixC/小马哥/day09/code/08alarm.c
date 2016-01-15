//alarm函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	//每隔1秒发送一次SIGALRM信号
	//alarm(1);
}

int main(void)
{
	//设置对SIGALRM信号的自定义处理
	signal(SIGALRM,fa);
	//表示5秒之后发送SIGALRM信号
	int res = alarm(5);
	//返回0表示之前没有闹钟
	printf("res = %d\n",res);
	
	sleep(2);
	//设置一个10秒之后响的闹钟
	res = alarm(10);
	printf("res = %d\n",res); //3 
	
	/*
	sleep(3);
	//取消闹钟
	res = alarm(0);
	printf("res = %d\n",res);//7
	*/
	while(1);
	return 0;
}
