//信号的屏蔽处理
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
	//打印当前进程的pid
	printf("pid = %d\n",getpid());
	//设置对信号2、3、50进行自定义处理
	signal(2,fa);
	signal(3,fa);
	signal(50,fa);
	int res = sleep(20);
	if(0 != res)
	{
		printf("没有信号屏蔽，还没有睡醒就被唤醒，还可以睡%d秒\n",res);
	}

	printf("--------------------------\n");
	printf("开始信号屏蔽\n");
	//准备两个信号集
	sigset_t set,old;
	//清空信号集
	sigemptyset(&set);
	sigemptyset(&old);
	//把要屏蔽的信号加入信号集中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	//调用函数进行屏蔽
	res = sigprocmask(SIG_SETMASK,&set,&old);
	if(-1 == res)
	{
		perror("sigprocmask"),exit(-1);
	}
	printf("信号屏蔽成功，开始进入睡眠\n");
	res = sleep(30);
	if(0 == res)
	{
		printf("总算睡了个好觉，信号屏蔽即将解除\n");
	}
	//获取信号屏蔽期间来过的信号
	sigset_t pend;
	res = sigpending(&pend);
	if(-1 == res)
	{
		perror("sigpending"),exit(-1);
	}
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
	//恢复系统默认的信号屏蔽字
	printf("old = %ld\n",old);
	sigprocmask(SIG_SETMASK,&old,NULL);
	return 0;
}



