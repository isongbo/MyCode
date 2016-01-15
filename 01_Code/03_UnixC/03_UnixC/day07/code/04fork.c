//父子进程之间的资源关系
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int i1 = 1;//全局区

int main(void)
{
	int i2 = 1;//栈区
	//pi指向堆区  pi本身在栈区
	char* pi = (char*)malloc(sizeof(char)*10);
	strcpy(pi,"abcd");

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
		strcpy(pi,"1234");
		int i3 = 2;
		printf("我是子进程%d,i1 = %d,i2 = %d,pi = %s,i3 = %d\n",getpid(),i1,i2,pi,i3);
		exit(0);//终止子进程
	}
	//i3不能访问
	printf("我是父进程%d,i1 = %d,i2 = %d,pi = %s\n",getpid(),i2,i2,pi);
	return 0;
}


