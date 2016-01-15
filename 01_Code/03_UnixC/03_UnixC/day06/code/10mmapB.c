//采用映射的方式读取文件中的内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct
{
	int id;
	char name[20];
	double salary;
}Emp;

int main(void)
{
	//1.打开文件
	int fd = open("emp.dat",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.建立虚拟地址到文件的映射
	void* p = mmap(NULL,3*sizeof(Emp),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED == p)
	{
		perror("mmap"),exit(-1);
	}
	//3.通过虚拟地址打印文件内容
	Emp* pe = p;
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		printf("%d,%s,%lf\n",pe[i].id,pe[i].name,pe[i].salary);
	}
	//4.解除映射 关闭文件
	munmap(p,3*sizeof(Emp));
	close(fd);
	return 0;
}





