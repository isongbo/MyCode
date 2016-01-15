//vfork函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = vfork();
	if(-1 == pid)
	{
		perror("vfork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		printf("子进程%d开始执行\n",getpid());
		sleep(5);
		printf("子进程%d结束\n",getpid());
		exit(0);
	}
	printf("父进程%d开始运行\n",getpid());
	printf("父进程%d结束\n",getpid());
	return 0;
}
