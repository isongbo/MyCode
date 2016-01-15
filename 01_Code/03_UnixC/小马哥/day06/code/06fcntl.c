//fcntl函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
		//1.创建一个文件
		int fd = open("d.txt",O_CREAT|O_RDWR,0666);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		printf("fd = %d\n",fd);//3
		//2.使用fcntl函数进行文件描述符的拷贝
		int fd2 = fcntl(fd,F_DUPFD,5/* >= 5*/);
		printf("fd2 = %d\n",fd2);//5

		printf("------------------------\n");
		//3.获取文件的状态标志以及访问模式
		int flags = fcntl(fd,F_GETFL);
		printf("O_CREAT = %d,O_RDWR = %d\n",O_CREAT,O_RDWR);//64 2
		// O_CREAT的值是获取不到的，因为只有创建时有效
		printf("flags = %d\n",flags);// 2
		
		printf("--------------------------\n");
		//4.设置文件的状态标志和访问权限
		fcntl(fd,F_SETFL,O_WRONLY|O_APPEND|O_CREAT|O_TRUNC);
		flags = fcntl(fd,F_GETFL);
		printf("O_WRONLY = %d,O_APPEND = %d,O_TRUNC = %d\n",O_WRONLY,O_APPEND,O_TRUNC);
		printf("flags = %d\n",flags);
		return 0;
}
