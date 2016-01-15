//各种ID的获取
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("当前进程的进程号是：%d\n",getpid());
	printf("当前进程的父进程号是：%d\n",getppid());
	printf("当前进程的用户ID是：%d\n",getuid());
	printf("当前进程的组ID是：%d\n",getgid());
	return 0;
}



