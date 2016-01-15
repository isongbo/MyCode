//使用sbrk函数和brk函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
		int* pi = sbrk(sizeof(int));
		*pi = 88;
		double* pd = sbrk(sizeof(double));
		*pd = 3.14;
		char* pc = sbrk(10);
		strcpy(pc,"hello");
		printf("*pi = %d,*pd = %lf,pc = %s\n",*pi,*pd,pc);
		printf("pi = %p,pd = %p,pc = %p\n",pi,pd,pc);
		//释放全部内存
		if(-1 == brk(pi))
		{
				perror("brk"),exit(-1);
		}
		printf("所有内存释放完毕\n");
		return 0;
}
