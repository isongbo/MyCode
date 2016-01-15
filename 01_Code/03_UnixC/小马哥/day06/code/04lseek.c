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
		
		//2.使用lseek函数操作文件
		char ch;
		//文件打开之后默认指向文件的开头位置，也就是第一个字符的位置
		read(fd,&ch,1);
		printf("ch = %c\n",ch);//a,指向下一个b
		read(fd,&ch,1);
		printf("ch = %c\n",ch);//b,指向下一个c

		printf("-------------------\n");
		//从当前位置向后偏移3个字节
		lseek(fd,3,SEEK_CUR);
		read(fd,&ch,1);
		printf("ch = %c\n",ch);//f 
		//从当前位置向前偏移2个字节
		lseek(fd,-2,SEEK_CUR);
		read(fd,&ch,1);
		printf("ch = %c\n",ch);//e

		printf("-----------------------\n");
		//回头文件的开头位置
		lseek(fd,0,SEEK_SET);
		write(fd,"1",1);//覆盖了字符a
		lseek(fd,2,SEEK_SET);
		write(fd,"2",1);//覆盖了字符c
		lseek(fd,3,SEEK_CUR);
		write(fd,"3",1);//覆盖了g
		lseek(fd,-2,SEEK_CUR);
		write(fd,"4",1);//覆盖了f

		printf("------------------------\n");
		//回到文件的末尾
		//lseek(fd,0,SEEK_END);
		//write(fd,"5",1);//在文件末尾写入5，相当于追加的效果
		lseek(fd,-1,SEEK_END);
		read(fd,&ch,1);
		// '\n' ASCII是10
		// 'a' 97    'A' 65  '0' 48  空格 32
		printf("最后一个ch = %c[%d]\n",ch,ch);//\n
		printf("a = %d,A = %d,0 = %d,空格 = %d\n",'a','A','0',' ');
		
		printf("------------------------\n");
		int res = lseek(fd,0,SEEK_END);
		printf("res = %d\n",res);

		//3.关闭文件
		close(fd);
		return 0;
}
