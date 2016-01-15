//写入员工信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//定义员工的结构体信息
typedef struct
{
	int id;//员工编号
	char name[20];//员工姓名
	double salary;//员工薪水
}Emp;

int main(void)
{
	//1.创建文件
	int fd = open("emp.dat",O_CREAT|O_EXCL|O_WRONLY,0666);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("创建文件成功\n");
	//2.准备员工信息，写入文件中
	Emp emp = {1001,"张飞",3000};
	int res = write(fd,&emp,sizeof(emp));
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("写入数据成功\n");
	//3.关闭文件
	close(fd);
	return 0;
}
