//使用UC函数实现向文件中写入数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
		//1.打开文件
		int fd = open("num2.dat",O_CREAT|O_EXCL|O_WRONLY,0666);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		//2.写入数据
		int i = 0;
		//定义一个缓冲区
		int buf[1000000] = {0};
		for(i = 0; i < 10000; i++)
		{
				/*char buf[20] = {0};
				sprintf(buf,"%d\n",i);
				write(fd,buf,strlen(buf));*/
				buf[i%10000] = i;
				if(9999 == i%10000)
				{
						//将缓冲区中的数据写入文件
						write(fd,buf,sizeof(buf));
				}
		}
		//3.关闭文件
		close(fd);
		return 0;
}
