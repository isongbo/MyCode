//获取各种id号
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("当前进程id是：%d\n",getpid());
	printf("当前进程的父进程id是：%d\n",getppid());
	printf("当前的用户id是：%d\n",getuid());
	printf("当前的组id是：%d\n",getgid());
	return 0;
}



