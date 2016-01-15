//mmap函数和munmap函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main(void)
{
	//1.建立新的映射
	void* p = mmap(NULL,//表示由内核指定
			4,//映射的大小
			PROT_READ|PROT_WRITE,//可读可写
			MAP_PRIVATE|MAP_ANONYMOUS,//映射物理内存,
			0,//文件描述符
			0//偏移量
	);
	if(MAP_FAILED == p)
	{
		perror("mmap"),exit(-1);
	}
	printf("建立映射成功\n");
	//2.使用映射所返回的虚拟地址
	int* pi = (int*)p;
	*pi = 100;
	printf("*pi = %d\n",*pi);
	//3.解除映射
	int res = munmap(p,4);
	if(-1 == res)
	{
		perror("munmap"),exit(-1);
	}
	printf("解除映射成功\n");
	return 0;
}


