//使用raise函数发送指定的信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//设置对信号2进行自定义处理
	signal(2,fa);
	int res = sleep(10);
	if(0 == res)
	{
		printf("总算睡了个美觉,没有被打扰\n");
	}
	else
	{
		printf("睡眠被打断,还有%d秒没有来得及睡\n",res);
	}
	//使用raise函数发送信号
	raise(3);
	while(1);
	return 0;
}
