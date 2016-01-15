//使用管道进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开管道文件
	int fd = open("a.pipe",O_WRONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.向管道文件中写入数据
	int i = 0;
	printf("开始写入数据...\n");
	for(i = 0; i < 100; i++)
	{
		write(fd,&i,sizeof(int));
		printf("写入数据%d\n",i);
		usleep(100000);
	}
	printf("写入数据成功\n");
	//3.关闭管道文件
	close(fd);
	//vi 06pipeB.c 负责从管道文件中读取数据,将读取到的数据打印出来
	return 0;
}




