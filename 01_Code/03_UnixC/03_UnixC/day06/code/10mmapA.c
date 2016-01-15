//使用mmap函数建立从虚拟地址到文件的映射
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

//定义员工信息结构体
typedef struct
{
	int id;//员工编号
	char name[20];//员工姓名
	double salary;//员工薪水
}Emp;

int main(void)
{
	//1.创建文件，并且指定文件的大小
	int fd = open("emp.dat",O_CREAT|O_EXCL|O_RDWR,0666);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//使用ftruncate函数指定文件的大小
	ftruncate(fd,3*sizeof(Emp));
	//2.建立虚拟地址到文件的映射
	void* p = mmap(NULL,//由内核指定
			3*sizeof(Emp),//映射的大小
			PROT_READ|PROT_WRITE,//可读可写
			MAP_SHARED,//共享的
			fd,//文件描述符
			0//文件中的偏移量
		);
	if(MAP_FAILED == p)
	{
		perror("mmap"),exit(-1);
	}
	//3.采用虚拟地址来写入数据到文件
	Emp* pe = p;
	// int arr[5]; arr[0];
	// int* pe = arr; pe[0]
	pe[0].id = 1001;
	strcpy(pe[0].name,"zhangfei");
	pe[0].salary = 3000;

	pe[1].id = 1002;
	strcpy(pe[1].name,"guanyu");
	pe[1].salary = 4000;
	
	pe[2].id = 1003;
	strcpy(pe[2].name,"liubei");
	pe[2].salary = 5000;
	//4.关闭文件 并且解除映射
	munmap(p,3*sizeof(Emp));
	close(fd);
	//练习:vi 10mmapB.c 采用映射的方式将文件内容打印出来
	return 0;
}




