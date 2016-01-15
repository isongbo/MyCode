//使用无名管道在父子进程之间通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//1.首先创建管道
	int fd[2] = {0};
	pipe(fd);
	//2.父子进程进行通信
	pid_t pid = fork();
	if(0 == pid) //子进程
	{
		//关闭写端
		close(fd[1]);
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			int x = 0;
			read(fd[0],&x,sizeof(int));
			printf("x = %d ",x);
			//刷新输出缓冲区
			fflush(stdout);
		}
		//关闭读端
		close(fd[0]);
		exit(0);
	}
	//关闭读端
	close(fd[0]);
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		write(fd[1],&i,sizeof(i));
		usleep(100000);
	}
	//关闭写端
	close(fd[1]);
	return 0;
}
