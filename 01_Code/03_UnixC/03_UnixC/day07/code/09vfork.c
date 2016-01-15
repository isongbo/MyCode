//vfork函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = vfork();
	if(-1 == pid)
	{
		perror("vfork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行\n",getpid());
		sleep(10);
		printf("子进程结束\n");
		exit(100);//结束子进程
	}
	printf("父进程开始执行\n");
	printf("父进程结束\n");
	return 0;
}
