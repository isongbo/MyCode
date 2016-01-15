//使用文件操作对管道进行写操作
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.pipe",O_WRONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.向文件中写入数据
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		write(fd,&i,sizeof(int));
		usleep(100000);//0.1秒 单位微秒
	}
	//3.关闭文件
	close(fd);
	return 0;
}
