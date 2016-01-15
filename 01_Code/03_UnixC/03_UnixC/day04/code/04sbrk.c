//sbrk函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("pid = %d\n",getpid());
	//申请4个字节的内存空间
	void* p1 = sbrk(4);
	void* p2 = sbrk(4);
	void* p3 = sbrk(4);
	void* p4 = sbrk(4);
	printf("p1 = %p,p2 = %p,p3 = %p,p4 = %p\n",p1,p2,p3,p4);
	
	//获取内存区域的当前位置
	void* cur = sbrk(0);
	printf("cur = %p\n",cur);
	
	//释放4个字节的内存
	void* p5 = sbrk(-4);
	printf("p5 = %p\n",p5);
	cur = sbrk(0);
	printf("cur = %p\n",cur);
	
	//释放8个字节
	sbrk(-8);
	cur = sbrk(0);
	printf("cur = %p\n",cur); //p2

	printf("-------------------\n");
	printf("目前剩下4个字节的内存\n");
	getchar();

	sbrk(4093);
	printf("目前一共有4097个字节内存\n");
	getchar();

	sbrk(-1);
	printf("释放1个字节，回到4096个字节\n");
	getchar();
	return 0;
}


