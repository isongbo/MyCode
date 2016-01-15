//使用UC函数写入数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件
	int fd = open("num2.dat",O_CREAT|O_WRONLY,0666);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.写入数据
	int i = 0;
	int buf[10000];
	while(i < 1000000)
	{
		//每次都是将数据放到缓冲区中
		buf[i%10000] = i;
		//当缓冲区满了的时候再写入文件中
		if(9999 == i%10000)
		{
			//write(fd,&i,sizeof(int));
			write(fd,buf,sizeof(buf));
		}
		i++;
	}
	//3.关闭文件
	close(fd);
	return 0;
}
