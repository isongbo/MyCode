//fork函数的使用
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	printf("主函数开始执行\n");
	pid_t pid = fork();
	//判断是否出错
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		//getpid获取当前进程的PID
		printf("我是子进程%d,我的父进程是：%d\n",getpid(),getppid());
	}
	else //父进程
	{
		printf("我是父进程%d,我的子进程是：%d\n",getpid(),pid);
	}
	//printf("主函数结束:%d\n",pid);
	return 0;
}
