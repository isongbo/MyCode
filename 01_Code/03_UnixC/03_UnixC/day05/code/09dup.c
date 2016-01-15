//dup和dup2函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件
	int fd = open("c.txt",O_CREAT|O_RDWR,0666);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("文件创建成功\n");
	//2.复制文件描述符
	//多个文件描述符对应同一个文件
	int fd2 = dup(fd);
	if(-1 == fd2)
	{
		perror("dup"),exit(-1);
	}
	printf("复制文件描述符成功，fd = %d,fd2 = %d\n",fd,fd2);
	//向两个文件描述符对应的文件中写入数据
	write(fd,"A",1);
	write(fd2,"B",1);

	printf("--------------------------\n");
	int fd3 = open("d.txt",O_CREAT|O_RDWR,0666);
	if(-1 == fd3)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功,fd3 = %d\n",fd3);
	//使用dup2进行文件描述符的复制
	int fd4 = dup2(fd,fd3);//fd到fd3的复制
	if(-1 == fd4)
	{
		perror("dup2"),exit(-1);
	}
	// fd3 和 fd4值是一样的,都表示新文件描述符
	printf("文件描述符复制成功，fd3 = %d,fd4 = %d\n",fd3,fd4);
	//向fd3和fd4中写入数据
	write(fd3,"C",1);
	write(fd4,"D",1);
	//3.关闭文件
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}


