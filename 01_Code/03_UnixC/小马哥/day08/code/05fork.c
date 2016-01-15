//fork函数创建的父子进程之间的关系
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i1 = 1;//全局区

int main(void)
{
	int i2 = 1;//栈区
	char* pc = malloc(20);//pc指向堆区
	strcpy(pc,"hello");

	//创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		i1 = 2;
		i2 = 2;
		pc[0] = 'A';
		int i3 = 2;
		printf("我是子进程%d,i1 = %d,i2 = %d,pc = %s,i3 = %d\n",getpid(),i1,i2,pc,i3);
		printf("我的父进程是%d\n",getppid());
		sleep(3);
		printf("我的父进程是%d\n",getppid());
		exit(0);//终止进程
	}
	//下面的代码由父进程执行
	sleep(1);
	printf("我是父进程%d,i1 = %d,i2 = %d,pc = %s\n",getpid(),i1,i2,pc);
	return 0;
}
