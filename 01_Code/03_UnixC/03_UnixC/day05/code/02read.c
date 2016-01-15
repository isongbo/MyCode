//读取文件中的内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.txt",O_RDONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.读取文件中的内容
	char buf[100] = {0};
	int res = read(fd,buf,sizeof(buf));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("读取到的数据内容是：%s,读取到的数据大小是：%d\n",buf,res);
	//3.关闭文件
	close(fd);
	return 0;
}


