//fork进程执行次序和结束次序的比较
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		printf("我是子进程%d,我的父进程是%d\n",getpid(),getppid());
		sleep(2);
		printf("我是子进程%d,我的父进程是%d\n",getpid(),getppid());
	}
	else //父进程
	{
		sleep(1);
		printf("我是父进程%d,我的子进程是：%d\n",getpid(),pid);
	}
	return 0;
}
