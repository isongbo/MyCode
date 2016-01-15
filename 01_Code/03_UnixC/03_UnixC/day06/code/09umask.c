//umask函数的使用
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	//使用umask函数设置新的权限屏蔽字
	mode_t old = umask(0055);
	printf("old = %o\n",old); //0002

	//创建新文件,系统默认屏蔽权限 0002,
	//其中屏蔽的权限002叫做权限屏蔽字
	int fd = open("b.txt",O_CREAT|O_RDWR,0777);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	
	//恢复系统默认的权限屏蔽字
	//umask的设置只是针对文件的创建生效
	umask(old);

	//关闭文件
	close(fd);
	return 0;
}





