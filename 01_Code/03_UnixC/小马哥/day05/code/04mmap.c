//mmap函数和munmap函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(void)
{
		//1.建立物理内存到虚拟地址的映射
		void* pv = mmap(NULL/*由内核指定*/,
				 4/*地址空间大小*/,
				 PROT_READ|PROT_WRITE/*可读可写*/,
				 MAP_PRIVATE|MAP_ANONYMOUS/*私有的,用于映射物理内存*/,
				 0/*映射物理内存，给0*/,
				 0/*偏移量,给0表示映射的不是文件*/);
		//表示建立映射失败
		if(pv == MAP_FAILED)
		{
				perror("mmap"),exit(-1);
		}
		
		//2.使用虚拟地址
		int* pi = pv;
		*pi = 100;
		printf("pi = %p,*pi = %d\n",pi,*pi);

		//3.解除映射
		int res = munmap(pv,4);
		if(-1 == res)
		{
				perror("munmap"),exit(-1);
		}
		printf("解除映射成功\n");
		return 0;
}
