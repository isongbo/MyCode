//使用brk函数操作内存
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	//获取起始地址
	void* p = sbrk(0);
	printf("p = %p\n",p);

	//申请4个字节内存空间
	int res = brk(p+4);
	if(-1 == res)
	{
		perror("brk"),exit(-1);
	}
	printf("成功申请了4个字节的内存\n");
	void* cur = sbrk(0);
	printf("cur = %p\n",cur);

	//申请了4个字节
	brk(p+8);
	cur = sbrk(0);
	printf("cur = %p\n",cur);

	//释放了4个字节内存
	brk(p+4);
	cur = sbrk(0);
	printf("cur = %p\n",cur);

	//释放所有内存
	brk(p);
	return 0;
}





