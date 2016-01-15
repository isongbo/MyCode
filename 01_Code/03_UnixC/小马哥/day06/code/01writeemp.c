//将员工信息写入文件中
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct Emp
{
		int id;//员工编号
		char name[20];//员工姓名
		double salary;//员工薪水
}Emp;

int main(void)
{
		//1.准备员工信息
		Emp emp;
		printf("请输入员工的编号，姓名，薪水：\n");
		scanf("%d%s%lf",&emp.id,emp.name,&emp.salary);
		//2.创建一个文件
		int fd = open("emp.dat",O_CREAT|O_EXCL|O_WRONLY,0666);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		//3.将员工信息写入文件中
		//将员工信息按照格式写入文件中
		char buf[100] = {0};
		sprintf(buf,"%d%s%lf",emp.id,emp.name,emp.salary);
		// size_t 本质上是 unsigned int
		// ssize_t 本质上是int类型
		// cc -E xxx.c > a.txt 
		ssize_t res = write(fd,buf,strlen(buf));
		//ssize_t res = write(fd,&emp,sizeof(emp));
		if(-1 == res)
		{
				perror("write"),exit(-1);
		}

		printf("fd = %d\n",fd);
		//4.关闭文件
		close(fd);
		return 0;
}
