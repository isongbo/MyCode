//read函数和write函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
		//1.创建一个文件
		int fd = open("b.txt",O_CREAT|O_TRUNC|O_WRONLY,0666);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}

		//2.写入一个数据
		//int num = 80;
		//int res = write(fd,&num,sizeof(num));
		int res = write(fd,"hello",5);
		printf("写入的数据大小是：%d\n",res);

		//3.关闭文件
		close(fd);

		//4.打开上述文件
		int fd2 = open("b.txt",O_RDONLY);
		if(-1 == fd2)
		{
				perror("open2"),exit(-1);
		}
		//5.读取文件的内容
		// int num2 = 0;
		// res = read(fd2,&num2,sizeof(num2));
		char buf[20] = {0};
		res = read(fd2,buf,sizeof(buf));
		printf("成功读取的数据内容是：%s,数据大小是：%d\n",buf,res);

		//6.关闭文件
		close(fd2);
		return 0;
}
