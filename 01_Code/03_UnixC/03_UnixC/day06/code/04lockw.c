//F_SETLKW参数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.准备一把锁
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_pid = -1;
	//3.进行加锁，加不上则等待
	int res = fcntl(fd,F_SETLKW,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("那边总算把锁打开了，这里加锁成功\n");
	//4.关闭文件
	close(fd);
	return 0;
}



