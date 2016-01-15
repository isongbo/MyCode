//使用raise函数进行信号的发送
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
		printf("总算睡了个好觉!\n");
	}
	else
	{
		printf("睡眠被打断,还差%d秒\n",res);
	}
	//给当前进程发送信号2
	//raise(2);
	raise(3);
	while(1);
	return 0;
}
