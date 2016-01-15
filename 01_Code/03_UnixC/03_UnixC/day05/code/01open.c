//文件的读写操作
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.创建文件,O_CREAT不存在则创建，存在打开
	//O_EXCL - 表示不存在创建，存在open出错
	int fd = open("a.txt",O_CREAT|O_EXCL|O_RDWR,0666);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("创建文件成功\n");
	//2.向文件中写入字符串
	int res = write(fd,"hello",5);
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("成功写入文件的大小是：%d\n",res);
	//3.关闭文件
	close(fd);
	return 0;
}





