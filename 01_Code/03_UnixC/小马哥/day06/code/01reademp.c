//将员工信息从文件中读取出来
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
		//2.创建一个文件
		int fd = open("emp.dat",O_RDONLY);
		if(-1 == fd)
		{
				perror("open"),exit(-1);
		}
		//3.将员工信息写入文件中
		ssize_t res = read(fd,&emp,sizeof(emp));
		if(-1 == res)
		{
				perror("read"),exit(-1);
		}
		printf("读取到的员工编号是：%d,员工姓名是：%s,员工薪水是：%lf\n",emp.id,emp.name,emp.salary);
		printf("fd = %d\n",fd);
		//4.关闭文件
		close(fd);
		return 0;
}
