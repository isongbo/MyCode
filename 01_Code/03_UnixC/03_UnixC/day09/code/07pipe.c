//使用无名管道进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//1.创建管道获取文件描述符
	int fd[2];
	int res = pipe(fd);
	if(-1 == res)
	{
		perror("pipe"),exit(-1);
	}
	//2.创建子进程，让子进程负责给父进程发数据
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		//关闭读端
		close(fd[0]);
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			write(fd[1],&i,sizeof(int));
			usleep(100000);
		}
		//关闭写端
		close(fd[1]);
		//终止子进程
		exit(0);
	}
	//关闭写端
	close(fd[1]);
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		int x = 0;
		read(fd[0],&x,sizeof(int));
		printf("%d ",x);
		//刷新输出缓冲区
		fflush(stdout);
	}
	printf("\n");
	//关闭读端
	close(fd[0]);
	return 0;
}
