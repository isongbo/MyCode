//使用free进行动态内存的释放
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("pid = %d\n",getpid());
	int* p1 = (int*)malloc(4096);
	printf("申请一个内存页大小的内存,p1 = %p\n",p1);
	getchar();

	int* p2 = (int*)malloc(30*4096);
	printf("申请30个内存页大小的内存,p2 = %p\n",p2);
	getchar();

	int* p3 = (int*)malloc(3*4096);
	printf("申请3个内存页大小的内存,已超过33个内存页,p3 = %p\n",p3);
	getchar();

	free(p3); p3 = NULL;
	printf("释放了3个内存页,回到33个内存页的范围\n");
	getchar();

	free(p2); p2 = NULL;
	printf("又释放了30个内存页\n");
	getchar();

	free(p1); p1 = NULL;
	printf("释放了所有的内存\n");
	getchar();
	return 0;
}

