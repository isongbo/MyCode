//dup函数和dup2函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
		//1.打开文件
		int fd = open("c.txt",O_RDWR);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		//2.使用dup函数进行复制
		int fd2 = dup(fd);
		printf("fd = %d,fd2 = %d\n",fd,fd2);
		//3.通过文件描述符向文件中写入数据
		write(fd,"A",1);
		write(fd2,"B",1);
		
		printf("-----------------------\n");
		int fd3 = open("b.txt",O_RDWR);
		if(-1 == fd3)
		{
				perror("open"),exit(-1);
		}
		printf("fd3 = %d\n",fd3);
		//使用dup2函数进行文件描述符的复制
		int fd4 = dup2(fd,fd3);
		printf("fd3 = %d,fd4 = %d\n",fd3,fd4);
		//fd3和fd4是一样的
		write(fd3,"hehe",4);//写入c.txt文件
		//write(fd4,"hello",4);//写入c.txt文件

		//4.关闭文件
		close(fd);
		close(fd2);
		return 0;
}
