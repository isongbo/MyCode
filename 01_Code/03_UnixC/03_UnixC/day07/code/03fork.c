//fork函数的使用
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	printf("pid = %d\n",getpid());//父进程
	printf("main函数开始执行\n");
	pid_t pid = fork();
	if(-1 == pid) //fork出错
	{
		perror("fork"),exit(-1);
	}
	//printf("main函数结束%d\n",pid);
	if(0 == pid) //子进程
	{
		printf("我是子进程%d,我的父进程是%d\n",getpid(),getppid());
	}
	else //父进程
	{
		printf("我是父进程%d,我的子进程是%d\n",getpid(),pid);
	}
	return 0;
}



