//open函数和close函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
		printf("O_RDONLY = %d,O_WRONLY = %d,O_RDWR = %d\n",O_RDONLY,O_WRONLY,O_RDWR);
		printf("O_CREAT = %d,O_EXCL = %d,O_TRUNC = %d,O_APPEND = %d\n",O_CREAT,O_EXCL,O_TRUNC,O_APPEND);

		//1.创建一个文件
		int fd = open("a.txt",O_CREAT|O_EXCL|O_RDWR,0666);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		printf("创建文件成功\n");
		//2.关闭文件
		close(fd);
		printf("关闭文件\n");
		return 0;
}
