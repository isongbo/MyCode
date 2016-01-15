//使用sigqueue发送信号和附加数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p)
{
	printf("捕获到了信号%d,进程%d发送了附加数据%d\n",signo,info->si_pid,info->si_value.sival_int);
}

int main(void)
{
	//准备结构体
	struct sigaction action = {};
	//使用第二个函数指针来处理信号
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = fa;
	//设置对信号40进行自定义处理
	int res = sigaction(40,&action,NULL);
	if(-1 == res)
	{
		perror("sigaction"),exit(-1);
	}
	
	//创建子进程发送信号和附加数据
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			union sigval val;
			val.sival_int = i;
			//发送信号和附加数据
			sigqueue(getppid(),40,val);
			//每隔0.1秒发送,usleep单位是微秒
			usleep(100000);
		}
		//子进程终止
		exit(0);
	}
	//父进程进入无限循环
	while(1);
	return 0;
}
