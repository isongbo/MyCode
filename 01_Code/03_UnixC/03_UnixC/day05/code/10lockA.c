//使用fcntl函数给指定的文件内容加锁
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("e.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.准备一把锁
	struct flock lock;
	//lock.l_type = F_RDLCK;//读锁
	lock.l_type = F_WRLCK;//写锁
	lock.l_whence = SEEK_SET;//从头开始
	lock.l_start = 0;//偏移0个字节
	lock.l_len = 10;//锁定的字节数
	lock.l_pid = -1;//默认值
	//3.给指定的文件加锁
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，开始操作文件...\n");
	//4.占用文件
	sleep(20);
	printf("操作文件结束,进程结束\n");
	//5.关闭文件
	close(fd);
	return 0;
}



