//读取员工信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//定义员工信息结构体
typedef struct
{
	int id;//员工编号
	char name[20];//员工姓名
	double salary;//员工薪水
}Emp;

int main(void)
{
	//1.打开文件
	int fd = open("emp.dat",O_RDONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.读取文件信息，并且打印
	Emp emp = {};
	int res = read(fd,&emp,sizeof(emp));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("读取成功,读取到的内容是：%d,%s,%lf\n",emp.id,emp.name,emp.salary);
	//3.关闭文件
	close(fd);
	return 0;
}
