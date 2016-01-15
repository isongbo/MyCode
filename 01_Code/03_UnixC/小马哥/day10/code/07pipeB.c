//读取管道文件中的数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.pipe",O_RDONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.读取文件中的内容
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		int x = 0;
		read(fd,&x,sizeof(int));
		printf("x = %d\n",x);
	}
	//3.关闭文件
	close(fd);
	return 0;
}
