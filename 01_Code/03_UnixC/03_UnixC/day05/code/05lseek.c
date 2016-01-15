//lseek函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("b.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.使用lseek函数操作文件
	int res = lseek(fd,1,SEEK_SET/*文件开头位置*/);
	if(-1 == res)
	{
		perror("lseek"),exit(-1);
	}
	printf("res = %d\n",res);//1

	char ch;
	//读取1个字符放到ch中,每次读取之后移动位置
	read(fd,&ch,1);
	printf("ch = %c\n",ch);//b
	read(fd,&ch,1);
	printf("ch = %c\n",ch);//c

	//表示从当前位置向后偏移3个字节
	lseek(fd,3,SEEK_CUR);
	read(fd,&ch,1);
	printf("ch = %c\n",ch);//g

	//表示从当前位置向前偏移1个字节
	lseek(fd,-1,SEEK_CUR);
	write(fd,"G",1); //覆盖g

	read(fd,&ch,1);
	printf("ch = %c\n",ch);//h

	//表示从文件结尾位置向前偏移1个字节
	lseek(fd,-1,SEEK_END);
	read(fd,&ch,1);
	printf("ch = %c[%d]",ch,ch);//\n

	lseek(fd,-3,SEEK_END);
	read(fd,&ch,1);
	// 'a' 97  'A' 65  '0' 48  '\n' 10
	printf("ch = %c[%d]\n",ch,ch);

	//FILE 
	printf("fd = %d\n",fd); //3
	//3.关闭文件
	close(fd);
	return 0;
}



