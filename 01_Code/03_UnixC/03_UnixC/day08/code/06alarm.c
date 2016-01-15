//使用alarm函数发送信号
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	//每隔1秒发送SIGALRM信号
	alarm(1);
}

int main(void)
{
	//设置SIGALRM信号进行自定义处理
	signal(SIGALRM,fa);
	//表示5秒后发送SIGALRM信号
	int res = alarm(5); // res = 0;
	sleep(2);
	res = alarm(10); // res = 3
	if(0 != res)
	{
		printf("res = %d\n",res);
	}
	//取消闹钟
	//res = alarm(0);
	//printf("res = %d\n",res);//10
	while(1);
	return 0;
}
